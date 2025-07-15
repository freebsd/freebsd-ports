--- components/eye_dropper/eye_dropper_view.cc.orig	2025-06-30 07:04:30 UTC
+++ components/eye_dropper/eye_dropper_view.cc
@@ -206,7 +206,7 @@ EyeDropperView::EyeDropperView(gfx::NativeView parent,
   // EyeDropper/WidgetDelegate.
   set_owned_by_client(OwnedByClientPassKey());
   SetPreferredSize(GetSize());
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Use TYPE_MENU for Linux to ensure that the eye dropper view is displayed
   // above the color picker.
   views::Widget::InitParams params(
