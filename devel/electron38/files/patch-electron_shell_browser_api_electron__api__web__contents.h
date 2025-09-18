--- electron/shell/browser/api/electron_api_web_contents.h.orig	2025-08-18 21:37:38 UTC
+++ electron/shell/browser/api/electron_api_web_contents.h
@@ -743,7 +743,7 @@ class WebContents final : public ExclusiveAccessContex
 #if defined(TOOLKIT_VIEWS) && !BUILDFLAG(IS_MAC)
   ui::ImageModel GetDevToolsWindowIcon() override;
 #endif
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   void GetDevToolsWindowWMClass(std::string* name,
                                 std::string* class_name) override;
 #endif
