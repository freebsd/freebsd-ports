--- src/mesh/BackgroundMesh.cpp.orig	2024-03-29 22:07:01 UTC
+++ src/mesh/BackgroundMesh.cpp
@@ -304,8 +304,8 @@ void backgroundMesh::propagateCrossFieldByDistance(GFa
         SPoint2 p1, p2;
         reparamMeshEdgeOnFace(v[0], v[1], _gf, p1, p2);
         /* a correct way of computing angles  */
-        Pair<SVector3, SVector3> der = _gf->firstDer((p1 + p2) * .5);
-        SVector3 t1 = der.first();
+        std::pair<SVector3, SVector3> der = _gf->firstDer((p1 + p2) * .5);
+        SVector3 t1 = der.first;
         SVector3 t2(v[1]->x() - v[0]->x(), v[1]->y() - v[0]->y(),
                     v[1]->z() - v[0]->z());
         t1.normalize();
@@ -459,9 +459,9 @@ void backgroundMesh::propagateCrossField(GFace *_gf,
         v[1] = (*it)->lines[i]->getVertex(1);
         SPoint2 p1, p2;
         reparamMeshEdgeOnFace(v[0], v[1], _gf, p1, p2);
-        Pair<SVector3, SVector3> der = _gf->firstDer((p1 + p2) * .5);
-        SVector3 t1 = der.first();
-        SVector3 t2 = der.second();
+        std::pair<SVector3, SVector3> der = _gf->firstDer((p1 + p2) * .5);
+        SVector3 t1 = der.first;
+        SVector3 t2 = der.second;
         SVector3 n = crossprod(t1, t2);
         n.normalize();
         SVector3 d1(v[1]->x() - v[0]->x(), v[1]->y() - v[0]->y(),
