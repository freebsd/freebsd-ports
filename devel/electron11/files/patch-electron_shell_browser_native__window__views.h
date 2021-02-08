--- electron/shell/browser/native_window_views.h.orig	2021-01-22 23:55:24 UTC
+++ electron/shell/browser/native_window_views.h
@@ -217,7 +217,7 @@ class NativeWindowViews : public NativeWindow,
       content::WebContents*,
       const content::NativeWebKeyboardEvent& event) override;
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // ui::EventHandler:
   void OnMouseEvent(ui::MouseEvent* event) override;
 #endif
