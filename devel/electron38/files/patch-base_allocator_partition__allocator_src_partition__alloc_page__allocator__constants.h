--- base/allocator/partition_allocator/src/partition_alloc/page_allocator_constants.h.orig	2025-08-26 20:49:50 UTC
+++ base/allocator/partition_allocator/src/partition_alloc/page_allocator_constants.h
@@ -31,8 +31,8 @@
 #define PAGE_ALLOCATOR_CONSTANTS_DECLARE_CONSTEXPR __attribute__((const))
 
 #elif (PA_BUILDFLAG(IS_ANDROID) && PA_BUILDFLAG(PA_ARCH_CPU_64_BITS)) || \
-    (PA_BUILDFLAG(IS_LINUX) && PA_BUILDFLAG(PA_ARCH_CPU_ARM64)) ||       \
-    (PA_BUILDFLAG(IS_LINUX) && PA_BUILDFLAG(PA_ARCH_CPU_PPC64))
+    ((PA_BUILDFLAG(IS_LINUX) || PA_BUILDFLAG(IS_BSD)) && PA_BUILDFLAG(PA_ARCH_CPU_ARM64)) ||       \
+    ((PA_BUILDFLAG(IS_LINUX) || PA_BUILDFLAG(IS_BSD)) && PA_BUILDFLAG(PA_ARCH_CPU_PPC64))
 // This should work for all POSIX (if needed), but currently all other
 // supported OS/architecture combinations use either hard-coded values
 // (such as x86) or have means to determine these values without needing
