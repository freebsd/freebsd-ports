--- src/mmap_file_pool.cpp.orig	2021-12-28 19:09:39 UTC
+++ src/mmap_file_pool.cpp
@@ -116,7 +116,12 @@ namespace mmap_allocator_namespace {
 			throw mmap_allocator_exception("Error in remmap(fd)");
 
 		void *last_address = memory_area;
+#if defined(__FreeBSD__)
+		memory_area = mmap(last_address, size_mapped, PROT_READ, MAP_SHARED, fd, 0);
+#else
 		memory_area = mmap(last_address, size_mapped, PROT_READ, MAP_SHARED | MAP_NORESERVE, fd, 0);
+#endif
+
 		if (memory_area == MAP_FAILED) {
 			if (get_verbosity() > 0) {
 				perror("mmap");
