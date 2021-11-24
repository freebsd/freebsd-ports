--- cc/test/pixel_test.cc.orig	2021-07-15 19:13:30 UTC
+++ cc/test/pixel_test.cc
@@ -71,7 +71,7 @@ PixelTest::PixelTest(GraphicsBackend backend)
     init_vulkan = true;
   } else if (backend == kSkiaDawn) {
     scoped_feature_list_.InitAndEnableFeature(features::kSkiaDawn);
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
     init_vulkan = true;
 #elif defined(OS_WIN)
     // TODO(sgilhuly): Initialize D3D12 for Windows.
