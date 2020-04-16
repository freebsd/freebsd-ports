--- src/unix/internal.h.orig	2020-04-15 16:31:21 UTC
+++ src/unix/internal.h
@@ -31,7 +31,6 @@
 #include <fcntl.h>  /* O_CLOEXEC and O_NONBLOCK, if supported. */
 #include <stdio.h>
 #include <errno.h>
-#include <sys/socket.h>
 
 #if defined(__STRICT_ANSI__)
 # define inline __inline
@@ -328,27 +327,5 @@ int uv__getsockpeername(const uv_handle_t* handle,
                         struct sockaddr* name,
                         int* namelen);
 
-#if defined(__linux__)            ||                                      \
-    defined(__FreeBSD__)          ||                                      \
-    defined(__FreeBSD_kernel__)
-#define HAVE_MMSG 1
-struct uv__mmsghdr {
-  struct msghdr msg_hdr;
-  unsigned int msg_len;
-};
-
-int uv__recvmmsg(int fd,
-                 struct uv__mmsghdr* mmsg,
-                 unsigned int vlen,
-                 unsigned int flags,
-                 struct timespec* timeout);
-int uv__sendmmsg(int fd,
-                 struct uv__mmsghdr* mmsg,
-                 unsigned int vlen,
-                 unsigned int flags);
-#else
-#define HAVE_MMSG 0
-#endif
-
-
 #endif /* UV_UNIX_INTERNAL_H_ */
+
