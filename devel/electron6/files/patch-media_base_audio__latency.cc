--- media/base/audio_latency.cc.orig	2019-09-10 10:42:39 UTC
+++ media/base/audio_latency.cc
@@ -106,7 +106,7 @@ int AudioLatency::GetRtcBufferSize(int sample_rate, in
     return frames_per_buffer;
   }
 
-#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_FUCHSIA)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_FUCHSIA) || defined(OS_BSD)
   // On Linux, MacOS and Fuchsia, the low level IO implementations on the
   // browser side supports all buffer size the clients want. We use the native
   // peer connection buffer size (10ms) to achieve best possible performance.
