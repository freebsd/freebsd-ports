--- plugins/3d/oce/loadmodel.cpp.orig	2021-11-08 21:10:20.307953000 +0100
+++ plugins/3d/oce/loadmodel.cpp	2021-11-08 21:42:19.793113000 +0100
@@ -71,6 +71,8 @@
 #include <TDF_LabelSequence.hxx>
 #include <TDF_ChildIterator.hxx>
 
+#include <Standard_Version.hxx>
+
 #include "plugins/3dapi/ifsg_all.h"
 
 // log mask for wxLogTrace
@@ -865,8 +867,10 @@
     else
         S3D::AddSGNodeRef( vshape.GetRawPtr(), ocolor );
 
+#if OCC_VERSION_HEX < 0x070600
     const TColgp_Array1OfPnt&    arrPolyNodes = triangulation->Nodes();
     const Poly_Array1OfTriangle& arrTriangles = triangulation->Triangles();
+#endif
 
     std::vector< SGPOINT > vertices;
     std::vector< int > indices;
@@ -875,14 +879,22 @@
 
     for(int i = 1; i <= triangulation->NbNodes(); i++)
     {
+#if OCC_VERSION_HEX < 0x070600
         gp_XYZ v( arrPolyNodes(i).Coord() );
+#else
+        gp_XYZ v( triangulation->Node(i).Coord() );
+#endif
         vertices.push_back( SGPOINT( v.X(), v.Y(), v.Z() ) );
     }
 
     for(int i = 1; i <= triangulation->NbTriangles(); i++)
     {
         int a, b, c;
+#if OCC_VERSION_HEX < 0x070600
         arrTriangles( i ).Get( a, b, c );
+#else
+        triangulation->Triangle(i).Get(a, b, c);
+#endif
         a--;
 
         if( reverse )
