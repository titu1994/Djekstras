/*
 ============================================================================
 Name        : Djejstras.c
 Author      : Somshubra Majumdar
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <conio.h>

#define infinity 999

void dij(int n,int v,int cost[10][10],int dist[]) {
	int i,j,u,visited[10] = {0},min;
	for(i=1;i<=n;i++)
		dist[i]=cost[v][i];
	i=2;
	while(i<=n) {
		min=999;
		for(j=1;j<=n;j++)
			if(dist[j]<min && !visited[j])
				min=dist[j],u=j;
		visited[u]=1;
		i++;
		for(j=1;j<=n;j++)
			if((dist[u]+cost[u][j]<dist[j]) && !visited[j])
				dist[j]=dist[u]+cost[u][j];
	}
}
int main() {
	int n,v,i,j,cost[10][10],dist[10];

	setbuf(stdout, NULL);

	printf("\n Enter the number of nodes:");
	scanf("%d",&n);
	printf("\n Enter the cost matrix:\n");
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++) {
			scanf("%d",&cost[i][j]);
			if(cost[i][j]==0)
				cost[i][j]=infinity;
		}
	printf("\n Enter the source :");
	scanf("%d",&v);
	dij(n,v,cost,dist);
	printf("\n Shortest path:\n");
	for(i=1;i<=n;i++)
		if(i!=v)
			printf("%d->%d,cost=%d\n",v,i,dist[i]);

	return 0;
}
