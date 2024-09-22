--- chrome/browser/ui/views/frame/browser_frame.h.orig	2024-02-21 00:20:37 UTC
+++ chrome/browser/ui/views/frame/browser_frame.h
@@ -65,7 +65,7 @@ class BrowserFrame : public views::Widget, public view
 
   ~BrowserFrame() override;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Returns whether the frame is in a tiled state.
   bool tiled() const { return tiled_; }
   void set_tiled(bool tiled) { tiled_ = tiled; }
@@ -225,7 +225,7 @@ class BrowserFrame : public views::Widget, public view
   // contents for smoother dragging.
   TabDragKind tab_drag_kind_ = TabDragKind::kNone;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   bool tiled_ = false;
 #endif
 
