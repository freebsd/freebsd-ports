--- tools/gn/src/base/files/file_posix.cc.orig	2022-09-24 10:57:32 UTC
+++ tools/gn/src/base/files/file_posix.cc
@@ -371,7 +371,7 @@ void File::DoInitialize(const FilePath& path, uint32_t
 bool File::Flush() {
   DCHECK(IsValid());
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   return !HANDLE_EINTR(fdatasync(file_.get()));
 #else
   return !HANDLE_EINTR(fsync(file_.get()));
