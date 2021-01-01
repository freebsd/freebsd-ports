--- source/lib/sysdep/os/unix/uvm.cpp.orig	2017-07-28 19:57:26 UTC
+++ source/lib/sysdep/os/unix/uvm.cpp
@@ -40,7 +40,7 @@ namespace vm {
 void* ReserveAddressSpace(size_t size, size_t UNUSED(commitSize), PageType UNUSED(pageType), int UNUSED(prot))
 {
 	errno = 0;
-	void* p = mmap(0, size, PROT_NONE, mmap_flags|MAP_NORESERVE, -1, 0);
+	void* p = mmap(0, size, PROT_NONE, mmap_flags, -1, 0);
 	if(p == MAP_FAILED)
 		return 0;
 	return p;
@@ -77,7 +77,7 @@ bool Commit(uintptr_t address, size_t size, PageType U
 bool Decommit(uintptr_t address, size_t size)
 {
 	errno = 0;
-	if(mmap((void*)address, size, PROT_NONE, mmap_flags|MAP_NORESERVE|MAP_FIXED, -1, 0) == MAP_FAILED)
+	if(mmap((void*)address, size, PROT_NONE, mmap_flags|MAP_FIXED, -1, 0) == MAP_FAILED)
 		return false;
 	return true;
 }
