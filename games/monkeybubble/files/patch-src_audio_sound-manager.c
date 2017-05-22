--- src/audio/sound-manager.c.orig	2017-05-09 13:02:38 UTC
+++ src/audio/sound-manager.c
@@ -223,7 +223,7 @@ start_play(SoundManager *m, gchar * path) 
     PRIVATE(m)->vorbis_dec = gst_element_factory_make("vorbisdec","vorbisdec");
     PRIVATE(m)->audioconvert = gst_element_factory_make("audioconvert","audioconvert");
     PRIVATE(m)->audioscale = gst_element_factory_make("audioscale", "audioscale");
-    PRIVATE(m)->output =  gst_element_factory_make("alsasink", "alsa-output");
+    PRIVATE(m)->output =  gst_element_factory_make("autoaudiosink", "autoaudiosink");
 
     PRIVATE(m)->current_music_path = g_strdup(path);
 
