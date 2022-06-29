--- base/allocator/partition_allocator/page_allocator_constants.h.orig	2022-05-25 04:00:42 UTC
+++ base/allocator/partition_allocator/page_allocator_constants.h
@@ -24,7 +24,7 @@
 // elimination.
 #define PAGE_ALLOCATOR_CONSTANTS_DECLARE_CONSTEXPR __attribute__((const))
 
-#elif BUILDFLAG(IS_LINUX) && defined(ARCH_CPU_ARM64)
+#elif (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && defined(ARCH_CPU_ARM64)
 // This should work for all POSIX (if needed), but currently all other
 // supported OS/architecture combinations use either hard-coded values
 // (such as x86) or have means to determine these values without needing
@@ -79,7 +79,7 @@ PageAllocationGranularityShift() {
   return 14;  // 16kB
 #elif BUILDFLAG(IS_APPLE) && defined(ARCH_CPU_64_BITS)
   return vm_page_shift;
-#elif BUILDFLAG(IS_LINUX) && defined(ARCH_CPU_ARM64)
+#elif (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && defined(ARCH_CPU_ARM64)
   // arm64 supports 4kb (shift = 12), 16kb (shift = 14), and 64kb (shift = 16)
   // page sizes. Retrieve from or initialize cache.
   int shift = page_characteristics.shift.load(std::memory_order_relaxed);
@@ -99,7 +99,7 @@ PageAllocationGranularity() {
   // This is literally equivalent to |1 << PageAllocationGranularityShift()|
   // below, but was separated out for IS_APPLE to avoid << on a non-constexpr.
   return vm_page_size;
-#elif BUILDFLAG(IS_LINUX) && defined(ARCH_CPU_ARM64)
+#elif (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && defined(ARCH_CPU_ARM64)
   // arm64 supports 4kb, 16kb, and 64kb page sizes. Retrieve from or
   // initialize cache.
   int size = page_characteristics.size.load(std::memory_order_relaxed);
