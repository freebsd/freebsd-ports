--- src/cluster_bg.c.orig	Mon Aug 23 15:00:34 2004
+++ src/cluster_bg.c	Mon Aug 23 15:02:36 2004
@@ -7,12 +7,11 @@



-int cluster_bg(int cluster) {
+int cluster_bg(int cluster_arg) {

 extern char spot_ptr[MAX_SPOTS][82];
 extern int spotarray[MAX_SPOTS];
 extern char spotinfo[32][82];
-extern int cluster;
 extern int announcefilter;
 extern int bandinx;

@@ -22,14 +21,14 @@



-				if (cluster == NOCLUSTER)
+				if (cluster_arg == NOCLUSTER)
 					return(1);

-				if (cluster == MAP)
+				if (cluster_arg == MAP)
 					clustermode = bandinx;
-				if (cluster  == SPOTS)
+				if (cluster_arg  == SPOTS)
 					clustermode =  9;
-				if ( cluster  != CLUSTER)
+				if ( cluster_arg  != CLUSTER)

 				{
 				announcefilter = FILTER_DX;
@@ -77,7 +76,7 @@
 				}


-				if (cluster  == CLUSTER){             /* all cluster info  */
+				if (cluster_arg  == CLUSTER){             /* all cluster info  */

 		   			k = getclusterinfo();

@@ -100,7 +99,6 @@
 extern int spotarray[];
 extern int announcefilter;
 extern char call[];
-extern int cluster;
 extern int bandinx;

 int bg, nd, i;
