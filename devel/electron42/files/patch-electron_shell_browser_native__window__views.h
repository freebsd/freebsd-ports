--- electron/shell/browser/native_window_views.h.orig	2026-08-24 01:09:19 UTC
+++ electron/shell/browser/native_window_views.h
@@ -32,7 +32,7 @@ namespace electron {
 
 namespace electron {
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 class ClientFrameViewLinux;
 class GlobalMenuBarX11;
 class LinuxFrameLayout;
@@ -182,7 +182,7 @@ class NativeWindowViews : public NativeWindow,
                     LPARAM l_param,
                     LRESULT* result);
   void SetIcon(HICON small_icon, HICON app_icon);
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   void SetIcon(const gfx::ImageSkia& icon);
 #endif
 
@@ -204,7 +204,7 @@ class NativeWindowViews : public NativeWindow,
     return overlay_symbol_color_;
   }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   LinuxFrameLayout* GetLinuxFrameLayout();
 #endif
 
@@ -282,7 +282,7 @@ class NativeWindowViews : public NativeWindow,
   // events from resizing the window.
   extensions::SizeConstraints old_size_constraints_;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   std::unique_ptr<GlobalMenuBarX11> global_menu_bar_;
 #endif
 
