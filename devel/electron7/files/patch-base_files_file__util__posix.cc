--- base/files/file_util_posix.cc.orig	2019-12-12 12:38:58 UTC
+++ base/files/file_util_posix.cc
@@ -426,7 +426,7 @@ bool CreatePipe(ScopedFD* read_fd, ScopedFD* write_fd,
 }
 
 bool CreateLocalNonBlockingPipe(int fds[2]) {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   return pipe2(fds, O_CLOEXEC | O_NONBLOCK) == 0;
 #else
   int raw_fds[2];
