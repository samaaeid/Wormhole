#include <iostream>
#include <cstring>
using namespace std;
#define INFINITY 9999
#define MAX 100

/*
0 10 0 30 100
10 0 50 0 0
0 50 0 20 10 
30 0 20 0 60
100 0 10 60 0 
0
4
*/
void dijkstra(int a[MAX][MAX],int n ,int startnode, int target)
{
	int cost[MAX][MAX],distance[MAX],pred[MAX],i,j;
	int visited[MAX],count,minidistance,nextnode;

	//pred[] stores the predecessor "grandfather"of each node

	//create the cost matrix
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if(a[i][j]==0)
				cost[i][j]=INFINITY;
			else
				cost[i][j]=a[i][j];

	//initialize pred[],distance[] and visited[]
	for( i=0;i<n;i++)
	{
		distance[i]=cost[startnode][i];
		pred[i]=startnode;
		visited[i]=0;
	}
	distance[startnode]=0;
	visited[startnode]=1;
	count=0;

	while(count < n-1)
	{
		minidistance=INFINITY;

		//nextnode gives the node at minimum distance

		for(i=0;i<n;i++)
			if(distance[i] < minidistance&&!visited[i])
			{
				minidistance=distance[i];
				nextnode=i;
			}
			//check if a better path exists through nextnode
			visited[nextnode]=1;
			for(i=0;i<n;i++)
				if(!visited[i])
					if(minidistance+cost[nextnode][i]<distance[i])
					{
						distance[i]=minidistance+cost[nextnode][i];
						pred[i]=nextnode;
					}
		count++;
	}
	//print the path and time of each node

		if(target!= startnode)
		{
			cout<< "\nTime between Planet" << target << " = " << distance[target];
			cout<< "\nPath between planets = " << target;

            j=target;

			do
			{
				j=pred[j];
				cout<<"<-"<<j;
			}while(j!=startnode);
	}

}

int main()
{
	int a[MAX][MAX],i,j,n,source,target,location;
    cout<<"Please Enter The Number Of Planets:";

	cin>>n;

    cout<<"\nEnter The Wormhole between Planets:\n";

	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
            cin>> a[i][j];


    cout<<"\nEnter Your Source:";

	cin>>source;


    cout<<"\nEnter Your Target: ";

	cin>>target;


	dijkstra(a,n,source,target);

	char dg[30];
	cout<<"\nDid something wrong happen? /n Please Enter Yes or No: ";

	cin>>dg;

    if ( strcmp( dg , "yes")== 0){
        cout<<"OK, Enter Your Location:";

        cin>>location;

        dijkstra(a,n,location,target);
    }

    else {
                 cout<<"Thanks";
    }

	return 0;
}