--- src/unix/freebsd.c.orig	2020-04-15 16:31:21 UTC
+++ src/unix/freebsd.c
@@ -289,27 +289,3 @@ int uv_cpu_info(uv_cpu_info_t** cpu_infos, int* count)
   return 0;
 }
 
-
-int uv__sendmmsg(int fd,
-                 struct uv__mmsghdr* mmsg,
-                 unsigned int vlen,
-                 unsigned int flags) {
-#if __FreeBSD__ >= 11
-  return sendmmsg(fd, mmsg, vlen, flags);
-#else
-  return errno = ENOSYS, -1;
-#endif
-}
-
-
-int uv__recvmmsg(int fd,
-                 struct uv__mmsghdr* mmsg,
-                 unsigned int vlen,
-                 unsigned int flags,
-                 struct timespec* timeout) {
-#if __FreeBSD__ >= 11
-  return recvmmsg(fd, mmsg, vlen, flags, timeout);
-#else
-  return errno = ENOSYS, -1;
-#endif
-}
