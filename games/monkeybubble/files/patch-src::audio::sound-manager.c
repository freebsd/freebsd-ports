--- src/audio/sound-manager.c.orig	Tue Aug 24 22:53:40 2004
+++ src/audio/sound-manager.c	Tue Aug 24 22:54:13 2004
@@ -193,6 +193,8 @@
 		 GObject *new_pad,
 		 SoundManager * m)
 {
+    
+    GstPad * pad;
    
     gst_element_set_state (PRIVATE(m)->main_bin, GST_STATE_PAUSED);
 
@@ -209,7 +211,7 @@
 		     PRIVATE(m)->output,
 			NULL);
   
-  GstPad * pad = gst_element_get_pad( GST_ELEMENT(PRIVATE(m)->vorbis_dec),"sink");
+  pad = gst_element_get_pad( GST_ELEMENT(PRIVATE(m)->vorbis_dec),"sink");
 
   gst_pad_link( GST_PAD(new_pad), pad);
   PRIVATE(m)->new_pad_ok = TRUE;
