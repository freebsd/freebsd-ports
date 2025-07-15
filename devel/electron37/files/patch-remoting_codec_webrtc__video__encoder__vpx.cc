--- remoting/codec/webrtc_video_encoder_vpx.cc.orig	2025-03-24 20:50:14 UTC
+++ remoting/codec/webrtc_video_encoder_vpx.cc
@@ -92,7 +92,7 @@ void SetVp8CodecParameters(vpx_codec_enc_cfg_t* config
                            const webrtc::DesktopSize& size) {
   SetCommonCodecParameters(config, size);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // On Linux, using too many threads for VP8 encoding has been linked to high
   // CPU usage on machines that are under stress. See http://crbug.com/1151148.
   // 5/3/2022 update: Perf testing has shown that doubling the number of threads
