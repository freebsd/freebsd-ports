--- third_party/blink/renderer/core/frame/web_frame_test.cc.orig	2025-09-10 14:33:47 UTC
+++ third_party/blink/renderer/core/frame/web_frame_test.cc
@@ -6474,7 +6474,7 @@ TEST_F(WebFrameTest, DISABLED_PositionForPointTest) {
 }
 
 #if BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) && !BUILDFLAG(IS_BSD)
 // TODO(crbug.com/1090246): Fix these tests on Fuchsia and re-enable.
 // TODO(crbug.com/1317375): Build these tests on all platforms.
 #define MAYBE_SelectRangeStaysHorizontallyAlignedWhenMoved \
@@ -6883,7 +6883,7 @@ TEST_F(CompositedSelectionBoundsTest, LargeSelectionNo
 TEST_F(CompositedSelectionBoundsTest, LargeSelectionNoScroll) {
   RunTest("composited_selection_bounds_large_selection_noscroll.html");
 }
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #if !BUILDFLAG(IS_ANDROID)
 TEST_F(CompositedSelectionBoundsTest, Input) {
   web_view_helper_.GetWebView()->GetSettings()->SetDefaultFontSize(16);
