--- src/arch.cc.orig	2025-12-20 13:37:07 UTC
+++ src/arch.cc
@@ -67,7 +67,7 @@
 #include <cstdlib>  // std::realloc, std::free
 
 
-constexpr auto memalignment = 16;
+constexpr auto vsearch_memalignment = 16;
 
 
 auto arch_get_memused() -> uint64_t
@@ -223,9 +223,9 @@ auto xmalloc(std::size_t size) -> void *
   size = std::max(size, minimal_allocation);
   void * ptr = nullptr;
 #ifdef _WIN32
-  ptr = _aligned_malloc(size, memalignment);
+  ptr = _aligned_malloc(size, vsearch_memalignment);
 #else
-  if (posix_memalign(&ptr, memalignment, size) != 0)
+  if (posix_memalign(&ptr, vsearch_memalignment, size) != 0)
     {
       ptr = nullptr;
     }
@@ -243,7 +243,7 @@ auto xrealloc(void * ptr, std::size_t size) -> void *
   static constexpr auto minimal_allocation = std::size_t{1};
   size = std::max(size, minimal_allocation);
 #ifdef _WIN32
-  void * new_ptr = _aligned_realloc(ptr, size, memalignment);
+  void * new_ptr = _aligned_realloc(ptr, size, vsearch_memalignment);
 #else
   void * new_ptr = realloc(ptr, size);
 #endif
