
$FreeBSD$

--- uxio.c.orig	Tue Apr  3 19:51:52 2001
+++ uxio.c	Thu Aug  5 00:40:16 2004
@@ -236,7 +236,7 @@
   return ((scr < 0) ? 0 : scr);
 }
 
-#ifdef _POSIX
+#ifdef __FreeBSD__
 #include <string.h>
 #else
 extern int EXFUN (strlen, (CONST char *));
