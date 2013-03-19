--- avmedia/source/gstreamer/gstplayer.hxx.ORIG	2013-03-09 04:35:46.000000000 +0000
+++ avmedia/source/gstreamer/gstplayer.hxx	2013-03-09 11:57:13.000000000 +0000
@@ -28,7 +28,7 @@
 
 #include "gstcommon.hxx"
 #include <glib.h>
-#include <glib/gatomic.h>
+//#include <glib/gatomic.h>
 
 // necessary for mixed environments with GStreamer-0.10 and GLib versions < 2.8
 #ifndef G_GNUC_NULL_TERMINATED
