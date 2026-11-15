--- ui/views/window/dialog_delegate.cc.orig	2026-10-19 21:50:55 UTC
+++ ui/views/window/dialog_delegate.cc
@@ -126,7 +126,7 @@ bool DialogDelegate::CanSupportCustomFrame(gfx::Native
 
 // static
 bool DialogDelegate::CanSupportCustomFrame(gfx::NativeView parent) {
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(ENABLE_DESKTOP_AURA)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(ENABLE_DESKTOP_AURA)
   // The new style doesn't support unparented dialogs on Linux desktop.
   return parent != nullptr;
 #else
