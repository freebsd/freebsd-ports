--- drivers/dummy/dummy_driver.h.orig	2009-02-12 05:04:38.000000000 +0100
+++ drivers/dummy/dummy_driver.h	2009-02-12 05:04:44.000000000 +0100
@@ -44,7 +44,7 @@
     jack_nframes_t  period_size;
     unsigned long   wait_time;
 
-#ifdef HAVE_CLOCK_GETTIME
+#if HAVE_CLOCK_GETTIME
     struct timespec next_wakeup;
 #else
     jack_time_t     next_time;
