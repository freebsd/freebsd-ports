--- third_party/pdfium/third_party/base/allocator/partition_allocator/page_allocator.cc.orig	2019-12-12 12:45:42 UTC
+++ third_party/pdfium/third_party/base/allocator/partition_allocator/page_allocator.cc
@@ -117,7 +117,7 @@ void* AllocPages(void* address,
   uintptr_t align_base_mask = ~align_offset_mask;
   DCHECK(!(reinterpret_cast<uintptr_t>(address) & align_offset_mask));
 
-#if defined(OS_LINUX) && defined(ARCH_CPU_64_BITS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && defined(ARCH_CPU_64_BITS)
   // On 64 bit Linux, we may need to adjust the address space limit for
   // guarded allocations.
   if (length >= kMinimumGuardedMemorySize) {
