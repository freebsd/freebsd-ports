--- lib/database/src/so/nodes/nurbs/libnurbs/ccw.c++.orig	2000-08-15 12:56:22 UTC
+++ lib/database/src/so/nodes/nurbs/libnurbs/ccw.c++
@@ -508,6 +508,6 @@ int
 Subdivider::ccw( TrimVertex *a, TrimVertex *b, TrimVertex *c )
 {
     REAL d = det3( a, b, c );
-    if( abs(d) < 0.0001 ) return -1;
+    if( absr(d) < 0.0001 ) return -1;
     return (d < 0.0) ? 0 : 1;
 }
