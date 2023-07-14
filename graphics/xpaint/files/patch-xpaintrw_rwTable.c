Extend support to FreeBSD and OpenBSD.

--- xpaintrw/rwTable.c.orig	2021-01-23 08:03:16 UTC
+++ xpaintrw/rwTable.c
@@ -294,7 +294,7 @@ RWGetMsg()
 char *
 RWGetMsg()
 {
-#ifndef __NetBSD__
+#if !defined(__FreeBSD__) && !defined(__OpenBSD__) && !defined(__NetBSD__)
 #if defined(BSD4_4)
     __const extern char *__const sys_errlist[];
 #else
