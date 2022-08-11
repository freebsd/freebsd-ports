--- chrome/browser/ui/views/eye_dropper/eye_dropper_view.cc.orig	2022-05-19 05:17:39 UTC
+++ chrome/browser/ui/views/eye_dropper/eye_dropper_view.cc
@@ -157,7 +157,7 @@ EyeDropperView::EyeDropperView(content::RenderFrameHos
   // EyeDropper/WidgetDelegate.
   set_owned_by_client();
   SetPreferredSize(GetSize());
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Use TYPE_MENU for Linux to ensure that the eye dropper view is displayed
   // above the color picker.
   views::Widget::InitParams params(views::Widget::InitParams::TYPE_MENU);
