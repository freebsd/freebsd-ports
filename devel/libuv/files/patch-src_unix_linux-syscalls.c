--- src/unix/linux-syscalls.c.orig	2020-04-15 16:31:21 UTC
+++ src/unix/linux-syscalls.c
@@ -19,187 +19,71 @@
  * IN THE SOFTWARE.
  */
 
-#include "linux-syscalls.h"
-#include <unistd.h>
+#ifndef UV_LINUX_SYSCALL_H_
+#define UV_LINUX_SYSCALL_H_
+
+#undef  _GNU_SOURCE
+#define _GNU_SOURCE
+
+#include <stdint.h>
 #include <signal.h>
-#include <sys/syscall.h>
 #include <sys/types.h>
-#include <errno.h>
+#include <sys/time.h>
+#include <sys/socket.h>
 
-#if defined(__arm__)
-# if defined(__thumb__) || defined(__ARM_EABI__)
-#  define UV_SYSCALL_BASE 0
-# else
-#  define UV_SYSCALL_BASE 0x900000
-# endif
-#endif /* __arm__ */
+struct uv__statx_timestamp {
+  int64_t tv_sec;
+  uint32_t tv_nsec;
+  int32_t unused0;
+};
 
-#ifndef __NR_recvmmsg
-# if defined(__x86_64__)
-#  define __NR_recvmmsg 299
-# elif defined(__i386__)
-#  define __NR_recvmmsg 337
-# elif defined(__arm__)
-#  define __NR_recvmmsg (UV_SYSCALL_BASE + 365)
-# endif
-#endif /* __NR_recvmsg */
+struct uv__statx {
+  uint32_t stx_mask;
+  uint32_t stx_blksize;
+  uint64_t stx_attributes;
+  uint32_t stx_nlink;
+  uint32_t stx_uid;
+  uint32_t stx_gid;
+  uint16_t stx_mode;
+  uint16_t unused0;
+  uint64_t stx_ino;
+  uint64_t stx_size;
+  uint64_t stx_blocks;
+  uint64_t stx_attributes_mask;
+  struct uv__statx_timestamp stx_atime;
+  struct uv__statx_timestamp stx_btime;
+  struct uv__statx_timestamp stx_ctime;
+  struct uv__statx_timestamp stx_mtime;
+  uint32_t stx_rdev_major;
+  uint32_t stx_rdev_minor;
+  uint32_t stx_dev_major;
+  uint32_t stx_dev_minor;
+  uint64_t unused1[14];
+};
 
-#ifndef __NR_sendmmsg
-# if defined(__x86_64__)
-#  define __NR_sendmmsg 307
-# elif defined(__i386__)
-#  define __NR_sendmmsg 345
-# elif defined(__arm__)
-#  define __NR_sendmmsg (UV_SYSCALL_BASE + 374)
-# endif
-#endif /* __NR_sendmmsg */
+struct uv__mmsghdr {
+  struct msghdr msg_hdr;
+  unsigned int msg_len;
+};
 
