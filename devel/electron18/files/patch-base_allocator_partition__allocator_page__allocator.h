--- base/allocator/partition_allocator/page_allocator.h.orig	2022-05-19 03:45:15 UTC
+++ base/allocator/partition_allocator/page_allocator.h
@@ -194,7 +194,7 @@ BASE_EXPORT void DecommitAndZeroSystemPages(void* addr
 // Whether decommitted memory is guaranteed to be zeroed when it is
 // recommitted. Do not assume that this will not change over time.
 constexpr BASE_EXPORT bool DecommittedMemoryIsAlwaysZeroed() {
-#if BUILDFLAG(IS_APPLE)
+#if BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_BSD)
   return false;
 #else
   return true;
