--- tools/gn/src/base/files/file_posix.cc.orig	2024-10-16 21:48:27 UTC
+++ tools/gn/src/base/files/file_posix.cc
@@ -359,7 +359,7 @@ bool File::Flush() {
 bool File::Flush() {
   DCHECK(IsValid());
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   return !HANDLE_EINTR(fdatasync(file_.get()));
 #else
   return !HANDLE_EINTR(fsync(file_.get()));
