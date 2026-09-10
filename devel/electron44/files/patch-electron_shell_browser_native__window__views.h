--- electron/shell/browser/native_window_views.h.orig	2026-08-31 00:54:38 UTC
+++ electron/shell/browser/native_window_views.h
@@ -30,7 +30,7 @@ class Arguments;
 class Arguments;
 }  // namespace gin
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 namespace views {
 class FrameViewLinux;
 }  // namespace views
@@ -38,7 +38,7 @@ namespace electron {
 
 namespace electron {
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 class GlobalMenuBarX11;
 #endif
 
@@ -186,7 +186,7 @@ class NativeWindowViews : public NativeWindow,
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
 #endif
 
@@ -289,7 +289,7 @@ class NativeWindowViews : public NativeWindow,
   // events from resizing the window.
   extensions::SizeConstraints old_size_constraints_;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   std::unique_ptr<GlobalMenuBarX11> global_menu_bar_;
 #endif
 
