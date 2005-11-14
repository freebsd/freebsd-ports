--- vl.c.orig	Mon Nov 14 15:55:56 2005
+++ vl.c	Mon Nov 14 15:57:25 2005
@@ -40,6 +40,10 @@
 #include <sys/socket.h>
 #include <netinet/in.h>
 #include <dirent.h>
+#ifdef __FreeBSD__
+#include <sys/types.h>
+#include <libutil.h>
+#endif
 #ifdef _BSD
 #include <sys/stat.h>
 #ifndef __APPLE__
@@ -1363,7 +1367,7 @@
     return chr;
 }
 
-#if defined(__linux__)
+#if defined(__linux__) || defined(__FreeBSD__)
 CharDriverState *qemu_chr_open_pty(void)
 {
     char slave_name[1024];
@@ -1509,6 +1513,7 @@
     return chr;
 }
 
+#if defined(__linux__)
 static int pp_ioctl(CharDriverState *chr, int cmd, void *arg)
 {
     int fd = (int)chr->opaque;
@@ -1571,6 +1576,7 @@
     chr->chr_ioctl = pp_ioctl;
     return chr;
 }
+#endif
 
 #else
 CharDriverState *qemu_chr_open_pty(void)
