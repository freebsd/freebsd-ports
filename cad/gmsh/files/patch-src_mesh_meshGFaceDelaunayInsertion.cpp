--- src/mesh/meshGFaceDelaunayInsertion.cpp.orig	2024-03-29 22:07:01 UTC
+++ src/mesh/meshGFaceDelaunayInsertion.cpp
@@ -331,11 +331,11 @@ void buildMetric(GFace *gf, double *uv, double *metric
 
 void buildMetric(GFace *gf, double *uv, double *metric)
 {
-  Pair<SVector3, SVector3> der = gf->firstDer(SPoint2(uv[0], uv[1]));
+  std::pair<SVector3, SVector3> der = gf->firstDer(SPoint2(uv[0], uv[1]));
 
-  metric[0] = dot(der.first(), der.first());
-  metric[1] = dot(der.second(), der.first());
-  metric[2] = dot(der.second(), der.second());
+  metric[0] = dot(der.first, der.first);
+  metric[1] = dot(der.second, der.first);
+  metric[2] = dot(der.second, der.second);
 }
 
 static double computeTolerance(const double radius)
