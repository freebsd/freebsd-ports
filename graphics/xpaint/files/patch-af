--- rw/libpnmrw.c.orig	Sun Apr 10 17:52:02 2005
+++ rw/libpnmrw.c	Sun Apr 17 01:33:51 2005
@@ -131,6 +131,7 @@
 static void
 pm_perror(char *reason)
 {
+#if !defined(__FreeBSD__) && !defined(__OpenBSD__) && !defined(__NetBSD__)
 #if defined(BSD4_4)
     __const extern char *__const sys_errlist[];
 #else
@@ -141,6 +142,7 @@
 #else
 #ifdef MISSING_STRERROR
     extern char *sys_errlist[];
+#endif
 #endif
 #endif
 #endif
