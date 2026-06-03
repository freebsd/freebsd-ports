--- v8/src/base/platform/platform-openbsd.cc.orig	2024-08-14 20:58:07 UTC
+++ v8/src/base/platform/platform-openbsd.cc
@@ -6,6 +6,7 @@
 // POSIX-compatible parts, the implementation is in platform-posix.cc.
 
 #include <pthread.h>
+#include <pthread_np.h>
 #include <semaphore.h>
 #include <signal.h>
 #include <stdlib.h>
@@ -121,6 +122,17 @@ void OS::AdjustSchedulingParams() {}
 }
 
 void OS::AdjustSchedulingParams() {}
+
+// static
+Stack::StackSlot Stack::ObtainCurrentThreadStackStart() {
+  stack_t ss;
+  void *base;
+  if (pthread_stackseg_np(pthread_self(), &ss) != 0)
+    return nullptr;
+
+  base = (void*)((size_t) ss.ss_sp - ss.ss_size);
+  return reinterpret_cast<uint8_t*>(base) + ss.ss_size;
+}
 
 std::optional<OS::MemoryRange> OS::GetFirstFreeMemoryRangeWithin(
     OS::Address boundary_start, OS::Address boundary_end, size_t minimum_size,
