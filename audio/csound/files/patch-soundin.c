$FreeBSD$

--- soundin.c.orig	Sun Jul 14 16:03:01 2002
+++ soundin.c	Sun Jul 14 16:02:57 2002
@@ -5,6 +5,7 @@
 /*RWD 3:2000*/
 #ifdef RWD_DBFS
 /* quick hack to save typing etc... */
+#undef INLONGFAC
 #define INLONGFAC  (double)long_to_dbfs
 #else
 #define INLONGFAC (1.0 / 65536.0)  /* convert 32bit long to quasi 16 bit range */
