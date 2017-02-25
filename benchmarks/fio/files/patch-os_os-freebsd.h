--- os/os-freebsd.h.orig	2017-02-23 15:44:32 UTC
+++ os/os-freebsd.h
@@ -24,7 +24,9 @@
 #define FIO_HAVE_CPU_AFFINITY
 /* Only have attach-to-open-removed when kern.ipc.shm_allow_removed is 1 */
 #undef  FIO_HAVE_SHM_ATTACH_REMOVED
-
+#if _POSIX_THREAD_PROCESS_SHARED > 0
+#define FIO_HAVE_PSHARED_MUTEX
+#endif
 
 #define OS_MAP_ANON		MAP_ANON
 
