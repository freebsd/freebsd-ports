--- src/mesh/meshGFaceBamg.cpp.orig	2024-03-29 22:07:01 UTC
+++ src/mesh/meshGFaceBamg.cpp
@@ -49,14 +49,14 @@ static void computeMeshMetricsForBamg(GFace *gf, int n
     SMetric3 m = BGM_MeshMetric(gf, u, v, gp.x(), gp.y(), gp.z());
 
     // compute the derivatives of the parametrization
-    Pair<SVector3, SVector3> der = gf->firstDer(SPoint2(u, v));
+    std::pair<SVector3, SVector3> der = gf->firstDer(SPoint2(u, v));
 
-    J(0, 0) = JT(0, 0) = der.first().x();
-    J(0, 1) = JT(1, 0) = der.first().y();
-    J(0, 2) = JT(2, 0) = der.first().z();
-    J(1, 0) = JT(0, 1) = der.second().x();
-    J(1, 1) = JT(1, 1) = der.second().y();
-    J(1, 2) = JT(2, 1) = der.second().z();
+    J(0, 0) = JT(0, 0) = der.first.x();
+    J(0, 1) = JT(1, 0) = der.first.y();
+    J(0, 2) = JT(2, 0) = der.first.z();
+    J(1, 0) = JT(0, 1) = der.second.x();
+    J(1, 1) = JT(1, 1) = der.second.y();
+    J(1, 2) = JT(2, 1) = der.second.z();
 
     m.getMat(M);
     J.mult(M, W);
