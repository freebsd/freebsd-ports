--- base/files/file_util_posix.cc.orig	2022-05-11 07:16:46 UTC
+++ base/files/file_util_posix.cc
@@ -694,32 +694,34 @@ bool CreateDirectoryAndGetError(const FilePath& full_p
                                 File::Error* error) {
   ScopedBlockingCall scoped_blocking_call(
       FROM_HERE, BlockingType::MAY_BLOCK);  // For call to mkdir().
+  const FilePath kFileSystemRoot("/");
   std::vector<FilePath> subpaths;
 
   // Collect a list of all parent directories.
   FilePath last_path = full_path;
-  subpaths.push_back(full_path);
+  if (full_path != kFileSystemRoot)
+    subpaths.push_back(full_path);
   for (FilePath path = full_path.DirName();
-       path.value() != last_path.value(); path = path.DirName()) {
+       (path.value() != last_path.value() &&
+       (path != kFileSystemRoot)); path = path.DirName()) {
     subpaths.push_back(path);
     last_path = path;
   }
 
   // Iterate through the parents and create the missing ones.
   for (auto i = subpaths.rbegin(); i != subpaths.rend(); ++i) {
-    if (DirectoryExists(*i))
-      continue;
-    if (mkdir(i->value().c_str(), 0700) == 0)
-      continue;
-    // Mkdir failed, but it might have failed with EEXIST, or some other error
-    // due to the directory appearing out of thin air. This can occur if
-    // two processes are trying to create the same file system tree at the same
-    // time. Check to see if it exists and make sure it is a directory.
-    int saved_errno = errno;
-    if (!DirectoryExists(*i)) {
-      if (error)
-        *error = File::OSErrorToFileError(saved_errno);
-      return false;
+    if (!PathExists(*i)) {
+      if ((mkdir(i->value().c_str(), 0700) == -1) &&
+          ((full_path != *i) ? (errno != ENOENT) : (-1))) {
+        int saved_errno = errno;
+        if (error)
+          *error = File::OSErrorToFileError(saved_errno);
+        return false;
+      }
+    } else if (!DirectoryExists(*i)) {
+        if (error)
+          *error = File::OSErrorToFileError(ENOTDIR);
+        return false;
     }
   }
   return true;
