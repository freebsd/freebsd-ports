--- rw/rwTable.c.orig	2012-02-08 09:08:02.000000000 +0100
+++ rw/rwTable.c	2013-09-16 13:27:46.000000000 +0200
@@ -339,7 +339,7 @@ RWtableGetWriterList()
 char *
 RWGetMsg()
 {
-#ifndef __NetBSD__
+#if !defined(__FreeBSD__) && !defined(__OpenBSD__) && !defined(__NetBSD__)
 #if defined(BSD4_4)
     __const extern char *__const sys_errlist[];
 #else
