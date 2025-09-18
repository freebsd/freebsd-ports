--- media/video/video_encode_accelerator_adapter_test.cc.orig	2025-03-24 20:50:14 UTC
+++ media/video/video_encode_accelerator_adapter_test.cc
@@ -260,7 +260,7 @@ TEST_F(VideoEncodeAcceleratorAdapterTest, InitializeAf
       });
 
   VideoPixelFormat expected_input_format = PIXEL_FORMAT_I420;
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   expected_input_format = PIXEL_FORMAT_NV12;
 #endif
   vea()->SetEncodingCallback(base::BindLambdaForTesting(
@@ -369,7 +369,7 @@ TEST_F(VideoEncodeAcceleratorAdapterTest, FlushDuringI
       });
 
   VideoPixelFormat expected_input_format = PIXEL_FORMAT_I420;
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   expected_input_format = PIXEL_FORMAT_NV12;
 #endif
 
@@ -467,7 +467,7 @@ TEST_P(VideoEncodeAcceleratorAdapterTest, TwoFramesRes
       CreateGreenFrame(large_size, pixel_format, base::Milliseconds(2));
 
   VideoPixelFormat expected_input_format = PIXEL_FORMAT_I420;
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     expected_input_format = PIXEL_FORMAT_NV12;
 #endif
   const gfx::ColorSpace expected_color_space =
@@ -674,7 +674,7 @@ TEST_F(VideoEncodeAcceleratorAdapterTest,
       });
 
   VideoPixelFormat expected_input_format = PIXEL_FORMAT_I420;
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   expected_input_format = PIXEL_FORMAT_NV12;
 #endif
   vea()->SetEncodingCallback(base::BindLambdaForTesting(
