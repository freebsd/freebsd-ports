--- electron/shell/browser/ui/views/frameless_view.h.orig	2026-05-26 16:24:13 UTC
+++ electron/shell/browser/ui/views/frameless_view.h
@@ -10,7 +10,7 @@
 #include "ui/gfx/geometry/insets.h"
 #include "ui/views/window/non_client_view.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "shell/browser/ui/views/linux_frame_layout.h"
 #endif
 
@@ -44,7 +44,7 @@ class FramelessView : public views::FrameView {
   // bounds of the view, used for CSD and resize targets on some platforms.
   virtual gfx::Insets RestoredFrameBorderInsets() const;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   virtual LinuxFrameLayout* GetLinuxFrameLayout() const;
 #endif
 
