--- unix/general.c.orig	2015-06-24 00:31:32 UTC
+++ unix/general.c
@@ -319,7 +319,7 @@ int delaytime;
     static struct timeval delay;
     delay.tv_sec = delaytime/1000;
     delay.tv_usec = (delaytime%1000)*1000;
-#if defined( __SVR4) || defined(LINUX)
+#if defined( __SVR4) || defined(LINUX) || defined(__FreeBSD__)
     (void) select(0, (fd_set *) 0, (fd_set *) 0, (fd_set *) 0, &delay);
 #else
     (void) select(0, (int *) 0, (int *) 0, (int *) 0, &delay);
