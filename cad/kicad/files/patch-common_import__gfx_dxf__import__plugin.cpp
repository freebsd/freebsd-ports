commit 0a4f751cb983c94fbf2e79edb6eb1c11fcef060c
Author: Christoph Moench-Tegeder <cmt@FreeBSD.org>

    rename "major" variable
    
    on FreeBSD, "major()" is a macro for extracting the major number
    from a device number - and this clashes with the constructor for
    the variable minor. Rename the variable to avoid compile time errors.

diff --git common/import_gfx/dxf_import_plugin.cpp common/import_gfx/dxf_import_plugin.cpp
index aaf2de0f85..0df0c26c21 100644
--- common/import_gfx/dxf_import_plugin.cpp
+++ common/import_gfx/dxf_import_plugin.cpp
@@ -629,7 +629,7 @@ void DXF_IMPORT_PLUGIN::addEllipse( const DL_EllipseData& aData )
     // For now, we assume ellipses in the XY plane.
 
     VECTOR2D center( mapX( centerCoords.x ), mapY( centerCoords.y ) );
-    VECTOR2D major( mapX( majorCoords.x ), mapY( majorCoords.y ) );
+    VECTOR2D vmajor( mapX( majorCoords.x ), mapY( majorCoords.y ) );
 
     // DXF elliptical arcs store their angles in radians (unlike circular arcs which use degrees)
     // The arcs wind CCW as in KiCad.  The end angle must be greater than the start angle, and if
@@ -645,7 +645,7 @@ void DXF_IMPORT_PLUGIN::addEllipse( const DL_EllipseData& aData )
 
     if( aData.ratio == 1.0 )
     {
-        double radius = major.EuclideanNorm();
+        double radius = vmajor.EuclideanNorm();
 
         if( startAngle == endAngle )
         {
@@ -656,8 +656,8 @@ void DXF_IMPORT_PLUGIN::addEllipse( const DL_EllipseData& aData )
         else
         {
             // Angles are relative to major axis
-            startAngle -= EDA_ANGLE( major );
-            endAngle -= EDA_ANGLE( major );
+            startAngle -= EDA_ANGLE( vmajor );
+            endAngle -= EDA_ANGLE( vmajor );
 
             DL_ArcData arc( aData.cx, aData.cy, aData.cz, radius, startAngle.AsDegrees(),
                             endAngle.AsDegrees() );
@@ -669,7 +669,7 @@ void DXF_IMPORT_PLUGIN::addEllipse( const DL_EllipseData& aData )
     // TODO: testcases for negative extrusion vector; handle it here
 
     std::vector<BEZIER<double>> splines;
-    ELLIPSE<double> ellipse( center, major, aData.ratio, startAngle, endAngle );
+    ELLIPSE<double> ellipse( center, vmajor, aData.ratio, startAngle, endAngle );
 
     TransformEllipseToBeziers( ellipse, splines );
 
@@ -683,8 +683,8 @@ void DXF_IMPORT_PLUGIN::addEllipse( const DL_EllipseData& aData )
         bufferToUse->AddSpline( b.Start, b.C1, b.C2, b.End, lineWidth );
 
     // Naive bounding
-    updateImageLimits( center + major );
-    updateImageLimits( center - major );
+    updateImageLimits( center + vmajor );
+    updateImageLimits( center - vmajor );
 }
 
 
