
$FreeBSD$

--- src/Window/display.hpp.orig	Fri Jun 27 17:46:00 2003
+++ src/Window/display.hpp	Wed Aug 27 10:47:48 2003
@@ -12,12 +12,17 @@
 
 #ifndef DISPLAY_H
 #define DISPLAY_H
+
+#include <osreldate.h>
+
 #include "tree.hpp"
 #include "bitmap_font.hpp"
 
+#if __FreeBSD_version < 500000
 #ifndef _TIME_T
 #define _TIME_T
 typedef long time_t;
+#endif
 #endif
 
 class font;
