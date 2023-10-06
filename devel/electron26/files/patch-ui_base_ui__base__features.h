--- ui/base/ui_base_features.h.orig	2023-08-10 01:49:09 UTC
+++ ui/base/ui_base_features.h
@@ -234,7 +234,7 @@ enum class ChromeRefresh2023Level {
 COMPONENT_EXPORT(UI_BASE_FEATURES)
 ChromeRefresh2023Level GetChromeRefresh2023Level();
 
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
 COMPONENT_EXPORT(UI_BASE_FEATURES) BASE_DECLARE_FEATURE(kWebUiSystemFont);
 #endif
 
