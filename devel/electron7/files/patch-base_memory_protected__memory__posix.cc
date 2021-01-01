--- base/memory/protected_memory_posix.cc.orig	2019-12-12 12:38:59 UTC
+++ base/memory/protected_memory_posix.cc
@@ -8,9 +8,9 @@
 #include <sys/mman.h>
 #include <unistd.h>
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include <sys/resource.h>
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 
 #if defined(OS_MACOSX) && !defined(OS_IOS)
 #include <mach/mach.h>
@@ -44,7 +44,7 @@ bool AutoWritableMemory::SetMemoryReadOnly(void* start
   return SetMemory(start, end, PROT_READ);
 }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 void AssertMemoryIsReadOnly(const void* ptr) {
 #if DCHECK_IS_ON()
   const uintptr_t page_mask = ~(base::GetPageSize() - 1);
@@ -74,6 +74,6 @@ void AssertMemoryIsReadOnly(const void* ptr) {
   DCHECK_EQ(region_info.protection, VM_PROT_READ);
 #endif  // DCHECK_IS_ON()
 }
-#endif  // defined(OS_LINUX) || (defined(OS_MACOSX) && !defined(OS_IOS))
+#endif  // defined(OS_LINUX) || (defined(OS_MACOSX) && !defined(OS_IOS)) || defined(OS_BSD)
 
 }  // namespace base
