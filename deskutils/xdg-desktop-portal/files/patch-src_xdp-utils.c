--- src/xdp-utils.c.orig	2026-06-17 16:46:28 UTC
+++ src/xdp-utils.c
@@ -54,7 +54,7 @@ pidfd_open (pid_t        pid,
 pidfd_open (pid_t        pid,
             unsigned int flags)
 {
-   return syscall (SYS_pidfd_open, pid, flags);
+   return -1;
 }
 #endif
 