-#ifndef __NR_utimensat
-# if defined(__x86_64__)
-#  define __NR_utimensat 280
-# elif defined(__i386__)
-#  define __NR_utimensat 320
-# elif defined(__arm__)
-#  define __NR_utimensat (UV_SYSCALL_BASE + 348)
-# endif
-#endif /* __NR_utimensat */
-
-#ifndef __NR_preadv
-# if defined(__x86_64__)
-#  define __NR_preadv 295
-# elif defined(__i386__)
-#  define __NR_preadv 333
-# elif defined(__arm__)
-#  define __NR_preadv (UV_SYSCALL_BASE + 361)
-# endif
-#endif /* __NR_preadv */
-
-#ifndef __NR_pwritev
-# if defined(__x86_64__)
-#  define __NR_pwritev 296
-# elif defined(__i386__)
-#  define __NR_pwritev 334
-# elif defined(__arm__)
-#  define __NR_pwritev (UV_SYSCALL_BASE + 362)
-# endif
-#endif /* __NR_pwritev */
-
-#ifndef __NR_dup3
-# if defined(__x86_64__)
-#  define __NR_dup3 292
-# elif defined(__i386__)
-#  define __NR_dup3 330
-# elif defined(__arm__)
-#  define __NR_dup3 (UV_SYSCALL_BASE + 358)
-# endif
-#endif /* __NR_pwritev */
-
-#ifndef __NR_statx
-# if defined(__x86_64__)
-#  define __NR_statx 332
-# elif defined(__i386__)
-#  define __NR_statx 383
-# elif defined(__aarch64__)
-#  define __NR_statx 397
-# elif defined(__arm__)
-#  define __NR_statx (UV_SYSCALL_BASE + 397)
-# elif defined(__ppc__)
-#  define __NR_statx 383
-# elif defined(__s390__)
-#  define __NR_statx 379
-# endif
-#endif /* __NR_statx */
-
-#ifndef __NR_getrandom
-# if defined(__x86_64__)
-#  define __NR_getrandom 318
-# elif defined(__i386__)
-#  define __NR_getrandom 355
-# elif defined(__aarch64__)
-#  define __NR_getrandom 384
-# elif defined(__arm__)
-#  define __NR_getrandom (UV_SYSCALL_BASE + 384)
-# elif defined(__ppc__)
-#  define __NR_getrandom 359
-# elif defined(__s390__)
-#  define __NR_getrandom 349
-# endif
-#endif /* __NR_getrandom */
-
-struct uv__mmsghdr;
-
-int uv__sendmmsg(int fd,
-                 struct uv__mmsghdr* mmsg,
-                 unsigned int vlen,
-                 unsigned int flags) {
-#if defined(__NR_sendmmsg)
-  return syscall(__NR_sendmmsg, fd, mmsg, vlen, flags);
-#else
-  return errno = ENOSYS, -1;
-#endif
-}
-
-
 int uv__recvmmsg(int fd,
                  struct uv__mmsghdr* mmsg,
                  unsigned int vlen,
                  unsigned int flags,
-                 struct timespec* timeout) {
-#if defined(__NR_recvmmsg)
-  return syscall(__NR_recvmmsg, fd, mmsg, vlen, flags, timeout);
-#else
-  return errno = ENOSYS, -1;
-#endif
-}
-
-
-ssize_t uv__preadv(int fd, const struct iovec *iov, int iovcnt, int64_t offset) {
-#if defined(__NR_preadv)
-  return syscall(__NR_preadv, fd, iov, iovcnt, (long)offset, (long)(offset >> 32));
-#else
-  return errno = ENOSYS, -1;
-#endif
-}
-
-
-ssize_t uv__pwritev(int fd, const struct iovec *iov, int iovcnt, int64_t offset) {
-#if defined(__NR_pwritev)
-  return syscall(__NR_pwritev, fd, iov, iovcnt, (long)offset, (long)(offset >> 32));
-#else
-  return errno = ENOSYS, -1;
-#endif
-}
-
-
-int uv__dup3(int oldfd, int newfd, int flags) {
-#if defined(__NR_dup3)
-  return syscall(__NR_dup3, oldfd, newfd, flags);
-#else
-  return errno = ENOSYS, -1;
-#endif
-}
-
-
+                 struct timespec* timeout);
+int uv__sendmmsg(int fd,
+                 struct uv__mmsghdr* mmsg,
+                 unsigned int vlen,
+                 unsigned int flags);
+ssize_t uv__preadv(int fd, const struct iovec *iov, int iovcnt, int64_t offset);
+ssize_t uv__pwritev(int fd, const struct iovec *iov, int iovcnt, int64_t offset);
+int uv__dup3(int oldfd, int newfd, int flags);
 int uv__statx(int dirfd,
               const char* path,
               int flags,
               unsigned int mask,
-              struct uv__statx* statxbuf) {
-  /* __NR_statx make Android box killed by SIGSYS.
-   * That looks like a seccomp2 sandbox filter rejecting the system call.
-   */
-#if defined(__NR_statx) && !defined(__ANDROID__)
-  return syscall(__NR_statx, dirfd, path, flags, mask, statxbuf);
-#else
-  return errno = ENOSYS, -1;
-#endif
-}
+              struct uv__statx* statxbuf);
+ssize_t uv__getrandom(void* buf, size_t buflen, unsigned flags);
 
+#endif /* UV_LINUX_SYSCALL_H_ */
 
-ssize_t uv__getrandom(void* buf, size_t buflen, unsigned flags) {
-#if defined(__NR_getrandom)
-  return syscall(__NR_getrandom, buf, buflen, flags);
-#else
-  return errno = ENOSYS, -1;
-#endif
-}
