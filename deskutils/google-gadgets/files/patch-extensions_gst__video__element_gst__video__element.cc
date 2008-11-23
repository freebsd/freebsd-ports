
$FreeBSD$

--- extensions/gst_video_element/gst_video_element.cc.orig
+++ extensions/gst_video_element/gst_video_element.cc
@@ -125,7 +125,7 @@
     return;
   } else {
     g_object_get(G_OBJECT(videosink_),
-                 "receive-image-handler", &receive_image_handler_, NULL);
+                 "receive-image-handler", &receive_image_handler_, (gchar*)0);
     if (!receive_image_handler_) {
       gst_object_unref(GST_OBJECT(playbin_));
       gst_object_unref(GST_OBJECT(videosink_));
@@ -135,7 +135,7 @@
   }
 
   // Set videosink to receive video output.
-  g_object_set(G_OBJECT(playbin_), "video-sink", videosink_, NULL);
+  g_object_set(G_OBJECT(playbin_), "video-sink", videosink_, (gchar*)0);
 
   // Create new audio sink with panorama support if possible.
   GstElement *audiosink = NULL;
@@ -161,15 +161,15 @@
     GstElement *audiobin = gst_bin_new("audiobin");
     GstPad *sinkpad;
     if (volume_ && panorama_) {
-      gst_bin_add_many(GST_BIN(audiobin), volume_, panorama_, audiosink, NULL);
-      gst_element_link_many(volume_, panorama_, audiosink, NULL);
+      gst_bin_add_many(GST_BIN(audiobin), volume_, panorama_, audiosink, (gchar*)0);
+      gst_element_link_many(volume_, panorama_, audiosink, (gchar*)0);
       sinkpad = gst_element_get_pad(volume_, "sink");
     } else if (volume_) {
-      gst_bin_add_many(GST_BIN(audiobin), volume_, audiosink, NULL);
+      gst_bin_add_many(GST_BIN(audiobin), volume_, audiosink, (gchar*)0);
       gst_element_link(volume_, audiosink);
       sinkpad = gst_element_get_pad(volume_, "sink");
     } else {
-      gst_bin_add_many(GST_BIN(audiobin), panorama_, audiosink, NULL);
+      gst_bin_add_many(GST_BIN(audiobin), panorama_, audiosink, (gchar*)0);
       gst_element_link(panorama_, audiosink);
       sinkpad = gst_element_get_pad(panorama_, "sink");
     }
@@ -179,7 +179,7 @@
   }
 
   // Set audio-sink to our new audiosink.
-  g_object_set(G_OBJECT(playbin_), "audio-sink", audiosink, NULL);
+  g_object_set(G_OBJECT(playbin_), "audio-sink", audiosink, (gchar*)0);
 
   // Watch the message bus.
   // The host using this class must use a g_main_loop to capture the
@@ -357,14 +357,14 @@
 
     src_ = src;
     media_changed_ = true;
-    g_object_set(G_OBJECT(playbin_), "uri", src_.c_str(), NULL);
+    g_object_set(G_OBJECT(playbin_), "uri", src_.c_str(), (gchar*)0);
   }
 }
 
 int GstVideoElement::GetVolume() const {
   if (playbin_) {
     double volume;
-    g_object_get(G_OBJECT(playbin_), "volume", &volume, NULL);
+    g_object_get(G_OBJECT(playbin_), "volume", &volume, (gchar*)0);
     int gg_volume = static_cast<int>((volume / kMaxGstVolume) *
                                      (kMaxVolume - kMinVolume) + kMinVolume);
     return Clamp(gg_volume, kMinVolume, kMaxVolume);
@@ -381,7 +381,7 @@
     }
     gdouble gg_volume = ((gdouble(volume - kMinVolume) /
                           (kMaxVolume - kMinVolume)) * kMaxGstVolume);
-    g_object_set(G_OBJECT(playbin_), "volume", gg_volume, NULL);
+    g_object_set(G_OBJECT(playbin_), "volume", gg_volume, (gchar*)0);
   } else {
     DLOG("Playbin was not initialized correctly.");
   }
@@ -403,7 +403,7 @@
 int GstVideoElement::GetBalance() const {
   if (playbin_ && panorama_) {
     gfloat balance;
-    g_object_get(G_OBJECT(panorama_), "panorama", &balance, NULL);
+    g_object_get(G_OBJECT(panorama_), "panorama", &balance, (gchar*)0);
     int gg_balance = static_cast<int>(((balance + 1) / 2) *
                                       (kMaxBalance - kMinBalance) +
                                       kMinBalance);
@@ -426,7 +426,7 @@
     }
     gfloat gg_balance = (gfloat(balance - kMinBalance) /
                           (kMaxBalance - kMinBalance)) * 2 - 1;
-    g_object_set(G_OBJECT(panorama_), "panorama", gg_balance, NULL);
+    g_object_set(G_OBJECT(panorama_), "panorama", gg_balance, (gchar*)0);
   } else {
     if (!playbin_)
       DLOG("Playbin was not initialized correctly.");
@@ -438,7 +438,7 @@
 bool GstVideoElement::IsMute() const {
   if (playbin_ && volume_) {
     gboolean mute;
-    g_object_get(G_OBJECT(volume_), "mute", &mute, NULL);
+    g_object_get(G_OBJECT(volume_), "mute", &mute, (gchar*)0);
     return static_cast<bool>(mute);
   } else {
     if (!playbin_)
@@ -451,7 +451,7 @@
 
 void GstVideoElement::SetMute(bool mute) {
   if (playbin_ && volume_) {
-    g_object_set(G_OBJECT(volume_), "mute", static_cast<gboolean>(mute), NULL);
+    g_object_set(G_OBJECT(volume_), "mute", static_cast<gboolean>(mute), (gchar*)0);
   } else {
     if (!playbin_)
       DLOG("Playbin was not initialized correctly.");
@@ -464,7 +464,7 @@
   if (playbin_ && videosink_) {
     g_object_set(G_OBJECT(videosink_),
                  "geometry-width", static_cast<int>(width),
-                 "geometry-height", static_cast<int>(height), NULL);
+                 "geometry-height", static_cast<int>(height), (gchar*)0);
   } else {
     if (!playbin_)
       DLOG("Playbin was not initialized correctly.");
