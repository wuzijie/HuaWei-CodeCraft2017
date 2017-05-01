//
//  MiniCostFlow.h
//  
//
//  Created by Mordekaiser on 17/4/3.
//
//

#ifndef ____MiniCostFlow__
#define ____MiniCostFlow__

#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <string>
#include "deploy.h"
#include "Graph.h"
#include "Genome.h"
#include <queue>

class MiniCostFlow {
private:
    #define MAXNODE 1000
    #define MAXEDGE MAXNODE*MAXNODE
    #define MIN(a,b) ((a)<(b)?(a):(b))
    #define OPPOSITE(x) (((x)&1)?((x)+1):((x)-1))   // x为奇数就加1，x为偶数就-1
    
    int N,S,T;
    // c表示流量，cost表示单价，endt表示增广链
    int begint[MAXNODE+1],endt[MAXEDGE+1],nextt[MAXEDGE+1],c[MAXEDGE+1],cost[MAXEDGE+1],d[MAXNODE+1],cur[MAXNODE+1];
    int cT[MAXEDGE+1],bT[MAXNODE+1];
    bool haslabel[MAXNODE+1];
    int Count = 0;  // 记录参与图中边的数量
    vector<int> tmp1;
    vector<int> tmp2;
    vector<vector<int>> tmp3;
    int NumConsumeNode[500];
    int NodeNum ;
    int EdgeNum ;
    int GustNum ;
    int needFlow;
    int allFlow;
    
public:
    void initial(Graph& graph,vector<vector<int>> &graph_param);    // 初始化最小费用流需要的相关变量
    int solve(Graph& graph,vector<vector<int>> &graph_param);   // 求解最小费用流

    int getCost(); // 求取费用
    bool Changelabel();//调整标号
    int getAugmentChain(int u,int f);// 找增广链
    void add_Node(int a,int b,int flow, int v); //构造残余图
    void ClearAll(int a,int b,int flow, int v); //清空所有，每次计算完务必执行
    void ClearAll_butc(int a,int b,int flow, int v);

    // 求解最小费用流，并返回每一条边的流量，用于解析结果，只需要最后求一次
    vector<float> getResult(Graph& graph,vector<vector<int>> &graph_param);
    
    // 以下两个函数用于获取初始种群，即利用最小费用流初步获取一个比较好的初始解，然后给遗传算法继续优化
    std::list<Genome::Individual> getInitialPopulation(Graph& graph,vector<vector<int>> &graph_param);
    std::list<Genome::Individual> getInitialPopulation_Improve(Graph& graph,vector<vector<int>> &graph_param, const vector<int>& inputservice);
};










#endif /* defined(____MiniCostFlow__) */
