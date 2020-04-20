--- src/external/atomic_queue/defs.h.orig	2020-04-20 01:14:22 UTC
+++ src/external/atomic_queue/defs.h
@@ -6,11 +6,15 @@
 
 #include <atomic>
 
+#if defined(__FreeBSD__) || defined(__DragonFly__)
+#include <machine/param.h> // for CACHE_LINE_SIZE
+#endif
+
 #if defined(__x86_64__) || defined(_M_X64) || \
     defined(__i386__) || defined(_M_IX86)
 #include <emmintrin.h>
 namespace atomic_queue {
-constexpr int CACHE_LINE_SIZE = 64;
+//constexpr int CACHE_LINE_SIZE = 64;
 static inline void spin_loop_pause() noexcept {
     _mm_pause();
 }
@@ -18,7 +22,7 @@ static inline void spin_loop_pause() noexcept {
 #elif defined(__arm__) || defined(__aarch64__)
 // TODO: These need to be verified as I do not have access to ARM platform.
 namespace atomic_queue {
-constexpr int CACHE_LINE_SIZE = 64;
+//constexpr int CACHE_LINE_SIZE = 64;
 static inline void spin_loop_pause() noexcept {
 #if (defined(__ARM_ARCH_6K__) || \
      defined(__ARM_ARCH_6Z__) || \
