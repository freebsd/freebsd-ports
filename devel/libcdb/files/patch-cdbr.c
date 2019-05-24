--- cdbr.c.orig	2019-05-24 08:03:40 UTC
+++ cdbr.c
@@ -52,7 +52,7 @@ __RCSID("$NetBSD: cdbr.c,v 1.1 2013/12/11 01:24:08 joe
 #endif
 #endif
 #if !HAVE_NBTOOL_CONFIG_H || HAVE_SYS_ENDIAN_H
-#ifdef __NetBSD__
+#if defined(__NetBSD__) || defined(__FreeBSD__)
 #include <sys/endian.h>
 #else
 #include <endian.h>
