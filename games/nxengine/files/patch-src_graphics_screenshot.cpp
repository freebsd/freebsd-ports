--- src/graphics/screenshot.cpp.orig	2018-03-24 09:37:42 UTC
+++ src/graphics/screenshot.cpp
@@ -1,7 +1,7 @@
 #include "pngfuncs.h"
 #include "graphics.h"
 #include "../common/stat.h"
-#if defined(__MACH__)
+#if defined(__MACH__) || defined (__FreeBSD__)
 #include <cstdlib>
 #else
 #include <malloc.h>
