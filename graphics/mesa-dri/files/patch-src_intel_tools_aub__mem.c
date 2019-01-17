- Partially implement memfd_create() via mkostemp()

--- src/intel/tools/aub_mem.c.orig	2018-11-06 16:16:02 UTC
+++ src/intel/tools/aub_mem.c
@@ -30,11 +30,34 @@
 
 #ifndef HAVE_MEMFD_CREATE
 #include <sys/syscall.h>
+#include <fcntl.h>
 
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
 
