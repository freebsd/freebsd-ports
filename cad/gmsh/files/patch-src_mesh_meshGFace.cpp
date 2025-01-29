--- src/mesh/meshGFace.cpp.orig	2024-03-29 22:07:01 UTC
+++ src/mesh/meshGFace.cpp
@@ -1269,7 +1269,7 @@ static bool improved_translate(GFace *gf, MVertex *ver
   SVector3 s1, s2;
   SVector3 normal;
   SVector3 basis_u, basis_v;
-  Pair<SVector3, SVector3> derivatives;
+  std::pair<SVector3, SVector3> derivatives;
 
   reparamMeshVertexOnFace(vertex, gf, point);
   x = point.x();
@@ -1278,8 +1278,8 @@ static bool improved_translate(GFace *gf, MVertex *ver
   angle = backgroundMesh::current()->getAngle(x, y, 0.0);
   derivatives = gf->firstDer(point);
 
-  s1 = derivatives.first();
-  s2 = derivatives.second();
+  s1 = derivatives.first;
+  s2 = derivatives.second;
   normal = crossprod(s1, s2);
 
   basis_u = s1;
