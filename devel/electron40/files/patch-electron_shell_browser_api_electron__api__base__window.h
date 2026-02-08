--- electron/shell/browser/api/electron_api_base_window.h.orig	2026-01-15 18:39:20 UTC
+++ electron/shell/browser/api/electron_api_base_window.h
@@ -261,7 +261,7 @@ class BaseWindow : public gin_helper::TrackableObject<
   v8::Local<v8::Value> GetAccentColor() const;
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   void SetTitleBarOverlay(const gin_helper::Dictionary& options,
                           gin::Arguments* args);
 #endif
