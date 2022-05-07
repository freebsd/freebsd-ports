--- include/btc/portable_endian.h.orig	2022-05-07 20:37:35 UTC
+++ include/btc/portable_endian.h
@@ -49,6 +49,7 @@
 
 #include <sys/endian.h>
 
+#if !defined(__FreeBSD__)
 #define be16toh(x) betoh16(x)
 #define le16toh(x) letoh16(x)
 
@@ -57,6 +58,7 @@
 
 #define be64toh(x) betoh64(x)
 #define le64toh(x) letoh64(x)
+#endif
 
 #elif defined(__WINDOWS__)
 
