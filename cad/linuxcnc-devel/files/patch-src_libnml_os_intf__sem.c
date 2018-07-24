--- src/libnml/os_intf/_sem.c.orig	2018-07-07 04:16:26.398676000 +0100
+++ src/libnml/os_intf/_sem.c	2018-07-07 04:16:54.402946000 +0100
@@ -30,6 +30,9 @@
    on Linux System V semaphores will be used instead.
 */
 
+#ifdef	__FreeBSD__
+#define _WANT_SEMUN
+#endif
 #include <sys/sem.h>		/* struct sembuf */
 #include <math.h>		/* fmod() */
 #include <signal.h>
