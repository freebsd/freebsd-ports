--- a/bsd-user/freebsd/os-proc.c
+++ b/bsd-user/freebsd/os-proc.c
@@ -364,7 +364,7 @@ execve_end:
 #error __FreeBSD_version not defined!
 #endif
 
-#if defined(__FreeBSD_version) && __FreeBSD_version >= 1001510
+#if defined(__FreeBSD_version) && __FreeBSD_version >= 1001510 && defined(PROC_REAP_ACQUIRE)
 
 #include <sys/procctl.h>
 
