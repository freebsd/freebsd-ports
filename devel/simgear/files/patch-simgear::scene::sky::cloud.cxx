--- simgear/scene/sky/cloud.cxx.orig	Tue Jun  1 10:38:58 2004
+++ simgear/scene/sky/cloud.cxx	Tue Jun  1 10:39:08 2004
@@ -24,8 +24,8 @@
 // #if defined (__APPLE__) 
 // // any C++ header file undefines isinf and isnan
 // // so this should be included before <iostream>
-// inline int (isinf)(double r) { return isinf(r); }
-// inline int (isnan)(double r) { return isnan(r); } 
+inline int (isinf)(double r) { return isinf(r); }
+inline int (isnan)(double r) { return isnan(r); } 
 // #endif
 
 // #include STL_IOSTREAM
