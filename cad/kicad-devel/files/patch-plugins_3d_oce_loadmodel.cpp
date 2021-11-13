--- plugins/3d/oce/loadmodel.cpp.orig	2021-11-13 17:46:24 UTC
+++ plugins/3d/oce/loadmodel.cpp
@@ -74,6 +74,8 @@
 #include <TDF_LabelSequence.hxx>
 #include <TDF_ChildIterator.hxx>
 
+#include <Standard_Version.hxx>
+
 #include "plugins/3dapi/ifsg_all.h"
 
 // log mask for wxLogTrace
@@ -960,8 +962,10 @@ bool processFace( const TopoDS_Face& face, DATA& data,
     else
         S3D::AddSGNodeRef( vshape.GetRawPtr(), ocolor );
 
+#if OCC_VERSION_HEX < 0x070600
     const TColgp_Array1OfPnt&    arrPolyNodes = triangulation->Nodes();
     const Poly_Array1OfTriangle& arrTriangles = triangulation->Triangles();
+#endif
 
     std::vector< SGPOINT > vertices;
     std::vector< int > indices;
@@ -970,14 +974,22 @@ bool processFace( const TopoDS_Face& face, DATA& data,
 
     for( int i = 1; i <= triangulation->NbNodes(); i++ )
     {
+#if OCC_VERSION_HEX < 0x070600
         gp_XYZ v( arrPolyNodes(i).Coord() );
+#else
+	gp_XYZ v( triangulation->Node(i).Coord() );
+#endif
         vertices.emplace_back( v.X(), v.Y(), v.Z() );
     }
 
     for( int i = 1; i <= triangulation->NbTriangles(); i++ )
     {
         int a, b, c;
+#if OCC_VERSION_HEX < 0x070600
         arrTriangles( i ).Get( a, b, c );
+#else
+	triangulation->Triangle(i).Get(a, b, c);
+#endif
         a--;
 
         if( reverse )
