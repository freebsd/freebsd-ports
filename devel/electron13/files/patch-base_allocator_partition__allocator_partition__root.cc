--- base/allocator/partition_allocator/partition_root.cc.orig	2021-07-15 19:13:29 UTC
+++ base/allocator/partition_allocator/partition_root.cc
@@ -22,7 +22,7 @@
 #include "wow64apiset.h"
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include <pthread.h>
 #endif
 
@@ -36,7 +36,7 @@ namespace {
 
 #if BUILDFLAG(USE_PARTITION_ALLOC_AS_MALLOC)
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 
 // NO_THREAD_SAFETY_ANALYSIS: acquires the lock and doesn't release it, by
 // design.
@@ -89,7 +89,7 @@ void AfterForkInChild() {
   internal::ThreadCacheRegistry::Instance()
       .ForcePurgeAllThreadAfterForkUnsafe();
 }
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 
 std::atomic<bool> g_global_init_called;
 void PartitionAllocMallocInitOnce() {
@@ -99,7 +99,7 @@ void PartitionAllocMallocInitOnce() {
   if (!g_global_init_called.compare_exchange_strong(expected, true))
     return;
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // When fork() is called, only the current thread continues to execute in the
   // child process. If the lock is held, but *not* by this thread when fork() is
   // called, we have a deadlock.
@@ -124,7 +124,7 @@ void PartitionAllocMallocInitOnce() {
   int err =
       pthread_atfork(BeforeForkInParent, AfterForkInParent, AfterForkInChild);
   PA_CHECK(err == 0);
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 }
 #endif  // BUILDFLAG(USE_PARTITION_ALLOC_AS_MALLOC)
 
