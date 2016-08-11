--- lib/database/src/so/nodes/nurbs/clients/softsurfeval.c++.orig	2000-08-15 12:56:22 UTC
+++ lib/database/src/so/nodes/nurbs/clients/softsurfeval.c++
@@ -50,8 +50,8 @@
 #include "softsurfeval.h"
 #include "nurbsconsts.h"
 
-inline REAL abs( REAL x ) { return (x < 0.0) ? -x : x; }
-inline int equal( REAL x, REAL y ) { return (abs(x-y) < 1.0E-6) ? 1 : 0; }
+inline REAL absr( REAL x ) { return (x < 0.0) ? -x : x; }
+inline int equal( REAL x, REAL y ) { return (absr(x-y) < 1.0E-6) ? 1 : 0; }
 
 _SoNurbsSurfaceEvaluator::~_SoNurbsSurfaceEvaluator() 
 { 
