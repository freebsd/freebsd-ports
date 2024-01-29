--- ui/base/test/skia_gold_pixel_diff.cc.orig	2023-10-19 19:59:21 UTC
+++ ui/base/test/skia_gold_pixel_diff.cc
@@ -115,7 +115,7 @@ const char* GetPlatformName() {
   return "macOS";
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return "linux";
 #elif BUILDFLAG(IS_CHROMEOS_LACROS)
   return "lacros";
