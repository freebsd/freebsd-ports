--- audioplayer.c.orig	Mon Dec 20 03:03:55 2004
+++ audioplayer.c	Wed Feb  2 21:42:19 2005
@@ -106,7 +106,8 @@
 
 static void async_cmd_cb_gst_setup_clock(__UNUSED__ void *data)
 {
-    GstClock *clock = gst_bin_get_clock(GST_BIN(pipeline_thread));
+    GstClock *clock;
+    clock = gst_bin_get_clock(GST_BIN(pipeline_thread));
     songstarted = gst_clock_get_time(clock) / GST_SECOND;
 }
 
@@ -157,8 +158,10 @@
 
 static void cb_iterate(GstBin *bin, __UNUSED__ gpointer data)
 {
-    GstClock *clock = gst_bin_get_clock(bin);
-    int seconds = gst_clock_get_time(clock) / GST_SECOND;
+    GstClock *clock;
+    int seconds;
+    clock = gst_bin_get_clock(bin);
+    seconds = gst_clock_get_time(clock) / GST_SECOND; 
 
     seconds = seconds - songstarted;
 
