--- src/Mod/Part/App/TopoShape.cpp.orig	2022-02-03 21:51:04.000000000 +0100
+++ src/Mod/Part/App/TopoShape.cpp	2022-02-03 22:55:05.882488000 +0100
@@ -38,8 +38,6 @@
 # include <BRep_Tool.hxx>
 # include <BRepAdaptor_Curve.hxx>
 # include <BRepAdaptor_CompCurve.hxx>
-# include <BRepAdaptor_HCurve.hxx>
-# include <BRepAdaptor_HCompCurve.hxx>
 # include <BRepAdaptor_Surface.hxx>
 # include <BRepAlgoAPI_Common.hxx>
 # include <BRepAlgoAPI_Cut.hxx>
@@ -1122,10 +1120,10 @@
         // check orientation
         TopAbs_Orientation orient = aFace.Orientation();
 
+        nbTriInFace = aPoly->NbTriangles();
         // cycling through the poly mesh
         const Poly_Array1OfTriangle& Triangles = aPoly->Triangles();
-        const TColgp_Array1OfPnt& Nodes = aPoly->Nodes();
-        for (int i=1;i<=nbTriInFace;i++) {
+        for (int i=1; i<=nbTriInFace; i++) {
             // Get the triangle
             Standard_Integer N1,N2,N3;
             Triangles(i).Get(N1,N2,N3);
@@ -1137,9 +1135,9 @@
                 N2 = tmp;
             }
 
-            gp_Pnt V1 = Nodes(N1);
-            gp_Pnt V2 = Nodes(N2);
-            gp_Pnt V3 = Nodes(N3);
+            gp_Pnt V1 = aPoly->Node(N1);
+            gp_Pnt V2 = aPoly->Node(N2);
+            gp_Pnt V3 = aPoly->Node(N3);
 
             // transform the vertices to the place of the face
             if (!identity) {
@@ -1193,6 +1191,7 @@
 
         std::vector<Base::Vector3f> vertices;
         Standard_Integer nbNodesInFace;
+        Standard_Integer nbNodesInTria;
 
         // triangulation succeeded?
         if (!aPoly.IsNull()) {
@@ -1233,16 +1232,14 @@
 
             // getting size and create the array
             nbNodesInFace = aPoly->NbNodes();
+            nbNodesInTria = aPolyTria->NbNodes();
             vertices.resize(nbNodesInFace);
 
-            const TColStd_Array1OfInteger& indices = aPoly->Nodes();
-            const TColgp_Array1OfPnt& Nodes = aPolyTria->Nodes();
-
             gp_Pnt V;
             int pos = 0;
             // go through the index array
-            for (Standard_Integer i=indices.Lower();i <= indices.Upper();i++) {
-                V = Nodes(indices(i));
+            for (Standard_Integer i=1; i<=nbNodesInTria; i++) {
+                V = aPolyTria->Node(i);
                 V.Transform(myTransf);
                 vertices[pos++].Set((float)(V.X()),(float)(V.Y()),(float)(V.Z()));
             }
@@ -2215,12 +2212,20 @@
     if (this->_Shape.IsNull())
         Standard_Failure::Raise("Cannot sweep along empty spine");
 
+#if OCC_VERSION_HEX >= 0x070600
+    Handle(Adaptor3d_Curve) myPath;
+    if (this->_Shape.ShapeType() == TopAbs_EDGE) {
+        const TopoDS_Edge& path_edge = TopoDS::Edge(this->_Shape);
+        myPath = new BRepAdaptor_Curve(path_edge);
+    }
+#else
     Handle(Adaptor3d_HCurve) myPath;
     if (this->_Shape.ShapeType() == TopAbs_EDGE) {
         const TopoDS_Edge& path_edge = TopoDS::Edge(this->_Shape);
         BRepAdaptor_Curve path_adapt(path_edge);
         myPath = new BRepAdaptor_HCurve(path_adapt);
     }
+#endif
     //else if (this->_Shape.ShapeType() == TopAbs_WIRE) {
     //    const TopoDS_Wire& path_wire = TopoDS::Wire(this->_Shape);
     //    BRepAdaptor_CompCurve path_adapt(path_wire);
@@ -3401,10 +3406,10 @@
 
         Domain domain;
         // copy the points
-        const TColgp_Array1OfPnt& points = theTriangulation->Nodes();
-        domain.points.reserve(points.Length());
-        for (int i = 1; i <= points.Length(); i++) {
-            gp_Pnt p = points(i);
+        int nbptintria = theTriangulation->NbNodes();
+        domain.points.reserve(nbptintria);
+        for (int i = 1; i <= nbptintria; i++) {
+            gp_Pnt p = theTriangulation->Node(i);
             p.Transform(loc.Transformation());
             Standard_Real X, Y, Z;
             p.Coord (X, Y, Z);
@@ -3414,11 +3419,11 @@
         // copy the triangles
         const TopAbs_Orientation anOrientation = face.Orientation();
         bool flip = (anOrientation == TopAbs_REVERSED);
-        const Poly_Array1OfTriangle& faces = theTriangulation->Triangles();
-        domain.facets.reserve(faces.Length());
-        for (int i = 1; i <= faces.Length(); i++) {
+        int nbtri = theTriangulation->NbTriangles();
+        domain.facets.reserve(nbtri);
+        for (int i = 1; i <= nbtri; i++) {
             Standard_Integer N1, N2, N3;
-            faces(i).Get(N1, N2, N3);
+            theTriangulation->Triangle(i).Get(N1, N2, N3);
 
             Facet tria;
             tria.I1 = N1-1; tria.I2 = N2-1; tria.I3 = N3-1;
@@ -3774,8 +3779,8 @@
                 const TColgp_Array1OfPnt& Nodes = aPoly->Nodes();
 
                 gp_Pnt V;
-                for (Standard_Integer i=0;i < nbNodesInFace;i++) {
-                    V = Nodes(i+1);
+                for (Standard_Integer i=1; i <= nbNodesInFace; i++) {
+                    V = Nodes(i);
                     V.Transform(myTransf);
                     vertices.emplace_back(V.X(),V.Y(),V.Z());
                 }
@@ -3808,14 +3813,12 @@
 
                 // getting size and create the array
                 nbNodesInFace = aPoly->NbNodes();
+                int nbNodesInTria = aPolyTria->NbNodes();
 
-                const TColStd_Array1OfInteger& indices = aPoly->Nodes();
-                const TColgp_Array1OfPnt& Nodes = aPolyTria->Nodes();
-
                 gp_Pnt V;
                 // go through the index array
-                for (Standard_Integer i=indices.Lower();i <= indices.Upper();i++) {
-                    V = Nodes(indices(i));
+                for (Standard_Integer i=1 ;i <= nbNodesInTria; i++) {
+                    V = aPolyTria->Node(i);
                     V.Transform(myTransf);
                     vertices.emplace_back(V.X(),V.Y(),V.Z());
                 }
