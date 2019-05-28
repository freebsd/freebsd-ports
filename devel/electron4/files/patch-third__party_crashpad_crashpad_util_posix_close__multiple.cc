--- third_party/crashpad/crashpad/util/posix/close_multiple.cc.orig	2019-03-15 06:38:19 UTC
+++ third_party/crashpad/crashpad/util/posix/close_multiple.cc
@@ -71,7 +71,7 @@ void CloseNowOrOnExec(int fd, bool ebadf_ok) {
 // This is an advantage over looping over all possible file descriptors, because
 // no attempt needs to be made to close file descriptors that are not open.
 bool CloseMultipleNowOrOnExecUsingFDDir(int min_fd, int preserve_fd) {
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_BSD)
   static constexpr char kFDDir[] = "/dev/fd";
 #elif defined(OS_LINUX) || defined(OS_ANDROID)
   static constexpr char kFDDir[] = "/proc/self/fd";
