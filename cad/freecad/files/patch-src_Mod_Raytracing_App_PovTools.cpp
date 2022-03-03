--- src/Mod/Raytracing/App/PovTools.cpp.orig	2022-02-03 23:01:51.000000000 +0100
+++ src/Mod/Raytracing/App/PovTools.cpp	2022-02-03 23:03:51.000000000 +0100
@@ -402,7 +402,6 @@
 
     // cycling through the poly mesh
     const Poly_Array1OfTriangle& Triangles = aPoly->Triangles();
-    const TColgp_Array1OfPnt& Nodes = aPoly->Nodes();
     for (i=1; i<=nbTriInFace; i++) {
         // Get the triangle
         Standard_Integer N1,N2,N3;
@@ -416,9 +415,9 @@
             N2 = tmp;
         }
 
-        gp_Pnt V1 = Nodes(N1);
-        gp_Pnt V2 = Nodes(N2);
-        gp_Pnt V3 = Nodes(N3);
+        gp_Pnt V1 = aPoly->Node(N1);
+        gp_Pnt V2 = aPoly->Node(N2);
+        gp_Pnt V3 = aPoly->Node(N3);
 
         // transform the vertices to the place of the face
         if (!identity) {
