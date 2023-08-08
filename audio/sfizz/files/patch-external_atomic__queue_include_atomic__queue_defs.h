--- external/atomic_queue/include/atomic_queue/defs.h.orig	2023-02-07 02:20:07 UTC
+++ external/atomic_queue/include/atomic_queue/defs.h
@@ -36,8 +36,19 @@ static inline void spin_loop_pause() noexcept {
 #endif
 }
 } // namespace atomic_queue
+#elif defined(__ppc64__) || defined(__powerpc64__)
+namespace atomic_queue {
+constexpr int CACHE_LINE_SIZE = 128; // TODO: Review that this is the correct value.
+static inline void spin_loop_pause() noexcept {
+    asm volatile("or 31,31,31 # very low priority"); // TODO: Review and benchmark that this is the right instruction.
+}
+} // namespace atomic_queue
 #else
-#error "Unknown CPU architecture."
+#warning "Unknown CPU architecture. Using L1 cache line size of 64 bytes and no spinloop pause instruction."
+namespace atomic_queue {
+constexpr int CACHE_LINE_SIZE = 64; // TODO: Review that this is the correct value.
+static inline void spin_loop_pause() noexcept {}
+} // namespace atomic_queue
 #endif
 
 ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
