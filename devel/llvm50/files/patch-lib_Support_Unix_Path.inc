--- lib/Support/Unix/Path.inc.orig
+++ lib/Support/Unix/Path.inc
@@ -427,7 +427,7 @@
   // If we have posix_fallocate use it. Unlike ftruncate it always allocates
   // space, so we get an error if the disk is full.
   if (int Err = ::posix_fallocate(FD, 0, Size)) {
-    if (Err != EOPNOTSUPP)
+    if (Err != EINVAL && Err != EOPNOTSUPP)
       return std::error_code(Err, std::generic_category());
   }
 #endif
