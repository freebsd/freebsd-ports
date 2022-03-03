--- src/Mod/MeshPart/App/MeshFlattening.cpp.orig	2022-02-03 23:13:33.919226000 +0100
+++ src/Mod/MeshPart/App/MeshFlattening.cpp	2022-02-03 23:30:59.747315000 +0100
@@ -141,37 +141,37 @@
     if (triangulation.IsNull())
         throw std::runtime_error("null triangulation in face construction");
 
+    Standard_Integer numNodes = triangulation->NbNodes();
+    Standard_Integer numTriangles = triangulation->NbTriangles();
+
 //  compute uv coordinates
     if (triangulation->HasUVNodes())
     {
-        const TColgp_Array1OfPnt2d &_uv_nodes = triangulation->UVNodes();
-        this->uv_nodes.resize(triangulation->NbNodes(), 2);
+        this->uv_nodes.resize(numNodes, 2);
         i = 0;
-        for (Standard_Integer index = _uv_nodes.Lower(); index <= _uv_nodes.Upper(); ++index)
+        for (Standard_Integer index = 1; index <= numNodes; ++index)
         {
-            const gp_Pnt2d& _uv_node = _uv_nodes.Value(index);
+            const gp_Pnt2d& _uv_node = triangulation->UVNode(index);
             this->uv_nodes.row(i) << _uv_node.X(), _uv_node.Y();
             i++;
         }
     }
 // 
-    const TColgp_Array1OfPnt &_nodes = triangulation->Nodes();
-    this->xyz_nodes.resize(triangulation->NbNodes(), 3);
+    this->xyz_nodes.resize(numNodes, 3);
     i = 0;
-    for (Standard_Integer index = _nodes.Lower(); index <= _nodes.Upper(); ++index)
+    for (Standard_Integer index = 1; index <= numNodes; ++index)
     {
-        gp_Pnt _node = _nodes.Value(index);
+        gp_Pnt _node = triangulation->Node(index);
         this->xyz_nodes.row(i) << _node.X(), _node.Y(), _node.Z();
         i++;
     }
     
-    const Poly_Array1OfTriangle &_tris = triangulation->Triangles();
-    this->tris.resize(triangulation->NbTriangles(), 3);
+    this->tris.resize(numTriangles, 3);
     i = 0;
-    for (Standard_Integer index = _tris.Lower(); index <= _tris.Upper(); ++index)
+    for (Standard_Integer index = 1; index <= numTriangles; ++index)
     {
         int n1, n2, n3;
-        Poly_Triangle _tri = _tris.Value(index);
+        Poly_Triangle _tri = triangulation->Triangle(index);
         _tri.Get(n1, n2, n3);
         this->tris.row(i) << n1-1, n2-1, n3-1;
         i++;
