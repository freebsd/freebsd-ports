--- classes/graphics/backends/cairo/fontcairo.cpp.orig	2020-06-13 21:01:13 UTC
+++ classes/graphics/backends/cairo/fontcairo.cpp
@@ -8,6 +8,10 @@
   * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
   * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE. */
 
+#include <stdio.h>
+#include <stdlib.h>
+#include <unistd.h>
+
 #include <smooth/graphics/backends/cairo/fontcairo.h>
 #include <smooth/graphics/surface.h>
 #include <smooth/files/file.h>
@@ -15,10 +19,6 @@
 #include <smooth/init.h>
 
 using namespace X11;
-
-#include <unistd.h>
-#include <stdio.h>
-#include <stdlib.h>
 
 #include <cairo/cairo-xlib.h>
 #include <pango/pangocairo.h>
