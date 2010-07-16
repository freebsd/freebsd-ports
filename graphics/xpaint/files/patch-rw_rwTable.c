--- rw/rwTable.c.orig	2010-04-09 14:27:03.000000000 +0900
+++ rw/rwTable.c	2010-05-29 13:28:58.000000000 +0900
@@ -296,7 +296,7 @@
 char *
 RWGetMsg()
 {
-#ifndef __NetBSD__
+#if !defined(__FreeBSD__) && !defined(__OpenBSD__) && !defined(__NetBSD__)
 #if defined(BSD4_4)
     __const extern char *__const sys_errlist[];
 #else
