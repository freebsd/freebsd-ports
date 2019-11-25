--- tools/gn/base/files/file_util_posix.cc.orig	2019-08-26 19:07:16 UTC
+++ tools/gn/base/files/file_util_posix.cc
@@ -254,7 +254,7 @@ bool ReplaceFile(const FilePath& from_path,
 #endif  // !defined(OS_NACL_NONSFI)
 
 bool CreateLocalNonBlockingPipe(int fds[2]) {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   return pipe2(fds, O_CLOEXEC | O_NONBLOCK) == 0;
 #else
   int raw_fds[2];
