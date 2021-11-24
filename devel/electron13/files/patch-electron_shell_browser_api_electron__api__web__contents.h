--- electron/shell/browser/api/electron_api_web_contents.h.orig	2021-10-27 21:25:28 UTC
+++ electron/shell/browser/api/electron_api_web_contents.h
@@ -696,7 +696,7 @@ class WebContents : public gin::Wrappable<WebContents>
 #if defined(TOOLKIT_VIEWS) && !defined(OS_MAC)
   gfx::ImageSkia GetDevToolsWindowIcon() override;
 #endif
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   void GetDevToolsWindowWMClass(std::string* name,
                                 std::string* class_name) override;
 #endif
