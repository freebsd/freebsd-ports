--- modules/media/src/main/native/jfxmedia/platform/gstreamer/GstPipelineFactory.cpp.orig	2017-09-08 16:56:55 UTC
+++ modules/media/src/main/native/jfxmedia/platform/gstreamer/GstPipelineFactory.cpp
@@ -351,6 +351,8 @@ GstElement* CGstPipelineFactory::CreateAudioSinkElemen
     return CreateElement("directsoundsink");
 #elif  TARGET_OS_MAC
     return CreateElement("osxaudiosink");
+#elif TARGET_OS_BSD
+    return CreateElement("bsdaudiosink");
 #elif  TARGET_OS_LINUX
     return CreateElement("alsasink");
 #else
