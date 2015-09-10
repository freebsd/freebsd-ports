--- Common/Swap.h.orig	2015-02-26 20:05:06 UTC
+++ Common/Swap.h
@@ -71,6 +71,15 @@ inline unsigned long long bswap64(unsign
 inline unsigned int bswap32(unsigned int x) { return __loadwordbytereverse(0, &x); }
 inline unsigned short bswap16(unsigned short x) { return __loadshortbytereverse(0, &x); }
 #endif
+#elif defined(__DragonFly__) || defined(__FreeBSD__) || \
+      defined(__NetBSD__) || defined(__OpenBSD__)
+#include <sys/endian.h>
+# ifdef __OpenBSD__
+#define bswap16 swap16
+#define bswap32 swap32
+#define bswap64 swap64
+#define
+# endif
 #else
 // TODO: speedup
 inline unsigned short bswap16(unsigned short x) { return (x << 8) | (x >> 8); }
