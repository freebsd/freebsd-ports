--- library/tulip/src/MetricProxy.cpp.orig	2007-12-21 18:18:19.000000000 +0100
+++ library/tulip/src/MetricProxy.cpp	2007-12-21 18:20:29.000000000 +0100
@@ -31,7 +31,7 @@
 double MetricProxy::getNodeMin(SuperGraph *sg) 
 {
   if (sg==0) sg=superGraph;
-  int sgi=(int)sg;
+  size_t sgi=(size_t)sg;
   if (minMaxOkNode.find(sgi)==minMaxOkNode.end()) minMaxOkNode[sgi]=false;
   if (!minMaxOkNode[sgi]) computeMinMaxNode(sg);
   return minN[sgi];
@@ -44,7 +44,7 @@
 double MetricProxy::getNodeMax(SuperGraph *sg) 
 {
   if (sg==0) sg=superGraph;
-  int sgi=(int)sg;
+  size_t sgi=(size_t)sg;
   if (minMaxOkNode.find(sgi)==minMaxOkNode.end()) minMaxOkNode[sgi]=false;
   if (!minMaxOkNode[sgi]) computeMinMaxNode(sg);
   return maxN[sgi];
@@ -57,7 +57,7 @@
 double MetricProxy::getEdgeMin(SuperGraph *sg) 
 {
   if (sg==0) sg=superGraph;
-  int sgi=(int)sg;
+  size_t sgi=(size_t)sg;
   if (minMaxOkEdge.find(sgi)==minMaxOkEdge.end()) minMaxOkEdge[sgi]=false;
   if (!minMaxOkEdge[sgi]) computeMinMaxEdge(sg);
   return minE[sgi];
@@ -71,7 +71,7 @@
 {
 
   if (sg==0) sg=superGraph;
-  int sgi=(int)sg;
+  size_t sgi=(size_t)sg;
   if (minMaxOkEdge.find(sgi)==minMaxOkEdge.end()) minMaxOkEdge[sgi]=false;
   if (!minMaxOkEdge[sgi]) computeMinMaxEdge(sg);
   return maxE[sgi];
@@ -125,7 +125,7 @@
   delete itN;
 
   if (sg==0) sg=superGraph;
-  int sgi=(int)sg;
+  size_t sgi=(size_t)sg;
 
   minMaxOkNode[sgi]=true;  
   minN[sgi]=minN2;
@@ -151,7 +151,7 @@
   delete itE;
 
   if (sg==0) sg=superGraph;
-  int sgi=(int)sg;
+  size_t sgi=(size_t)sg;
 
   minMaxOkEdge[sgi]=true;  
   minE[sgi]=minE2;
