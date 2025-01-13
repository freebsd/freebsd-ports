--- src/prim/unix/prim.c.orig	2025-01-04 04:21:48 UTC
+++ src/prim/unix/prim.c
@@ -201,7 +201,8 @@ static void* unix_mmap_prim(void* addr, size_t size, s
   void* p = NULL;
   #if defined(MAP_ALIGNED)  // BSD
   if (addr == NULL && try_alignment > 1 && (try_alignment % _mi_os_page_size()) == 0) {
-    size_t n = mi_bsr(try_alignment);
+    size_t idx;
+    size_t n = mi_bsr(try_alignment, &idx);
     if (((size_t)1 << n) == try_alignment && n >= 12 && n <= 30) {  // alignment is a power of 2 and 4096 <= alignment <= 1GiB
       p = mmap(addr, size, protect_flags, flags | MAP_ALIGNED(n), fd, 0);
       if (p==MAP_FAILED || !_mi_is_aligned(p,try_alignment)) {
