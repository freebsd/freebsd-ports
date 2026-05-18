--- chrome/browser/ui/views/compose/compose_dialog_view.cc.orig	2025-01-27 17:37:37 UTC
+++ chrome/browser/ui/views/compose/compose_dialog_view.cc
@@ -160,7 +160,7 @@ void ComposeDialogView::OnBeforeBubbleWidgetInit(
     views::Widget::InitParams* params,
     views::Widget* widget) const {
   WebUIBubbleDialogView::OnBeforeBubbleWidgetInit(params, widget);
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // In linux, windows may be clipped to their anchors' bounds,
   // resulting in visual errors, unless they use accelerated rendering. See
   // crbug.com/1445770 for details.
