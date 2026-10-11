Use pthread_getthreadid_np() and pthread_attr_get_np(), convert the
pointer-sized pthread_t with reinterpret_cast, and reject
--worker_thread_priority, since setpriority() can't target one thread
on FreeBSD (series 0007).
FreeBSD-specific, not submitted upstream yet.
--- runtime/vm/os_thread_linux.cc.orig	2026-09-29 08:00:52 UTC
+++ runtime/vm/os_thread_linux.cc
@@ -14,6 +14,10 @@
 #include <sys/syscall.h>
 #include <sys/time.h>
 
+#if defined(__FreeBSD__)
+#include <pthread_np.h>
+#endif
+
 #include "platform/address_sanitizer.h"
 #include "platform/assert.h"
 #include "platform/safe_stack.h"
@@ -67,11 +71,16 @@ static void* ThreadStart(void* data_ptr) {
 // exits.
 static void* ThreadStart(void* data_ptr) {
   if (FLAG_worker_thread_priority != kMinInt) {
+#if defined(__FreeBSD__)
+    // setpriority() cannot target individual threads on FreeBSD.
+    FATAL("Setting thread priority is not supported on FreeBSD\n");
+#else
     if (setpriority(PRIO_PROCESS, syscall(__NR_gettid),
                     FLAG_worker_thread_priority) == -1) {
       FATAL("Setting thread priority to %d failed: errno = %d\n",
             FLAG_worker_thread_priority, errno);
     }
+#endif
   }
 
   ThreadStartData* data = reinterpret_cast<ThreadStartData*>(data_ptr);
@@ -132,7 +141,11 @@ ThreadId OSThread::GetCurrentThreadTraceId() {
 
 #ifdef SUPPORT_TIMELINE
 ThreadId OSThread::GetCurrentThreadTraceId() {
+#if defined(__FreeBSD__)
+  return ThreadIdFromIntPtr(pthread_getthreadid_np());
+#else
   return syscall(__NR_gettid);
+#endif
 }
 #endif  // SUPPORT_TIMELINE
 
@@ -166,21 +179,40 @@ void OSThread::Detach(ThreadJoinId id) {
   VALIDATE_PTHREAD_RESULT(result);
 }
 
+// pthread_t is an integer on Linux and a pointer on FreeBSD.
 intptr_t OSThread::ThreadIdToIntPtr(ThreadId id) {
   COMPILE_ASSERT(sizeof(id) <= sizeof(intptr_t));
+#if defined(__FreeBSD__)
+  return reinterpret_cast<intptr_t>(id);
+#else
   return static_cast<intptr_t>(id);
+#endif
 }
 
 ThreadId OSThread::ThreadIdFromIntPtr(intptr_t id) {
+#if defined(__FreeBSD__)
+  return reinterpret_cast<ThreadId>(id);
+#else
   return static_cast<ThreadId>(id);
+#endif
 }
 
 bool OSThread::GetCurrentStackBounds(uword* lower, uword* upper) {
   pthread_attr_t attr;
+#if defined(__FreeBSD__)
+  if (pthread_attr_init(&attr) != 0) {
+    return false;
+  }
+  if (pthread_attr_get_np(pthread_self(), &attr) != 0) {
+    pthread_attr_destroy(&attr);
+    return false;
+  }
+#else
   // May fail on the main thread.
   if (pthread_getattr_np(pthread_self(), &attr) != 0) {
     return false;
   }
+#endif
 
   void* base;
   size_t size;
