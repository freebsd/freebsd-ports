--- src/portable_endian.h.orig	2019-10-12 18:24:24 UTC
+++ src/portable_endian.h
@@ -54,6 +54,7 @@
 
 #	include <sys/endian.h>
 
+#if !defined(__FreeBSD__)
 #	define be16toh(x) betoh16(x)
 #	define le16toh(x) letoh16(x)
 
@@ -62,6 +63,7 @@
 
 #	define be64toh(x) betoh64(x)
 #	define le64toh(x) letoh64(x)
+#endif /*!defined(__FreeBSD__)*/
 
 #elif defined(__WINDOWS__)
 
