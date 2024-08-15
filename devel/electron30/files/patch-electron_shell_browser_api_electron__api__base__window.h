--- electron/shell/browser/api/electron_api_base_window.h.orig	2024-07-15 11:51:18 UTC
+++ electron/shell/browser/api/electron_api_base_window.h
@@ -243,7 +243,7 @@ class BaseWindow : public gin_helper::TrackableObject<
   void SetAppDetails(const gin_helper::Dictionary& options);
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   void SetTitleBarOverlay(const gin_helper::Dictionary& options,
                           gin_helper::Arguments* args);
 #endif
