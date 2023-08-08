--- libs/baseconfig/src/endiantype.h.orig	2020-01-23 13:00:42 UTC
+++ libs/baseconfig/src/endiantype.h
@@ -39,10 +39,10 @@
 #define be64toh(x) OSSwapBigToHostInt64(x)
 #define le64toh(x) OSSwapLittleToHostInt64(x)
 
-#elif defined(__OpenBSD__)
+#elif defined(__OpenBSD__) || defined(__FreeBSD__)
 #include	<sys/endian.h>
 
-#elif defined(__NetBSD__) || defined(__FreeBSD__) || defined(__DragonFly__)
+#elif defined(__NetBSD__) || defined(__DragonFly__)
 #include	<sys/endian.h>
 
 #define be16toh(x) betoh16(x)
