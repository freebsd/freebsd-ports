--- source/lib/allocators/page_aligned.cpp.orig	2017-07-28 19:57:26 UTC
+++ source/lib/allocators/page_aligned.cpp
@@ -49,7 +49,7 @@ static const int mmap_flags = MAP_PRIVATE|MAP_ANONYMOU
 Status mem_Reserve(size_t size, u8** pp)
 {
 	errno = 0;
-	void* ret = mmap(0, size, PROT_NONE, mmap_flags|MAP_NORESERVE, -1, 0);
+	void* ret = mmap(0, size, PROT_NONE, mmap_flags, -1, 0);
 	*pp = (u8*)ret;
 	return StatusFromMap(ret);
 }
@@ -76,7 +76,7 @@ Status mem_Commit(u8* p, size_t size, int prot)
 Status mem_Decommit(u8* p, size_t size)
 {
 	errno = 0;
-	void* ret = mmap(p, size, PROT_NONE, mmap_flags|MAP_NORESERVE|MAP_FIXED, -1, 0);
+	void* ret = mmap(p, size, PROT_NONE, mmap_flags|MAP_FIXED, -1, 0);
 	return StatusFromMap(ret);
 }
 
