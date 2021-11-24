--- chrome/browser/ui/views/eye_dropper/eye_dropper_view.cc.orig	2021-11-12 06:03:43 UTC
+++ chrome/browser/ui/views/eye_dropper/eye_dropper_view.cc
@@ -112,7 +112,7 @@ EyeDropperView::EyeDropperView(content::RenderFrameHos
   SetModalType(ui::MODAL_TYPE_WINDOW);
   SetOwnedByWidget(false);
   SetPreferredSize(GetSize());
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // Use TYPE_MENU for Linux to ensure that the eye dropper view is displayed
   // above the color picker.
   views::Widget::InitParams params(views::Widget::InitParams::TYPE_MENU);
