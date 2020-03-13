--- base/test/test_file_util_linux.cc.orig	2019-12-12 12:38:59 UTC
+++ base/test/test_file_util_linux.cc
@@ -51,8 +51,10 @@ bool EvictFileFromSystemCache(const FilePath& file) {
     return false;
   if (fdatasync(fd.get()) != 0)
     return false;
+#if !defined(OS_BSD)
   if (posix_fadvise(fd.get(), 0, 0, POSIX_FADV_DONTNEED) != 0)
     return false;
+#endif
   return true;
 }
 
