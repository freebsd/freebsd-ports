--- include/mpeg4ip_byteswap.h.orig	Wed Nov 13 16:44:43 2002
+++ include/mpeg4ip_byteswap.h	Wed Nov 13 16:44:47 2002
@@ -26,2 +26,6 @@
 
+#if (defined(__unix__) || defined(unix)) && !defined(USG)
+#include <sys/param.h>
+#endif
+
 #if defined(WORDS_BIGENDIAN)
@@ -51,2 +55,16 @@
 #define B2N_64(x) x = swap64(x)
+
+#elif defined(__FreeBSD__) && __FreeBSD_version >= 470000
+#include <sys/endian.h>
+#define B2N_16(x) (be16toh(x))
+#define B2N_32(x) (be32toh(x))
+#define B2N_64(x) \
+ x = ((((x) & 0xff00000000000000) >> 56) | \
+      (((x) & 0x00ff000000000000) >> 40) | \
+      (((x) & 0x0000ff0000000000) >> 24) | \
+      (((x) & 0x000000ff00000000) >>  8) | \
+      (((x) & 0x00000000ff000000) <<  8) | \
+      (((x) & 0x0000000000ff0000) << 24) | \
+      (((x) & 0x000000000000ff00) << 40) | \
+      (((x) & 0x00000000000000ff) << 56))
 
