--- ui/views/window/dialog_delegate.cc.orig	2019-12-12 12:41:35 UTC
+++ ui/views/window/dialog_delegate.cc
@@ -53,7 +53,7 @@ Widget* DialogDelegate::CreateDialogWidget(WidgetDeleg
 
 // static
 bool DialogDelegate::CanSupportCustomFrame(gfx::NativeView parent) {
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   // The new style doesn't support unparented dialogs on Linux desktop.
   return parent != nullptr;
 #elif defined(OS_WIN)
