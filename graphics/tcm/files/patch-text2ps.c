--- src/gl/text2ps.c.orig	Wed Jul 18 00:14:43 2001
+++ src/gl/text2ps.c	Wed Jul 18 00:16:33 2001
@@ -86,7 +86,7 @@
 /* extern struct tm *localtime(); */
 /* extern long time(); */
 extern double atof();
-#ifndef __linux__
+#ifndef __FreeBSD__
 extern char *sys_errlist[];
 #endif
 extern int errno;
