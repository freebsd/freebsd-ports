--- src/ctl_knob.cpp.orig	2018-05-28 01:13:37 UTC
+++ src/ctl_knob.cpp
@@ -24,7 +24,7 @@
 #include <gdk/gdkkeysyms.h>
 #include <cairo/cairo.h>
 #if !defined(__APPLE__)
-#include <malloc.h>
+//#include <malloc.h>
 #endif
 #include <math.h>
 #include <stdint.h>
