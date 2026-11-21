--- components/eye_dropper/eye_dropper_view.cc.orig	2026-11-20 03:52:43 UTC
+++ components/eye_dropper/eye_dropper_view.cc
@@ -360,7 +360,7 @@ EyeDropperView::EyeDropperView(gfx::NativeView parent,
   contents_view->SetPreferredSize(contents_view->GetSize());
   delegate_->SetContentsView(std::move(contents_view));
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Use TYPE_MENU for Linux to ensure that the eye dropper view is displayed
   // above the color picker.
   views::Widget::InitParams params(
