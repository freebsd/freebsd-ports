--- rw/rwTable.c.orig	Sun Apr 10 17:52:02 2005
+++ rw/rwTable.c	Sun Apr 17 01:35:47 2005
@@ -249,6 +249,7 @@
 char *
 RWGetMsg()
 {
+#if !defined(__FreeBSD__) && !defined(__OpenBSD__) && !defined(__NetBSD__)
 #if defined(BSD4_4)
     __const extern char *__const sys_errlist[];
 #else
@@ -258,6 +259,7 @@
 #  define sys_errlist _sys_errlist
 #else
     extern char *sys_errlist[];
+#endif
 #endif
 #endif
 #endif
