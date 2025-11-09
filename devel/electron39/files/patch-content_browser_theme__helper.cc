--- content/browser/theme_helper.cc.orig	2025-10-21 20:19:54 UTC
+++ content/browser/theme_helper.cc
@@ -27,7 +27,7 @@ mojom::UpdateSystemColorInfoParamsPtr MakeUpdateSystem
     ui::NativeTheme* native_theme) {
   mojom::UpdateSystemColorInfoParamsPtr params =
       mojom::UpdateSystemColorInfoParams::New();
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   params->accent_color = native_theme->user_color();
 #endif
 
