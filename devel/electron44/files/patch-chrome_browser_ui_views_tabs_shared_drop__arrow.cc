--- chrome/browser/ui/views/tabs/shared/drop_arrow.cc.orig	2026-08-24 20:59:34 UTC
+++ chrome/browser/ui/views/tabs/shared/drop_arrow.cc
@@ -82,7 +82,7 @@ void DropArrow::MaybeAdjustDisplayBounds(gfx::Rect& di
 
 // static
 void DropArrow::MaybeAdjustDisplayBounds(gfx::Rect& display_bounds) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // On Linux, `GetBoundsInScreen` returns coordinates relative to the browser
   // window (plus shadow elevation outsets) rather than the screen. To handle
   // this, we adjust the display bounds by the difference between the drop arrow
