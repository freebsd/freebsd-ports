--- electron/shell/browser/native_window_views.h.orig	2026-10-13 23:18:11 UTC
+++ electron/shell/browser/native_window_views.h
@@ -33,7 +33,7 @@ class Arguments;
 class Arguments;
 }  // namespace gin
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 namespace views {
 class FrameViewLinux;
 }  // namespace views
@@ -41,7 +41,7 @@ namespace electron {
 
 namespace electron {
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 class GlobalMenuBarX11;
 #endif
 
@@ -185,7 +185,7 @@ class NativeWindowViews : public NativeWindow,
                     LPARAM l_param,
                     LRESULT* result);
   void SetIcon(HICON small_icon, HICON app_icon);
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   void SetIcon(const gfx::ImageSkia& icon);
 #endif
 
@@ -208,7 +208,7 @@ class NativeWindowViews : public NativeWindow,
     return overlay_symbol_color_;
   }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   views::FrameViewLinux* GetFrameViewLinux() const;
   [[nodiscard]] bool ignore_mouse_events() const {
     return ignore_mouse_events_;
@@ -306,7 +306,7 @@ class NativeWindowViews : public NativeWindow,
   // events from resizing the window.
   extensions::SizeConstraints old_size_constraints_;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   std::unique_ptr<GlobalMenuBarX11> global_menu_bar_;
 
   // Set while the window is disabled; running it re-enables event dispatch.
@@ -325,7 +325,7 @@ class NativeWindowViews : public NativeWindow,
   // This value is determined when the window is created.
   bool rounded_corner_ = true;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   bool ignore_mouse_events_ = false;
 #endif
 
