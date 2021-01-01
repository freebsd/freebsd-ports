--- electron/atom/browser/native_window_views.h.orig	2019-04-04 16:09:31 UTC
+++ electron/atom/browser/native_window_views.h
@@ -209,7 +209,7 @@ class NativeWindowViews : public NativeWindow,
       content::WebContents*,
       const content::NativeWebKeyboardEvent& event) override;
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // ui::EventHandler:
   void OnMouseEvent(ui::MouseEvent* event) override;
 #endif
