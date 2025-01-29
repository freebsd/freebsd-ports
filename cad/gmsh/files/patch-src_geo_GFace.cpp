--- src/geo/GFace.cpp.orig	2024-03-29 22:07:00 UTC
+++ src/geo/GFace.cpp
@@ -880,10 +880,10 @@ double GFace::curvatureDiv(const SPoint2 &param) const
 
   const double eps = 1.e-5;
 
-  Pair<SVector3, SVector3> der = firstDer(param);
+  std::pair<SVector3, SVector3> der = firstDer(param);
 
-  SVector3 du = der.first();
-  SVector3 dv = der.second();
+  SVector3 du = der.first;
+  SVector3 dv = der.second;
   SVector3 nml = crossprod(du, dv);
 
   double detJ = norm(nml);
@@ -937,19 +937,19 @@ double GFace::curvatures(const SPoint2 &param, SVector
                          SVector3 &dirMin, double &curvMax,
                          double &curvMin) const
 {
-  Pair<SVector3, SVector3> D1 = firstDer(param);
+  std::pair<SVector3, SVector3> D1 = firstDer(param);
 
   if(geomType() == Plane || geomType() == BoundaryLayerSurface) {
-    dirMax = D1.first();
-    dirMin = D1.second();
+    dirMax = D1.first;
+    dirMin = D1.second;
     curvMax = 0.;
     curvMin = 0.;
     return 0.;
   }
 
   if(geomType() == Sphere) {
-    dirMax = D1.first();
-    dirMin = D1.second();
+    dirMax = D1.first;
+    dirMin = D1.second;
     curvMax = curvatureDiv(param);
     curvMin = curvMax;
     return curvMax;
@@ -961,8 +961,8 @@ double GFace::curvatures(const SPoint2 &param, SVector
   // curvatures and main directions
   curvMax = fabs(eigVal[1]);
   curvMin = fabs(eigVal[0]);
-  dirMax = eigVec[1] * D1.first() + eigVec[3] * D1.second();
-  dirMin = eigVec[0] * D1.first() + eigVec[2] * D1.second();
+  dirMax = eigVec[1] * D1.first + eigVec[3] * D1.second;
+  dirMin = eigVec[0] * D1.first + eigVec[2] * D1.second;
 
   return curvMax;
 }
@@ -979,9 +979,9 @@ void GFace::getMetricEigenVectors(const SPoint2 &param
                                   double eigVec[4]) const
 {
   // first derivatives
-  Pair<SVector3, SVector3> D1 = firstDer(param);
-  SVector3 du = D1.first();
-  SVector3 dv = D1.second();
+  std::pair<SVector3, SVector3> D1 = firstDer(param);
+  SVector3 du = D1.first;
+  SVector3 dv = D1.second;
   SVector3 nor = crossprod(du, dv);
   nor.normalize();
 
@@ -1088,13 +1088,13 @@ void GFace::XYZtoUV(double X, double Y, double Z, doub
 
       while(err > tol && iter < MaxIter) {
         P = point(U, V);
-        Pair<SVector3, SVector3> der = firstDer(SPoint2(U, V));
-        mat[0][0] = der.left().x();
-        mat[0][1] = der.left().y();
-        mat[0][2] = der.left().z();
-        mat[1][0] = der.right().x();
-        mat[1][1] = der.right().y();
-        mat[1][2] = der.right().z();
+        std::pair<SVector3, SVector3> der = firstDer(SPoint2(U, V));
+        mat[0][0] = der.first.x();
+        mat[0][1] = der.first.y();
+        mat[0][2] = der.first.z();
+        mat[1][0] = der.second.x();
+        mat[1][1] = der.second.y();
+        mat[1][2] = der.second.z();
         mat[2][0] = 0.;
         mat[2][1] = 0.;
         mat[2][2] = 0.;
@@ -1193,15 +1193,15 @@ void bfgs_callback(const alglib::real_1d_array &x, dou
   // printf("func : %f\n", func);
 
   // Value of the gradient
-  Pair<SVector3, SVector3> der = gf->firstDer(SPoint2(x[0], x[1]));
-  grad[0] = -(p.x() - pnt.x()) * der.left().x() -
-            (p.y() - pnt.y()) * der.left().y() -
-            (p.z() - pnt.z()) * der.left().z();
-  grad[1] = -(p.x() - pnt.x()) * der.right().x() -
-            (p.y() - pnt.y()) * der.right().y() -
-            (p.z() - pnt.z()) * der.right().z();
+  std::pair<SVector3, SVector3> der = gf->firstDer(SPoint2(x[0], x[1]));
+  grad[0] = -(p.x() - pnt.x()) * der.first.x() -
+            (p.y() - pnt.y()) * der.first.y() -
+            (p.z() - pnt.z()) * der.first.z();
+  grad[1] = -(p.x() - pnt.x()) * der.second.x() -
+            (p.y() - pnt.y()) * der.second.y() -
+            (p.z() - pnt.z()) * der.second.z();
   // printf("func %22.15E Gradients %22.15E %22.15E der %g %g %g\n", func,
-  //         grad[0], grad[1],der.left().x(),der.left().y(),der.left().z());
+  //         grad[0], grad[1],der.first.x(),der.first.y(),der.first.z());
 }
 #endif
 
@@ -1296,8 +1296,8 @@ SVector3 GFace::normal(const SPoint2 &param) const
 {
   if(geomType() == BoundaryLayerSurface) return SVector3();
 
-  Pair<SVector3, SVector3> der = firstDer(param);
-  SVector3 n = crossprod(der.first(), der.second());
+  std::pair<SVector3, SVector3> der = firstDer(param);
+  SVector3 n = crossprod(der.first, der.second);
   n.normalize();
   return n;
 }
