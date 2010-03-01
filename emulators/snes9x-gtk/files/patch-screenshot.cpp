--- ../screenshot.cpp.orig	2010-02-23 00:19:36.132640984 -0500
+++ ../screenshot.cpp	2010-02-23 00:19:59.151074837 -0500
@@ -182,6 +182,7 @@
 #include "memmap.h"
 #include "display.h"
 #include "screenshot.h"
+#include <unistd.h>
 
 
 bool8 S9xDoScreenshot (int width, int height)
