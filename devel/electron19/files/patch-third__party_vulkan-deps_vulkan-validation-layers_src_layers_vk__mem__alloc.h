--- third_party/vulkan-deps/vulkan-validation-layers/src/layers/vk_mem_alloc.h.orig	2022-05-11 07:08:01 UTC
+++ third_party/vulkan-deps/vulkan-validation-layers/src/layers/vk_mem_alloc.h
@@ -3181,7 +3181,8 @@ void *aligned_alloc(size_t alignment, size_t size)
 
     return memalign(alignment, size);
 }
-#elif defined(__APPLE__) || defined(__ANDROID__)
+#elif defined(__APPLE__) || defined(__ANDROID__) || defined(__OpenBSD__) || \
+      defined(__FreeBSD__)
 #  define ALIGNED_ALLOC_WITH_POSIX_MEMALIGN
 #elif defined(__GNU_LIBRARY__)
 #  if !defined(__GLIBC_PREREQ) || !__GLIBC_PREREQ(2, 16)
