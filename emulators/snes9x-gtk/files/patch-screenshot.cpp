--- screenshot.cpp.orig	2016-10-15 00:20:34 UTC
+++ screenshot.cpp
@@ -186,6 +186,7 @@
 #include "memmap.h"
 #include "display.h"
 #include "screenshot.h"
+#include <unistd.h>
 
 
 bool8 S9xDoScreenshot (int width, int height)
