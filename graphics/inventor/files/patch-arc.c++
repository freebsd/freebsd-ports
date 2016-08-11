--- lib/database/src/so/nodes/nurbs/libnurbs/arc.c++.orig	2000-08-15 12:56:22 UTC
+++ lib/database/src/so/nodes/nurbs/libnurbs/arc.c++
@@ -332,7 +332,7 @@ Arc::check( void )
 
 inline long tooclose( REAL x, REAL y )
 {
-    return (abs(x-y) < TOL) ?  1 : 0;
+    return (absr(x-y) < TOL) ?  1 : 0;
 }
 
 
