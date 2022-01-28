--- storage/innobase/include/detail/ut/large_page_alloc-linux.h.orig	2021-12-17 16:07:27 UTC
+++ storage/innobase/include/detail/ut/large_page_alloc-linux.h
@@ -52,7 +52,7 @@ inline void *large_page_aligned_alloc(size_t n_bytes) 
   // mmap will internally round n_bytes to the multiple of huge-page size if it
   // is not already
   void *ptr = mmap(nullptr, n_bytes, PROT_READ | PROT_WRITE,
-                   MAP_PRIVATE | MAP_ANON | MAP_HUGETLB, -1, 0);
+                   MAP_PRIVATE | MAP_ANON, -1, 0);
   if (unlikely(ptr == (void *)-1)) {
     ib::log_warn(ER_IB_MSG_856) << "large_page_aligned_alloc mmap(" << n_bytes
                                 << " bytes) failed;"
