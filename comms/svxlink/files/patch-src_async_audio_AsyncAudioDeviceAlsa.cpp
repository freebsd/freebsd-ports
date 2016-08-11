--- src/async/audio/AsyncAudioDeviceAlsa.cpp.orig	2015-11-22 16:03:59 UTC
+++ src/async/audio/AsyncAudioDeviceAlsa.cpp
@@ -548,7 +548,7 @@ bool AudioDeviceAlsa::initParams(snd_pcm
     return false;
   }
 
-  if (::abs(real_rate - sample_rate) > 100)
+  if (::abs((int)real_rate - sample_rate) > 100)
   {
     cerr << "*** ERROR: The sample rate could not be set to "
          << sample_rate << "Hz for ALSA device \"" << dev_name << "\". "
