--- hdr/generator.h.orig	Sun Aug 28 14:44:26 2005
+++ hdr/generator.h	Sun Aug 28 22:33:12 2005
@@ -257,17 +257,26 @@
 #include "registers.h"
 #endif
 
+#if (defined(__unix__) || defined(unix)) && !defined(USG)
+#include <sys/param.h>
+#endif
+
 #if defined(linux)
 
 #include <byteswap.h>
 #define SWAP16(x) bswap_16((x))
 #define SWAP32(x) bswap_32((x))
 
-#elif defined(__FreeBSD__)
+#elif defined(__FreeBSD__) && __FreeBSD_version >=500000
 
 #include <sys/endian.h>
 #define SWAP16(x) bswap16((x))
 #define SWAP32(x) bswap32((x))
+
+#elif defined(__FreeBSD__)
+#include <sys/endian.h>
+#define SWAP16(x) (be16toh(x))
+#define SWAP32(x) (be32toh(x))
 
 #elif defined(__NetBSD__)
 
