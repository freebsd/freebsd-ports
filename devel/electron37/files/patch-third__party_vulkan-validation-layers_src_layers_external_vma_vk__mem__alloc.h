--- third_party/vulkan-validation-layers/src/layers/external/vma/vk_mem_alloc.h.orig	2025-03-24 20:50:14 UTC
+++ third_party/vulkan-validation-layers/src/layers/external/vma/vk_mem_alloc.h
@@ -2971,7 +2971,7 @@ static void* vma_aligned_alloc(size_t alignment, size_
 
     return memalign(alignment, size);
 }
-#elif defined(__APPLE__) || defined(__ANDROID__) || (defined(__linux__) && defined(__GLIBCXX__) && !defined(_GLIBCXX_HAVE_ALIGNED_ALLOC))
+#elif defined(__APPLE__) || defined(__ANDROID__) || (defined(__linux__) && defined(__GLIBCXX__) && !defined(_GLIBCXX_HAVE_ALIGNED_ALLOC)) || defined(__OpenBSD__) || defined(__FreeBSD__)
 #include <cstdlib>
 
 #if defined(__APPLE__)
