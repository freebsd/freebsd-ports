--- strtol.c.orig	1995-08-25 12:59:08.000000000 +0800
+++ strtol.c	2008-01-26 13:15:27.000000000 +0800
@@ -25,7 +25,7 @@
 #include <stdlib.h>
 #include <errno.h>
 
-#ifdef __sparc__
+#if defined(__sparc) && !defined(__FreeBSD__)
 extern int errno;
 extern int toupper(int);
 #endif
