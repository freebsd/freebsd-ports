--- third_party/blink/renderer/core/frame/web_frame_test.cc.orig	2022-05-25 04:01:08 UTC
+++ third_party/blink/renderer/core/frame/web_frame_test.cc
@@ -6281,7 +6281,7 @@ TEST_F(WebFrameTest, DISABLED_PositionForPointTest) {
   EXPECT_EQ(64, ComputeOffset(layout_object, 1000, 1000));
 }
 
-#if !BUILDFLAG(IS_MAC) && !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS)
+#if !BUILDFLAG(IS_MAC) && !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS) && !BUILDFLAG(IS_BSD)
 TEST_F(WebFrameTest, SelectRangeStaysHorizontallyAlignedWhenMoved) {
   RegisterMockedHttpURLLoad("move_caret.html");
 
@@ -6660,7 +6660,7 @@ TEST_F(CompositedSelectionBoundsTest, SVGBasic) {
 TEST_F(CompositedSelectionBoundsTest, SVGTextWithFragments) {
   RunTest("composited_selection_bounds_svg_text_with_fragments.html");
 }
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #if !BUILDFLAG(IS_ANDROID)
 TEST_F(CompositedSelectionBoundsTest, Input) {
   web_view_helper_.GetWebView()->GetSettings()->SetDefaultFontSize(16);
