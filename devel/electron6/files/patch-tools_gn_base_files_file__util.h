--- tools/gn/base/files/file_util.h.orig	2019-08-26 19:07:16 UTC
+++ tools/gn/base/files/file_util.h
@@ -361,7 +361,7 @@ bool VerifyPathControlledByAdmin(const base::FilePath&
 // the directory |path|, in the number of FilePath::CharType, or -1 on failure.
 int GetMaximumPathComponentLength(const base::FilePath& path);
 
-#if defined(OS_LINUX) || defined(OS_AIX)
+#if defined(OS_LINUX) || defined(OS_AIX) || defined(OS_BSD)
 // Broad categories of file systems as returned by statfs() on Linux.
 enum FileSystemType {
   FILE_SYSTEM_UNKNOWN,   // statfs failed.
