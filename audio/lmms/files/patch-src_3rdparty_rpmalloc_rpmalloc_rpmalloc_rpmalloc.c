--- src/3rdparty/rpmalloc/rpmalloc/rpmalloc/rpmalloc.c.orig	2018-07-14 14:17:12 UTC
+++ src/3rdparty/rpmalloc/rpmalloc/rpmalloc/rpmalloc.c
@@ -1627,6 +1627,8 @@ _memory_map_os(size_t size, size_t* offset) {
 #else
 #  if defined(__APPLE__)
 	void* ptr = mmap(0, size + padding, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS | MAP_UNINITIALIZED, (_memory_huge_pages ? VM_FLAGS_SUPERPAGE_SIZE_2MB : -1), 0);
+#  elif defined(__FreeBSD__)
+	void* ptr = mmap(0, size + padding, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS | MAP_UNINITIALIZED, -1, 0);
 #  else
 	void* ptr = mmap(0, size + padding, PROT_READ | PROT_WRITE, (_memory_huge_pages ? MAP_HUGETLB : 0) | MAP_PRIVATE | MAP_ANONYMOUS | MAP_UNINITIALIZED, -1, 0);
 #  endif
