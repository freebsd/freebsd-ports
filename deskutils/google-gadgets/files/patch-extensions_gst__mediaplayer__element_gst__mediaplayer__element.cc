
$FreeBSD$

--- extensions/gst_mediaplayer_element/gst_mediaplayer_element.cc.orig
+++ extensions/gst_mediaplayer_element/gst_mediaplayer_element.cc
@@ -133,7 +133,7 @@
     return;
   } else {
     g_object_get(G_OBJECT(videosink_),
-                 "receive-image-handler", &receive_image_handler_, NULL);
+                 "receive-image-handler", &receive_image_handler_, (gchar*)0);
     if (!receive_image_handler_) {
       gst_object_unref(GST_OBJECT(playbin_));
       gst_object_unref(GST_OBJECT(videosink_));
@@ -143,7 +143,7 @@
   }
 
   // Set videosink to receive video output.
-  g_object_set(G_OBJECT(playbin_), "video-sink", videosink_, NULL);
+  g_object_set(G_OBJECT(playbin_), "video-sink", videosink_, (gchar*)0);
 
   // Create new audio sink with panorama support if possible.
   GstElement *audiosink = NULL;
@@ -169,15 +169,15 @@
     GstElement *audiobin = gst_bin_new("audiobin");
     GstPad *sinkpad;
     if (volume_ && panorama_) {
-      gst_bin_add_many(GST_BIN(audiobin), volume_, panorama_, audiosink, NULL);
-      gst_element_link_many(volume_, panorama_, audiosink, NULL);
+      gst_bin_add_many(GST_BIN(audiobin), volume_, panorama_, audiosink, (GstElement*)0);
+      gst_element_link_many(volume_, panorama_, audiosink, (GstElement*)0);
       sinkpad = gst_element_get_pad(volume_, "sink");
     } else if (volume_) {
-      gst_bin_add_many(GST_BIN(audiobin), volume_, audiosink, NULL);
+      gst_bin_add_many(GST_BIN(audiobin), volume_, audiosink, (GstElement*)0);
       gst_element_link(volume_, audiosink);
       sinkpad = gst_element_get_pad(volume_, "sink");
     } else {
-      gst_bin_add_many(GST_BIN(audiobin), panorama_, audiosink, NULL);
+      gst_bin_add_many(GST_BIN(audiobin), panorama_, audiosink, (GstElement*)0);
       gst_element_link(panorama_, audiosink);
       sinkpad = gst_element_get_pad(panorama_, "sink");
     }
@@ -187,7 +187,7 @@
   }
 
   // Set audio-sink to our new audiosink.
-  g_object_set(G_OBJECT(playbin_), "audio-sink", audiosink, NULL);
+  g_object_set(G_OBJECT(playbin_), "audio-sink", audiosink, (gchar*)0);
 
   // Watch the message bus.
   // The host using this class must use a g_main_loop to capture the
@@ -262,7 +262,7 @@
   if (src_.compare(new_src_) != 0) {
     src_ = new_src_;
     media_changed_ = true;
-    g_object_set(G_OBJECT(playbin_), "uri", src_.c_str(), NULL);
+    g_object_set(G_OBJECT(playbin_), "uri", src_.c_str(), (gchar*)0);
 
     // Empty the tag cache when loading a new media.
     if (tag_list_) {
@@ -370,7 +370,7 @@
 void GstMediaPlayerElement::SetGeometry(int width, int height) {
   if (playbin_ && videosink_) {
     g_object_set(G_OBJECT(videosink_),
-                 "geometry-width", width, "geometry-height", height, NULL);
+                 "geometry-width", width, "geometry-height", height, (gchar*)0);
   } else {
     if (!playbin_)
       DLOG("Playbin was not initialized correctly.");
@@ -382,7 +382,7 @@
 int GstMediaPlayerElement::GetVolume() {
   if (playbin_) {
     double volume;
-    g_object_get(G_OBJECT(playbin_), "volume", &volume, NULL);
+    g_object_get(G_OBJECT(playbin_), "volume", &volume, (gchar*)0);
     int gg_volume = static_cast<int>((volume / kMaxGstVolume) *
                                       (kMaxVolume - kMinVolume) +
                                       kMinVolume);
@@ -404,7 +404,7 @@
       (gdouble(volume - kMinVolume) / (kMaxVolume - kMinVolume)) *
       kMaxGstVolume;
 
-    g_object_set(G_OBJECT(playbin_), "volume", gst_volume, NULL);
+    g_object_set(G_OBJECT(playbin_), "volume", gst_volume, (gchar*)0);
   } else {
     DLOG("Playbin was not initialized correctly.");
   }
@@ -413,7 +413,7 @@
 int GstMediaPlayerElement::GetBalance() {
   if (playbin_ && panorama_) {
     gfloat balance;
-    g_object_get(G_OBJECT(panorama_), "panorama", &balance, NULL);
+    g_object_get(G_OBJECT(panorama_), "panorama", &balance, (gchar*)0);
     int gg_balance = static_cast<int>(((balance + 1) / 2) *
                                       (kMaxBalance - kMinBalance) +
                                       kMinBalance);
@@ -437,7 +437,7 @@
     }
     gfloat gst_balance =
       (gfloat(balance - kMinBalance) / (kMaxBalance - kMinBalance)) * 2 - 1;
-    g_object_set(G_OBJECT(panorama_), "panorama", gst_balance, NULL);
+    g_object_set(G_OBJECT(panorama_), "panorama", gst_balance, (gchar*)0);
   } else {
     if (!playbin_)
       DLOG("Playbin was not initialized correctly.");
@@ -449,7 +449,7 @@
 bool GstMediaPlayerElement::GetMute() {
   if (playbin_ && volume_) {
     gboolean mute;
-    g_object_get(G_OBJECT(volume_), "mute", &mute, NULL);
+    g_object_get(G_OBJECT(volume_), "mute", &mute, (gchar*)0);
     return static_cast<bool>(mute);
   } else {
     if (!playbin_)
@@ -462,7 +462,7 @@
 
 void GstMediaPlayerElement::SetMute(bool mute) {
   if (playbin_ && volume_) {
-    g_object_set(G_OBJECT(volume_), "mute", static_cast<gboolean>(mute), NULL);
+    g_object_set(G_OBJECT(volume_), "mute", static_cast<gboolean>(mute), (gchar*)0);
   } else {
     if (!playbin_)
       DLOG("Playbin was not initialized correctly.");
