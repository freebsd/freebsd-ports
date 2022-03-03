--- src/Mod/PartDesign/Gui/ViewProviderTransformed.cpp.orig	2022-03-03 21:21:36.816245000 +0100
+++ src/Mod/PartDesign/Gui/ViewProviderTransformed.cpp	2022-03-03 21:22:41.559121000 +0100
@@ -285,7 +285,6 @@
 
                 // cycling through the poly mesh
                 const Poly_Array1OfTriangle& Triangles = mesh->Triangles();
-                const TColgp_Array1OfPnt& Nodes = mesh->Nodes();
                 for (int g=1; g <= nbTriInFace; g++) {
                     // Get the triangle
                     Standard_Integer N1,N2,N3;
@@ -299,7 +298,7 @@
                     }
 
                     // get the 3 points of this triangle
-                    gp_Pnt V1(Nodes(N1)), V2(Nodes(N2)), V3(Nodes(N3));
+                    gp_Pnt V1(mesh->Node(N1)), V2(mesh->Node(N2)), V3(mesh->Node(N3));
 
                     // transform the vertices to the place of the face
                     if (!identity) {
