--- contrib/HighOrderMeshOptimizer/HighOrderMeshElasticAnalogy.cpp.orig	2024-03-29 22:06:53 UTC
+++ contrib/HighOrderMeshOptimizer/HighOrderMeshElasticAnalogy.cpp
@@ -242,25 +242,25 @@ void highOrderTools::_computeMetricInfo(GFace *gf, MEl
   for(int j = 0; j < nbNodes; j++) {
     SPoint2 param;
     reparamMeshVertexOnFace(e->getVertex(j), gf, param);
-    Pair<SVector3, SVector3> der = gf->firstDer(param);
+    std::pair<SVector3, SVector3> der = gf->firstDer(param);
     int XJ = j;
     int YJ = j + nbNodes;
     int ZJ = j + 2 * nbNodes;
     int UJ = j;
     int VJ = j + nbNodes;
-    J(XJ, UJ) = der.first().x();
-    J(YJ, UJ) = der.first().y();
-    J(ZJ, UJ) = der.first().z();
-    J(XJ, VJ) = der.second().x();
-    J(YJ, VJ) = der.second().y();
-    J(ZJ, VJ) = der.second().z();
+    J(XJ, UJ) = der.first.x();
+    J(YJ, UJ) = der.first.y();
+    J(ZJ, UJ) = der.first.z();
+    J(XJ, VJ) = der.second.x();
+    J(YJ, VJ) = der.second.y();
+    J(ZJ, VJ) = der.second.z();
 
-    JT(UJ, XJ) = der.first().x();
-    JT(UJ, YJ) = der.first().y();
-    JT(UJ, ZJ) = der.first().z();
-    JT(VJ, XJ) = der.second().x();
-    JT(VJ, YJ) = der.second().y();
-    JT(VJ, ZJ) = der.second().z();
+    JT(UJ, XJ) = der.first.x();
+    JT(UJ, YJ) = der.first.y();
+    JT(UJ, ZJ) = der.first.z();
+    JT(VJ, XJ) = der.second.x();
+    JT(VJ, YJ) = der.second.y();
+    JT(VJ, ZJ) = der.second.z();
 
     SVector3 ss = getSSL(e->getVertex(j));
     GPoint gp = gf->point(param);
