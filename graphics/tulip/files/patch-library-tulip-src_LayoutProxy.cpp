--- library/tulip/src/LayoutProxy.cpp.orig	2003-04-07 16:16:06.000000000 +0200
+++ library/tulip/src/LayoutProxy.cpp	2007-12-21 18:16:10.000000000 +0100
@@ -18,7 +18,7 @@
 TemplateFactory<LayoutFactory,Layout,PropertyContext *> LayoutProxy::factory;
 
 LayoutProxy::LayoutProxy (PropertyContext *context):PropertyProxy<PointType,LineType>(context) {
-  minMaxOk[(int)superGraph]=false;
+  minMaxOk[(size_t)superGraph]=false;
   currentLayout=0;
   propertyProxy=this;
 }
@@ -87,7 +87,7 @@
 
 Coord LayoutProxy::getMax(SuperGraph *sg) {
   if (sg==0) sg=superGraph;
-  int sgi=(int)sg;
+  size_t sgi=(size_t)sg;
   if (minMaxOk.find(sgi)==minMaxOk.end()) minMaxOk[sgi]=false;
 
   if (!minMaxOk[sgi]) computeMinMax(sg);
@@ -96,7 +96,7 @@
 
 Coord  LayoutProxy::getMin(SuperGraph *sg) {
   if (sg==0) sg=superGraph;
-  int sgi=(int)sg;
+  size_t sgi=(size_t)sg;
   if (minMaxOk.find(sgi)==minMaxOk.end()) minMaxOk[sgi]=false;
   if (!minMaxOk[sgi]) computeMinMax(sg);
   return min[sgi];
@@ -107,7 +107,7 @@
 #ifndef NDEBUG
   cerr << "LayoutProxy::center()" << endl;
 #endif
-  int sgi=(int)superGraph;
+  size_t sgi=(size_t)superGraph;
   if (superGraph->numberOfNodes()==0) return;
   Observable::holdObservers();
   Coord translate=getMax()+getMin();
@@ -209,9 +209,11 @@
   deltaY = (double )getMax()[1]-(double )getMin()[1];
   deltaZ = (double )getMax()[2]-(double )getMin()[2];
 
-  double delta= deltaX >? deltaY;
-  delta = delta >? deltaZ;
+  double delta;
 
+  delta = (deltaX > deltaY) ? deltaX : deltaY;
+  delta = (delta  > deltaZ) ? delta  : deltaZ;
+  
   if (delta<0.001) return;
 
   if (deltaX<0.001) deltaX=delta;
@@ -302,7 +304,7 @@
   }delete itE;
 
 
-  int sgi=(int)sg;
+  size_t sgi=(size_t)sg;
 
   minMaxOk[sgi]=true;  
   min[sgi].set(minX,minY,minZ);
