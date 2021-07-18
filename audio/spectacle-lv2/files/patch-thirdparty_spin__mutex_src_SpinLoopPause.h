--- thirdparty/spin_mutex/src/SpinLoopPause.h.orig	2021-05-18 17:31:07 UTC
+++ thirdparty/spin_mutex/src/SpinLoopPause.h
@@ -32,6 +32,10 @@ static inline void spin_loop_pause() noexcept {
     asm volatile ("nop" ::: "memory");
 #endif
 }
+#elif defined(__powerpc__)
+static inline void spin_loop_pause() noexcept {
+    asm volatile("ori 0,0,0" ::: "memory");
+}
 #else
 #error "Unknown CPU architecture."
 #endif
