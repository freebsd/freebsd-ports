--- base/allocator/partition_allocator/starscan/pcscan.cc.orig	2021-07-15 19:13:29 UTC
+++ base/allocator/partition_allocator/starscan/pcscan.cc
@@ -67,7 +67,7 @@ namespace internal {
 
 namespace {
 
-#if DCHECK_IS_ON() && defined(OS_LINUX)
+#if DCHECK_IS_ON() && (defined(OS_LINUX) || defined(OS_BSD))
 // Currently, check reentracy only on Linux. On Android TLS is emulated by the
 // runtime lib, which can allocate and therefore cause reentrancy.
 struct ReentrantScannerGuard final {
