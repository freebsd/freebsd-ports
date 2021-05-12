--- electron/shell/browser/api/electron_api_web_contents.h.orig	2021-04-22 15:13:27 UTC
+++ electron/shell/browser/api/electron_api_web_contents.h
@@ -669,7 +669,7 @@ class WebContents : public gin::Wrappable<WebContents>
 #if defined(TOOLKIT_VIEWS) && !defined(OS_MAC)
   gfx::ImageSkia GetDevToolsWindowIcon() override;
 #endif
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   void GetDevToolsWindowWMClass(std::string* name,
                                 std::string* class_name) override;
 #endif
