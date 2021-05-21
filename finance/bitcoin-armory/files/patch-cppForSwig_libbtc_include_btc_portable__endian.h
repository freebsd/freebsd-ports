- fix for the libbtc bug

--- cppForSwig/libbtc/include/btc/portable_endian.h.orig	2021-05-20 07:15:56 UTC
+++ cppForSwig/libbtc/include/btc/portable_endian.h
@@ -49,6 +49,8 @@
 
 #include <sys/endian.h>
 
+#if !defined(__FreeBSD__)
+
 #define be16toh(x) betoh16(x)
 #define le16toh(x) letoh16(x)
 
@@ -57,6 +59,8 @@
 
 #define be64toh(x) betoh64(x)
 #define le64toh(x) letoh64(x)
+
+#endif
 
 #elif defined(__WINDOWS__)
 
