--- src/unix/linux-syscalls.h.orig	2020-04-15 16:31:21 UTC
+++ src/unix/linux-syscalls.h
@@ -61,6 +61,20 @@ struct uv__statx {
   uint64_t unused1[14];
 };
 
+struct uv__mmsghdr {
+  struct msghdr msg_hdr;
+  unsigned int msg_len;
+};
+
+int uv__recvmmsg(int fd,
+                 struct uv__mmsghdr* mmsg,
+                 unsigned int vlen,
+                 unsigned int flags,
+                 struct timespec* timeout);
+int uv__sendmmsg(int fd,
+                 struct uv__mmsghdr* mmsg,
+                 unsigned int vlen,
+                 unsigned int flags);
 ssize_t uv__preadv(int fd, const struct iovec *iov, int iovcnt, int64_t offset);
 ssize_t uv__pwritev(int fd, const struct iovec *iov, int iovcnt, int64_t offset);
 int uv__dup3(int oldfd, int newfd, int flags);
@@ -72,3 +86,4 @@ int uv__statx(int dirfd,
 ssize_t uv__getrandom(void* buf, size_t buflen, unsigned flags);
 
 #endif /* UV_LINUX_SYSCALL_H_ */
+
