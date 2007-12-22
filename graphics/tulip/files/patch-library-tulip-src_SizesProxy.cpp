--- library/tulip/src/SizesProxy.cpp.orig	2003-04-07 16:16:06.000000000 +0200
+++ library/tulip/src/SizesProxy.cpp	2007-12-21 18:28:35.000000000 +0100
@@ -59,7 +59,7 @@
 
 Size SizesProxy::getMax(SuperGraph *sg) {
   if (sg==0) sg=superGraph;
-  int sgi=(int)sg;
+  size_t sgi=(size_t)sg;
   if (minMaxOk.find(sgi)==minMaxOk.end()) minMaxOk[sgi]=false;
   if (!minMaxOk[sgi]) computeMinMax(sg);
   return max[sgi];
@@ -67,7 +67,7 @@
 
 Size  SizesProxy::getMin(SuperGraph *sg) {
   if (sg==0) sg=superGraph;
-  int sgi=(int)sg;
+  size_t sgi=(size_t)sg;
   if (minMaxOk.find(sgi)==minMaxOk.end()) minMaxOk[sgi]=false;
   if (!minMaxOk[sgi]) computeMinMax(sg);
   return min[sgi];
@@ -94,13 +94,13 @@
     node itn=itN->next();
     tmpSize=getNodeValue(itn);
     for (int i=0;i<3;++i) {
-      maxS[i]=maxS[i]>?tmpSize[i];
-      minS[i]=minS[i]<?tmpSize[i];
+      maxS[i]=(maxS[i] > tmpSize[i]) ? maxS[i] : tmpSize[i];
+      minS[i]=(minS[i] < tmpSize[i]) ? minS[i] : tmpSize[i];
     }
   }delete itN;
 
   if (sg==0) sg=superGraph;
-  int sgi=(int)sg;
+  size_t sgi=(size_t)sg;
 
   minMaxOk[sgi]=true;  
   min[sgi]=minS;
