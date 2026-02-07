--- base/allocator/partition_allocator/src/partition_alloc/page_allocator.h.orig	2024-08-14 20:54:22 UTC
+++ base/allocator/partition_allocator/src/partition_alloc/page_allocator.h
@@ -269,7 +269,7 @@ constexpr PA_COMPONENT_EXPORT(
 // recommitted. Do not assume that this will not change over time.
 constexpr PA_COMPONENT_EXPORT(
     PARTITION_ALLOC) bool DecommittedMemoryIsAlwaysZeroed() {
-#if PA_BUILDFLAG(IS_APPLE)
+#if PA_BUILDFLAG(IS_APPLE) || PA_BUILDFLAG(IS_BSD)
   return false;
 #else
   return true;
