--- src/wadgen/WadGen.h.orig	2026-10-15 11:58:04 UTC
+++ src/wadgen/WadGen.h
@@ -17,7 +17,7 @@
 #include <rpcdce.h>
 #include <io.h>
 #else
-#include <linux/limits.h>
+#include <limits.h>
 #define MAX_PATH PATH_MAX
 #define ZeroMemory(a,l) memset(a, 0, l)
 #endif
@@ -33,7 +33,7 @@
 #ifdef PLATFORM_PC
 
 #define USE_PNG
-#include <libpng15/png.h>
+#include <png.h>
 
 #endif
 
