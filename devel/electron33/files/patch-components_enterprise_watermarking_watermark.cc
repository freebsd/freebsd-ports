--- components/enterprise/watermarking/watermark.cc.orig	2024-10-16 21:31:10 UTC
+++ components/enterprise/watermarking/watermark.cc
@@ -34,7 +34,7 @@ gfx::Font WatermarkFont() {
       "Segoe UI",
 #elif BUILDFLAG(IS_MAC)
       "SF Pro Text",
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       "Ubuntu",
 #elif BUILDFLAG(IS_CHROMEOS)
       "Google Sans",
@@ -45,7 +45,7 @@ gfx::Font::Weight WatermarkFontWeight() {
 }
 
 gfx::Font::Weight WatermarkFontWeight() {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return gfx::Font::Weight::SEMIBOLD;
 #else
   return gfx::Font::Weight::MEDIUM;
