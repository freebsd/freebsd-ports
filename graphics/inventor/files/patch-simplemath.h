--- lib/database/src/so/nodes/nurbs/head/simplemath.h.orig	2000-08-15 12:56:22 UTC
+++ lib/database/src/so/nodes/nurbs/head/simplemath.h
@@ -54,6 +54,6 @@ inline int 
 absi( int x ) { return ( x < 0 ) ? -x : x; }
 
 inline REAL 
-abs( REAL x ) { return ( x < 0.0 ) ? -x : x; }
+absr( REAL x ) { return ( x < 0.0 ) ? -x : x; }
 
 #endif /* __glusimplemath_h_ */
