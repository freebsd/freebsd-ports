--- pcbnew/import_gfx/dxf_import_plugin.cpp.orig	2023-06-22 13:35:48 UTC
+++ pcbnew/import_gfx/dxf_import_plugin.cpp
@@ -580,7 +580,7 @@ void DXF_IMPORT_PLUGIN::addEllipse( const DL_EllipseDa
     // For now, we assume ellipses in the XY plane.
 
     VECTOR2D center( mapX( centerCoords.x ), mapY( centerCoords.y ) );
-    VECTOR2D major( mapX( majorCoords.x ), mapY( majorCoords.y ) );
+    VECTOR2D _major( mapX( majorCoords.x ), mapY( majorCoords.y ) );
 
     // DXF elliptical arcs store their angles in radians (unlike circular arcs which use degrees)
     // The arcs wind CCW as in KiCad.  The end angle must be greater than the start angle, and if
@@ -598,7 +598,7 @@ void DXF_IMPORT_PLUGIN::addEllipse( const DL_EllipseDa
 
     if( aData.ratio == 1.0 )
     {
-        double radius = major.EuclideanNorm();
+        double radius = _major.EuclideanNorm();
 
         if( startAngle == endAngle )
         {
@@ -616,7 +616,7 @@ void DXF_IMPORT_PLUGIN::addEllipse( const DL_EllipseDa
     }
 
     std::vector<BEZIER<double>> splines;
-    ELLIPSE<double> ellipse( center, major, aData.ratio, startAngle, endAngle );
+    ELLIPSE<double> ellipse( center, _major, aData.ratio, startAngle, endAngle );
 
     TransformEllipseToBeziers( ellipse, splines );
 
@@ -630,8 +630,8 @@ void DXF_IMPORT_PLUGIN::addEllipse( const DL_EllipseDa
         bufferToUse->AddSpline( b.Start, b.C1, b.C2, b.End, lineWidth );
 
     // Naive bounding
-    updateImageLimits( center + major );
-    updateImageLimits( center - major );
+    updateImageLimits( center + _major );
+    updateImageLimits( center - _major );
 }
 
 
