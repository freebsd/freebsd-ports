--- drivers/dummy/dummy_driver.h.orig	2013-10-04 00:45:25 UTC
+++ drivers/dummy/dummy_driver.h
@@ -44,7 +44,7 @@ struct _dummy_driver
     jack_nframes_t  period_size;
     unsigned long   wait_time;
 
-#ifdef HAVE_CLOCK_GETTIME
+#if HAVE_CLOCK_GETTIME
     struct timespec next_wakeup;
 #else
     jack_time_t     next_time;
