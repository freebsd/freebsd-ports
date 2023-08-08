--- base/allocator/partition_allocator/partition_root.cc.orig	2023-05-25 00:41:37 UTC
+++ base/allocator/partition_allocator/partition_root.cc
@@ -46,7 +46,7 @@
 #include "wow64apiset.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include <pthread.h>
 #endif
 
@@ -287,7 +287,7 @@ void PartitionAllocMallocInitOnce() {
     return;
   }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // When fork() is called, only the current thread continues to execute in the
   // child process. If the lock is held, but *not* by this thread when fork() is
   // called, we have a deadlock.
@@ -381,7 +381,7 @@ static size_t PartitionPurgeSlotSpan(
   constexpr size_t kMaxSlotCount =
       (PartitionPageSize() * kMaxPartitionPagesPerRegularSlotSpan) /
       MinPurgeableSlotSize();
-#elif BUILDFLAG(IS_APPLE) || (BUILDFLAG(IS_LINUX) && defined(ARCH_CPU_ARM64))
+#elif BUILDFLAG(IS_APPLE) || ((BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && defined(ARCH_CPU_ARM64))
   // It's better for slot_usage to be stack-allocated and fixed-size, which
   // demands that its size be constexpr. On IS_APPLE and Linux on arm64,
   // PartitionPageSize() is always SystemPageSize() << 2, so regardless of
@@ -853,7 +853,7 @@ void PartitionRoot<thread_safe>::Init(PartitionOptions
     // apple OSes.
     PA_CHECK((internal::SystemPageSize() == (size_t{1} << 12)) ||
              (internal::SystemPageSize() == (size_t{1} << 14)));
-#elif BUILDFLAG(IS_LINUX) && defined(ARCH_CPU_ARM64)
+#elif (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && defined(ARCH_CPU_ARM64)
     // Check runtime pagesize. Though the code is currently the same, it is
     // not merged with the IS_APPLE case above as a 1 << 16 case needs to be
     // added here in the future, to allow 64 kiB pagesize. That is only
