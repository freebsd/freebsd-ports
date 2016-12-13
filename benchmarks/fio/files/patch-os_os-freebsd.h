--- os/os-freebsd.h.orig	2016-10-25 18:38:13 UTC
+++ os/os-freebsd.h
@@ -22,6 +22,9 @@
 #define FIO_HAVE_TRIM
 #define FIO_HAVE_GETTID
 #define FIO_HAVE_CPU_AFFINITY
+#if _POSIX_THREAD_PROCESS_SHARED > 0
+#define FIO_HAVE_PSHARED_MUTEX
+#endif
 
 #define OS_MAP_ANON		MAP_ANON
 
