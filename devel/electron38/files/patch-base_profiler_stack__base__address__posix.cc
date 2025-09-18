--- base/profiler/stack_base_address_posix.cc.orig	2025-04-22 20:15:27 UTC
+++ base/profiler/stack_base_address_posix.cc
@@ -18,6 +18,10 @@
 #include "base/files/scoped_file.h"
 #endif
 
+#if BUILDFLAG(IS_BSD)
+#include <pthread_np.h>
+#endif
+
 #if BUILDFLAG(IS_CHROMEOS)
 extern "C" void* __libc_stack_end;
 #endif
@@ -49,7 +53,21 @@ uintptr_t GetThreadStackBaseAddressImpl(pthread_t pthr
 
 #if !BUILDFLAG(IS_LINUX)
 uintptr_t GetThreadStackBaseAddressImpl(pthread_t pthread_id) {
+#if BUILDFLAG(IS_OPENBSD)
+  stack_t ss;
+  void *address;
+  size_t size;
+  if (pthread_stackseg_np(pthread_id, &ss) != 0)
+    return 0;
+  size = ss.ss_size;
+  address = (void*)((size_t) ss.ss_sp - ss.ss_size);
+#else
   pthread_attr_t attr;
+#if BUILDFLAG(IS_FREEBSD)
+  int result;
+  pthread_attr_init(&attr);
+  pthread_attr_get_np(pthread_id, &attr);
+#else
   // pthread_getattr_np will crash on ChromeOS & Linux if we are in the sandbox
   // and pthread_id refers to a different thread, due to the use of
   // sched_getaffinity().
@@ -62,12 +80,14 @@ uintptr_t GetThreadStackBaseAddressImpl(pthread_t pthr
                       << logging::SystemErrorCodeToString(result);
   // See crbug.com/617730 for limitations of this approach on Linux-like
   // systems.
+#endif
   void* address;
   size_t size;
   result = pthread_attr_getstack(&attr, &address, &size);
   CHECK_EQ(result, 0) << "pthread_attr_getstack returned "
                       << logging::SystemErrorCodeToString(result);
   pthread_attr_destroy(&attr);
+#endif
   const uintptr_t base_address = reinterpret_cast<uintptr_t>(address) + size;
   return base_address;
 }
@@ -84,7 +104,7 @@ std::optional<uintptr_t> GetThreadStackBaseAddress(Pla
   // trying to work around the problem.
   return std::nullopt;
 #else
-  const bool is_main_thread = id.raw() == GetCurrentProcId();
+  const bool is_main_thread = id.raw() == (checked_cast<uint64_t>(GetCurrentProcId()));
   if (is_main_thread) {
 #if BUILDFLAG(IS_ANDROID)
     // The implementation of pthread_getattr_np() in Bionic reads proc/self/maps
