--- classes/gui/window/backends/xlib/windowxlib.cpp.orig	2020-08-27 22:43:07 UTC
+++ classes/gui/window/backends/xlib/windowxlib.cpp
@@ -8,6 +8,9 @@
   * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
   * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE. */
 
+#include <stdio.h>
+#include <stdlib.h>
+
 #include <smooth/gui/window/backends/xlib/windowxlib.h>
 #include <smooth/gui/window/window.h>
 #include <smooth/gui/widgets/special/cursor.h>
@@ -20,9 +23,6 @@
 #include <smooth/foreach.h>
 #include <smooth/init.h>
 #include <smooth/backends/xlib/backendxlib.h>
-
-#include <stdio.h>
-#include <stdlib.h>
 
 using namespace X11;
 
