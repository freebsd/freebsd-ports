--- src/byteorder.h.orig	2020-10-20 00:54:48 UTC
+++ src/byteorder.h
@@ -56,8 +56,12 @@ typedef uint64_t subblock;
 #elif defined( __x86_64__)
 #define SWAPPED(x) ({register uint64_t __out, __in = (x); __asm__("bswap %q0" : "=r"(__out) : "0"(__in)); __out;})
 #else
+#if defined(__linux__)
 #include <byteswap.h>
-#define SWAPPED(x) bswap_64(x)
+#elif defined(__FreeBSD__)
+#include <sys/endian.h>
+#endif // defined(__linux__)
+#define SWAPPED(x) bswap64(x)
 #endif // defined(BYTE_ORDER_BIG_ENDIAN)
 #else
 #define BLOCKSIZE 4
