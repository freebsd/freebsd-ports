--- ui/views/widget/desktop_aura/desktop_drag_drop_client_ozone.cc.orig	2024-06-18 21:44:03 UTC
+++ ui/views/widget/desktop_aura/desktop_drag_drop_client_ozone.cc
@@ -200,7 +200,7 @@ DragOperation DesktopDragDropClientOzone::StartDragAnd
   return selected_operation_;
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void DesktopDragDropClientOzone::UpdateDragImage(const gfx::ImageSkia& image,
                                                  const gfx::Vector2d& offset) {
   DCHECK(drag_handler_);
