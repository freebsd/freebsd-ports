--- media/webrtc/helpers.cc.orig	2023-02-01 18:43:22 UTC
+++ media/webrtc/helpers.cc
@@ -40,7 +40,7 @@ void ConfigAutomaticGainControl(const AudioProcessingS
     apm_config.gain_controller2.enabled = false;
     return;
   }
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Use the Hybrid AGC setup, which combines the AGC1 input volume controller
   // and the AGC2 digital adaptive controller.
 
