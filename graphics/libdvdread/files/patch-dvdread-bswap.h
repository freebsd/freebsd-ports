--- dvdread/bswap.h.orig	Sat Apr  7 17:35:10 2001
+++ dvdread/bswap.h	Wed Jun 27 01:23:04 2001
@@ -27,7 +27,28 @@
 #define B2N_32(x) (void)(x)
 #define B2N_64(x) (void)(x)
 #else
+#if defined(__FreeBSD__)
+/* how about assmbler versions? */
+#define bswap_16(x) \
+     ((((x) & 0xff00) >> 8) | \
+      (((x) & 0x00ff) << 8))
+#define bswap_32(x) \
+     ((((x) & 0xff000000) >> 24) | \
+      (((x) & 0x00ff0000) >>  8) | \
+      (((x) & 0x0000ff00) <<  8) | \
+      (((x) & 0x000000ff) << 24))
+#define bswap_64(x) \
+     ((((x) & 0xff00000000000000) >> 56) | \
+      (((x) & 0x00ff000000000000) >> 40) | \
+      (((x) & 0x0000ff0000000000) >> 24) | \
+      (((x) & 0x000000ff00000000) >>  8) | \
+      (((x) & 0x00000000ff000000) <<  8) | \
+      (((x) & 0x0000000000ff0000) << 24) | \
+      (((x) & 0x000000000000ff00) << 40) | \
+      (((x) & 0x00000000000000ff) << 56))
+#else
 #include <byteswap.h>
+#endif
 #define B2N_16(x) x = bswap_16((x))
 #define B2N_32(x) x = bswap_32((x))
 #define B2N_64(x) x = bswap_64((x))
