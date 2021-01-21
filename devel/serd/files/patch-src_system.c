--- src/system.c.orig	2021-01-20 12:24:18 UTC
+++ src/system.c
@@ -55,8 +55,6 @@ serd_malloc_aligned(const size_t alignment, const size
 {
 #if defined(_WIN32)
   return _aligned_malloc(size, alignment);
-#elif USE_ALIGNED_ALLOC
-  return aligned_alloc(alignment, size);
 #elif USE_POSIX_MEMALIGN
   void*     ptr = NULL;
   const int ret = posix_memalign(&ptr, alignment, size);
