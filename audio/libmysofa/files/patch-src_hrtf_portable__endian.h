Fix linking on FreeBSD and DragonFly.

https://github.com/hoene/libmysofa/pull/213

--- src/hrtf/portable_endian.h.orig	2023-10-17 18:48:34 UTC
+++ src/hrtf/portable_endian.h
@@ -41,22 +41,9 @@
 #	define __LITTLE_ENDIAN LITTLE_ENDIAN
 #	define __PDP_ENDIAN    PDP_ENDIAN
 
-#elif defined(__OpenBSD__)
+#elif defined(__DragonFly__) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__)
 
 #	include <sys/endian.h>
-
-#elif defined(__NetBSD__) || defined(__FreeBSD__) || defined(__DragonFly__)
-
-#	include <sys/endian.h>
-
-#	define be16toh(x) betoh16(x)
-#	define le16toh(x) letoh16(x)
-
-#	define be32toh(x) betoh32(x)
-#	define le32toh(x) letoh32(x)
-
-#	define be64toh(x) betoh64(x)
-#	define le64toh(x) letoh64(x)
 
 #elif defined(__WINDOWS__)
 
