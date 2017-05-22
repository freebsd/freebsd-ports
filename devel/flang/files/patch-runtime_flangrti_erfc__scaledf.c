--- runtime/flangrti/erfc_scaledf.c.orig	2017-05-17 00:40:01 UTC
+++ runtime/flangrti/erfc_scaledf.c
@@ -19,7 +19,7 @@
 #pragma global - Mx, 6, 0x100
 
 #include "mthdecls.h"
-#if defined(TARGET_WIN) || defined(win32) || defined(TARGET_OSX)
+#if defined(TARGET_WIN) || defined(win32) || defined(TARGET_OSX) || defined(__FreeBSD__)
 #include <float.h>
 #else
 #include <values.h>
