- NetBSD has fdatasync(2), see https://github.com/NetBSD/src/commit/e963c41c6fb9
- OpenBSD has fdatasync(3), see https://github.com/openbsd/src/commit/aa96fc3dc04f
- FreeBSD 11.0 has robust mutexes (see base r300043) and 11.1 has fdatasync(2) (see base r304977)

--- mdb.c.orig	2018-03-22 15:23:05 UTC
+++ mdb.c
@@ -124,11 +124,12 @@ typedef SSIZE_T	ssize_t;
 #include <resolv.h>	/* defines BYTE_ORDER on HPUX and Solaris */
 #endif
 
-#if defined(__APPLE__) || defined (BSD) || defined(__FreeBSD_kernel__)
-# define MDB_USE_POSIX_SEM	1
+#if defined(__APPLE__) || defined(ANDROID) || defined(__DragonFly__) || (defined(__FreeBSD__) && __FreeBSD__ < 11)
 # define MDB_FDATASYNC		fsync
-#elif defined(ANDROID)
-# define MDB_FDATASYNC		fsync
+#endif
+
+#if defined(__APPLE__) || defined(__DragonFly__) || defined(__NetBSD__) || defined(__OpenBSD__) || (defined(__FreeBSD__) && __FreeBSD__ < 11)
+# define MDB_USE_POSIX_SEM	1
 #endif
 
 #ifndef _WIN32
