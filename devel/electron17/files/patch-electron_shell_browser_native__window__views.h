--- electron/shell/browser/native_window_views.h.orig	2022-05-11 15:32:29 UTC
+++ electron/shell/browser/native_window_views.h
@@ -172,7 +172,7 @@ class NativeWindowViews : public NativeWindow,
                     LPARAM l_param,
                     LRESULT* result);
   void SetIcon(HICON small_icon, HICON app_icon);
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   void SetIcon(const gfx::ImageSkia& icon);
 #endif
 
