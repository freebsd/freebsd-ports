--- lib/Support/Unix/Path.inc.orig
+++ lib/Support/Unix/Path.inc
@@ -342,14 +342,15 @@
 #if defined(HAVE_POSIX_FALLOCATE)
   // If we have posix_fallocate use it. Unlike ftruncate it always allocates
   // space, so we get an error if the disk is full.
-  if (int Err = ::posix_fallocate(FD, 0, Size))
-    return std::error_code(Err, std::generic_category());
-#else
+  if (int Err = ::posix_fallocate(FD, 0, Size)) {
+    if (Err != EINVAL && Err != EOPNOTSUPP)
+      return std::error_code(Err, std::generic_category());
+  }
+#endif
   // Use ftruncate as a fallback. It may or may not allocate space. At least on
   // OS X with HFS+ it does.
   if (::ftruncate(FD, Size) == -1)
     return std::error_code(errno, std::generic_category());
-#endif
 
   return std::error_code();
 }
