--- base/allocator/dispatcher/tls.h.orig	2025-08-26 20:49:50 UTC
+++ base/allocator/dispatcher/tls.h
@@ -86,7 +86,7 @@ struct BASE_EXPORT MMapAllocator {
   constexpr static size_t AllocationChunkSize = 16384;
 #elif BUILDFLAG(IS_ANDROID) && defined(ARCH_CPU_64_BITS)
   constexpr static size_t AllocationChunkSize = 16384;
-#elif BUILDFLAG(IS_LINUX) && defined(ARCH_CPU_ARM64)
+#elif (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && defined(ARCH_CPU_ARM64)
   constexpr static size_t AllocationChunkSize = 16384;
 #else
   constexpr static size_t AllocationChunkSize = 4096;
