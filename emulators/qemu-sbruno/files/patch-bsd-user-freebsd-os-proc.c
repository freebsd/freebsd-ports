--- a/bsd-user/freebsd/os-proc.c
+++ b/bsd-user/freebsd/os-proc.c
@@ -365,8 +365,10 @@ execve_end:
 #endif
 
 #if defined(__FreeBSD_version) && __FreeBSD_version >= 1001510
-
 #include <sys/procctl.h>
+#endif
+
+#if defined(__FreeBSD_version) && __FreeBSD_version >= 1001510 && defined(PROC_REAP_ACQUIRE)
 
 static abi_long
 t2h_procctl_cmd(int target_cmd, int *host_cmd)
