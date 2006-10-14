--- glib/gtimer.c.orig	Sun Oct  1 01:51:15 2006
+++ glib/gtimer.c	Tue Oct  3 17:00:39 2006
@@ -257,7 +257,7 @@
 
   if (microseconds)
     *microseconds = (elapsed / 10) % 1000000;
-#elif HAVE_CLOCK_GETTIME
+#elif USE_CLOCK_GETTIME
   if (timer->active)
     GETTIME (timer->end);
 
