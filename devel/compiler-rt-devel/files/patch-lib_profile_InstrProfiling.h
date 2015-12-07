--- lib/profile/InstrProfiling.h.orig	2015-12-05 03:14:53 UTC
+++ lib/profile/InstrProfiling.h
@@ -23,33 +23,9 @@
  if (getenv("LLVM_PROFILE_VERBOSE_ERRORS")) \
    fprintf(stderr, Format, __VA_ARGS__ );
 
-
-#if defined(__FreeBSD__) && defined(__i386__)
-
-/* System headers define 'size_t' incorrectly on x64 FreeBSD (prior to
- * FreeBSD 10, r232261) when compiled in 32-bit mode.
- */
-#define PRIu64 "llu"
-typedef unsigned char uint8_t;
-typedef unsigned short uint16_t;
-typedef unsigned int uint32_t;
-typedef unsigned long long uint64_t;
-typedef uint32_t uintptr_t;
-#elif defined(__FreeBSD__) && defined(__x86_64__)
-#define PRIu64 "lu"
-typedef unsigned char uint8_t;
-typedef unsigned short uint16_t;
-typedef unsigned int uint32_t;
-typedef unsigned long long uint64_t;
-typedef unsigned long int uintptr_t;
-
-#else /* defined(__FreeBSD__) && defined(__i386__) */
-
 #include <inttypes.h>
 #include <stdint.h>
 
-#endif /* defined(__FreeBSD__) && defined(__i386__) */
-
 #include "InstrProfData.inc"
 
 enum ValueKind {
