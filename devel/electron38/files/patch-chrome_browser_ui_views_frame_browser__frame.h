--- chrome/browser/ui/views/frame/browser_frame.h.orig	2025-01-27 17:37:37 UTC
+++ chrome/browser/ui/views/frame/browser_frame.h
@@ -66,7 +66,7 @@ class BrowserFrame : public views::Widget, public view
 
   ~BrowserFrame() override;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Returns whether the frame is in a tiled state.
   bool tiled() const { return tiled_; }
   void set_tiled(bool tiled) { tiled_ = tiled; }
@@ -227,7 +227,7 @@ class BrowserFrame : public views::Widget, public view
   // contents for smoother dragging.
   TabDragKind tab_drag_kind_ = TabDragKind::kNone;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   bool tiled_ = false;
 #endif
 
