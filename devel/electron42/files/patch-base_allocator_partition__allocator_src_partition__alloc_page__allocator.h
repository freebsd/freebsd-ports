--- base/allocator/partition_allocator/src/partition_alloc/page_allocator.h.orig	2026-03-13 16:54:03 UTC
+++ base/allocator/partition_allocator/src/partition_alloc/page_allocator.h
@@ -279,7 +279,7 @@ constexpr PA_COMPONENT_EXPORT(
 // recommitted. Do not assume that this will not change over time.
 constexpr PA_COMPONENT_EXPORT(
     PARTITION_ALLOC) bool DecommittedMemoryIsAlwaysZeroed() {
-#if PA_BUILDFLAG(IS_APPLE)
+#if PA_BUILDFLAG(IS_APPLE) || PA_BUILDFLAG(IS_BSD)
   return false;
 #else
   return true;
