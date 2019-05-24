--- mi_vector_hash.c.orig	2019-05-24 08:15:13 UTC
+++ mi_vector_hash.c
@@ -46,7 +46,7 @@
 __RCSID("$NetBSD: mi_vector_hash.c,v 1.1 2013/12/11 01:24:08 joerg Exp $");
 
 #if !HAVE_NBTOOL_CONFIG_H || HAVE_SYS_ENDIAN_H
-#ifdef __NetBSD__
+#if defined(__NetBSD__) || defined(__FreeBSD__)
 #include <sys/endian.h>
 #else
 #include <endian.h>
