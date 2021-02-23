--- electron/shell/browser/native_window_views.h.orig	2021-02-19 19:40:19 UTC
+++ electron/shell/browser/native_window_views.h
@@ -218,7 +218,7 @@ class NativeWindowViews : public NativeWindow,
       content::WebContents*,
       const content::NativeWebKeyboardEvent& event) override;
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // ui::EventHandler:
   void OnMouseEvent(ui::MouseEvent* event) override;
 #endif
