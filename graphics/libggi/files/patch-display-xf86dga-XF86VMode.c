--- display/xf86dga/XF86VMode.c.orig	Wed Jan 15 09:29:40 2003
+++ display/xf86dga/XF86VMode.c	Tue Dec  9 00:20:08 2003
@@ -36,6 +36,10 @@
 
 /* THIS IS NOT AN X CONSORTIUM STANDARD */
 
+#include <sys/types.h>
+#include <sys/time.h>
+#include <unistd.h>
+
 #define _POSIX_C_SOURCE	199309L
 #if !defined (__OpenBSD__)
 #define _POSIX_SOURCE
