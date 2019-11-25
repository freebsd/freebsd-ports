--- media/audio/audio_input_device.cc.orig	2019-09-10 11:14:07 UTC
+++ media/audio/audio_input_device.cc
@@ -248,7 +248,7 @@ void AudioInputDevice::OnStreamCreated(
 // also a risk of false positives if we are suspending when starting the stream
 // here. See comments in AliveChecker and PowerObserverHelper for details and
 // todos.
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   const bool stop_at_first_alive_notification = true;
   const bool pause_check_during_suspend = false;
 #else
