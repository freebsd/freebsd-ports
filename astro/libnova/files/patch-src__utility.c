--- src/utility.c.orig	Wed Jan 17 08:16:02 2007
+++ src/utility.c	Sat Feb 10 12:08:36 2007
@@ -45,10 +45,6 @@
 #include <ctype.h>
 #include <libnova/utility.h>
 
-#ifndef __APPLE__
-#include <malloc.h>
-#endif
-
 /* Include unistd.h only if not on a Win32 platform */
 /* Include Win32 Headers sys/types.h and sys/timeb.h if on Win32 */
 #ifndef __WIN32__
