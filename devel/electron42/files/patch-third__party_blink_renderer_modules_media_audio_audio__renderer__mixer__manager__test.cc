--- third_party/blink/renderer/modules/media/audio/audio_renderer_mixer_manager_test.cc.orig	2025-04-22 20:15:27 UTC
+++ third_party/blink/renderer/modules/media/audio/audio_renderer_mixer_manager_test.cc
@@ -857,7 +857,7 @@ TEST_F(AudioRendererMixerManagerTest, MixerParamsLaten
             mixer->get_output_params_for_testing().sample_rate());
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_APPLE) || \
-    BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
   // Use 10 ms buffer (441 frames per buffer).
   EXPECT_EQ(output_sample_rate / 100,
             mixer->get_output_params_for_testing().frames_per_buffer());
