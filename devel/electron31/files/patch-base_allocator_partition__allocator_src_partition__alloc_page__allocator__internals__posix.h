--- base/allocator/partition_allocator/src/partition_alloc/page_allocator_internals_posix.h.orig	2024-02-21 00:20:30 UTC
+++ base/allocator/partition_allocator/src/partition_alloc/page_allocator_internals_posix.h
@@ -411,8 +411,12 @@ void DiscardSystemPagesInternal(uintptr_t address, siz
 
 void DiscardSystemPagesInternal(uintptr_t address, size_t length) {
   void* ptr = reinterpret_cast<void*>(address);
-#if BUILDFLAG(IS_APPLE)
+#if BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_BSD)
+#if BUILDFLAG(IS_BSD)
+  int ret = madvise(ptr, length, MADV_FREE);
+#else
   int ret = madvise(ptr, length, MADV_FREE_REUSABLE);
+#endif
   if (ret) {
     // MADV_FREE_REUSABLE sometimes fails, so fall back to MADV_DONTNEED.
     ret = madvise(ptr, length, MADV_DONTNEED);
