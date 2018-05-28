--- src/ctl_tube.cpp.orig	2017-07-04 21:41:59 UTC
+++ src/ctl_tube.cpp
@@ -22,7 +22,7 @@
 #include <calf/ctl_tube.h>
 #include <cairo/cairo.h>
 #if !defined(__APPLE__)
-#include <malloc.h>
+//#include <malloc.h>
 #endif
 #include <math.h>
 #include <stdint.h>
