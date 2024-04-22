--- components/eye_dropper/eye_dropper_view_aura.cc.orig	2023-11-29 21:39:58 UTC
+++ components/eye_dropper/eye_dropper_view_aura.cc
@@ -129,7 +129,7 @@ void EyeDropperView::CaptureInputIfNeeded() {
 }
 
 void EyeDropperView::CaptureInputIfNeeded() {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // The eye dropper needs to capture input since it is not activated
   // in order to avoid dismissing the color picker.
   GetWidget()->GetNativeWindow()->SetCapture();
