--- third_party/blink/renderer/platform/fonts/font_palette.h.orig	2023-10-19 19:58:33 UTC
+++ third_party/blink/renderer/platform/fonts/font_palette.h
@@ -96,7 +96,11 @@ class PLATFORM_EXPORT FontPalette : public RefCounted<
       Color::ColorSpace color_interpolation_space,
       absl::optional<Color::HueInterpolationMethod> hue_interpolation_method) {
     return base::AdoptRef(new FontPalette(
+#if defined(__clang__) && (__clang_major__ >= 16)
         start, end, NonNormalizedPercentages(start_percentage, end_percentage),
+#else
+        start, end, NonNormalizedPercentages(NonNormalizedPercentages{start_percentage, end_percentage}),
+#endif
         normalized_percentage, alpha_multiplier, color_interpolation_space,
         hue_interpolation_method));
   }
@@ -170,7 +174,11 @@ class PLATFORM_EXPORT FontPalette : public RefCounted<
       double normalized_percentage) {
     double end_percentage = normalized_percentage * 100.0;
     double start_percentage = 100.0 - end_percentage;
+#if defined(__clang__) && (__clang_major__ >= 16)
     return NonNormalizedPercentages(start_percentage, end_percentage);
+#else
+    return NonNormalizedPercentages(NonNormalizedPercentages{start_percentage, end_percentage});
+#endif
   }
 
   double GetAlphaMultiplier() const {
