--- src/wx-sdl2.c.orig	2020-12-01 19:49:05 UTC
+++ src/wx-sdl2.c
@@ -44,9 +44,16 @@
 #include "wx-common.h"
 #include "wx-display.h"
 
-#if __APPLE__
+#ifdef __APPLE__
 #define pause __pause
 #include <util.h>
+#include <fcntl.h>
+#include <unistd.h>
+#undef pause
+#endif
+
+#ifdef __FreeBSD__
+#define pause __pause
 #include <fcntl.h>
 #include <unistd.h>
 #undef pause
