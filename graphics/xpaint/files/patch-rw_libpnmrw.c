--- rw/libpnmrw.c.orig	2009-12-09 05:39:15.000000000 +0900
+++ rw/libpnmrw.c	2010-05-29 13:26:56.000000000 +0900
@@ -131,7 +131,7 @@
 static void
 pm_perror(char *reason)
 {
-#if !defined(__NetBSD__)
+#if !defined(__FreeBSD__) && !defined(__OpenBSD__) && !defined(__NetBSD__)
 #if defined(BSD4_4)
     __const extern char *__const sys_errlist[];
 #else
