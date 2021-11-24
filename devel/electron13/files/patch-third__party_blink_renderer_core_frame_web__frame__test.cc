--- third_party/blink/renderer/core/frame/web_frame_test.cc.orig	2021-07-15 19:13:45 UTC
+++ third_party/blink/renderer/core/frame/web_frame_test.cc
@@ -6057,7 +6057,7 @@ TEST_F(WebFrameTest, DISABLED_PositionForPointTest) {
   EXPECT_EQ(64, ComputeOffset(layout_object, 1000, 1000));
 }
 
-#if !defined(OS_MAC) && !defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if !defined(OS_MAC) && !defined(OS_LINUX) && !defined(OS_CHROMEOS) && !defined(OS_BSD)
 TEST_F(WebFrameTest, SelectRangeStaysHorizontallyAlignedWhenMoved) {
   RegisterMockedHttpURLLoad("move_caret.html");
 
@@ -6426,7 +6426,7 @@ TEST_P(CompositedSelectionBoundsTest, SVGBasic) {
 TEST_P(CompositedSelectionBoundsTest, SVGTextWithFragments) {
   RunTest("composited_selection_bounds_svg_text_with_fragments.html");
 }
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 #if !defined(OS_ANDROID)
 TEST_P(CompositedSelectionBoundsTest, Input) {
   RunTest("composited_selection_bounds_input.html");
