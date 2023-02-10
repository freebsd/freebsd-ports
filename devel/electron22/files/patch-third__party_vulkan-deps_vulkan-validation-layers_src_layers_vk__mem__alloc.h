--- third_party/vulkan-deps/vulkan-validation-layers/src/layers/vk_mem_alloc.h.orig	2022-10-24 13:33:33 UTC
+++ third_party/vulkan-deps/vulkan-validation-layers/src/layers/vk_mem_alloc.h
@@ -2700,7 +2700,7 @@ static void* vma_aligned_alloc(size_t alignment, size_
 
     return memalign(alignment, size);
 }
-#elif defined(__APPLE__) || defined(__ANDROID__) || (defined(__linux__) && defined(__GLIBCXX__) && !defined(_GLIBCXX_HAVE_ALIGNED_ALLOC))
+#elif defined(__APPLE__) || defined(__ANDROID__) || (defined(__linux__) && defined(__GLIBCXX__) && !defined(_GLIBCXX_HAVE_ALIGNED_ALLOC)) || defined(__OpenBSD__) || defined(__FreeBSD__)
 #define ALIGNED_ALLOC_WITH_POSIX_MEMALIGN
 #elif defined(__GNU_LIBRARY__)
 #  if !defined(__GLIBC_PREREQ) || !__GLIBC_PREREQ(2, 16)
