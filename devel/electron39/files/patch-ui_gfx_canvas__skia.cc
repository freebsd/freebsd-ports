--- ui/gfx/canvas_skia.cc.orig	2025-04-22 20:15:27 UTC
+++ ui/gfx/canvas_skia.cc
@@ -219,7 +219,7 @@ void Canvas::DrawStringRectWithFlags(std::u16string_vi
     Range range = StripAcceleratorChars(flags, &adjusted_text);
     bool elide_text = ((flags & NO_ELLIPSIS) == 0);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     // On Linux, eliding really means fading the end of the string. But only
     // for LTR text. RTL text is still elided (on the left) with "...".
     if (elide_text) {
