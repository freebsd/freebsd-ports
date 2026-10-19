-- upstreamed: https://github.com/BirolLab/btllib/pull/152

--- src/btllib/status.cpp.orig	2026-10-16 20:52:17 UTC
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
