--- base/include/android-base/endian.h.orig	2019-10-18 00:22:21 UTC
+++ base/include/android-base/endian.h
@@ -50,6 +50,8 @@
 #if defined(__APPLE__)
 /* macOS has some of the basics. */
 #include <sys/_endian.h>
+#elif defined(__DragonFly__) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__)
+#include <sys/endian.h>
 #else
 /* Windows has some of the basics as well. */
 #include <sys/param.h>
@@ -71,22 +73,39 @@
 
 #define ntohq(x) __builtin_bswap64(x)
 
+#if !defined(__DragonFly__) && !defined(__FreeBSD__) && !defined(__NetBSD__) && !defined(__OpenBSD__)
 #define htobe16(x) __builtin_bswap16(x)
 #define htobe32(x) __builtin_bswap32(x)
 #define htobe64(x) __builtin_bswap64(x)
+#endif
 
+#if defined(__DragonFly__) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__)
+#define betoh16(x) be16toh(x)
+#define betoh32(x) be32toh(x)
+#define betoh64(x) be64toh(x)
+#else
 #define betoh16(x) __builtin_bswap16(x)
 #define betoh32(x) __builtin_bswap32(x)
 #define betoh64(x) __builtin_bswap64(x)
+#endif
 
+#if !defined(__DragonFly__) && !defined(__FreeBSD__) && !defined(__NetBSD__) && !defined(__OpenBSD__)
 #define htole16(x) (x)
 #define htole32(x) (x)
 #define htole64(x) (x)
+#endif
 
+#if defined(__DragonFly__) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__)
+#define letoh16(x) le16toh(x)
+#define letoh32(x) le32toh(x)
+#define letoh64(x) le64toh(x)
+#else
 #define letoh16(x) (x)
 #define letoh32(x) (x)
 #define letoh64(x) (x)
+#endif
 
+#if !defined(__DragonFly__) && !defined(__FreeBSD__) && !defined(__NetBSD__) && !defined(__OpenBSD__)
 #define be16toh(x) __builtin_bswap16(x)
 #define be32toh(x) __builtin_bswap32(x)
 #define be64toh(x) __builtin_bswap64(x)
@@ -94,5 +113,6 @@
 #define le16toh(x) (x)
 #define le32toh(x) (x)
 #define le64toh(x) (x)
+#endif
 
 #endif
