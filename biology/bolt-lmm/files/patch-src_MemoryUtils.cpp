--- src/MemoryUtils.cpp.orig	2022-03-20 14:01:47 UTC
+++ src/MemoryUtils.cpp
@@ -26,7 +26,8 @@ void *ALIGNED_MALLOC(uint64 size) {
 #ifdef USE_MKL_MALLOC
   void *p = mkl_malloc(size, MEM_ALIGNMENT);
 #else
-  void *p = _mm_malloc(size, MEM_ALIGNMENT);
+  //void *p = _mm_malloc(size, MEM_ALIGNMENT);
+  void *p = aligned_alloc(MEM_ALIGNMENT, size);
 #endif
   // TODO: change to assert() or dispense with altogether and change ALIGNED_MALLOC to macro?
   if (p == NULL) {
