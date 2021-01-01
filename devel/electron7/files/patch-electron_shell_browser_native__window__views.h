--- electron/shell/browser/native_window_views.h.orig	2019-12-13 19:48:14 UTC
+++ electron/shell/browser/native_window_views.h
@@ -208,7 +208,7 @@ class NativeWindowViews : public NativeWindow,
       content::WebContents*,
       const content::NativeWebKeyboardEvent& event) override;
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // ui::EventHandler:
   void OnMouseEvent(ui::MouseEvent* event) override;
 #endif
