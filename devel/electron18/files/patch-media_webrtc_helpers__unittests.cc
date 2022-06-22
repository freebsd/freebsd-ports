--- media/webrtc/helpers_unittests.cc.orig	2022-05-19 05:17:44 UTC
+++ media/webrtc/helpers_unittests.cc
@@ -36,7 +36,7 @@ TEST(CreateWebRtcAudioProcessingModuleTest, CheckDefau
   EXPECT_FALSE(config.pre_amplifier.enabled);
   EXPECT_TRUE(config.echo_canceller.enabled);
   EXPECT_TRUE(config.gain_controller1.enabled);
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   EXPECT_TRUE(config.gain_controller2.enabled);
 #else
   EXPECT_FALSE(config.gain_controller2.enabled);
@@ -94,7 +94,7 @@ TEST(CreateWebRtcAudioProcessingModuleTest, CheckDefau
 
   // Check that either AGC1 digital or AGC2 digital is used based on the
   // platforms where the Hybrid AGC is enabled by default.
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   EXPECT_FALSE(agc1_analog_config.enable_digital_adaptive);
   EXPECT_TRUE(config.gain_controller2.enabled);
   EXPECT_TRUE(config.gain_controller2.adaptive_digital.enabled);
