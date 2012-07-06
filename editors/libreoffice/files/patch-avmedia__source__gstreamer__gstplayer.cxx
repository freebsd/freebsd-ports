--- avmedia/source/gstreamer/gstplayer.cxx.orig	2012-07-05 18:26:32.000000000 -0300
+++ avmedia/source/gstreamer/gstplayer.cxx	2012-07-05 18:15:27.000000000 -0300
@@ -380,7 +380,7 @@
         if( !isPlaying() )
             gst_element_set_state( mpPlaybin, GST_STATE_PAUSED );
 
-        DBG( "seek to: %"SAL_PRIdINT64" ns original: %lf s", gst_position, fTime );
+        DBG( "seek to: %" SAL_PRIdINT64 " ns original: %lf s", gst_position, fTime );
     }
 }
 
