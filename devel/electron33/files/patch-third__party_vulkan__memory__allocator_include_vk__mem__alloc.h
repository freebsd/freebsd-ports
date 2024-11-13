--- third_party/vulkan_memory_allocator/include/vk_mem_alloc.h.orig	2023-11-29 21:41:06 UTC
+++ third_party/vulkan_memory_allocator/include/vk_mem_alloc.h
@@ -2760,7 +2760,7 @@ void* vma_aligned_alloc(size_t alignment, size_t size)
 
     return memalign(alignment, size);
 }
-#elif defined(__APPLE__) || defined(__ANDROID__) || (defined(__linux__) && defined(__GLIBCXX__) && !defined(_GLIBCXX_HAVE_ALIGNED_ALLOC))
+#elif defined(__APPLE__) || defined(__ANDROID__) || (defined(__linux__) && defined(__GLIBCXX__) && !defined(_GLIBCXX_HAVE_ALIGNED_ALLOC)) || defined(__OpenBSD__) || defined(__FreeBSD__)
 #include <cstdlib>
 
 #if defined(__APPLE__)
