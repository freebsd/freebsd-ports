--- third_party/vulkan-deps/vulkan-validation-layers/src/layers/external/vma/vk_mem_alloc.h.orig	2023-05-25 00:46:25 UTC
+++ third_party/vulkan-deps/vulkan-validation-layers/src/layers/external/vma/vk_mem_alloc.h
@@ -2740,7 +2740,7 @@ static void* vma_aligned_alloc(size_t alignment, size_
 
     return memalign(alignment, size);
 }
-#elif defined(__APPLE__) || defined(__ANDROID__) || (defined(__linux__) && defined(__GLIBCXX__) && !defined(_GLIBCXX_HAVE_ALIGNED_ALLOC))
+#elif defined(__APPLE__) || defined(__ANDROID__) || (defined(__linux__) && defined(__GLIBCXX__) && !defined(_GLIBCXX_HAVE_ALIGNED_ALLOC)) || defined(__OpenBSD__) || defined(__FreeBSD__)
 #include <cstdlib>
 
 #if defined(__APPLE__)
