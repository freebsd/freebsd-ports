--- electron/shell/browser/native_window_views.h.orig	2021-05-19 20:52:49 UTC
+++ electron/shell/browser/native_window_views.h
@@ -163,7 +163,7 @@ class NativeWindowViews : public NativeWindow,
                     LPARAM l_param,
                     LRESULT* result);
   void SetIcon(HICON small_icon, HICON app_icon);
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   void SetIcon(const gfx::ImageSkia& icon);
 #endif
 
@@ -223,7 +223,7 @@ class NativeWindowViews : public NativeWindow,
       content::WebContents*,
       const content::NativeWebKeyboardEvent& event) override;
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // ui::EventHandler:
   void OnMouseEvent(ui::MouseEvent* event) override;
 #endif
