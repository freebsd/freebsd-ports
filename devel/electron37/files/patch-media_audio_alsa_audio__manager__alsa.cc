--- media/audio/alsa/audio_manager_alsa.cc.orig	2025-06-30 07:04:30 UTC
+++ media/audio/alsa/audio_manager_alsa.cc
@@ -106,7 +106,9 @@ void AudioManagerAlsa::GetAlsaAudioDevices(StreamType 
   int card = -1;
 
   // Loop through the physical sound cards to get ALSA device hints.
+#if !BUILDFLAG(IS_BSD) 
   while (!wrapper_->CardNext(&card) && card >= 0) {
+#endif
     void** hints = nullptr;
     int error = wrapper_->DeviceNameHint(card, kPcmInterfaceName, &hints);
     if (!error) {
@@ -118,7 +120,9 @@ void AudioManagerAlsa::GetAlsaAudioDevices(StreamType 
       DLOG(WARNING) << "GetAlsaAudioDevices: unable to get device hints: "
                     << wrapper_->StrError(error);
     }
+#if !BUILDFLAG(IS_BSD) 
   }
+#endif
 }
 
 void AudioManagerAlsa::GetAlsaDevicesInfo(AudioManagerAlsa::StreamType type,
@@ -202,7 +206,11 @@ bool AudioManagerAlsa::IsAlsaDeviceAvailable(
   // goes through software conversion if needed (e.g. incompatible
   // sample rate).
   // TODO(joi): Should we prefer "hw" instead?
+#if BUILDFLAG(IS_BSD)
+  static const char kDeviceTypeDesired[] = "plug";
+#else
   static const char kDeviceTypeDesired[] = "plughw";
+#endif
   return strncmp(kDeviceTypeDesired, device_name,
                  std::size(kDeviceTypeDesired) - 1) == 0;
 }
@@ -254,7 +262,9 @@ bool AudioManagerAlsa::HasAnyAlsaAudioDevice(
   // Loop through the sound cards.
   // Don't use snd_device_name_hint(-1,..) since there is an access violation
   // inside this ALSA API with libasound.so.2.0.0.
+#if !BUILDFLAG(IS_BSD)
   while (!wrapper_->CardNext(&card) && (card >= 0) && !has_device) {
+#endif
     int error = wrapper_->DeviceNameHint(card, kPcmInterfaceName, &hints);
     if (!error) {
       for (void** hint_iter = hints; *hint_iter != nullptr; hint_iter++) {
@@ -279,7 +289,9 @@ bool AudioManagerAlsa::HasAnyAlsaAudioDevice(
       DLOG(WARNING) << "HasAnyAudioDevice: unable to get device hints: "
                     << wrapper_->StrError(error);
     }
+#if !BUILDFLAG(IS_BSD)
   }
+#endif
 
   return has_device;
 }
