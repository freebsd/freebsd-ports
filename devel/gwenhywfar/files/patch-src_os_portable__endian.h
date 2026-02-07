Deal with the infamous 'portable_endian.h' yet again. This file hasn't aged
well, especially for *BSD, but various forms of it keep appearing in projects.

--- src/os/portable_endian.h.orig	2024-04-21 13:51:43 UTC
+++ src/os/portable_endian.h
@@ -13,7 +13,8 @@
 
 #endif
 
-#if defined(__linux__) || defined(__CYGWIN__)
+#if defined(__linux__) || defined(__CYGWIN__) || defined(__DragonFly__) || \
+    defined(__FreeBSD__) && __FreeBSD_version >= 1400079 || defined(__NetBSD__) || defined(__OpenBSD__)
 
 #	include <endian.h>
 
@@ -41,27 +42,10 @@
 #	define __LITTLE_ENDIAN LITTLE_ENDIAN
 #	define __PDP_ENDIAN    PDP_ENDIAN
 
-#elif defined(__OpenBSD__)
+// FreeBSD added <endian.h> in 14.0
+#elif defined(__FreeBSD__) && __FreeBSD_version < 1400079
 
-#	include <endian.h>
-
-#	define __BYTE_ORDER    BYTE_ORDER
-#	define __BIG_ENDIAN    BIG_ENDIAN
-#	define __LITTLE_ENDIAN LITTLE_ENDIAN
-#	define __PDP_ENDIAN    PDP_ENDIAN
-
-#elif defined(__NetBSD__) || defined(__FreeBSD__) || defined(__DragonFly__)
-
 #	include <sys/endian.h>
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
 
