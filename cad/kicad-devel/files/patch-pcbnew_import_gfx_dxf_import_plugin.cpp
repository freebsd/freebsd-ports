--- pcbnew/import_gfx/dxf_import_plugin.cpp.orig	2023-01-08 16:40:34.270267000 +0100
+++ pcbnew/import_gfx/dxf_import_plugin.cpp	2023-01-08 16:40:37.228586000 +0100
@@ -581,5 +581,5 @@
 
     VECTOR2D center( mapX( centerCoords.x ), mapY( centerCoords.y ) );
-    VECTOR2D major( mapX( majorCoords.x ), mapY( majorCoords.y ) );
+    VECTOR2D _major( mapX( majorCoords.x ), mapY( majorCoords.y ) );
 
     // DXF elliptical arcs store their angles in radians (unlike circular arcs which use degrees)
@@ -599,5 +599,5 @@
     if( aData.ratio == 1.0 )
     {
-        double radius = major.EuclideanNorm();
+        double radius = _major.EuclideanNorm();
 
         if( startAngle == endAngle )
@@ -617,5 +617,5 @@
 
     std::vector<BEZIER<double>> splines;
-    ELLIPSE<double> ellipse( center, major, aData.ratio, startAngle, endAngle );
+    ELLIPSE<double> ellipse( center, _major, aData.ratio, startAngle, endAngle );
 
     TransformEllipseToBeziers( ellipse, splines );
@@ -631,6 +631,6 @@
 
     // Naive bounding
-    updateImageLimits( center + major );
-    updateImageLimits( center - major );
+    updateImageLimits( center + _major );
+    updateImageLimits( center - _major );
 }
 
