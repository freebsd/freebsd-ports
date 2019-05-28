--- base/test/test_file_util_posix.cc.orig	2019-03-15 06:36:56 UTC
+++ base/test/test_file_util_posix.cc
@@ -79,7 +79,7 @@ bool DieFileDie(const FilePath& file, bool recurse) {
   return DeleteFile(file, recurse);
 }
 
-#if !defined(OS_LINUX) && !defined(OS_MACOSX) && !defined(OS_ANDROID)
+#if !defined(OS_LINUX) && !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_BSD)
 bool EvictFileFromSystemCache(const FilePath& file) {
   // There doesn't seem to be a POSIX way to cool the disk cache.
   NOTIMPLEMENTED();
