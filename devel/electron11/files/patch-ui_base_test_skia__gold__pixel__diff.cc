--- ui/base/test/skia_gold_pixel_diff.cc.orig	2021-01-07 00:37:26 UTC
+++ ui/base/test/skia_gold_pixel_diff.cc
@@ -127,7 +127,7 @@ std::string SkiaGoldPixelDiff::GetPlatform() {
   return "windows";
 #elif defined(OS_APPLE)
   return "macOS";
-#elif defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#elif (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   return "linux";
 #endif
 }
