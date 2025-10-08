--- include/__generator.hpp.orig	2025-01-31 23:53:04 UTC
+++ include/__generator.hpp
@@ -36,6 +36,7 @@ using std::experimental::suspend_never;
 #include <utility>
 #include <concepts>
 #include <cassert>
+#include <memory>
 
 #if __has_include(<ranges>)
 #  include <ranges>
@@ -309,7 +310,7 @@ class __promise_base_alloc { (public)
     static void operator delete(void* __ptr, std::size_t __frameSize) noexcept {
         _Alloc& __alloc = __get_allocator(__ptr, __frameSize);
         _Alloc __localAlloc(std::move(__alloc));
-        __alloc.~Alloc();
+        __alloc.~_Alloc();
         __localAlloc.deallocate(static_cast<std::byte*>(__ptr), __padded_frame_size(__frameSize));
     }
 };
