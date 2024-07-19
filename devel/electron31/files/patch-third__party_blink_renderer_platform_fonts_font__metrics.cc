--- third_party/blink/renderer/platform/fonts/font_metrics.cc.orig	2024-02-21 00:20:54 UTC
+++ third_party/blink/renderer/platform/fonts/font_metrics.cc
@@ -39,7 +39,7 @@ namespace blink {
 namespace blink {
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || \
-    BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 // This is the largest VDMX table which we'll try to load and parse.
 static const size_t kMaxVDMXTableSize = 1024 * 1024;  // 1 MB
 #endif
@@ -67,7 +67,7 @@ void FontMetrics::AscentDescentWithHacks(
   bool is_vdmx_valid = false;
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || \
-    BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
   // Manually digging up VDMX metrics is only applicable when bytecode hinting
   // using FreeType.  With DirectWrite or CoreText, no bytecode hinting is ever
   // done.  This code should be pushed into FreeType (hinted font metrics).
@@ -111,7 +111,7 @@ void FontMetrics::AscentDescentWithHacks(
     descent = SkScalarRoundToScalar(metrics.fDescent);
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || \
-    BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
     // When subpixel positioning is enabled, if the descent is rounded down,
     // the descent part of the glyph may be truncated when displayed in a
     // 'overflow: hidden' container.  To avoid that, borrow 1 unit from the
