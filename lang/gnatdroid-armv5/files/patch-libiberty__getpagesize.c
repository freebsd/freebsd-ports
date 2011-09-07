--- libiberty/getpagesize.c.orig	2011-01-29 06:55:10 +0100
+++ libiberty/getpagesize.c	2011-01-29 07:07:40 +0100
@@ -20,6 +20,7 @@
 
 */
 
+#ifndef __ANDROID__
 #ifndef VMS
 
 #include "config.h"
@@ -88,3 +89,4 @@
 }
 
 #endif /* VMS */
+#endif /* __ANDROID__ */
