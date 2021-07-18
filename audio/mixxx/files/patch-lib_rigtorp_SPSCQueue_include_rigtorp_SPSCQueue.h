--- lib/rigtorp/SPSCQueue/include/rigtorp/SPSCQueue.h.orig	2021-06-28 20:04:59 UTC
+++ lib/rigtorp/SPSCQueue/include/rigtorp/SPSCQueue.h
@@ -189,7 +189,7 @@ template <typename T, typename Allocator = std::alloca
 // on macOS there is a bug in libc++ where __cpp_lib_hardware_interference_size
 // is defined but std::hardware_destructive_interference_size is not actually implemented
 // https://bugs.llvm.org/show_bug.cgi?id=41423
-#if defined(__cpp_lib_hardware_interference_size) && ! defined(__APPLE__)
+#if defined(__cpp_lib_hardware_interference_size) && ! defined(__APPLE__) && ! defined(__FreeBSD__)
   static constexpr size_t kCacheLineSize =
       std::hardware_destructive_interference_size;
 #else
