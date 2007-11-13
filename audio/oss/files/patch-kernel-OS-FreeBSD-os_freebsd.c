--- kernel/OS/FreeBSD/os_freebsd.c.orig	2007-11-12 15:40:51.000000000 -0500
+++ kernel/OS/FreeBSD/os_freebsd.c	2007-11-12 15:42:12.000000000 -0500
@@ -28,6 +28,7 @@
 #include <sys/proc.h>
 #include <sys/sx.h>
 #include <sys/mman.h>
+#include <sys/lockmgr.h>
 #include <fs/devfs/devfs.h>
 #include <sys/poll.h>
 
@@ -153,7 +154,7 @@
     return 0;
 
   wq->flags = 0;
-  flag = msleep (wq, *mutex, PRIBIO | PCATCH, "oss", ticks);
+  flag = msleep_spin (wq, *mutex, "oss", ticks);
 
   if (flag == EWOULDBLOCK)	/* Timeout */
     {
