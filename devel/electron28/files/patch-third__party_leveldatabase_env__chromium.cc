--- third_party/leveldatabase/env_chromium.cc.orig	2023-10-19 19:59:09 UTC
+++ third_party/leveldatabase/env_chromium.cc
@@ -320,7 +320,8 @@ ChromiumWritableFile::ChromiumWritableFile(const std::
 
 Status ChromiumWritableFile::SyncParent() {
   TRACE_EVENT0("leveldb", "SyncParent");
-#if defined(OS_POSIX) || defined(OS_FUCHSIA)
+// pledge violation (directory passed as fd)
+#if (defined(OS_POSIX) || defined(OS_FUCHSIA)) && !defined(OS_OPENBSD)
   FilePath path = FilePath::FromUTF8Unsafe(parent_dir_);
   FileErrorOr<base::File> result = filesystem_->OpenFile(
       path, base::File::FLAG_OPEN | base::File::FLAG_READ);
