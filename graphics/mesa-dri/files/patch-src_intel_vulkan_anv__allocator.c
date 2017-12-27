- Partially implement sys_futex() via _umtx_op()
- Partially implement memfd_create() via mkostemp()
- Ignore MAP_POPULATE if unsupported

--- src/intel/vulkan/anv_allocator.c.orig	2017-08-12 16:09:52 UTC
+++ src/intel/vulkan/anv_allocator.c
@@ -26,12 +26,31 @@
 #include <unistd.h>
 #include <limits.h>
 #include <assert.h>
+#ifdef __linux__
 #include <linux/futex.h>
 #include <linux/memfd.h>
+#endif
 #include <sys/time.h>
 #include <sys/mman.h>
+#ifdef __linux__
 #include <sys/syscall.h>
+#else
+#include <fcntl.h>
+#endif
 
+#ifdef __FreeBSD__
+#include <errno.h>
+#include <sys/umtx.h>
+#endif
+
+#ifndef MAP_POPULATE
+#define MAP_POPULATE 0
+#endif
+
+#ifndef MFD_CLOEXEC
+#define MFD_CLOEXEC O_CLOEXEC
+#endif
+
 #include "anv_private.h"
 
 #include "util/hash_table.h"
@@ -112,6 +131,8 @@ struct anv_mmap_cleanup {
 
 #define ANV_MMAP_CLEANUP_INIT ((struct anv_mmap_cleanup){0})
 
+#if defined(__linux__)
+
 static inline long
 sys_futex(void *addr1, int op, int val1,
           struct timespec *timeout, void *addr2, int val3)
@@ -131,11 +152,56 @@ futex_wait(uint32_t *addr, int32_t value)
    return sys_futex(addr, FUTEX_WAIT, value, NULL, NULL, 0);
 }
 
+#elif defined(__FreeBSD__)
+
+/* Based on libxshmfence */
+
+static inline int
+sys_futex(void *addr, int op, int32_t val)
+{
+   return _umtx_op(addr, op, (uint32_t)val, NULL, NULL) == -1 ? errno : 0;
+}
+
+static inline int
+futex_wake(uint32_t *addr, int count)
+{
+   return sys_futex(addr, UMTX_OP_WAKE, count);
+}
+
+static inline int
+futex_wait(uint32_t *addr, int32_t value)
+{
+   return sys_futex(addr, UMTX_OP_WAIT_UINT, value);
+}
+#endif
+
 #ifndef HAVE_MEMFD_CREATE
 static inline int
 memfd_create(const char *name, unsigned int flags)
 {
+#if defined(__linux__)
    return syscall(SYS_memfd_create, name, flags);
+#elif defined(__FreeBSD__)
+   return shm_open(SHM_ANON, flags | O_RDWR | O_CREAT, 0600);
+#else /* DragonFly, NetBSD, OpenBSD, Solaris */
+   char template[] = "/tmp/shmfd-XXXXXX";
+#ifdef HAVE_MKOSTEMP
+   int fd = mkostemp(template, flags);
+#else
+   int fd = mkstemp(template);
+   if (flags & O_CLOEXEC) {
+     int flags = fcntl(fd, F_GETFD);
+     if (flags != -1) {
+       flags |= FD_CLOEXEC;
+       (void) fcntl(fd, F_SETFD, &flags);
+     }
+   }
+#endif /* HAVE_MKOSTEMP */
+   if (fd >= 0)
+     unlink(template);
+
+   return fd;
+#endif /* __linux__ */
 }
 #endif
 
