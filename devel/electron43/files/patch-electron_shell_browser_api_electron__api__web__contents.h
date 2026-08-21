--- electron/shell/browser/api/electron_api_web_contents.h.orig	2026-08-18 19:28:27 UTC
+++ electron/shell/browser/api/electron_api_web_contents.h
@@ -767,7 +767,7 @@ class WebContents final : public ExclusiveAccessContex
 #if defined(TOOLKIT_VIEWS) && !BUILDFLAG(IS_MAC)
   ui::ImageModel GetDevToolsWindowIcon() override;
 #endif
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   void GetDevToolsWindowWMClass(std::string* name,
                                 std::string* class_name) override;
 #endif
