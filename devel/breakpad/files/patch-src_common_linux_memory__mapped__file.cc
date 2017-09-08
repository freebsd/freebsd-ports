--- src/common/linux/memory_mapped_file.cc.orig	2017-07-12 17:53:15 UTC
+++ src/common/linux/memory_mapped_file.cc
@@ -65,9 +65,10 @@ bool MemoryMappedFile::Map(const char* p
   }
 
 #if defined(__x86_64__) || defined(__aarch64__) || \
-   (defined(__mips__) && _MIPS_SIM == _ABI64)
+   (defined(__mips__) && _MIPS_SIM == _ABI64) || \
+   defined(__FreeBSD__)
 
-  struct kernel_stat st;
+  struct stat st;
   if (sys_fstat(fd, &st) == -1 || st.st_size < 0) {
 #else
   struct kernel_stat64 st;
