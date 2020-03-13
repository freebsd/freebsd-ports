--- third_party/crashpad/crashpad/util/posix/close_multiple.cc.orig	2019-12-12 12:41:25 UTC
+++ third_party/crashpad/crashpad/util/posix/close_multiple.cc
@@ -31,7 +31,7 @@
 #include "util/file/directory_reader.h"
 #include "util/misc/implicit_cast.h"
 
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_BSD)
 #include <sys/sysctl.h>
 #endif
 
@@ -72,7 +72,7 @@ void CloseNowOrOnExec(int fd, bool ebadf_ok) {
 // This is an advantage over looping over all possible file descriptors, because
 // no attempt needs to be made to close file descriptors that are not open.
 bool CloseMultipleNowOrOnExecUsingFDDir(int min_fd, int preserve_fd) {
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_BSD)
   static constexpr char kFDDir[] = "/dev/fd";
 #elif defined(OS_LINUX) || defined(OS_ANDROID)
   static constexpr char kFDDir[] = "/proc/self/fd";
@@ -146,7 +146,7 @@ void CloseMultipleNowOrOnExec(int fd, int preserve_fd)
   // while the system is running, but it’s still a better upper bound than the
   // current RLIMIT_NOFILE value.
 
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_BSD)
   // See 10.11.6 xnu-3248.60.10/bsd/kern/kern_resource.c maxfilesperproc,
   // referenced by dosetrlimit().
   int oid[] = {CTL_KERN, KERN_MAXFILESPERPROC};
