--- ui/base/test/skia_gold_pixel_diff.cc.orig	2022-07-22 17:30:31 UTC
+++ ui/base/test/skia_gold_pixel_diff.cc
@@ -150,7 +150,7 @@ std::string SkiaGoldPixelDiff::GetPlatform() {
   return "macOS";
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return "linux";
 #elif BUILDFLAG(IS_CHROMEOS_LACROS)
   return "lacros";
