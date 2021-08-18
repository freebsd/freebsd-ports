--- classes/graphics/backends/cairo/fontcairo.cpp.orig	2021-06-22 22:10:12 UTC
+++ classes/graphics/backends/cairo/fontcairo.cpp
@@ -8,6 +8,8 @@
   * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
   * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE. */
 
+#include <pango/pangocairo.h>
+
 #include <smooth/graphics/backends/cairo/fontcairo.h>
 #include <smooth/graphics/surface.h>
 #include <smooth/files/file.h>
@@ -17,7 +19,6 @@
 using namespace X11;
 
 #include <cairo/cairo-xlib.h>
-#include <pango/pangocairo.h>
 
 #include <smooth/backends/xlib/backendxlib.h>
 
