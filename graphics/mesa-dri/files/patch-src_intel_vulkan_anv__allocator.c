- Partially implement memfd_create() via mkostemp()
- Ignore MAP_POPULATE if unsupported

--- src/intel/vulkan/anv_allocator.c.orig	2018-01-23 18:08:50 UTC
+++ src/intel/vulkan/anv_allocator.c
@@ -25,9 +25,21 @@
 #include <unistd.h>
 #include <limits.h>
 #include <assert.h>
+#ifdef __linux__
 #include <linux/memfd.h>
+#else
+#include <fcntl.h>
+#endif
 #include <sys/mman.h>
 
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
@@ -113,7 +125,29 @@ struct anv_mmap_cleanup {
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
 
