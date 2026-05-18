--- electron/shell/browser/ui/views/frameless_view.h.orig	2026-03-17 08:46:52 UTC
+++ electron/shell/browser/ui/views/frameless_view.h
@@ -10,7 +10,7 @@
 #include "ui/gfx/geometry/insets.h"
 #include "ui/views/window/non_client_view.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "shell/browser/ui/views/linux_frame_layout.h"
 #endif
 
@@ -46,7 +46,7 @@ class FramelessView : public views::FrameView {
   // bounds of the view, used for CSD and resize targets on some platforms.
   virtual gfx::Insets RestoredFrameBorderInsets() const;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   virtual LinuxFrameLayout* GetLinuxFrameLayout() const;
 #endif
 
