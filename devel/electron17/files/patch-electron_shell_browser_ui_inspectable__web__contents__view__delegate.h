--- electron/shell/browser/ui/inspectable_web_contents_view_delegate.h.orig	2021-11-08 18:41:28 UTC
+++ electron/shell/browser/ui/inspectable_web_contents_view_delegate.h
@@ -24,7 +24,7 @@ class InspectableWebContentsViewDelegate {
   // Returns the icon of devtools window.
   virtual ui::ImageModel GetDevToolsWindowIcon();
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // Called when creating devtools window.
   virtual void GetDevToolsWindowWMClass(std::string* name,
                                         std::string* class_name) {}
