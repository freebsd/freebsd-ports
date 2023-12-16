--- third_party/blink/renderer/modules/canvas/canvas2d/canvas_style.cc.orig	2023-08-10 01:48:50 UTC
+++ third_party/blink/renderer/modules/canvas/canvas2d/canvas_style.cc
@@ -76,6 +76,9 @@ bool ParseCanvasColorString(const String& color_string
 
 void CanvasStyle::ApplyToFlags(cc::PaintFlags& flags,
                                float global_alpha) const {
+#if defined(__clang__) && (__clang_major__ < 16)
+  SkColor4f custom_color = SkColor4f{0.0f, 0.0f, 0.0f, global_alpha};
+#endif
   switch (type_) {
     case kColor:
       ApplyColorToFlags(flags, global_alpha);
@@ -83,12 +86,20 @@ void CanvasStyle::ApplyToFlags(cc::PaintFlags& flags,
     case kGradient:
       GetCanvasGradient()->GetGradient()->ApplyToFlags(flags, SkMatrix::I(),
                                                        ImageDrawOptions());
+#if defined(__clang__) && (__clang_major__ >= 16)
       flags.setColor(SkColor4f(0.0f, 0.0f, 0.0f, global_alpha));
+#else
+      flags.setColor(custom_color);
+#endif
       break;
     case kImagePattern:
       GetCanvasPattern()->GetPattern()->ApplyToFlags(
           flags, AffineTransformToSkMatrix(GetCanvasPattern()->GetTransform()));
+#if defined(__clang__) && (__clang_major__ >= 16)
       flags.setColor(SkColor4f(0.0f, 0.0f, 0.0f, global_alpha));
+#else
+      flags.setColor(custom_color);
+#endif
       break;
     default:
       NOTREACHED();
