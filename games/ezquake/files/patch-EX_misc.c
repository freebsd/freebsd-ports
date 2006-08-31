--- ./EX_misc.c.orig	Wed Mar 29 18:54:03 2006
+++ ./EX_misc.c	Tue Aug 29 20:59:12 2006
@@ -8,7 +8,7 @@
 #include "EX_misc.h"
 #include "EX_FunNames.h"
 
-#if defined __linux || defined(__APPLE__)
+#if defined __unix__ || defined(__APPLE__)
 #define CLIPBOARDSIZE 1024
 static char clipboard[CLIPBOARDSIZE] = "\0";    // for clipboard implementation
 #endif
