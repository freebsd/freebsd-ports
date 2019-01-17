- Partially implement memfd_create() via mkostemp()

--- src/intel/tools/aubinator.c.orig	2018-08-02 15:41:20 UTC
+++ src/intel/tools/aubinator.c
@@ -52,7 +52,29 @@
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
 
