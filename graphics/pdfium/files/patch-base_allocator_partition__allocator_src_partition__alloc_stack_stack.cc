-- Use FreeBSD's pthread_np.h and pthread_attr_get_np() to obtain the current
-- thread's stack attributes, since pthread_getattr_np() is glibc-specific.
--- base/allocator/partition_allocator/src/partition_alloc/stack/stack.cc.orig	2026-09-24 10:29:00 UTC
+++ base/allocator/partition_allocator/src/partition_alloc/stack/stack.cc
@@ -17,7 +17,10 @@
 #include <windows.h>
 #else
 #include <pthread.h>
+#if defined(__FreeBSD__)
+#include <pthread_np.h>
 #endif
+#endif
 
 #if PA_BUILDFLAG(PA_LIBC_GLIBC)
 extern "C" void* __libc_stack_end;
@@ -55,7 +58,12 @@ void* GetStackTop() {
 
 void* GetStackTop() {
   pthread_attr_t attr;
+#if defined(__FreeBSD__)
+  pthread_attr_init(&attr);
+  int error = pthread_attr_get_np(pthread_self(), &attr);
+#else
   int error = pthread_getattr_np(pthread_self(), &attr);
+#endif
   if (!error) {
     void* base;
     size_t size;
