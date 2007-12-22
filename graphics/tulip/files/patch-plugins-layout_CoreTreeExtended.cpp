--- plugins/layout/ConeTreeExtended.cpp.orig	2007-12-18 22:22:22.000000000 +0100
+++ plugins/layout/ConeTreeExtended.cpp	2007-12-18 22:25:35.000000000 +0100
@@ -94,6 +94,7 @@
   double sumRadius=0;
   double maxRadius=0;
   double newRadius;
+  double minRadiusResult;
 
   std::vector<double> subCircleRadius(superGraph->outdeg(n));
   Iterator<node> *itN=superGraph->getOutNodes(n);
@@ -101,7 +102,7 @@
     node itn = itN->next();
     subCircleRadius[i] = treePlace3D(itn,posRelX,posRelY);
     sumRadius += 2*subCircleRadius[i];
-    maxRadius = maxRadius >? subCircleRadius[i];
+    maxRadius = (maxRadius > subCircleRadius[i]) ? maxRadius : subCircleRadius[i];
   }delete itN;
   
   double radius=sumRadius/(2*M_PI);
@@ -120,7 +121,8 @@
   for (int i=0;i<subCircleRadius.size()-1;++i) {
     //if (subCircleRadius[i]>1)
       for (int j=i+1;j<subCircleRadius.size();++j) {
-	newRadius = newRadius >? minRadius(subCircleRadius[i],vangles[i],subCircleRadius[j],vangles[j]); 
+         minRadiusResult = minRadius(subCircleRadius[i],vangles[i],subCircleRadius[j],vangles[j]);
+         newRadius = (newRadius > minRadiusResult) ? newRadius : minRadiusResult;
       }
   }
   if (newRadius==0) newRadius=radius;
