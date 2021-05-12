--- third_party/blink/renderer/modules/mediastream/processed_local_audio_source.cc.orig	2021-04-14 01:08:56 UTC
+++ third_party/blink/renderer/modules/mediastream/processed_local_audio_source.cc
@@ -409,7 +409,7 @@ void ProcessedLocalAudioSource::CaptureUsingProcessor(
     bool key_pressed) {
 #if defined(OS_WIN) || defined(OS_MAC)
   DCHECK_LE(volume, 1.0);
-#elif defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_OPENBSD)
+#elif defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_OPENBSD) || defined(OS_BSD)
   // We have a special situation on Linux where the microphone volume can be
   // "higher than maximum". The input volume slider in the sound preference
   // allows the user to set a scaling that is higher than 100%. It means that
