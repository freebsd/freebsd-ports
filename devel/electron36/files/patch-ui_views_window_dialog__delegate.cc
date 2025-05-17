--- ui/views/window/dialog_delegate.cc.orig	2025-04-22 20:15:27 UTC
+++ ui/views/window/dialog_delegate.cc
@@ -106,7 +106,7 @@ bool DialogDelegate::CanSupportCustomFrame(gfx::Native
 
 // static
 bool DialogDelegate::CanSupportCustomFrame(gfx::NativeView parent) {
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(ENABLE_DESKTOP_AURA)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(ENABLE_DESKTOP_AURA)
   // The new style doesn't support unparented dialogs on Linux desktop.
   return parent != nullptr;
 #else
