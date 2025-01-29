--- contrib/domhex/BackgroundMesh2D.cpp.orig	2024-03-29 22:06:54 UTC
+++ contrib/domhex/BackgroundMesh2D.cpp
@@ -490,9 +490,9 @@ void frameFieldBackgroundMesh2D::computeCrossField(
         v[1] = (*it)->lines[i]->getVertex(1);
         SPoint2 p1, p2;
         reparamMeshEdgeOnFace(v[0], v[1], face, p1, p2);
-        Pair<SVector3, SVector3> der = face->firstDer((p1 + p2) * .5);
-        SVector3 t1 = der.first();
-        SVector3 t2 = der.second();
+        std::pair<SVector3, SVector3> der = face->firstDer((p1 + p2) * .5);
+        SVector3 t1 = der.first;
+        SVector3 t2 = der.second;
         SVector3 n = crossprod(t1, t2);
         n.normalize();
         SVector3 d1(v[1]->x() - v[0]->x(), v[1]->y() - v[0]->y(),
@@ -534,21 +534,21 @@ void frameFieldBackgroundMesh2D::eval_crossfield(doubl
                                                  STensor3 &cf)
 {
   double quadAngle = angle(u, v);
-  Pair<SVector3, SVector3> dirs =
+  std::pair<SVector3, SVector3> dirs =
     compute_crossfield_directions(u, v, quadAngle);
-  SVector3 n = crossprod(dirs.first(), dirs.second());
+  SVector3 n = crossprod(dirs.first, dirs.second);
 
   for(int i = 0; i < 3; i++) {
-    cf(i, 0) = dirs.first()[i];
-    cf(i, 1) = dirs.second()[i];
+    cf(i, 0) = dirs.first[i];
+    cf(i, 1) = dirs.second[i];
     cf(i, 2) = n[i];
   }
 
   //  SVector3 t1,t2,n;
   //  GFace *face = dynamic_cast<GFace*>(gf);
-  //  Pair<SVector3, SVector3> der = face->firstDer(SPoint2(u,v));
-  //  SVector3 s1 = der.first();
-  //  SVector3 s2 = der.second();
+  //  std::pair<SVector3, SVector3> der = face->firstDer(SPoint2(u,v));
+  //  SVector3 s1 = der.first;
+  //  SVector3 s2 = der.second;
   //  n = crossprod(s1,s2);
   //  n.normalize();
   //  s1.normalize();
@@ -642,12 +642,12 @@ void frameFieldBackgroundMesh2D::exportCrossField(cons
     double angle_current = angle(v);
     GPoint p = get_GPoint_from_MVertex(v);
     for(int i = 0; i < 2; i++) {
-      Pair<SVector3, SVector3> dirs = compute_crossfield_directions(
+      std::pair<SVector3, SVector3> dirs = compute_crossfield_directions(
         v->x(), v->y(), angle_current + deltas[i]);
       fprintf(f, "VP(%g,%g,%g) {%g,%g,%g};\n", p.x(), p.y(), p.z(),
-              dirs.first()[0], dirs.first()[1], dirs.first()[2]);
+              dirs.first[0], dirs.first[1], dirs.first[2]);
       fprintf(f, "VP(%g,%g,%g) {%g,%g,%g};\n", p.x(), p.y(), p.z(),
-              dirs.second()[0], dirs.second()[1], dirs.second()[2]);
+              dirs.second[0], dirs.second[1], dirs.second[2]);
     }
   }
   fprintf(f, "};\n");
@@ -656,7 +656,7 @@ void frameFieldBackgroundMesh2D::exportCrossField(cons
 
 // returns the cross field as a pair of othogonal vectors (NOT in parametric
 // coordinates, but real 3D coordinates)
-Pair<SVector3, SVector3>
+std::pair<SVector3, SVector3>
 frameFieldBackgroundMesh2D::compute_crossfield_directions(double u, double v,
                                                           double angle_current)
 {
@@ -664,12 +664,12 @@ frameFieldBackgroundMesh2D::compute_crossfield_directi
   GFace *face = dynamic_cast<GFace *>(gf);
   if(!face) {
     Msg::Error("Entity is not a face in background mesh");
-    return Pair<SVector3, SVector3>(SVector3(), SVector3());
+    return std::pair<SVector3, SVector3>(SVector3(), SVector3());
   }
 
-  Pair<SVector3, SVector3> der = face->firstDer(SPoint2(u, v));
-  SVector3 s1 = der.first();
-  SVector3 s2 = der.second();
+  std::pair<SVector3, SVector3> der = face->firstDer(SPoint2(u, v));
+  SVector3 s1 = der.first;
+  SVector3 s2 = der.second;
   SVector3 n = crossprod(s1, s2);
   n.normalize();
 
@@ -687,8 +687,8 @@ frameFieldBackgroundMesh2D::compute_crossfield_directi
   SVector3 t2 = crossprod(n, t1);
   t2.normalize();
 
-  return Pair<SVector3, SVector3>(SVector3(t1[0], t1[1], t1[2]),
-                                  SVector3(t2[0], t2[1], t2[2]));
+  return std::pair<SVector3, SVector3>(SVector3(t1[0], t1[1], t1[2]),
+                                       SVector3(t2[0], t2[1], t2[2]));
 }
 
 bool frameFieldBackgroundMesh2D::compute_RK_infos(double u, double v, double x,
@@ -711,9 +711,9 @@ bool frameFieldBackgroundMesh2D::compute_RK_infos(doub
     return false;
   }
 
-  Pair<SVector3, SVector3> der = face->firstDer(SPoint2(u, v));
-  SVector3 s1 = der.first();
-  SVector3 s2 = der.second();
+  std::pair<SVector3, SVector3> der = face->firstDer(SPoint2(u, v));
+  SVector3 s1 = der.first;
+  SVector3 s2 = der.second;
   SVector3 n = crossprod(s1, s2);
   n.normalize();
   SVector3 basis_u = s1;
