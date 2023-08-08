--- electron/shell/browser/ui/inspectable_web_contents_view_delegate.h.orig	2022-05-18 15:31:32 UTC
+++ electron/shell/browser/ui/inspectable_web_contents_view_delegate.h
@@ -24,7 +24,7 @@ class InspectableWebContentsViewDelegate {
   // Returns the icon of devtools window.
   virtual ui::ImageModel GetDevToolsWindowIcon();
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Called when creating devtools window.
   virtual void GetDevToolsWindowWMClass(std::string* name,
                                         std::string* class_name) {}
