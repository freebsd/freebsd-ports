--- drivers/rtaudio/RtAudio.cpp.orig	2016-08-09 07:52:15 UTC
+++ drivers/rtaudio/RtAudio.cpp
@@ -8589,6 +8589,12 @@ bool RtApiPulse::probeDeviceOpen( unsign
 #include <errno.h>
 #include <math.h>
 
+#if defined(__FreeBSD__)
+#define SND_DEVICE "/dev/dsp"
+#else
+#define SND_DEVICE "/dev/mixer"
+#endif
+
 static void *ossCallbackHandler(void * ptr);
 
 // A structure to hold various information related to the OSS API
@@ -8615,9 +8621,11 @@ RtApiOss :: ~RtApiOss()
 
 unsigned int RtApiOss :: getDeviceCount( void )
 {
-  int mixerfd = open( "/dev/mixer", O_RDWR, 0 );
+  int mixerfd = open( SND_DEVICE, O_RDWR, 0 );
   if ( mixerfd == -1 ) {
-    errorText_ = "RtApiOss::getDeviceCount: error opening '/dev/mixer'.";
+    errorText_ = "RtApiOss::getDeviceCount: error opening '";
+    errorText_ += SND_DEVICE;
+    errorText_ += "'.";
     error( RtAudioError::WARNING );
     return 0;
   }
@@ -8639,9 +8647,11 @@ RtAudio::DeviceInfo RtApiOss :: getDevic
   RtAudio::DeviceInfo info;
   info.probed = false;
 
-  int mixerfd = open( "/dev/mixer", O_RDWR, 0 );
+  int mixerfd = open( SND_DEVICE, O_RDWR, 0 );
   if ( mixerfd == -1 ) {
-    errorText_ = "RtApiOss::getDeviceInfo: error opening '/dev/mixer'.";
+    errorText_ = "RtApiOss::getDeviceInfo: error opening '";
+    errorText_ += SND_DEVICE;
+    errorText_ += "'.";
     error( RtAudioError::WARNING );
     return info;
   }
@@ -8697,8 +8707,10 @@ RtAudio::DeviceInfo RtApiOss :: getDevic
     info.nativeFormats |= RTAUDIO_SINT8;
   if ( mask & AFMT_S32_LE || mask & AFMT_S32_BE )
     info.nativeFormats |= RTAUDIO_SINT32;
+#if defined(AFMT_FLOAT)
   if ( mask & AFMT_FLOAT )
     info.nativeFormats |= RTAUDIO_FLOAT32;
+#endif
   if ( mask & AFMT_S24_LE || mask & AFMT_S24_BE )
     info.nativeFormats |= RTAUDIO_SINT24;
 
@@ -8757,9 +8769,11 @@ bool RtApiOss :: probeDeviceOpen( unsign
                                   RtAudioFormat format, unsigned int *bufferSize,
                                   RtAudio::StreamOptions *options )
 {
-  int mixerfd = open( "/dev/mixer", O_RDWR, 0 );
+  int mixerfd = open( SND_DEVICE, O_RDWR, 0 );
   if ( mixerfd == -1 ) {
-    errorText_ = "RtApiOss::probeDeviceOpen: error opening '/dev/mixer'.";
+    errorText_ = "RtApiOss::probeDeviceOpen: error opening '";
+    errorText_ += SND_DEVICE;
+    errorText_ += "'.";
     return FAILURE;
   }
 
@@ -8787,7 +8801,11 @@ bool RtApiOss :: probeDeviceOpen( unsign
   }
 
   oss_audioinfo ainfo;
+#if defined(__FreeBSD__)
+  ainfo.dev = -1; // specify -1 to get default device
+#else
   ainfo.dev = device;
+#endif
   result = ioctl( mixerfd, SNDCTL_AUDIOINFO, &ainfo );
   close( mixerfd );
   if ( result == -1 ) {
@@ -9025,7 +9043,7 @@ bool RtApiOss :: probeDeviceOpen( unsign
   }
 
   // Verify the sample rate setup worked.
-  if ( abs( srate - sampleRate ) > 100 ) {
+  if ( abs( srate - (int)sampleRate ) > 100 ) {
     close( fd );
     errorStream_ << "RtApiOss::probeDeviceOpen: device (" << ainfo.name << ") does not support sample rate (" << sampleRate << ").";
     errorText_ = errorStream_.str();
