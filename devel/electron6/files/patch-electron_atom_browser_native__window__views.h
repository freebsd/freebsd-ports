--- electron/atom/browser/native_window_views.h.orig	2019-09-11 17:30:11 UTC
+++ electron/atom/browser/native_window_views.h
@@ -206,7 +206,7 @@ class NativeWindowViews : public NativeWindow,
       content::WebContents*,
       const content::NativeWebKeyboardEvent& event) override;
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // ui::EventHandler:
   void OnMouseEvent(ui::MouseEvent* event) override;
 #endif
