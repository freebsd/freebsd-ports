--- RResolver/btllib/include/btllib/status.hpp.orig	2022-07-29 18:56:25 UTC
+++ RResolver/btllib/include/btllib/status.hpp
@@ -151,7 +151,7 @@ get_strerror()
   char buf[buflen];
 // POSIX and GNU implementation of strerror_r differ, even in function signature
 // and so we need to check which one is used
-#if __APPLE__ ||                                                               \
+#if __APPLE__ || defined(__FreeBSD__) ||                                                    \
   ((_POSIX_C_SOURCE >= 200112L || _XOPEN_SOURCE >= 600) && !_GNU_SOURCE)
   strerror_r(errno, buf, buflen);
   return buf;
