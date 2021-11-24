--- third_party/vulkan_memory_allocator/src/vk_mem_alloc.h.orig	2021-11-12 06:03:42 UTC
+++ third_party/vulkan_memory_allocator/src/vk_mem_alloc.h
@@ -3946,7 +3946,7 @@ void *vma_aligned_alloc(size_t alignment, size_t size)
 
     return memalign(alignment, size);
 }
-#elif defined(__APPLE__) || defined(__ANDROID__) || (defined(__linux__) && defined(__GLIBCXX__) && !defined(_GLIBCXX_HAVE_ALIGNED_ALLOC))
+#elif defined(__APPLE__) || defined(__ANDROID__) || defined(__FreeBSD__) || (defined(__linux__) && defined(__GLIBCXX__) && !defined(_GLIBCXX_HAVE_ALIGNED_ALLOC))
 #include <cstdlib>
 
 #if defined(__APPLE__)
