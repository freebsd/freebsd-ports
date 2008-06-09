
$FreeBSD$

--- extensions/gst_audio_framework/gst_audio_framework.cc.orig
+++ extensions/gst_audio_framework/gst_audio_framework.cc
@@ -91,7 +91,7 @@
     }
 
     // Use fakesink as video-sink to discard the video output.
-    g_object_set(G_OBJECT(playbin_), "video-sink", videosink, NULL);
+    g_object_set(G_OBJECT(playbin_), "video-sink", videosink, (gchar*)0);
 
     // Create new audio sink with panorama support if possible.
     GstElement *audiosink = NULL;
@@ -114,7 +114,7 @@
     // panorama support.
     if (panorama_) {
       GstElement *audiobin = gst_bin_new("audiobin");
-      gst_bin_add_many(GST_BIN(audiobin), panorama_, audiosink, NULL);
+      gst_bin_add_many(GST_BIN(audiobin), panorama_, audiosink, (GstElement*)0);
       gst_element_link(panorama_, audiosink);
       GstPad *sinkpad = gst_element_get_pad(panorama_, "sink");
       gst_element_add_pad(audiobin, gst_ghost_pad_new("sink", sinkpad));
@@ -123,7 +123,7 @@
     }
 
     // Set audio-sink to our new audiosink.
-    g_object_set(G_OBJECT(playbin_), "audio-sink", audiosink, NULL);
+    g_object_set(G_OBJECT(playbin_), "audio-sink", audiosink, (gchar*)0);
 
     // Watch the message bus.
     // The host using this class must use a g_main_loop to capture the
@@ -153,7 +153,7 @@
   virtual int GetBalance() const {
     if (playbin_ && panorama_) {
       gfloat balance;
-      g_object_get(G_OBJECT(panorama_), "panorama", &balance, NULL);
+      g_object_get(G_OBJECT(panorama_), "panorama", &balance, (gchar*)0);
       int gg_balance = static_cast<int>(((balance + 1) / 2) *
                                         (kMaxBalance - kMinBalance) +
                                         kMinBalance);
@@ -177,7 +177,7 @@
       }
       gfloat gst_balance =
         (gfloat(balance - kMinBalance) / (kMaxBalance - kMinBalance)) * 2 - 1;
-      g_object_set(G_OBJECT(panorama_), "panorama", gst_balance, NULL);
+      g_object_set(G_OBJECT(panorama_), "panorama", gst_balance, (gchar*)0);
     } else {
       if (!playbin_)
         DLOG("Playbin was not initialized correctly.");
@@ -237,7 +237,7 @@
       // FIXME:
       // Playbin won't produce ERROR whether it's a bad uri or the file's
       // format is not supported. We must check here.
-      g_object_set(G_OBJECT(playbin_), "uri", src, NULL);
+      g_object_set(G_OBJECT(playbin_), "uri", src, (gchar*)0);
     } else {
       if (!playbin_)
         DLOG("Playbin was not initialized correctly.");
@@ -253,7 +253,7 @@
   virtual int GetVolume() const {
     if (playbin_) {
       double volume;
-      g_object_get(G_OBJECT(playbin_), "volume", &volume, NULL);
+      g_object_get(G_OBJECT(playbin_), "volume", &volume, (gchar*)0);
       int gg_volume = static_cast<int>((volume / kMaxGstVolume) *
                                         (kMaxVolume - kMinVolume) +
                                         kMinVolume);
@@ -275,7 +275,7 @@
         (gdouble(volume - kMinVolume) / (kMaxVolume - kMinVolume)) *
         kMaxGstVolume;
 
-      g_object_set(G_OBJECT(playbin_), "volume", gst_volume, NULL);
+      g_object_set(G_OBJECT(playbin_), "volume", gst_volume, (gchar*)0);
     } else {
       DLOG("Playbin was not initialized correctly.");
     }
