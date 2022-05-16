--- base/allocator/partition_allocator/page_allocator.h.orig	2022-05-11 07:16:46 UTC
+++ base/allocator/partition_allocator/page_allocator.h
@@ -170,7 +170,7 @@ BASE_EXPORT void DecommitAndZeroSystemPages(void* addr
 // Whether decommitted memory is guaranteed to be zeroed when it is
 // recommitted. Do not assume that this will not change over time.
 constexpr BASE_EXPORT bool DecommittedMemoryIsAlwaysZeroed() {
-#if defined(OS_APPLE)
+#if defined(OS_APPLE) || defined(OS_BSD)
   return false;
 #else
   return true;
