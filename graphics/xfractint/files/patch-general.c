--- general.c.orig	Mon Sep  3 18:45:31 2007
+++ general.c	Mon Sep  3 18:46:25 2007
@@ -314,7 +314,7 @@
     static struct timeval delay;
     delay.tv_sec = delaytime/1000;
     delay.tv_usec = (delaytime%1000)*1000;
-#if defined( __SVR4) || defined(LINUX)
+#if defined( __SVR4) || defined(LINUX) || defined(__FreeBSD__)
     (void) select(0, (fd_set *) 0, (fd_set *) 0, (fd_set *) 0, &delay);
 #else
     (void) select(0, (int *) 0, (int *) 0, (int *) 0, &delay);
