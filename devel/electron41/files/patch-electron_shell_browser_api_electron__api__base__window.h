--- electron/shell/browser/api/electron_api_base_window.h.orig	2026-04-15 14:10:25 UTC
+++ electron/shell/browser/api/electron_api_base_window.h
@@ -264,7 +264,7 @@ class BaseWindow : public gin_helper::TrackableObject<
   v8::Local<v8::Value> GetAccentColor() const;
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   void SetTitleBarOverlay(const gin_helper::Dictionary& options,
                           gin::Arguments* args);
 #endif
