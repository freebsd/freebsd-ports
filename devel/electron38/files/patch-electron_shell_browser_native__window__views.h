--- electron/shell/browser/native_window_views.h.orig	2025-09-02 20:56:04 UTC
+++ electron/shell/browser/native_window_views.h
@@ -30,7 +30,7 @@ namespace electron {
 
 namespace electron {
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 class ClientFrameViewLinux;
 class GlobalMenuBarX11;
 #endif
@@ -171,7 +171,7 @@ class NativeWindowViews : public NativeWindow,
                     LPARAM l_param,
                     LRESULT* result);
   void SetIcon(HICON small_icon, HICON app_icon);
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   void SetIcon(const gfx::ImageSkia& icon);
 #endif
 
@@ -188,7 +188,7 @@ class NativeWindowViews : public NativeWindow,
   SkColor overlay_button_color() const { return overlay_button_color_; }
   SkColor overlay_symbol_color() const { return overlay_symbol_color_; }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // returns the ClientFrameViewLinux iff that is our NonClientFrameView type,
   // nullptr otherwise.
   ClientFrameViewLinux* GetClientFrameViewLinux();
@@ -266,7 +266,7 @@ class NativeWindowViews : public NativeWindow,
   // events from resizing the window.
   extensions::SizeConstraints old_size_constraints_;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   std::unique_ptr<GlobalMenuBarX11> global_menu_bar_;
 #endif
 
