--- cdbw.c.orig	2019-05-24 08:14:32 UTC
+++ cdbw.c
@@ -43,7 +43,7 @@ __RCSID("$NetBSD: cdbw.c,v 1.5 2012/07/21 22:49:37 joe
 #endif
 
 #if !HAVE_NBTOOL_CONFIG_H || HAVE_SYS_ENDIAN_H
-#ifdef __NetBSD__
+#if defined(__NetBSD__) || defined(__FreeBSD__)
 #include <sys/endian.h>
 #else
 #include <endian.h>
