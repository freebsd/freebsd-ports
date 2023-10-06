--- electron/shell/browser/api/electron_api_web_contents.h.orig	2023-08-14 18:19:06 UTC
+++ electron/shell/browser/api/electron_api_web_contents.h
@@ -735,7 +735,7 @@ class WebContents : public ExclusiveAccessContext,
 #if defined(TOOLKIT_VIEWS) && !BUILDFLAG(IS_MAC)
   ui::ImageModel GetDevToolsWindowIcon() override;
 #endif
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   void GetDevToolsWindowWMClass(std::string* name,
                                 std::string* class_name) override;
 #endif
