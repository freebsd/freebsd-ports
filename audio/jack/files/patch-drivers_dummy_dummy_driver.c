--- drivers/dummy/dummy_driver.c.orig	Sun Dec 10 16:31:55 2006
+++ drivers/dummy/dummy_driver.c	Sun Dec 10 16:32:27 2006
@@ -41,10 +41,11 @@
 /* this is used for calculate what counts as an xrun */
 #define PRETEND_BUFFER_SIZE 4096
 
+#define VIDEO_SYNC_PERIOD 48000 / 30
+
 void
 FakeVideoSync( dummy_driver_t *driver )
 {
-        static const int VIDEO_SYNC_PERIOD = 48000 / 30;
         static int vidCounter = VIDEO_SYNC_PERIOD;
         
         int period = driver->period_size;
