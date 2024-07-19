--- base/allocator/partition_allocator/src/partition_alloc/partition_root.cc.orig	2024-06-18 21:43:17 UTC
+++ base/allocator/partition_allocator/src/partition_alloc/partition_root.cc
@@ -48,7 +48,7 @@
 #include "wow64apiset.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include <pthread.h>
 #endif
 
@@ -280,7 +280,7 @@ void PartitionAllocMallocInitOnce() {
     return;
   }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // When fork() is called, only the current thread continues to execute in the
   // child process. If the lock is held, but *not* by this thread when fork() is
   // called, we have a deadlock.
@@ -957,7 +957,7 @@ void PartitionRoot::Init(PartitionOptions opts) {
     // apple OSes.
     PA_CHECK((internal::SystemPageSize() == (size_t{1} << 12)) ||
              (internal::SystemPageSize() == (size_t{1} << 14)));
-#elif BUILDFLAG(IS_LINUX) && defined(ARCH_CPU_ARM64)
+#elif (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && defined(ARCH_CPU_ARM64)
     // Check runtime pagesize. Though the code is currently the same, it is
     // not merged with the IS_APPLE case above as a 1 << 16 case needs to be
     // added here in the future, to allow 64 kiB pagesize. That is only
