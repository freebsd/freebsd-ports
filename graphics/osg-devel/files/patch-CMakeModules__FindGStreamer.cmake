--- CMakeModules/FindGStreamer.cmake.orig	2014-12-18 12:03:15.000000000 +0300
+++ CMakeModules/FindGStreamer.cmake	2015-01-24 21:36:08.000000000 +0300
@@ -104,7 +104,7 @@
 
 # 1.1. Find headers and libraries
 FIND_GSTREAMER_COMPONENT(GSTREAMER gstreamer-1.0 gst/gst.h gstreamer-1.0)
-#FIND_GSTREAMER_COMPONENT(GSTREAMER_BASE gstreamer-base-1.0 gst/gst.h gstbase-1.0)
+FIND_GSTREAMER_COMPONENT(GSTREAMER_BASE gstreamer-base-1.0 gst/gst.h gstbase-1.0)
 
 
 # 1.2. Check GStreamer version
