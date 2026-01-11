--- include/roaring/portability.h.orig	2026-09-08 23:18:25 UTC
+++ include/roaring/portability.h
@@ -456,6 +456,7 @@ static inline int roaring_hamming(uint64_t x) {
 #if defined(__linux__)
 #define croaring_htobe64(x) bswap_64(x)
 #elif defined(__FreeBSD__)
+#include <sys/endian.h>
 #define croaring_htobe64(x) bswap64(x)
 #else
 #warning "Unknown platform, report as an error"
