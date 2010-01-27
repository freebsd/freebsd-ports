--- ./unix/general.c.orig	2008-04-11 10:36:28.000000000 -0400
+++ ./unix/general.c	2010-01-27 13:52:46.000000000 -0500
@@ -317,7 +317,7 @@
     static struct timeval delay;
     delay.tv_sec = delaytime/1000;
     delay.tv_usec = (delaytime%1000)*1000;
-#if defined( __SVR4) || defined(LINUX)
+#if defined( __SVR4) || defined(LINUX) || defined(__FreeBSD__)
     (void) select(0, (fd_set *) 0, (fd_set *) 0, (fd_set *) 0, &delay);
 #else
     (void) select(0, (int *) 0, (int *) 0, (int *) 0, &delay);
