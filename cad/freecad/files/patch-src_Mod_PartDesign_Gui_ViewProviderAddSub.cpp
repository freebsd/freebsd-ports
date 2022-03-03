--- src/Mod/PartDesign/Gui/ViewProviderAddSub.cpp.orig	2022-03-03 20:43:05.599798000 +0100
+++ src/Mod/PartDesign/Gui/ViewProviderAddSub.cpp	2022-03-03 21:06:11.466643000 +0100
@@ -194,8 +194,7 @@
 
             // cycling through the poly mesh
             const Poly_Array1OfTriangle& Triangles = mesh->Triangles();
-            const TColgp_Array1OfPnt& Nodes = mesh->Nodes();
-            TColgp_Array1OfDir Normals (Nodes.Lower(), Nodes.Upper());
+            TColgp_Array1OfDir Normals (1, nbNodesInFace);
             getNormals(actFace, mesh, Normals);
 
             for (int g=1;g<=nbTriInFace;g++) {
@@ -211,7 +210,7 @@
                 }
 
                 // get the 3 points of this triangle
-                gp_Pnt V1(Nodes(N1)), V2(Nodes(N2)), V3(Nodes(N3));
+                gp_Pnt V1(mesh->Node(N1)), V2(mesh->Node(N2)), V3(mesh->Node(N3));
 
                 // get the 3 previewNormals of this triangle
                 gp_Dir NV1(Normals(N1)), NV2(Normals(N2)), NV3(Normals(N3));
