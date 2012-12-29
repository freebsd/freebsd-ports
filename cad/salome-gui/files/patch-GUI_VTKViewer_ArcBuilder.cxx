--- src/VTKViewer/VTKViewer_ArcBuilder.cxx.orig	2010-06-17 12:55:20.000000000 -0230
+++ src/VTKViewer/VTKViewer_ArcBuilder.cxx	2012-09-13 13:37:37.000000000 -0230
@@ -148,7 +148,9 @@
  * Calculate angle between vectors in degrees
  */
 double Vec::AngleBetweenInGrad(const Vec & Other){
-  return AngleBetween(Other)*vtkMath::DoubleRadiansToDegrees();
+  double res;
+  res = AngleBetween(Other);
+  return vtkMath::DegreesFromRadians(res);
 }
 
 /*
@@ -463,7 +465,7 @@
   double angle3 = GetPointAngleOnCircle(xCenter,yCenter,x3,y3);
   
   
-  double aMaxAngle = vtkMath::DoubleDegreesToRadians()*myAngle*2;   
+  double aMaxAngle = vtkMath::DegreesFromRadians(myAngle*2);   
   
   /*  double aTotalAngle =  fabs(angle3 - angle1);
   
