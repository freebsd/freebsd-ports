--- src/utility.c.orig	2012-04-28 09:41:42 UTC
+++ src/utility.c
@@ -44,10 +44,6 @@
 #include <ctype.h>
 #include <libnova/libnova.h>
 
-#ifndef __APPLE__
-#include <malloc.h>
-#endif
-
 /* Include unistd.h only if not on a Win32 platform */
 /* Include Win32 Headers sys/types.h and sys/timeb.h if on Win32 */
 #ifndef __WIN32__
