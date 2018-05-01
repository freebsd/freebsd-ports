--- third_party/ijar/mapped_file_unix.cc.orig	2018-04-09 14:20:44 UTC
+++ third_party/ijar/mapped_file_unix.cc
@@ -110,7 +110,7 @@
 
   // Ensure that any buffer overflow in JarStripper will result in
   // SIGSEGV or SIGBUS by over-allocating beyond the end of the file.
-  size_t mmap_length = std::min(estimated_size + sysconf(_SC_PAGESIZE),
+  size_t mmap_length = std::min(estimated_size + ((size_t)sysconf(_SC_PAGESIZE)),
                                 std::numeric_limits<size_t>::max());
   void* mapped = mmap(NULL, mmap_length, PROT_WRITE, MAP_SHARED, fd, 0);
   if (mapped == MAP_FAILED) {
