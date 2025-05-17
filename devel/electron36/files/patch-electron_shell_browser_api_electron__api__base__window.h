--- electron/shell/browser/api/electron_api_base_window.h.orig	2025-05-07 07:36:13 UTC
+++ electron/shell/browser/api/electron_api_base_window.h
@@ -257,7 +257,7 @@ class BaseWindow : public gin_helper::TrackableObject<
   bool IsSnapped() const;
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   void SetTitleBarOverlay(const gin_helper::Dictionary& options,
                           gin_helper::Arguments* args);
 #endif
