--- electron/shell/browser/native_window_views.h.orig	2021-10-27 21:25:28 UTC
+++ electron/shell/browser/native_window_views.h
@@ -165,7 +165,7 @@ class NativeWindowViews : public NativeWindow,
                     LPARAM l_param,
                     LRESULT* result);
   void SetIcon(HICON small_icon, HICON app_icon);
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   void SetIcon(const gfx::ImageSkia& icon);
 #endif
 
