--- audioplayer.c.orig	Thu Apr 29 11:31:57 2004
+++ audioplayer.c	Wed Jul 28 06:38:45 2004
@@ -62,8 +62,10 @@
 
 static void cb_iterate(GstBin *bin, gpointer data)
 {
-    GstClock *clock = gst_bin_get_clock(bin);
-    int seconds = gst_clock_get_time(clock) / GST_SECOND;
+    GstClock *clock;
+    int seconds;
+    clock = gst_bin_get_clock(bin);
+    seconds = gst_clock_get_time(clock) / GST_SECOND; 
 
     seconds = seconds - songstarted;
 
@@ -80,8 +82,10 @@
     gst_init(0, NULL);
 
     pipeline_thread = gst_thread_new ("pipeline");
+#if 0
     gst_bin_set_post_iterate_function(GST_BIN(pipeline_thread),
                                       cb_iterate, NULL);
+#endif
     pipesrc = gst_element_factory_make ("fdsrc", "pipe_source");
     if (!pipesrc)
     {
@@ -136,11 +140,12 @@
 
 void audioplayer_playpipe(int fd)
 {
+    GstClock *clock;
     playing = 1;
     audioplayer_loadpipe(fd);
 
     gst_element_set_state (GST_ELEMENT (pipeline_thread), GST_STATE_PLAYING);
-    GstClock *clock = gst_bin_get_clock(GST_BIN(pipeline_thread));
+    clock = gst_bin_get_clock(GST_BIN(pipeline_thread));
     songstarted = gst_clock_get_time(clock) / GST_SECOND;
 }
 
