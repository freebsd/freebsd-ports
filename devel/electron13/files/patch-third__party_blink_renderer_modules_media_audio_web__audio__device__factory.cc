--- third_party/blink/renderer/modules/media/audio/web_audio_device_factory.cc.orig	2021-04-14 01:08:56 UTC
+++ third_party/blink/renderer/modules/media/audio/web_audio_device_factory.cc
@@ -33,7 +33,7 @@ WebAudioDeviceFactory* WebAudioDeviceFactory::factory_
 
 namespace {
 
-#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD) || \
     BUILDFLAG(IS_CHROMEOS_LACROS)
 // Due to driver deadlock issues on Windows (http://crbug/422522) there is a
 // chance device authorization response is never received from the browser side.
