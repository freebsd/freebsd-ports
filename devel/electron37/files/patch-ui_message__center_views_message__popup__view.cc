--- ui/message_center/views/message_popup_view.cc.orig	2025-01-27 17:37:37 UTC
+++ ui/message_center/views/message_popup_view.cc
@@ -153,7 +153,7 @@ std::unique_ptr<views::Widget> MessagePopupView::Show(
       views::Widget::InitParams::CLIENT_OWNS_WIDGET,
       views::Widget::InitParams::TYPE_POPUP);
   params.z_order = ui::ZOrderLevel::kFloatingWindow;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Make the widget explicitly activatable as TYPE_POPUP is not activatable by
   // default but we need focus for the inline reply textarea.
   params.activatable = views::Widget::InitParams::Activatable::kYes;
