--- base/allocator/partition_allocator/src/partition_alloc/page_allocator_constants.h.orig	2024-04-15 20:33:42 UTC
+++ base/allocator/partition_allocator/src/partition_alloc/page_allocator_constants.h
@@ -26,7 +26,7 @@
 #define PAGE_ALLOCATOR_CONSTANTS_DECLARE_CONSTEXPR __attribute__((const))
 
 #elif (BUILDFLAG(IS_ANDROID) && defined(ARCH_CPU_64_BITS)) || \
-    (BUILDFLAG(IS_LINUX) && defined(ARCH_CPU_ARM64))
+    ((BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && defined(ARCH_CPU_ARM64))
 // This should work for all POSIX (if needed), but currently all other
 // supported OS/architecture combinations use either hard-coded values
 // (such as x86) or have means to determine these values without needing
