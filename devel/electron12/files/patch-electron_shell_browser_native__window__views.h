--- electron/shell/browser/native_window_views.h.orig	2021-10-11 17:12:26 UTC
+++ electron/shell/browser/native_window_views.h
@@ -163,7 +163,7 @@ class NativeWindowViews : public NativeWindow,
                     LPARAM l_param,
                     LRESULT* result);
   void SetIcon(HICON small_icon, HICON app_icon);
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   void SetIcon(const gfx::ImageSkia& icon);
 #endif
 
