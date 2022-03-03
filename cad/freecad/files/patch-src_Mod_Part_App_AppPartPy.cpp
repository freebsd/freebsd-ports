--- src/Mod/Part/App/AppPartPy.cpp.orig	2022-01-30 22:29:02.026790000 +0100
+++ src/Mod/Part/App/AppPartPy.cpp	2022-01-30 22:50:54.044159000 +0100
@@ -804,14 +804,26 @@
             const TopAbs_Orientation anOrientation = currentFace.Orientation();
             bool flip = (anOrientation == TopAbs_REVERSED);
             if (!facets.IsNull()) {
+#if OCC_VERSION_HEX < 0x070600
                 const TColgp_Array1OfPnt& nodes = facets->Nodes();
                 const Poly_Array1OfTriangle& triangles = facets->Triangles();
                 for (int i = 1; i <= triangles.Length(); i++) {
+#else
+                int nbtri = facets->NbTriangles();
+                for (int i = 1; i <= nbtri; i++) {
+#endif
                     Standard_Integer n1,n2,n3;
+#if OCC_VERSION_HEX < 0x070600
                     triangles(i).Get(n1, n2, n3);
                     gp_Pnt p1 = nodes(n1);
                     gp_Pnt p2 = nodes(n2);
                     gp_Pnt p3 = nodes(n3);
+#else
+                    facets->Triangle(i).Get(n1, n2, n3);
+                    gp_Pnt p1 = facets->Node(n1);
+                    gp_Pnt p2 = facets->Node(n2);
+                    gp_Pnt p3 = facets->Node(n3);
+#endif
                     p1.Transform(loc.Transformation());
                     p2.Transform(loc.Transformation());
                     p3.Transform(loc.Transformation());
