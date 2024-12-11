--- deps/paryfor/paryfor.hpp.orig	2024-10-15 18:25:21 UTC
+++ deps/paryfor/paryfor.hpp
@@ -51,7 +51,22 @@ static inline void spin_loop_pause() noexcept {
 }
 } // namespace atomic_queue
 } // namespace paryfor
+#elif defined(__ppc64__) || defined(__powerpc64__)
+namespace paryfor {
+namespace atomic_queue {
+constexpr int CACHE_LINE_SIZE = 128; // TODO: Review that this is the correct value.
+static inline void spin_loop_pause() noexcept {
+    asm volatile("or 31,31,31 # very low priority"); // TODO: Review and benchmark that this is the right instruction.
+}
+} // namespace atomic_queue
+} // namespace paryfor
 #else
+namespace paryfor {
+namespace atomic_queue {
+constexpr int CACHE_LINE_SIZE = 64; // TODO: Review that this is the correct value.
+static inline void spin_loop_pause() noexcept {}
+} // namespace atomic_queue
+} // namespace paryfor
 #error "Unknown CPU architecture."
 #endif
 
