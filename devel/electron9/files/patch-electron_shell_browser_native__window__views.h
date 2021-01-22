--- electron/shell/browser/native_window_views.h.orig	2020-12-11 21:16:23 UTC
+++ electron/shell/browser/native_window_views.h
@@ -216,7 +216,7 @@ class NativeWindowViews : public NativeWindow,
       content::WebContents*,
       const content::NativeWebKeyboardEvent& event) override;
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // ui::EventHandler:
   void OnMouseEvent(ui::MouseEvent* event) override;
 #endif
