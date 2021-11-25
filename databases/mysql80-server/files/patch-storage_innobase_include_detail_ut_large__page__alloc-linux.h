--- storage/innobase/include/detail/ut/large_page_alloc-linux.h.orig	2021-09-28 11:46:34 UTC
+++ storage/innobase/include/detail/ut/large_page_alloc-linux.h
@@ -50,7 +50,7 @@ inline void *large_page_aligned_alloc(size_t n_bytes) 
   // mmap will internally round n_bytes to the multiple of huge-page size if it
   // is not already
   void *ptr = mmap(nullptr, n_bytes, PROT_READ | PROT_WRITE,
-                   MAP_PRIVATE | MAP_ANON | MAP_HUGETLB, -1, 0);
+                   MAP_PRIVATE | MAP_ANON, -1, 0);
   return (ptr != (void *)-1) ? ptr : nullptr;
 }
 
