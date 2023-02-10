--- env/io_posix.h.orig	2022-12-22 17:30:39 UTC
+++ env/io_posix.h
@@ -29,7 +29,7 @@
 
 // For non linux platform, the following macros are used only as place
 // holder.
-#if !(defined OS_LINUX) && !(defined CYGWIN) && !(defined OS_AIX)
+#if !(defined OS_LINUX) && !(defined CYGWIN) && !(defined OS_AIX) && !(defined OS_FREEBSD)
 #define POSIX_FADV_NORMAL 0     /* [MC1] no further special treatment */
 #define POSIX_FADV_RANDOM 1     /* [MC1] expect random page refs */
 #define POSIX_FADV_SEQUENTIAL 2 /* [MC1] expect sequential page refs */
