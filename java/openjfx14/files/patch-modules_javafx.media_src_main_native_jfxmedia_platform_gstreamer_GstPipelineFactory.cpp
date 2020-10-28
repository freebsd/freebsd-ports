--- modules/javafx.media/src/main/native/jfxmedia/platform/gstreamer/GstPipelineFactory.cpp.orig	2020-07-17 10:21:33 UTC
+++ modules/javafx.media/src/main/native/jfxmedia/platform/gstreamer/GstPipelineFactory.cpp
@@ -338,6 +338,8 @@ GstElement* CGstPipelineFactory::CreateAudioSinkElemen
     return CreateElement("directsoundsink");
 #elif  TARGET_OS_MAC
     return CreateElement("osxaudiosink");
+#elif TARGET_OS_BSD
+    return CreateElement("bsdaudiosink");
 #elif  TARGET_OS_LINUX
     return CreateElement("alsasink");
 #else
