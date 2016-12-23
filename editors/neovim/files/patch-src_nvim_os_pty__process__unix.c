--- src/nvim/os/pty_process_unix.c.orig	2016-11-08 05:50:09 UTC
+++ src/nvim/os/pty_process_unix.c
@@ -9,7 +9,7 @@
 #include <sys/ioctl.h>
 
 // forkpty is not in POSIX, so headers are platform-specific
-#if defined(__FreeBSD__)
+#if defined(__FreeBSD__) || defined (__DragonFly__)
 # include <libutil.h>
 #elif defined(__OpenBSD__) || defined(__NetBSD__) || defined(__APPLE__)
 # include <util.h>
