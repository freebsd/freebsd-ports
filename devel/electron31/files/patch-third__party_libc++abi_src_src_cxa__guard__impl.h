--- third_party/libc++abi/src/src/cxa_guard_impl.h.orig	2024-02-21 00:21:25 UTC
+++ third_party/libc++abi/src/src/cxa_guard_impl.h
@@ -411,7 +411,20 @@ struct InitByteGlobalMutex { (private)
 //                         Futex Implementation
 //===----------------------------------------------------------------------===//
 
-#if defined(SYS_futex)
+#ifdef __OpenBSD__
+#include <sys/futex.h>
+
+void PlatformFutexWait(int* addr, int expect) {
+  constexpr int WAIT = 0;
+  futex((volatile uint32_t *)addr, WAIT, expect, NULL, NULL);
+  __tsan_acquire(addr);
+}
+void PlatformFutexWake(int* addr) {
+  constexpr int WAKE = 1;
+  __tsan_release(addr);
+  futex((volatile uint32_t *)addr, WAKE, INT_MAX, NULL, NULL);
+}
+#elif defined(SYS_futex)
 void PlatformFutexWait(int* addr, int expect) {
   constexpr int WAIT = 0;
   syscall(SYS_futex, addr, WAIT, expect, 0);
