--- src/corelib/global/qsystemdetection.h.orig	2026-05-11 20:54:55 UTC
+++ src/corelib/global/qsystemdetection.h
@@ -100,9 +100,7 @@
 #elif defined(__linux__) || defined(__linux)
 #  define Q_OS_LINUX
 #elif defined(__FreeBSD__) || defined(__DragonFly__) || defined(__FreeBSD_kernel__)
-#  ifndef __FreeBSD_kernel__
-#    define Q_OS_FREEBSD
-#  endif
+#  define Q_OS_FREEBSD
 #  define Q_OS_FREEBSD_KERNEL
 #  define Q_OS_BSD4
 #elif defined(__NetBSD__)
