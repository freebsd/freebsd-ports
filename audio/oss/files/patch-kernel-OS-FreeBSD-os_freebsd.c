--- kernel/OS/FreeBSD/os_freebsd.c.orig	2007-06-12 17:32:57.000000000 -0400
+++ kernel/OS/FreeBSD/os_freebsd.c	2007-07-11 20:41:43.000000000 -0400
@@ -145,7 +145,7 @@
     return 0;
 
   wq->flags = 0;
-  flag = msleep (wq, *mutex, PRIBIO | PCATCH, "oss", ticks);
+  flag = msleep_spin (wq, *mutex, "oss", ticks);
 
   if (flag == EWOULDBLOCK)	/* Timeout */
     {
