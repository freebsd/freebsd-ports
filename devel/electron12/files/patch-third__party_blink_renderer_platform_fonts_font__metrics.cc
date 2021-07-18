--- third_party/blink/renderer/platform/fonts/font_metrics.cc.orig	2021-01-07 00:36:43 UTC
+++ third_party/blink/renderer/platform/fonts/font_metrics.cc
@@ -38,7 +38,7 @@
 
 namespace blink {
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID) || \
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID) || defined(OS_BSD) || \
     defined(OS_FUCHSIA)
 // This is the largest VDMX table which we'll try to load and parse.
 static const size_t kMaxVDMXTableSize = 1024 * 1024;  // 1 MB
@@ -68,7 +68,7 @@ void FontMetrics::AscentDescentWithHacks(
   int vdmx_ascent = 0, vdmx_descent = 0;
   bool is_vdmx_valid = false;
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID) || \
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID) || defined(OS_BSD) || \
     defined(OS_FUCHSIA)
   // Manually digging up VDMX metrics is only applicable when bytecode hinting
   // using FreeType.  With DirectWrite or CoreText, no bytecode hinting is ever
@@ -116,7 +116,7 @@ void FontMetrics::AscentDescentWithHacks(
       visual_overflow_inflation_for_ascent = 1;
     if (descent < metrics.fDescent) {
       visual_overflow_inflation_for_descent = 1;
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID) || \
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID) || defined(OS_BSD) || \
     defined(OS_FUCHSIA)
       // When subpixel positioning is enabled, if the descent is rounded down,
       // the descent part of the glyph may be truncated when displayed in a
