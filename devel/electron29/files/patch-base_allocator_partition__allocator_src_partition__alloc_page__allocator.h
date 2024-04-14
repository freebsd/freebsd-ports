--- base/allocator/partition_allocator/src/partition_alloc/page_allocator.h.orig	2024-02-21 00:20:30 UTC
+++ base/allocator/partition_allocator/src/partition_alloc/page_allocator.h
@@ -256,7 +256,7 @@ constexpr PA_COMPONENT_EXPORT(
 // recommitted. Do not assume that this will not change over time.
 constexpr PA_COMPONENT_EXPORT(
     PARTITION_ALLOC) bool DecommittedMemoryIsAlwaysZeroed() {
-#if BUILDFLAG(IS_APPLE)
+#if BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_BSD)
   return false;
 #else
   return true;
