--- src/audio/sound-manager.c.orig	Sat Jan 17 15:26:09 2004
+++ src/audio/sound-manager.c	Sat Jan 17 15:26:16 2004
@@ -145,7 +145,7 @@
     
     g_object_set( G_OBJECT( PRIVATE(m)->filesrc), "location",path,NULL);
     
-    gst_element_link_many( PRIVATE(m)->filesrc, PRIVATE(m)->vorbis_dec, PRIVATE(m)->output);
+    gst_element_link_many( PRIVATE(m)->filesrc, PRIVATE(m)->vorbis_dec, PRIVATE(m)->output, NULL);
     
     
     PRIVATE(m)->is_playing = TRUE;
