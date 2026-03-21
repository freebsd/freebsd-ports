--- third_party/webrtc/modules/video_capture/linux/pipewire_session.cc.orig	2025-08-25 14:15:51 UTC
+++ third_party/webrtc/modules/video_capture/linux/pipewire_session.cc
@@ -14,6 +14,7 @@
 #include <spa/param/format-utils.h>
 #include <spa/param/format.h>
 #include <spa/param/video/raw.h>
+#include <spa/pod/iter.h>
 #include <spa/pod/parser.h>
 
 #include <algorithm>
