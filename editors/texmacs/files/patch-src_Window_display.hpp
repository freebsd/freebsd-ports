--- ./src/Window/display.hpp.orig	Sun Oct  3 13:26:38 2004
+++ ./src/Window/display.hpp	Sat Oct 23 17:39:48 2004
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
 
 struct font;
