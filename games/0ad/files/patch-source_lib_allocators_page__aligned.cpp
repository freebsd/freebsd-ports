--- source/lib/allocators/page_aligned.cpp.orig	2025-01-28 19:58:03 UTC
+++ source/lib/allocators/page_aligned.cpp
@@ -48,7 +48,7 @@ Status mem_Reserve(size_t size, u8** pp)
 Status mem_Reserve(size_t size, u8** pp)
 {
 	errno = 0;
-	void* ret = mmap(0, size, PROT_NONE, mmap_flags|MAP_NORESERVE, -1, 0);
+	void* ret = mmap(0, size, PROT_NONE, mmap_flags, -1, 0);
 	*pp = (u8*)ret;
 	return StatusFromMap(ret);
 }
@@ -75,7 +75,7 @@ Status mem_Decommit(u8* p, size_t size)
 Status mem_Decommit(u8* p, size_t size)
 {
 	errno = 0;
-	void* ret = mmap(p, size, PROT_NONE, mmap_flags|MAP_NORESERVE|MAP_FIXED, -1, 0);
+	void* ret = mmap(p, size, PROT_NONE, mmap_flags|MAP_FIXED, -1, 0);
 	return StatusFromMap(ret);
 }
 
