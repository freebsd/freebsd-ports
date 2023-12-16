--- media/webrtc/helpers_unittests.cc.orig	2023-02-01 18:43:22 UTC
+++ media/webrtc/helpers_unittests.cc
@@ -39,7 +39,7 @@ TEST(CreateWebRtcAudioProcessingModuleTest, CheckDefau
   EXPECT_FALSE(config.pre_amplifier.enabled);
   EXPECT_TRUE(config.echo_canceller.enabled);
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   EXPECT_TRUE(config.gain_controller1.enabled);
   EXPECT_TRUE(config.gain_controller2.enabled);
 #elif BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
@@ -77,7 +77,7 @@ TEST(CreateWebRtcAudioProcessingModuleTest,
   EXPECT_EQ(config.gain_controller2, kDefaultApmConfig.gain_controller2);
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 TEST(CreateWebRtcAudioProcessingModuleTest,
      InputVolumeAdjustmentEnabledWithHybridAgc) {
   ::base::test::ScopedFeatureList feature_list;
@@ -103,7 +103,7 @@ TEST(CreateWebRtcAudioProcessingModuleTest,
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 TEST(CreateWebRtcAudioProcessingModuleTest,
      OnlyOneInputVolumeControllerEnabledOnDesktopPlatforms) {
   auto config = CreateApmGetConfig(
