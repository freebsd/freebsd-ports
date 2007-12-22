--- library/tulip-ogl/src/GlGraphDrawGraph.cpp.orig	2007-12-18 21:44:00.000000000 +0100
+++ library/tulip-ogl/src/GlGraphDrawGraph.cpp	2007-12-18 21:45:56.000000000 +0100
@@ -58,8 +58,10 @@
 
   Coord translate= (elementLayout->getMax(_superGraph)+elementLayout->getMin(_superGraph))/-2.0;
   double max=maxS[0]+maxL[0]-minL[0];
-  max=max>?maxS[1]+maxL[1]-minL[1];
-  max=max>?maxS[2]+maxL[2]-minL[2];
+  double max1 = maxS[1]+maxL[1]-minL[1];
+  double max2 = maxS[2]+maxL[2]-minL[2];
+  max = (max > max1) ? max : max1;
+  max = (max > max2) ? max : max2;
   
   if (max<0.0001) max=1;
   max=1/max;
