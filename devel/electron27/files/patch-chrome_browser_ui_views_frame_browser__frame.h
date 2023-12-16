--- chrome/browser/ui/views/frame/browser_frame.h.orig	2023-10-19 19:58:07 UTC
+++ chrome/browser/ui/views/frame/browser_frame.h
@@ -12,7 +12,7 @@
 #include "ui/views/context_menu_controller.h"
 #include "ui/views/widget/widget.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
 #include "ui/base/ui_base_types.h"
 #endif
 
@@ -68,7 +68,7 @@ class BrowserFrame : public views::Widget, public view
 
   ~BrowserFrame() override;
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
   // Returns which edges of the frame are tiled.
   const ui::WindowTiledEdges& tiled_edges() const { return tiled_edges_; }
   void set_tiled_edges(ui::WindowTiledEdges tiled_edges) {
@@ -230,7 +230,7 @@ class BrowserFrame : public views::Widget, public view
   // contents for smoother dragging.
   TabDragKind tab_drag_kind_ = TabDragKind::kNone;
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
   ui::WindowTiledEdges tiled_edges_;
 #endif
 
