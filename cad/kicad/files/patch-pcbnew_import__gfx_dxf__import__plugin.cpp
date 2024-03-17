--- pcbnew/import_gfx/dxf_import_plugin.cpp.orig	2023-04-13 20:27:39 UTC
+++ pcbnew/import_gfx/dxf_import_plugin.cpp
@@ -28,6 +28,9 @@
 // like void DXF_IMPORT_PLUGIN::addLine( const DL_LineData& data ) when a line is read.
 // this function just add the BOARD entity from dxf parameters (start and end point ...)
 
+#ifdef __BSD_VISIBLE
+#undef __BSD_VISIBLE
+#endif
 
 #include "dxf_import_plugin.h"
 #include <wx/arrstr.h>
@@ -580,7 +583,7 @@ void DXF_IMPORT_PLUGIN::addEllipse( const DL_EllipseDa
     // For now, we assume ellipses in the XY plane.
 
     VECTOR2D center( mapX( centerCoords.x ), mapY( centerCoords.y ) );
-    VECTOR2D major( mapX( majorCoords.x ), mapY( majorCoords.y ) );
+    VECTOR2D vmajor( mapX( majorCoords.x ), mapY( majorCoords.y ) );
 
     // DXF elliptical arcs store their angles in radians (unlike circular arcs which use degrees)
     // The arcs wind CCW as in KiCad.  The end angle must be greater than the start angle, and if
@@ -598,7 +601,7 @@ void DXF_IMPORT_PLUGIN::addEllipse( const DL_EllipseDa
 
     if( aData.ratio == 1.0 )
     {
-        double radius = major.EuclideanNorm();
+        double radius = vmajor.EuclideanNorm();
 
         if( startAngle == endAngle )
         {
@@ -616,7 +619,7 @@ void DXF_IMPORT_PLUGIN::addEllipse( const DL_EllipseDa
     }
 
     std::vector<BEZIER<double>> splines;
-    ELLIPSE<double> ellipse( center, major, aData.ratio, startAngle, endAngle );
+    ELLIPSE<double> ellipse( center, vmajor, aData.ratio, startAngle, endAngle );
 
     TransformEllipseToBeziers( ellipse, splines );
 
@@ -630,8 +633,8 @@ void DXF_IMPORT_PLUGIN::addEllipse( const DL_EllipseDa
         bufferToUse->AddSpline( b.Start, b.C1, b.C2, b.End, lineWidth );
 
     // Naive bounding
-    updateImageLimits( center + major );
-    updateImageLimits( center - major );
+    updateImageLimits( center + vmajor );
+    updateImageLimits( center - vmajor );
 }
 
 
