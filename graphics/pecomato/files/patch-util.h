--- util.h.orig	2007-09-28 12:04:57.000000000 -0400
+++ util.h	2009-03-25 03:18:26.000000000 -0400
@@ -10,6 +10,7 @@
 #define _util_h_
 
 
+#include <sys/param.h>
 #include <stdio.h>
 #include <stdarg.h>
 
@@ -67,9 +68,11 @@
 #define _SSIZE_T_DECLARED
 #endif
 #endif
+#if __FreeBSD_version < 800067
 #include "gnu-getline.h"
 #include "gnu-strndup.h"
 #endif
+#endif
 
 /* Microsoft Windows specific defines */
 #ifdef OS_WIN32
