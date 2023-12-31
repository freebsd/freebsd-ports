--- src/byteorder.h.orig	2021-03-21 20:49:04 UTC
+++ src/byteorder.h
@@ -56,8 +56,10 @@ typedef uint64_t subblock;
 #elif defined( __x86_64__)
 #define SWAPPED(x) ({register uint64_t __out, __in = (x); __asm__("bswap %q0" : "=r"(__out) : "0"(__in)); __out;})
 #else
+#if defined(__linux__)
 #include <byteswap.h>
 #define SWAPPED(x) bswap_64(x)
+#endif // defined(__linux__)
 #endif // defined(BYTE_ORDER_BIG_ENDIAN)
 #else
 #define BLOCKSIZE 4
