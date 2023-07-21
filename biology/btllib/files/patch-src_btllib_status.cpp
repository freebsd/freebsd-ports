--- src/btllib/status.cpp.orig	2023-07-21 18:23:40 UTC
+++ src/btllib/status.cpp
@@ -84,7 +84,7 @@ get_strerror()
   char buf[buflen];
 // POSIX and GNU implementation of strerror_r differ, even in function signature
 // and so we need to check which one is used
-#if __APPLE__ ||                                                               \
+#if __APPLE__ || __FreeBSD__  ||                                         \
   ((_POSIX_C_SOURCE >= 200112L || _XOPEN_SOURCE >= 600) && !_GNU_SOURCE)
   strerror_r(errno, buf, buflen);
   return buf;
@@ -111,4 +111,4 @@ check_file_accessibility(const std::string& filepath)
   btllib::check_error(ret != 0, get_strerror() + ": " + filepath);
 }
 
-} // namespace btllib
\ No newline at end of file
+} // namespace btllib
