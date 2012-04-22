--- ./svx/source/customshapes/EnhancedCustomShapeGeometry.cxx.orig	2012-03-27 18:22:01.000000000 +0200
+++ ./svx/source/customshapes/EnhancedCustomShapeGeometry.cxx	2012-04-16 14:24:48.000000000 +0200
@@ -26,8 +26,13 @@
  *
  ************************************************************************/
 
+#include <limits>
+
 #include "svx/EnhancedCustomShapeGeometry.hxx"
 #include <com/sun/star/drawing/EnhancedCustomShapeGluePointType.hpp>
+
+static const sal_Int32 MIN_INT32 = std::numeric_limits<sal_Int32>::min();
+
 /*
 static const SvxMSDffVertPair Vert[] =
 {
@@ -58,7 +63,7 @@
     (sal_Int32*)mso_sptDefault,
     (SvxMSDffTextRectangles*)mso_sptTextRect, sizeof( mso_sptTextRect ) / sizeof( SvxMSDffTextRectangles ),
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     (SvxMSDffVertPair*)mso_sptVert, sizeof( mso_sptVert ) / sizeof( SvxMSDffVertPair ),
     (SvxMSDffHandles*)mso_sptHandles, sizeof( mso_sptHandles ) / sizeof( SvxMSDffHandles )
 };
@@ -161,9 +166,9 @@
 static const SvxMSDffHandle mso_sptArcHandle[] =
 {
     {   MSDFF_HANDLE_FLAGS_POLAR | MSDFF_HANDLE_FLAGS_RADIUS_RANGE,
-        10800, 0x100, 10800, 10800, 10800, 10800, 0x80000000, 0x7fffffff },
+        10800, 0x100, 10800, 10800, 10800, 10800, MIN_INT32, 0x7fffffff },
     {   MSDFF_HANDLE_FLAGS_POLAR | MSDFF_HANDLE_FLAGS_RADIUS_RANGE,
-        10800, 0x101, 10800, 10800, 10800, 10800, 0x80000000, 0x7fffffff }
+        10800, 0x101, 10800, 10800, 10800, 10800, MIN_INT32, 0x7fffffff }
 };
 static const mso_CustomShape msoArc =
 {
@@ -173,7 +178,7 @@
     (sal_Int32*)mso_sptArcDefault,
     NULL, 0,
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     NULL, 0,
     (SvxMSDffHandle*)mso_sptArcHandle, sizeof( mso_sptArcHandle ) / sizeof( SvxMSDffHandle )        // handles
 };
@@ -190,7 +195,7 @@
     NULL,
     NULL, 0,
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     NULL, 0,
     NULL, 0     // handles
 };
@@ -207,7 +212,7 @@
     NULL,
     NULL, 0,
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     NULL, 0,
     NULL, 0     // handles
 };
@@ -242,7 +247,7 @@
 static const SvxMSDffHandle mso_sptRoundRectangleHandle[] =
 {
     {   MSDFF_HANDLE_FLAGS_RANGE | MSDFF_HANDLE_FLAGS_SWITCHED,
-        0x100, 0, 10800, 10800, 0, 10800, 0x80000000, 0x7fffffff }
+        0x100, 0, 10800, 10800, 0, 10800, MIN_INT32, 0x7fffffff }
 };
 static const mso_CustomShape msoRoundRectangle =
 {
@@ -277,7 +282,7 @@
     NULL,
     (SvxMSDffTextRectangles*)mso_sptRightTriangleTextRect, sizeof( mso_sptRightTriangleTextRect ) / sizeof( SvxMSDffTextRectangles ),
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     (SvxMSDffVertPair*)mso_sptRightTriangleGluePoints, sizeof( mso_sptRightTriangleGluePoints ) / sizeof( SvxMSDffVertPair ),
     NULL, 0     // handles
 };
@@ -306,7 +311,7 @@
     NULL,
     (SvxMSDffTextRectangles*)mso_sptEllipseTextRect, sizeof( mso_sptEllipseTextRect ) / sizeof( SvxMSDffTextRectangles ),
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     (SvxMSDffVertPair*)mso_sptEllipseGluePoints, sizeof( mso_sptEllipseGluePoints ) / sizeof( SvxMSDffVertPair ),
     NULL, 0     // handles
 };
@@ -347,7 +352,7 @@
 static const SvxMSDffHandle mso_sptParallelogramHandle[] =
 {
     {   MSDFF_HANDLE_FLAGS_RANGE,
-        0x100, 0, 10800, 10800, 0, 21600, 0x80000000, 0x7fffffff }
+        0x100, 0, 10800, 10800, 0, 21600, MIN_INT32, 0x7fffffff }
 };
 static const mso_CustomShape msoParallelogram =
 {
@@ -357,7 +362,7 @@
     (sal_Int32*)mso_sptDefault5400,
     (SvxMSDffTextRectangles*)mso_sptParallelogramTextRect, sizeof( mso_sptParallelogramTextRect ) / sizeof( SvxMSDffTextRectangles ),
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     (SvxMSDffVertPair*)mso_sptParallelogramGluePoints, sizeof( mso_sptParallelogramGluePoints ) / sizeof( SvxMSDffVertPair ),
     (SvxMSDffHandle*)mso_sptParallelogramHandle, sizeof( mso_sptParallelogramHandle ) / sizeof( SvxMSDffHandle )        // handles
 };
@@ -378,7 +383,7 @@
     NULL,
     (SvxMSDffTextRectangles*)mso_sptDiamondTextRect, sizeof( mso_sptDiamondTextRect ) / sizeof( SvxMSDffTextRectangles ),
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     (SvxMSDffVertPair*)mso_sptStandardGluePoints, sizeof( mso_sptStandardGluePoints ) / sizeof( SvxMSDffVertPair ),
     NULL, 0     // handles
 };
@@ -412,7 +417,7 @@
 static const SvxMSDffHandle mso_sptTrapezoidHandle[] =
 {
     {   MSDFF_HANDLE_FLAGS_RANGE,
-        0x100, 1, 10800, 10800, 0, 10800, 0x80000000, 0x7fffffff }
+        0x100, 1, 10800, 10800, 0, 10800, MIN_INT32, 0x7fffffff }
 };
 static const mso_CustomShape msoTrapezoid =
 {
@@ -422,7 +427,7 @@
     (sal_Int32*)mso_sptDefault5400,
     (SvxMSDffTextRectangles*)mso_sptTrapezoidTextRect, sizeof( mso_sptTrapezoidTextRect ) / sizeof( SvxMSDffTextRectangles ),
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     (SvxMSDffVertPair*)mso_sptTrapezoidGluePoints, sizeof( mso_sptTrapezoidGluePoints ) / sizeof( SvxMSDffVertPair ),
     (SvxMSDffHandle*)mso_sptTrapezoidHandle, sizeof( mso_sptTrapezoidHandle ) / sizeof( SvxMSDffHandle )        // handles
 };
@@ -459,7 +464,7 @@
 static const SvxMSDffHandle mso_sptOctagonHandle[] =
 {
     {   MSDFF_HANDLE_FLAGS_RANGE,
-        0x100, 0, 10800, 10800, 0, 10800, 0x80000000, 0x7fffffff }
+        0x100, 0, 10800, 10800, 0, 10800, MIN_INT32, 0x7fffffff }
 };
 static const mso_CustomShape msoOctagon =
 {
@@ -505,7 +510,7 @@
 static const SvxMSDffHandle mso_sptIsocelesTriangleHandle[] =
 {
     {   MSDFF_HANDLE_FLAGS_RANGE,
-        0x100, 0, 10800, 10800, 0, 21600, 0x80000000, 0x7fffffff }
+        0x100, 0, 10800, 10800, 0, 21600, MIN_INT32, 0x7fffffff }
 };
 static const mso_CustomShape msoIsocelesTriangle =
 {
@@ -515,7 +520,7 @@
     (sal_Int32*)mso_sptDefault10800,
     (SvxMSDffTextRectangles*)mso_sptIsocelesTriangleTextRect, sizeof( mso_sptIsocelesTriangleTextRect ) / sizeof( SvxMSDffTextRectangles ),
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     (SvxMSDffVertPair*)mso_sptIsocelesTriangleGluePoints, sizeof( mso_sptIsocelesTriangleGluePoints ) / sizeof( SvxMSDffVertPair ),
     (SvxMSDffHandle*)mso_sptIsocelesTriangleHandle, sizeof( mso_sptIsocelesTriangleHandle ) / sizeof( SvxMSDffHandle )      // handles
 };
@@ -544,7 +549,7 @@
 static const SvxMSDffHandle mso_sptHexagonHandle[] =
 {
     {   MSDFF_HANDLE_FLAGS_RANGE,
-        0x100, 0, 10800, 10800, 0, 10800, 0x80000000, 0x7fffffff }
+        0x100, 0, 10800, 10800, 0, 10800, MIN_INT32, 0x7fffffff }
 };
 static const mso_CustomShape msoHexagon =
 {
@@ -554,7 +559,7 @@
     (sal_Int32*)mso_sptDefault5400,
     (SvxMSDffTextRectangles*)mso_sptHexagonTextRect, sizeof( mso_sptHexagonTextRect ) / sizeof( SvxMSDffTextRectangles ),
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     (SvxMSDffVertPair*)mso_sptStandardGluePoints, sizeof( mso_sptStandardGluePoints ) / sizeof( SvxMSDffVertPair ),
     (SvxMSDffHandle*)mso_sptHexagonHandle, sizeof( mso_sptHexagonHandle ) / sizeof( SvxMSDffHandle )        // handles
 };
@@ -581,7 +586,7 @@
     NULL,
     (SvxMSDffTextRectangles*)mso_sptPentagonTextRect, sizeof( mso_sptPentagonTextRect ) / sizeof( SvxMSDffTextRectangles ),
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     (SvxMSDffVertPair*)mso_sptPentagonGluePoints, sizeof( mso_sptPentagonGluePoints ) / sizeof( SvxMSDffVertPair ),
     NULL, 0     // handles
 };
@@ -606,7 +611,7 @@
 static const SvxMSDffHandle mso_sptPlusHandle[] =
 {
     {   MSDFF_HANDLE_FLAGS_RANGE | MSDFF_HANDLE_FLAGS_SWITCHED,
-        0x100, 0, 10800, 10800, 0, 10800, 0x80000000, 0x7fffffff }
+        0x100, 0, 10800, 10800, 0, 10800, MIN_INT32, 0x7fffffff }
 };
 static const mso_CustomShape msoPlus =
 {
@@ -663,7 +668,7 @@
 static const SvxMSDffHandle mso_sptCanHandle[] =
 {
     {   MSDFF_HANDLE_FLAGS_RANGE,
-        7 + 3, 0x100, 44, 10800, 0x80000000, 0x7fffffff, 0, 10800 }
+        7 + 3, 0x100, 44, 10800, MIN_INT32, 0x7fffffff, 0, 10800 }
 };
 static const mso_CustomShape msoCan =
 {
@@ -673,7 +678,7 @@
     (sal_Int32*)mso_sptDefault5400,
     (SvxMSDffTextRectangles*)mso_sptCanTextRect, sizeof( mso_sptCanTextRect ) / sizeof( SvxMSDffTextRectangles ),
     88, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     (SvxMSDffVertPair*)mso_sptCanGluePoints, sizeof( mso_sptCanGluePoints ) / sizeof( SvxMSDffVertPair ),
     (SvxMSDffHandle*)mso_sptCanHandle, sizeof( mso_sptCanHandle ) / sizeof( SvxMSDffHandle )        // handles
 };
@@ -715,7 +720,7 @@
     (sal_Int32*)mso_sptDefault16200and5400,
     (SvxMSDffTextRectangles*)mso_sptArrowTextRect, sizeof( mso_sptArrowTextRect ) / sizeof( SvxMSDffTextRectangles ),
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     NULL, 0,
     (SvxMSDffHandle*)mso_sptArrowHandle, sizeof( mso_sptArrowHandle ) / sizeof( SvxMSDffHandle )        // handles
 };
@@ -750,7 +755,7 @@
     (sal_Int32*)mso_sptLeftArrowDefault,
     (SvxMSDffTextRectangles*)mso_sptLeftArrowTextRect, sizeof( mso_sptLeftArrowTextRect ) / sizeof( SvxMSDffTextRectangles ),
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     NULL, 0,
     (SvxMSDffHandle*)mso_sptLeftArrowHandle, sizeof( mso_sptLeftArrowHandle ) / sizeof( SvxMSDffHandle )        // handles
 };
@@ -781,7 +786,7 @@
     (sal_Int32*)mso_sptDefault16200and5400,
     (SvxMSDffTextRectangles*)mso_sptDownArrowTextRect, sizeof( mso_sptDownArrowTextRect ) / sizeof( SvxMSDffTextRectangles ),
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     NULL, 0,
     (SvxMSDffHandle*)mso_sptDownArrowHandle, sizeof( mso_sptDownArrowHandle ) / sizeof( SvxMSDffHandle )        // handles
 };
@@ -816,7 +821,7 @@
     (sal_Int32*)mso_sptUpArrowDefault,
     (SvxMSDffTextRectangles*)mso_sptUpArrowTextRect, sizeof( mso_sptUpArrowTextRect ) / sizeof( SvxMSDffTextRectangles ),
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     NULL, 0,
     (SvxMSDffHandle*)mso_sptUpArrowHandle, sizeof( mso_sptUpArrowHandle ) / sizeof( SvxMSDffHandle )        // handles
 };
@@ -865,7 +870,7 @@
     (sal_Int32*)mso_sptLeftRightArrowDefault,
     (SvxMSDffTextRectangles*)mso_sptLeftRightArrowTextRect, sizeof( mso_sptLeftRightArrowTextRect ) / sizeof( SvxMSDffTextRectangles ),
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     NULL, 0,
     (SvxMSDffHandle*)mso_sptLeftRightArrowHandle, sizeof( mso_sptLeftRightArrowHandle ) / sizeof( SvxMSDffHandle )      // handles
 };
@@ -901,7 +906,7 @@
     (sal_Int32*)mso_sptUpDownArrowDefault,
     (SvxMSDffTextRectangles*)mso_sptUpDownArrowTextRect, sizeof( mso_sptUpDownArrowTextRect ) / sizeof( SvxMSDffTextRectangles ),
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     NULL, 0,
     (SvxMSDffHandle*)mso_sptUpDownArrowHandle, sizeof( mso_sptUpDownArrowHandle ) / sizeof( SvxMSDffHandle )        // handles
 };
@@ -941,7 +946,7 @@
     {   MSDFF_HANDLE_FLAGS_RANGE | MSDFF_HANDLE_FLAGS_RANGE_Y_MAX_IS_SPECIAL | MSDFF_HANDLE_FLAGS_RANGE_X_MIN_IS_SPECIAL,
         0x101, 0x102, 10800, 10800, 0x100, 10800, 0, 0x100 },
     {   MSDFF_HANDLE_FLAGS_RANGE | MSDFF_HANDLE_FLAGS_RANGE_X_MIN_IS_SPECIAL | MSDFF_HANDLE_FLAGS_RANGE_X_MAX_IS_SPECIAL,
-        0x100, 0, 10800, 10800, 0x102, 0x101, 0x80000000, 0x7fffffff }
+        0x100, 0, 10800, 10800, 0x102, 0x101, MIN_INT32, 0x7fffffff }
 };
 static const mso_CustomShape msoQuadArrow =
 {
@@ -951,7 +956,7 @@
     (sal_Int32*)mso_sptQuadArrowDefault,
     (SvxMSDffTextRectangles*)mso_sptQuadArrowTextRect, sizeof( mso_sptQuadArrowTextRect ) / sizeof( SvxMSDffTextRectangles ),
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     NULL, 0,
     (SvxMSDffHandle*)mso_sptQuadArrowHandle, sizeof( mso_sptQuadArrowHandle ) / sizeof( SvxMSDffHandle )        // handles
 };
@@ -990,7 +995,7 @@
     {   MSDFF_HANDLE_FLAGS_RANGE | MSDFF_HANDLE_FLAGS_RANGE_Y_MAX_IS_SPECIAL | MSDFF_HANDLE_FLAGS_RANGE_X_MIN_IS_SPECIAL,
         0x101, 0x102, 10800, 10800, 0x100, 10800, 0, 0x100 },
     {   MSDFF_HANDLE_FLAGS_RANGE | MSDFF_HANDLE_FLAGS_RANGE_X_MIN_IS_SPECIAL | MSDFF_HANDLE_FLAGS_RANGE_X_MAX_IS_SPECIAL,
-        0x100, 0, 10800, 10800, 0x102, 0x101, 0x80000000, 0x7fffffff }
+        0x100, 0, 10800, 10800, 0x102, 0x101, MIN_INT32, 0x7fffffff }
 };
 static const mso_CustomShape msoLeftRightUpArrow =
 {
@@ -1000,7 +1005,7 @@
     (sal_Int32*)mso_sptLeftRightUpArrowDefault,
     (SvxMSDffTextRectangles*)mso_sptLeftRightUpArrowTextRect, sizeof( mso_sptLeftRightUpArrowTextRect ) / sizeof( SvxMSDffTextRectangles ),
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     NULL, 0,
     (SvxMSDffHandle*)mso_sptLeftRightUpArrowHandle, sizeof( mso_sptLeftRightUpArrowHandle ) / sizeof( SvxMSDffHandle )      // handles
 };
@@ -1044,7 +1049,7 @@
     (sal_Int32*)mso_sptBentArrowDefault,
     (SvxMSDffTextRectangles*)mso_sptBentArrowTextRect, sizeof( mso_sptBentArrowTextRect ) / sizeof( SvxMSDffTextRectangles ),
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     NULL, 0,
     (SvxMSDffHandle*)mso_sptBentArrowHandle, sizeof( mso_sptBentArrowHandle ) / sizeof( SvxMSDffHandle )        // handles
 };
@@ -1075,7 +1080,7 @@
     NULL,
     (SvxMSDffTextRectangles*)mso_sptUturnArrowTextRect, sizeof( mso_sptUturnArrowTextRect ) / sizeof( SvxMSDffTextRectangles ),
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     NULL, 0,
     NULL, 0     // handles
 };
@@ -1117,7 +1122,7 @@
     {   MSDFF_HANDLE_FLAGS_RANGE | MSDFF_HANDLE_FLAGS_RANGE_Y_MAX_IS_SPECIAL | MSDFF_HANDLE_FLAGS_RANGE_X_MIN_IS_SPECIAL,
         0x101, 0x102, 10800, 10800, 3 + 5, 21600, 0, 0x100 },
     {   MSDFF_HANDLE_FLAGS_RANGE | MSDFF_HANDLE_FLAGS_RANGE_X_MIN_IS_SPECIAL | MSDFF_HANDLE_FLAGS_RANGE_X_MAX_IS_SPECIAL,
-        0x100, 0, 10800, 10800, 0x102, 3 + 9, 0x80000000, 0x7fffffff }
+        0x100, 0, 10800, 10800, 0x102, 3 + 9, MIN_INT32, 0x7fffffff }
 };
 static const mso_CustomShape msoLeftUpArrow =
 {
@@ -1127,7 +1132,7 @@
     (sal_Int32*)mso_sptLeftUpArrowDefault,
     (SvxMSDffTextRectangles*)mso_sptLeftUpArrowTextRect, sizeof( mso_sptLeftUpArrowTextRect ) / sizeof( SvxMSDffTextRectangles ),
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     NULL, 0,
     (SvxMSDffHandle*)mso_sptLeftUpArrowHandle, sizeof( mso_sptLeftUpArrowHandle ) / sizeof( SvxMSDffHandle )        // handles
 };
@@ -1170,7 +1175,7 @@
     {   MSDFF_HANDLE_FLAGS_RANGE | MSDFF_HANDLE_FLAGS_RANGE_Y_MAX_IS_SPECIAL | MSDFF_HANDLE_FLAGS_RANGE_X_MIN_IS_SPECIAL,
         0x101, 0x102, 10800, 10800, 3 + 5, 21600, 0, 0x100 },
     {   MSDFF_HANDLE_FLAGS_RANGE | MSDFF_HANDLE_FLAGS_RANGE_X_MIN_IS_SPECIAL | MSDFF_HANDLE_FLAGS_RANGE_X_MAX_IS_SPECIAL,
-        0x100, 0, 10800, 10800, 0x102, 3 + 10, 0x80000000, 0x7fffffff }
+        0x100, 0, 10800, 10800, 0x102, 3 + 10, MIN_INT32, 0x7fffffff }
 };
 static const mso_CustomShape msoBentUpArrow =
 {
@@ -1180,7 +1185,7 @@
     (sal_Int32*)mso_sptBentUpArrowDefault,
     (SvxMSDffTextRectangles*)mso_sptBentUpArrowTextRect, sizeof( mso_sptBentUpArrowTextRect ) / sizeof( SvxMSDffTextRectangles ),
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     NULL, 0,
     (SvxMSDffHandle*)mso_sptBentUpArrowHandle, sizeof( mso_sptBentUpArrowHandle ) / sizeof( SvxMSDffHandle )
 };
@@ -1288,7 +1293,7 @@
     (sal_Int32*)mso_sptCurvedRightDefault,
     (SvxMSDffTextRectangles*)mso_sptCurvedRightTextRect, sizeof( mso_sptCurvedRightTextRect ) / sizeof( SvxMSDffTextRectangles ),
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     (SvxMSDffVertPair*)mso_sptCurvedRightGluePoints, sizeof( mso_sptCurvedRightGluePoints ) / sizeof( SvxMSDffVertPair ),
     (SvxMSDffHandle*)mso_sptCurvedRightHandles, sizeof( mso_sptCurvedRightHandles ) / sizeof( SvxMSDffHandle )
 };
@@ -1343,7 +1348,7 @@
    (sal_Int32*)mso_sptCurvedRightDefault,
    (SvxMSDffTextRectangles*)mso_sptCurvedDownTextRect, sizeof( mso_sptCurvedDownTextRect ) / sizeof( SvxMSDffTextRectangles ),
    21600, 21600,
-   0x80000000, 0x80000000,
+   MIN_INT32, MIN_INT32,
    (SvxMSDffVertPair*)mso_sptCurvedDownGluePoints, sizeof( mso_sptCurvedDownGluePoints ) / sizeof( SvxMSDffVertPair ),
    (SvxMSDffHandle*)mso_sptCurvedDownHandles, sizeof( mso_sptCurvedDownHandles ) / sizeof( SvxMSDffHandle )
 };
@@ -1449,7 +1454,7 @@
    (sal_Int32*)mso_sptCurvedUpDefault,
    (SvxMSDffTextRectangles*)mso_sptCurvedUpTextRect, sizeof( mso_sptCurvedUpTextRect ) / sizeof( SvxMSDffTextRectangles ),
    21600, 21600,
-   0x80000000, 0x80000000,
+   MIN_INT32, MIN_INT32,
    (SvxMSDffVertPair*)mso_sptCurvedUpGluePoints, sizeof( mso_sptCurvedUpGluePoints ) / sizeof( SvxMSDffVertPair ),
    (SvxMSDffHandle*)mso_sptCurvedUpHandles, sizeof( mso_sptCurvedUpHandles ) / sizeof( SvxMSDffHandle )
 };
@@ -1502,7 +1507,7 @@
     (sal_Int32*)mso_sptCurvedUpDefault,
     (SvxMSDffTextRectangles*)mso_sptCurvedLeftTextRect, sizeof( mso_sptCurvedLeftTextRect ) / sizeof( SvxMSDffTextRectangles ),
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     (SvxMSDffVertPair*)mso_sptCurvedLeftGluePoints, sizeof( mso_sptCurvedLeftGluePoints ) / sizeof( SvxMSDffVertPair ),
     (SvxMSDffHandle*)mso_sptCurvedLeftHandles, sizeof( mso_sptCurvedLeftHandles ) / sizeof( SvxMSDffHandle )
 };
@@ -1546,7 +1551,7 @@
     (sal_Int32*)mso_sptDefault16200and5400,
     (SvxMSDffTextRectangles*)mso_sptStripedRightArrowTextRect, sizeof( mso_sptStripedRightArrowTextRect ) / sizeof( SvxMSDffTextRectangles ),
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     NULL, 0,
     (SvxMSDffHandle*)mso_sptStripedRightArrowHandle, sizeof( mso_sptStripedRightArrowHandle ) / sizeof( SvxMSDffHandle )
 };
@@ -1582,7 +1587,7 @@
     (sal_Int32*)mso_sptDefault16200and5400,
     (SvxMSDffTextRectangles*)mso_sptNotchedRightArrowTextRect, sizeof( mso_sptNotchedRightArrowTextRect ) / sizeof( SvxMSDffTextRectangles ),
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     NULL, 0,
     (SvxMSDffHandle*)mso_sptNotchedRightArrowHandle, sizeof( mso_sptNotchedRightArrowHandle ) / sizeof( SvxMSDffHandle )
 };
@@ -1611,7 +1616,7 @@
 static const SvxMSDffHandle mso_sptHomePlateHandle[] =
 {
     {   MSDFF_HANDLE_FLAGS_RANGE,
-        0x100, 0, 10800, 10800, 0, 21600, 0x80000000, 0x7fffffff }
+        0x100, 0, 10800, 10800, 0, 21600, MIN_INT32, 0x7fffffff }
 };
 static const mso_CustomShape msoHomePlate =
 {
@@ -1621,7 +1626,7 @@
     (sal_Int32*)mso_sptHomePlateDefault,
     (SvxMSDffTextRectangles*)mso_sptHomePlateTextRect, sizeof( mso_sptHomePlateTextRect ) / sizeof( SvxMSDffTextRectangles ),
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     NULL, 0,
     (SvxMSDffHandle*)mso_sptHomePlateHandle, sizeof( mso_sptHomePlateHandle ) / sizeof( SvxMSDffHandle )
 };
@@ -1651,7 +1656,7 @@
 static const SvxMSDffHandle mso_sptChevronHandle[] =
 {
     {   MSDFF_HANDLE_FLAGS_RANGE,
-        0x100, 0, 10800, 10800, 0, 21600, 0x80000000, 0x7fffffff }
+        0x100, 0, 10800, 10800, 0, 21600, MIN_INT32, 0x7fffffff }
 };
 static const mso_CustomShape msoChevron =
 {
@@ -1661,7 +1666,7 @@
     (sal_Int32*)mso_sptChevronDefault,
     (SvxMSDffTextRectangles*)mso_sptChevronTextRect, sizeof( mso_sptChevronTextRect ) / sizeof( SvxMSDffTextRectangles ),
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     NULL, 0,
     (SvxMSDffHandle*)mso_sptChevronHandle, sizeof( mso_sptChevronHandle ) / sizeof( SvxMSDffHandle )
 };
@@ -1696,11 +1701,11 @@
 static const SvxMSDffHandle mso_sptRightArrowCalloutHandle[] =
 {
     {   MSDFF_HANDLE_FLAGS_RANGE | MSDFF_HANDLE_FLAGS_RANGE_X_MAX_IS_SPECIAL,
-        0x100, 0, 10800, 10800, 0, 0x102, 0x80000000, 0x7fffffff },
+        0x100, 0, 10800, 10800, 0, 0x102, MIN_INT32, 0x7fffffff },
     {   MSDFF_HANDLE_FLAGS_RANGE | MSDFF_HANDLE_FLAGS_RANGE_X_MIN_IS_SPECIAL | MSDFF_HANDLE_FLAGS_RANGE_Y_MIN_IS_SPECIAL,
         0x102, 0x103, 10800, 10800, 0x100, 21600, 0x101, 10800 },
     {   MSDFF_HANDLE_FLAGS_RANGE | MSDFF_HANDLE_FLAGS_RANGE_Y_MAX_IS_SPECIAL,
-        1, 0x101, 10800, 10800, 0x80000000, 0x7fffffff, 0, 0x103 }
+        1, 0x101, 10800, 10800, MIN_INT32, 0x7fffffff, 0, 0x103 }
 };
 static const mso_CustomShape msoRightArrowCallout =
 {
@@ -1710,7 +1715,7 @@
     (sal_Int32*)mso_sptRightArrowCalloutDefault,
     (SvxMSDffTextRectangles*)mso_sptRightArrowCalloutTextRect, sizeof( mso_sptRightArrowCalloutTextRect ) / sizeof( SvxMSDffTextRectangles ),
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     NULL, 0,
     (SvxMSDffHandle*)mso_sptRightArrowCalloutHandle, sizeof( mso_sptRightArrowCalloutHandle ) / sizeof( SvxMSDffHandle )
 };
@@ -1745,11 +1750,11 @@
 static const SvxMSDffHandle mso_sptLeftArrowCalloutHandle[] =
 {
     {   MSDFF_HANDLE_FLAGS_RANGE | MSDFF_HANDLE_FLAGS_RANGE_X_MIN_IS_SPECIAL,
-        0x100, 0, 10800, 10800, 0x102, 21600, 0x80000000, 0x7fffffff },
+        0x100, 0, 10800, 10800, 0x102, 21600, MIN_INT32, 0x7fffffff },
     {   MSDFF_HANDLE_FLAGS_RANGE | MSDFF_HANDLE_FLAGS_RANGE_X_MAX_IS_SPECIAL | MSDFF_HANDLE_FLAGS_RANGE_Y_MIN_IS_SPECIAL,
         0x102, 0x103, 10800, 10800, 0, 0x100, 0x101, 10800 },
     {   MSDFF_HANDLE_FLAGS_RANGE | MSDFF_HANDLE_FLAGS_RANGE_Y_MAX_IS_SPECIAL,
-        0, 0x101, 10800, 10800, 0x80000000, 0x7fffffff, 0, 0x103 }
+        0, 0x101, 10800, 10800, MIN_INT32, 0x7fffffff, 0, 0x103 }
 };
 static const mso_CustomShape msoLeftArrowCallout =
 {
@@ -1759,7 +1764,7 @@
     (sal_Int32*)mso_sptLeftArrowCalloutDefault,
     (SvxMSDffTextRectangles*)mso_sptLeftArrowCalloutTextRect, sizeof( mso_sptLeftArrowCalloutTextRect ) / sizeof( SvxMSDffTextRectangles ),
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     NULL, 0,
     (SvxMSDffHandle*)mso_sptLeftArrowCalloutHandle, sizeof( mso_sptLeftArrowCalloutHandle ) / sizeof( SvxMSDffHandle )
 };
@@ -1794,11 +1799,11 @@
 static const SvxMSDffHandle mso_sptUpArrowCalloutHandle[] =
 {
     {   MSDFF_HANDLE_FLAGS_RANGE | MSDFF_HANDLE_FLAGS_RANGE_Y_MIN_IS_SPECIAL,
-        0, 0x100, 10800, 10800, 0x80000000, 0x7fffffff, 0x102, 21600 },
+        0, 0x100, 10800, 10800, MIN_INT32, 0x7fffffff, 0x102, 21600 },
     {   MSDFF_HANDLE_FLAGS_RANGE | MSDFF_HANDLE_FLAGS_RANGE_X_MIN_IS_SPECIAL | MSDFF_HANDLE_FLAGS_RANGE_Y_MAX_IS_SPECIAL,
         0x103, 0x102, 10800, 10800, 0x101, 10800, 0, 0x100 },
     {   MSDFF_HANDLE_FLAGS_RANGE | MSDFF_HANDLE_FLAGS_RANGE_X_MAX_IS_SPECIAL,
-        0x101, 0, 10800, 10800, 0, 0x103, 0x80000000, 0x7fffffff }
+        0x101, 0, 10800, 10800, 0, 0x103, MIN_INT32, 0x7fffffff }
 };
 static const mso_CustomShape msoUpArrowCallout =
 {
@@ -1808,7 +1813,7 @@
     (sal_Int32*)mso_sptUpArrowCalloutDefault,
     (SvxMSDffTextRectangles*)mso_sptUpArrowCalloutTextRect, sizeof( mso_sptUpArrowCalloutTextRect ) / sizeof( SvxMSDffTextRectangles ),
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     NULL, 0,
     (SvxMSDffHandle*)mso_sptUpArrowCalloutHandle, sizeof( mso_sptUpArrowCalloutHandle ) / sizeof( SvxMSDffHandle )
 };
@@ -1843,11 +1848,11 @@
 static const SvxMSDffHandle mso_sptDownArrowCalloutHandle[] =
 {
     {   MSDFF_HANDLE_FLAGS_RANGE | MSDFF_HANDLE_FLAGS_RANGE_Y_MAX_IS_SPECIAL,
-        0, 0x100, 10800, 10800, 0x80000000, 0x7fffffff, 0, 0x102 },
+        0, 0x100, 10800, 10800, MIN_INT32, 0x7fffffff, 0, 0x102 },
     {   MSDFF_HANDLE_FLAGS_RANGE | MSDFF_HANDLE_FLAGS_RANGE_X_MIN_IS_SPECIAL | MSDFF_HANDLE_FLAGS_RANGE_Y_MIN_IS_SPECIAL,
         0x103, 0x102, 10800, 10800, 0x101, 10800, 0x100, 21600 },
     {   MSDFF_HANDLE_FLAGS_RANGE | MSDFF_HANDLE_FLAGS_RANGE_X_MAX_IS_SPECIAL,
-        0x101, 1, 10800, 10800, 0, 0x103, 0x80000000, 0x7fffffff }
+        0x101, 1, 10800, 10800, 0, 0x103, MIN_INT32, 0x7fffffff }
 };
 static const mso_CustomShape msoDownArrowCallout =
 {
@@ -1857,7 +1862,7 @@
     (sal_Int32*)mso_sptDownArrowCalloutDefault,
     (SvxMSDffTextRectangles*)mso_sptDownArrowCalloutTextRect, sizeof( mso_sptDownArrowCalloutTextRect ) / sizeof( SvxMSDffTextRectangles ),
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     NULL, 0,
     (SvxMSDffHandle*)mso_sptDownArrowCalloutHandle, sizeof( mso_sptDownArrowCalloutHandle ) / sizeof( SvxMSDffHandle )
 };
@@ -1896,11 +1901,11 @@
 static const SvxMSDffHandle mso_sptLeftRightArrowCalloutHandle[] =
 {
     {   MSDFF_HANDLE_FLAGS_RANGE | MSDFF_HANDLE_FLAGS_RANGE_X_MIN_IS_SPECIAL,
-        0x100, 0, 10800, 10800, 0x102, 10800, 0x80000000, 0x7fffffff },
+        0x100, 0, 10800, 10800, 0x102, 10800, MIN_INT32, 0x7fffffff },
     {   MSDFF_HANDLE_FLAGS_RANGE | MSDFF_HANDLE_FLAGS_RANGE_X_MAX_IS_SPECIAL | MSDFF_HANDLE_FLAGS_RANGE_Y_MIN_IS_SPECIAL,
         0x102, 0x103, 10800, 10800, 0, 0x100, 0x101, 10800 },
     {   MSDFF_HANDLE_FLAGS_RANGE | MSDFF_HANDLE_FLAGS_RANGE_Y_MAX_IS_SPECIAL,
-        0, 0x101, 10800, 10800, 0x80000000, 0x7fffffff, 0, 0x103 }
+        0, 0x101, 10800, 10800, MIN_INT32, 0x7fffffff, 0, 0x103 }
 };
 static const mso_CustomShape msoLeftRightArrowCallout =
 {
@@ -1910,7 +1915,7 @@
     (sal_Int32*)mso_sptLeftRightArrowCalloutDefault,
     (SvxMSDffTextRectangles*)mso_sptLeftRightArrowCalloutTextRect, sizeof( mso_sptLeftRightArrowCalloutTextRect ) / sizeof( SvxMSDffTextRectangles ),
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     NULL, 0,
     (SvxMSDffHandle*)mso_sptLeftRightArrowCalloutHandle, sizeof( mso_sptLeftRightArrowCalloutHandle ) / sizeof( SvxMSDffHandle )
 };
@@ -1949,11 +1954,11 @@
 static const SvxMSDffHandle mso_sptUpDownArrowCalloutHandle[] =
 {
     {   MSDFF_HANDLE_FLAGS_RANGE | MSDFF_HANDLE_FLAGS_RANGE_Y_MIN_IS_SPECIAL,
-        0, 0x100, 10800, 10800, 0x80000000, 0x7fffffff, 0x102, 10800 },
+        0, 0x100, 10800, 10800, MIN_INT32, 0x7fffffff, 0x102, 10800 },
     {   MSDFF_HANDLE_FLAGS_RANGE | MSDFF_HANDLE_FLAGS_RANGE_X_MIN_IS_SPECIAL | MSDFF_HANDLE_FLAGS_RANGE_Y_MAX_IS_SPECIAL,
         0x103, 0x102, 10800, 10800, 0x101, 10800, 0, 0x100 },
     {   MSDFF_HANDLE_FLAGS_RANGE | MSDFF_HANDLE_FLAGS_RANGE_X_MAX_IS_SPECIAL,
-        0x101, 0, 10800, 10800, 0, 0x103, 0x80000000, 0x7fffffff }
+        0x101, 0, 10800, 10800, 0, 0x103, MIN_INT32, 0x7fffffff }
 };
 static const mso_CustomShape msoUpDownArrowCallout =
 {
@@ -1963,7 +1968,7 @@
     (sal_Int32*)mso_sptUpDownArrowCalloutDefault,
     (SvxMSDffTextRectangles*)mso_sptUpDownArrowCalloutTextRect, sizeof( mso_sptUpDownArrowCalloutTextRect ) / sizeof( SvxMSDffTextRectangles ),
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     NULL, 0,
     (SvxMSDffHandle*)mso_sptUpDownArrowCalloutHandle, sizeof( mso_sptUpDownArrowCalloutHandle ) / sizeof( SvxMSDffHandle )
 };
@@ -2005,9 +2010,9 @@
 static const SvxMSDffHandle mso_sptQuadArrowCalloutHandle[] =
 {
     {   MSDFF_HANDLE_FLAGS_RANGE | MSDFF_HANDLE_FLAGS_RANGE_Y_MIN_IS_SPECIAL | MSDFF_HANDLE_FLAGS_RANGE_Y_MAX_IS_SPECIAL,
-        0, 0x100, 10800, 10800, 0x80000000, 0x7fffffff, 0x102, 0x101 },
+        0, 0x100, 10800, 10800, MIN_INT32, 0x7fffffff, 0x102, 0x101 },
     {   MSDFF_HANDLE_FLAGS_RANGE | MSDFF_HANDLE_FLAGS_RANGE_X_MIN_IS_SPECIAL,
-        0x101, 0, 10800, 10800, 0x100, 10800, 0x80000000, 0x7fffffff },
+        0x101, 0, 10800, 10800, 0x100, 10800, MIN_INT32, 0x7fffffff },
     {   MSDFF_HANDLE_FLAGS_RANGE | MSDFF_HANDLE_FLAGS_RANGE_X_MIN_IS_SPECIAL | MSDFF_HANDLE_FLAGS_RANGE_Y_MAX_IS_SPECIAL,
         0x103, 0x102, 10800, 10800, 0x101, 10800, 0, 0x100 }
 };
@@ -2019,7 +2024,7 @@
     (sal_Int32*)mso_sptQuadArrowCalloutDefault,
     (SvxMSDffTextRectangles*)mso_sptQuadArrowCalloutTextRect, sizeof( mso_sptQuadArrowCalloutTextRect ) / sizeof( SvxMSDffTextRectangles ),
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     NULL, 0,
     (SvxMSDffHandle*)mso_sptQuadArrowCalloutHandle, sizeof( mso_sptQuadArrowCalloutHandle ) / sizeof( SvxMSDffHandle )
 };
@@ -2103,9 +2108,9 @@
 static const SvxMSDffHandle mso_sptCircularArrowHandle[] =
 {
     {   MSDFF_HANDLE_FLAGS_POLAR | MSDFF_HANDLE_FLAGS_RADIUS_RANGE,
-        10800, 0x100, 10800, 10800, 10800, 10800, 0xff4c0000, 0x00b40000 },
+        10800, 0x100, 10800, 10800, 10800, 10800, -0x7f4c0000, 0x00b40000 },
     {   MSDFF_HANDLE_FLAGS_POLAR | MSDFF_HANDLE_FLAGS_RADIUS_RANGE,
-        0x102, 0x101, 10800, 10800, 0, 10800, 0xff4c0000, 0x00b40000 }
+        0x102, 0x101, 10800, 10800, 0, 10800, -0x7f4c0000, 0x00b40000 }
 };
 static const mso_CustomShape msoCircularArrow =
 {
@@ -2115,7 +2120,7 @@
     (sal_Int32*)mso_sptCircularArrowDefault,
     (SvxMSDffTextRectangles*)mso_sptCircularArrowTextRect, sizeof( mso_sptCircularArrowTextRect ) / sizeof( SvxMSDffTextRectangles ),
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     NULL, 0,
     (SvxMSDffHandle*)mso_sptCircularArrowHandle, sizeof( mso_sptCircularArrowHandle ) / sizeof( SvxMSDffHandle )        // handles
 };
@@ -2155,7 +2160,7 @@
 static const SvxMSDffHandle mso_sptCubeHandle[] =
 {
     {   MSDFF_HANDLE_FLAGS_RANGE | MSDFF_HANDLE_FLAGS_SWITCHED,
-        0, 0x100, 10800, 10800, 0x80000000, 0x7fffffff, 0, 21600 }
+        0, 0x100, 10800, 10800, MIN_INT32, 0x7fffffff, 0, 21600 }
 };
 static const SvxMSDffVertPair mso_sptCubeGluePoints[] =
 {
@@ -2204,7 +2209,7 @@
 static const SvxMSDffHandle mso_sptBevelHandle[] =
 {
     {   MSDFF_HANDLE_FLAGS_RANGE | MSDFF_HANDLE_FLAGS_SWITCHED,
-        0x100, 0, 10800, 10800, 0, 10800, 0x80000000, 0x7fffffff }
+        0x100, 0, 10800, 10800, 0, 10800, MIN_INT32, 0x7fffffff }
 };
 static const mso_CustomShape msoBevel =
 {
@@ -2256,7 +2261,7 @@
 static const SvxMSDffHandle mso_sptFoldedCornerHandle[] =
 {
     {   MSDFF_HANDLE_FLAGS_RANGE,
-        0x100, 1, 10800, 10800, 10800, 21600, 0x80000000, 0x7fffffff }
+        0x100, 1, 10800, 10800, 10800, 21600, MIN_INT32, 0x7fffffff }
 };
 static const mso_CustomShape msoFoldedCorner =
 {
@@ -2266,7 +2271,7 @@
     (sal_Int32*)mso_sptFoldedCornerDefault,
     (SvxMSDffTextRectangles*)mso_sptFoldedCornerTextRect, sizeof( mso_sptFoldedCornerTextRect ) / sizeof( SvxMSDffTextRectangles ),
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     (SvxMSDffVertPair*)mso_sptStandardGluePoints, sizeof( mso_sptStandardGluePoints ) / sizeof( SvxMSDffVertPair ),
     (SvxMSDffHandle*)mso_sptFoldedCornerHandle, sizeof( mso_sptFoldedCornerHandle ) / sizeof( SvxMSDffHandle )
 };
@@ -2300,7 +2305,7 @@
 static const SvxMSDffHandle mso_sptButtonHandle[] =
 {
     {   MSDFF_HANDLE_FLAGS_RANGE | MSDFF_HANDLE_FLAGS_SWITCHED,
-        0x100, 0, 10800, 10800, 0, 5400, 0x80000000, 0x7fffffff }
+        0x100, 0, 10800, 10800, 0, 5400, MIN_INT32, 0x7fffffff }
 };
 static const mso_CustomShape msoActionButtonBlank =
 {
@@ -3111,7 +3116,7 @@
 static const SvxMSDffHandle mso_sptSmileyHandle[] =
 {
     {   MSDFF_HANDLE_FLAGS_RANGE,
-        10800, 0x100, 10800, 10800, 0x80000000, 0x7fffffff, 15510, 17520 }
+        10800, 0x100, 10800, 10800, MIN_INT32, 0x7fffffff, 15510, 17520 }
 };
 static const mso_CustomShape msoSmileyFace =
 {
@@ -3121,7 +3126,7 @@
     (sal_Int32*)mso_sptSmileyFaceDefault,
     (SvxMSDffTextRectangles*)mso_sptEllipseTextRect, sizeof( mso_sptEllipseTextRect ) / sizeof( SvxMSDffTextRectangles ),
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     (SvxMSDffVertPair*)mso_sptEllipseGluePoints, sizeof( mso_sptEllipseGluePoints ) / sizeof( SvxMSDffVertPair ),
     (SvxMSDffHandle*)mso_sptSmileyHandle, sizeof( mso_sptSmileyHandle ) / sizeof( SvxMSDffHandle )      // handles
 };
@@ -3143,7 +3148,7 @@
 static const SvxMSDffHandle mso_sptDonutHandle[] =
 {
     {   MSDFF_HANDLE_FLAGS_RANGE,
-        0x100, 10800, 10800, 10800, 0, 10800, 0x80000000, 0x7fffffff }
+        0x100, 10800, 10800, 10800, 0, 10800, MIN_INT32, 0x7fffffff }
 };
 static const mso_CustomShape msoDonut =
 {
@@ -3153,7 +3158,7 @@
     (sal_Int32*)mso_sptDefault5400,
     (SvxMSDffTextRectangles*)mso_sptEllipseTextRect, sizeof( mso_sptEllipseTextRect ) / sizeof( SvxMSDffTextRectangles ),
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     (SvxMSDffVertPair*)mso_sptEllipseGluePoints, sizeof( mso_sptEllipseGluePoints ) / sizeof( SvxMSDffVertPair ),
     (SvxMSDffHandle*)mso_sptDonutHandle, sizeof( mso_sptDonutHandle ) / sizeof( SvxMSDffHandle )        // handles
 };
@@ -3192,7 +3197,7 @@
 static const SvxMSDffHandle mso_sptNoSmokingHandle[] =
 {
     {   MSDFF_HANDLE_FLAGS_RANGE,
-        0x100, 10800, 10800, 10800, 0, 7200, 0x80000000, 0x7fffffff }
+        0x100, 10800, 10800, 10800, 0, 7200, MIN_INT32, 0x7fffffff }
 };
 static const mso_CustomShape msoNoSmoking =
 {
@@ -3202,7 +3207,7 @@
     (sal_Int32*)mso_sptDefault2700,
     (SvxMSDffTextRectangles*)mso_sptEllipseTextRect, sizeof( mso_sptEllipseTextRect ) / sizeof( SvxMSDffTextRectangles ),
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     (SvxMSDffVertPair*)mso_sptEllipseGluePoints, sizeof( mso_sptEllipseGluePoints ) / sizeof( SvxMSDffVertPair ),
     (SvxMSDffHandle*)mso_sptNoSmokingHandle, sizeof( mso_sptNoSmokingHandle ) / sizeof( SvxMSDffHandle )        // handles
 };
@@ -3235,7 +3240,7 @@
 static const SvxMSDffHandle mso_sptBlockArcHandle[] =
 {
     {   MSDFF_HANDLE_FLAGS_POLAR | MSDFF_HANDLE_FLAGS_RADIUS_RANGE,
-        0x101, 0x100, 10800, 10800, 0, 10800, 0x80000000, 0x7fffffff }
+        0x101, 0x100, 10800, 10800, 0, 10800, MIN_INT32, 0x7fffffff }
 };
 static const mso_CustomShape msoBlockArc =
 {
@@ -3245,7 +3250,7 @@
     (sal_Int32*)mso_sptBlockArcDefault,
     NULL, 0,
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     NULL, 0,
     (SvxMSDffHandle*)mso_sptBlockArcHandle, sizeof( mso_sptBlockArcHandle ) / sizeof( SvxMSDffHandle )      // handles
 };
@@ -3309,7 +3314,7 @@
     NULL,
     (SvxMSDffTextRectangles*)mso_sptHeartTextRect, sizeof( mso_sptHeartTextRect ) / sizeof( SvxMSDffTextRectangles ),
     21615, 21602,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     (SvxMSDffVertPair*)mso_sptHeartGluePoints, sizeof( mso_sptHeartGluePoints ) / sizeof( SvxMSDffVertPair ),
     NULL, 0     // handles
 };
@@ -3337,7 +3342,7 @@
     NULL,
     (SvxMSDffTextRectangles*)mso_sptLightningBoldTextRect, sizeof( mso_sptLightningBoldTextRect ) / sizeof( SvxMSDffTextRectangles ),
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     (SvxMSDffVertPair*)mso_sptLightningBoldGluePoints, sizeof( mso_sptLightningBoldGluePoints ) / sizeof( SvxMSDffVertPair ),
     NULL, 0     // handles
 };
@@ -3431,7 +3436,7 @@
 static const SvxMSDffHandle mso_sptSunHandle[] =
 {
     {   MSDFF_HANDLE_FLAGS_RANGE,
-        0x100, 10800, 10800, 10800, 2700, 10125, 0x80000000, 0x7fffffff }
+        0x100, 10800, 10800, 10800, 2700, 10125, MIN_INT32, 0x7fffffff }
 };
 static const mso_CustomShape msoSun =
 {
@@ -3441,7 +3446,7 @@
     (sal_Int32*)mso_sptDefault5400,
     (SvxMSDffTextRectangles*)mso_sptSunTextRect, sizeof( mso_sptSunTextRect ) / sizeof( SvxMSDffTextRectangles ),
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     (SvxMSDffVertPair*)mso_sptStandardGluePoints, sizeof( mso_sptStandardGluePoints ) / sizeof( SvxMSDffVertPair ),
     (SvxMSDffHandle*)mso_sptSunHandle, sizeof( mso_sptSunHandle ) / sizeof( SvxMSDffHandle )        // handles
 };
@@ -3483,7 +3488,7 @@
 static const SvxMSDffHandle mso_sptMoonHandle[] =
 {
     {   MSDFF_HANDLE_FLAGS_RANGE,
-        0x100, 10800, 10800, 10800, 0, 18900, 0x80000000, 0x7fffffff }
+        0x100, 10800, 10800, 10800, 0, 18900, MIN_INT32, 0x7fffffff }
 };
 static const mso_CustomShape msoMoon =
 {
@@ -3493,7 +3498,7 @@
     (sal_Int32*)mso_sptDefault10800,
     (SvxMSDffTextRectangles*)mso_sptMoonTextRect, sizeof( mso_sptMoonTextRect ) / sizeof( SvxMSDffTextRectangles ),
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     (SvxMSDffVertPair*)mso_sptMoonGluePoints, sizeof( mso_sptMoonGluePoints ) / sizeof( SvxMSDffVertPair ),
     (SvxMSDffHandle*)mso_sptMoonHandle, sizeof( mso_sptMoonHandle ) / sizeof( SvxMSDffHandle )      // handles
 };
@@ -3536,7 +3541,7 @@
 static const SvxMSDffHandle mso_sptBracketPairHandle[] =
 {
     {   MSDFF_HANDLE_FLAGS_RANGE | MSDFF_HANDLE_FLAGS_SWITCHED,
-        0x100, 0, 10800, 10800, 0, 10800, 0x80000000, 0x7fffffff }
+        0x100, 0, 10800, 10800, 0, 10800, MIN_INT32, 0x7fffffff }
 };
 static const mso_CustomShape msoBracketPair =
 {
@@ -3546,7 +3551,7 @@
     (sal_Int32*)mso_sptDefault3700,
     (SvxMSDffTextRectangles*)mso_sptBracketPairTextRect, sizeof( mso_sptBracketPairTextRect ) / sizeof( SvxMSDffTextRectangles ),
     21600, 21600,
-    10800, 0x80000000,
+    10800, MIN_INT32,
     (SvxMSDffVertPair*)mso_sptStandardGluePoints, sizeof( mso_sptStandardGluePoints ) / sizeof( SvxMSDffVertPair ),
     (SvxMSDffHandle*)mso_sptBracketPairHandle, sizeof( mso_sptBracketPairHandle ) / sizeof( SvxMSDffHandle )        // handles
 };
@@ -3562,7 +3567,7 @@
 static const SvxMSDffHandle mso_sptPlaqueHandle[] =
 {
     {   MSDFF_HANDLE_FLAGS_RANGE | MSDFF_HANDLE_FLAGS_SWITCHED,
-        0x100, 0, 10800, 10800, 0, 10800, 0x80000000, 0x7fffffff }
+        0x100, 0, 10800, 10800, 0, 10800, MIN_INT32, 0x7fffffff }
 };
 static const mso_CustomShape msoPlaque =
 {
@@ -3614,7 +3619,7 @@
 static const SvxMSDffHandle mso_sptBracePairHandle[] =
 {
     {   MSDFF_HANDLE_FLAGS_RANGE | MSDFF_HANDLE_FLAGS_SWITCHED,
-        0, 0x100, 10800, 10800, 0x80000000, 0x7fffffff, 0, 5400 }
+        0, 0x100, 10800, 10800, MIN_INT32, 0x7fffffff, 0, 5400 }
 };
 static const mso_CustomShape msoBracePair =
 {
@@ -3624,7 +3629,7 @@
     (sal_Int32*)mso_sptDefault1800,
     (SvxMSDffTextRectangles*)mso_sptBracePairTextRect, sizeof( mso_sptBracePairTextRect ) / sizeof( SvxMSDffTextRectangles ),
     21600, 21600,
-    10800, 0x80000000,
+    10800, MIN_INT32,
     (SvxMSDffVertPair*)mso_sptStandardGluePoints, sizeof( mso_sptStandardGluePoints ) / sizeof( SvxMSDffVertPair ),
     (SvxMSDffHandle*)mso_sptBracePairHandle, sizeof( mso_sptBracePairHandle ) / sizeof( SvxMSDffHandle )        // handles
 };
@@ -3657,7 +3662,7 @@
 static const SvxMSDffHandle mso_sptLeftBracketHandle[] =
 {
     {   MSDFF_HANDLE_FLAGS_RANGE,
-        0, 0x100, 10800, 10800, 0x80000000, 0x7fffffff, 0, 10800 }
+        0, 0x100, 10800, 10800, MIN_INT32, 0x7fffffff, 0, 10800 }
 };
 static const mso_CustomShape msoLeftBracket =
 {
@@ -3667,7 +3672,7 @@
     (sal_Int32*)mso_sptDefault1800,
     (SvxMSDffTextRectangles*)mso_sptLeftBracketTextRect, sizeof( mso_sptLeftBracketTextRect ) / sizeof( SvxMSDffTextRectangles ),
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     (SvxMSDffVertPair*)mso_sptLeftBracketGluePoints, sizeof( mso_sptLeftBracketGluePoints ) / sizeof( SvxMSDffVertPair ),
     (SvxMSDffHandle*)mso_sptLeftBracketHandle, sizeof( mso_sptLeftBracketHandle ) / sizeof( SvxMSDffHandle )        // handles
 };
@@ -3687,7 +3692,7 @@
 static const SvxMSDffHandle mso_sptRightBracketHandle[] =
 {
     {   MSDFF_HANDLE_FLAGS_RANGE,
-        1, 0x100, 10800, 10800, 0x80000000, 0x7fffffff, 0, 10800 }
+        1, 0x100, 10800, 10800, MIN_INT32, 0x7fffffff, 0, 10800 }
 };
 static const mso_CustomShape msoRightBracket =
 {
@@ -3697,7 +3702,7 @@
     (sal_Int32*)mso_sptDefault1800,
     (SvxMSDffTextRectangles*)mso_sptRightBracketTextRect, sizeof( mso_sptRightBracketTextRect ) / sizeof( SvxMSDffTextRectangles ),
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     (SvxMSDffVertPair*)mso_sptRightBracketGluePoints, sizeof( mso_sptRightBracketGluePoints ) / sizeof( SvxMSDffVertPair ),
     (SvxMSDffHandle*)mso_sptRightBracketHandle, sizeof( mso_sptRightBracketHandle ) / sizeof( SvxMSDffHandle )      // handles
 };
@@ -3741,9 +3746,9 @@
 static const SvxMSDffHandle mso_sptLeftBraceHandle[] =
 {
     {   MSDFF_HANDLE_FLAGS_RANGE,
-        10800, 0x100, 10800, 10800, 0x80000000, 0x7fffffff, 0, 5400 },
+        10800, 0x100, 10800, 10800, MIN_INT32, 0x7fffffff, 0, 5400 },
     {   MSDFF_HANDLE_FLAGS_RANGE,
-        0, 0x101, 10800, 10800, 0x80000000, 0x7fffffff, 0, 21600 }
+        0, 0x101, 10800, 10800, MIN_INT32, 0x7fffffff, 0, 21600 }
 };
 static const mso_CustomShape msoLeftBrace =     // adj value0 0 -> 5400
 {                                               // adj value1 0 -> 21600
@@ -3753,7 +3758,7 @@
     (sal_Int32*)mso_sptBraceDefault,
     (SvxMSDffTextRectangles*)mso_sptLeftBraceTextRect, sizeof( mso_sptLeftBraceTextRect ) / sizeof( SvxMSDffTextRectangles ),
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     (SvxMSDffVertPair*)mso_sptLeftBracketGluePoints, sizeof( mso_sptLeftBracketGluePoints ) / sizeof( SvxMSDffVertPair ),
     (SvxMSDffHandle*)mso_sptLeftBraceHandle, sizeof( mso_sptLeftBraceHandle ) / sizeof( SvxMSDffHandle )        // handles
 };
@@ -3774,9 +3779,9 @@
 static const SvxMSDffHandle mso_sptRightBraceHandle[] =
 {
     {   MSDFF_HANDLE_FLAGS_RANGE,
-        10800, 0x100, 10800, 10800, 0x80000000, 0x7fffffff, 0, 5400 },
+        10800, 0x100, 10800, 10800, MIN_INT32, 0x7fffffff, 0, 5400 },
     {   MSDFF_HANDLE_FLAGS_RANGE,
-        1, 0x101, 10800, 10800, 0x80000000, 0x7fffffff, 0, 21600 }
+        1, 0x101, 10800, 10800, MIN_INT32, 0x7fffffff, 0, 21600 }
 };
 static const mso_CustomShape msoRightBrace =        // adj value0 0 -> 5400
 {                                               // adj value1 0 -> 21600
@@ -3786,7 +3791,7 @@
     (sal_Int32*)mso_sptBraceDefault,
     (SvxMSDffTextRectangles*)mso_sptRightBraceTextRect, sizeof( mso_sptRightBraceTextRect ) / sizeof( SvxMSDffTextRectangles ),
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     (SvxMSDffVertPair*)mso_sptRightBracketGluePoints, sizeof( mso_sptRightBracketGluePoints ) / sizeof( SvxMSDffVertPair ),
     (SvxMSDffHandle*)mso_sptRightBraceHandle, sizeof( mso_sptRightBraceHandle ) / sizeof( SvxMSDffHandle )      // handles
 };
@@ -3816,7 +3821,7 @@
     NULL,
     (SvxMSDffTextRectangles*)mso_sptIrregularSeal1TextRect, sizeof( mso_sptIrregularSeal1TextRect ) / sizeof( SvxMSDffTextRectangles ),
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     (SvxMSDffVertPair*)mso_sptIrregularSeal1GluePoints, sizeof( mso_sptIrregularSeal1GluePoints ) / sizeof( SvxMSDffVertPair ),
     NULL, 0     // handles
 };
@@ -3848,7 +3853,7 @@
     NULL,
     (SvxMSDffTextRectangles*)mso_sptIrregularSeal2TextRect, sizeof( mso_sptIrregularSeal2TextRect ) / sizeof( SvxMSDffTextRectangles ),
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     (SvxMSDffVertPair*)mso_sptIrregularSeal2GluePoints, sizeof( mso_sptIrregularSeal2GluePoints ) / sizeof( SvxMSDffVertPair ),
     NULL, 0     // handles
 };
@@ -3874,7 +3879,7 @@
 static const SvxMSDffHandle mso_sptSealHandle[] =
 {
     {   MSDFF_HANDLE_FLAGS_RANGE,
-        0x100, 10800, 10800, 10800, 0, 10800, 0x80000000, 0x7fffffff }
+        0x100, 10800, 10800, 10800, 0, 10800, MIN_INT32, 0x7fffffff }
 };
 static const mso_CustomShape msoSeal4 =
 {
@@ -3884,7 +3889,7 @@
     (sal_Int32*)mso_sptDefault8100,
     (SvxMSDffTextRectangles*)mso_sptSeal4TextRect, sizeof( mso_sptSeal4TextRect ) / sizeof( SvxMSDffTextRectangles ),
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     NULL, 0,
     (SvxMSDffHandle*)mso_sptSealHandle, sizeof( mso_sptSealHandle ) / sizeof( SvxMSDffHandle )      // handles
 };
@@ -3907,7 +3912,7 @@
     NULL,
     (SvxMSDffTextRectangles*)mso_sptStarTextRect, sizeof( mso_sptStarTextRect ) / sizeof( SvxMSDffTextRectangles ),
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     NULL, 0,
     NULL, 0     // handles
 };
@@ -4036,7 +4041,7 @@
     (sal_Int32*)mso_sptDefault2500,
     (SvxMSDffTextRectangles*)mso_sptSealTextRect, sizeof( mso_sptSealTextRect ) / sizeof( SvxMSDffTextRectangles ),
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     NULL, 0,
     (SvxMSDffHandle*)mso_sptSealHandle, sizeof( mso_sptSealHandle ) / sizeof( SvxMSDffHandle )      // handles
 };
@@ -4132,7 +4137,7 @@
     (sal_Int32*)mso_sptDefault2500,
     (SvxMSDffTextRectangles*)mso_sptSealTextRect, sizeof( mso_sptSealTextRect ) / sizeof( SvxMSDffTextRectangles ),
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     NULL, 0,
     (SvxMSDffHandle*)mso_sptSealHandle, sizeof( mso_sptSealHandle ) / sizeof( SvxMSDffHandle )      // handles
 };
@@ -4160,7 +4165,7 @@
     (sal_Int32*)mso_sptDefault2500,
     (SvxMSDffTextRectangles*)mso_sptSealTextRect, sizeof( mso_sptSealTextRect ) / sizeof( SvxMSDffTextRectangles ),
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     NULL, 0,
     (SvxMSDffHandle*)mso_sptSealHandle, sizeof( mso_sptSealHandle ) / sizeof( SvxMSDffHandle )      // handles
 };
@@ -4328,7 +4333,7 @@
     (sal_Int32*)mso_sptDefault2500,
     (SvxMSDffTextRectangles*)mso_sptSealTextRect, sizeof( mso_sptSealTextRect ) / sizeof( SvxMSDffTextRectangles ),
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     NULL, 0,
     (SvxMSDffHandle*)mso_sptSealHandle, sizeof( mso_sptSealHandle ) / sizeof( SvxMSDffHandle )
 };
@@ -4413,9 +4418,9 @@
 static const SvxMSDffHandle mso_sptRibbon2Handle[] =
 {
     {   MSDFF_HANDLE_FLAGS_RANGE,
-        0x100, 0, 10800, 10800, 2700, 8100, 0x80000000, 0x7fffffff },
+        0x100, 0, 10800, 10800, 2700, 8100, MIN_INT32, 0x7fffffff },
     {   MSDFF_HANDLE_FLAGS_RANGE,
-        10800, 0x101, 10800, 10800, 0x80000000, 0x7fffffff, 14400, 21600 }
+        10800, 0x101, 10800, 10800, MIN_INT32, 0x7fffffff, 14400, 21600 }
 };
 static const mso_CustomShape msoRibbon2 =
 {
@@ -4425,7 +4430,7 @@
     (sal_Int32*)mso_sptRibbon2Default,
     (SvxMSDffTextRectangles*)mso_sptRibbon2TextRect, sizeof( mso_sptRibbon2TextRect ) / sizeof( SvxMSDffTextRectangles ),
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     NULL, 0,
     (SvxMSDffHandle*)mso_sptRibbon2Handle, sizeof( mso_sptRibbon2Handle ) / sizeof( SvxMSDffHandle )
 };
@@ -4494,9 +4499,9 @@
 static const SvxMSDffHandle mso_sptRibbonHandle[] =
 {
     {   MSDFF_HANDLE_FLAGS_RANGE,
-        0x100, 0, 10800, 10800, 2700, 8100, 0x80000000, 0x7fffffff },
+        0x100, 0, 10800, 10800, 2700, 8100, MIN_INT32, 0x7fffffff },
     {   MSDFF_HANDLE_FLAGS_RANGE,
-        10800, 0x101, 10800, 10800, 0x80000000, 0x7fffffff, 0, 7200 }
+        10800, 0x101, 10800, 10800, MIN_INT32, 0x7fffffff, 0, 7200 }
 };
 static const mso_CustomShape msoRibbon =
 {
@@ -4506,7 +4511,7 @@
     (sal_Int32*)mso_sptRibbonDefault,
     (SvxMSDffTextRectangles*)mso_sptRibbonTextRect, sizeof( mso_sptRibbonTextRect ) / sizeof( SvxMSDffTextRectangles ),
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     (SvxMSDffVertPair*)mso_sptRibbonGluePoints, sizeof( mso_sptRibbonGluePoints ) / sizeof( SvxMSDffVertPair ),
     (SvxMSDffHandle*)mso_sptRibbonHandle, sizeof( mso_sptRibbonHandle ) / sizeof( SvxMSDffHandle )
 };
@@ -4562,7 +4567,7 @@
 static const SvxMSDffHandle mso_sptVerticalScrollHandle[] =
 {
     {   MSDFF_HANDLE_FLAGS_RANGE,
-        0, 0x100, 10800, 10800, 0x80000000, 0x7fffffff, 0, 5400 }
+        0, 0x100, 10800, 10800, MIN_INT32, 0x7fffffff, 0, 5400 }
 };
 static const mso_CustomShape msoVerticalScroll =
 {
@@ -4608,7 +4613,7 @@
 static const SvxMSDffHandle mso_sptHorizontalScrollHandle[] =
 {
     {   MSDFF_HANDLE_FLAGS_RANGE,
-        0x100, 0, 10800, 10800, 0, 5400, 0x80000000, 0x7fffffff }
+        0x100, 0, 10800, 10800, 0, 5400, MIN_INT32, 0x7fffffff }
 };
 static const mso_CustomShape msoHorizontalScroll =
 {
@@ -4635,7 +4640,7 @@
     NULL,
     NULL, 0,
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     (SvxMSDffVertPair*)mso_sptStandardGluePoints, sizeof( mso_sptStandardGluePoints ) / sizeof( SvxMSDffVertPair ),
     NULL, 0     // handles
 };
@@ -4672,7 +4677,7 @@
     NULL,
     (SvxMSDffTextRectangles*)mso_sptFlowChartAlternateProcessTextRect, sizeof( mso_sptFlowChartAlternateProcessTextRect ) / sizeof( SvxMSDffTextRectangles ),
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     (SvxMSDffVertPair*)mso_sptStandardGluePoints, sizeof( mso_sptStandardGluePoints ) / sizeof( SvxMSDffVertPair ),
     NULL, 0     // handles
 };
@@ -4693,7 +4698,7 @@
     NULL,
     (SvxMSDffTextRectangles*)mso_sptFlowChartDecisionTextRect, sizeof( mso_sptFlowChartDecisionTextRect ) / sizeof( SvxMSDffTextRectangles ),
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     (SvxMSDffVertPair*)mso_sptStandardGluePoints, sizeof( mso_sptStandardGluePoints ) / sizeof( SvxMSDffVertPair ),
     NULL, 0     // handles
 };
@@ -4718,7 +4723,7 @@
     NULL,
     (SvxMSDffTextRectangles*)mso_sptFlowChartInputOutputTextRect, sizeof( mso_sptFlowChartInputOutputTextRect ) / sizeof( SvxMSDffTextRectangles ),
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     (SvxMSDffVertPair*)mso_sptFlowChartInputOutputGluePoints, sizeof( mso_sptFlowChartInputOutputGluePoints ) / sizeof( SvxMSDffVertPair ),
     NULL, 0     // handles
 };
@@ -4749,7 +4754,7 @@
     NULL,
     (SvxMSDffTextRectangles*)mso_sptFlowChartPredefinedProcessTextRect, sizeof( mso_sptFlowChartPredefinedProcessTextRect ) / sizeof( SvxMSDffTextRectangles ),
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     NULL, 0,
     NULL, 0     // handles
 };
@@ -4780,7 +4785,7 @@
     NULL,
     (SvxMSDffTextRectangles*)mso_sptFlowChartInternalStorageTextRect, sizeof( mso_sptFlowChartInternalStorageTextRect ) / sizeof( SvxMSDffTextRectangles ),
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     NULL, 0,
     NULL, 0     // handles
 };
@@ -4811,7 +4816,7 @@
     NULL,
     (SvxMSDffTextRectangles*)mso_sptFlowChartDocumentTextRect, sizeof( mso_sptFlowChartDocumentTextRect ) / sizeof( SvxMSDffTextRectangles ),
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     (SvxMSDffVertPair*)mso_sptFlowChartDocumentGluePoints, sizeof( mso_sptFlowChartDocumentGluePoints ) / sizeof( SvxMSDffVertPair ),
     NULL, 0     // handles
 };
@@ -4850,7 +4855,7 @@
     NULL,
     (SvxMSDffTextRectangles*)mso_sptFlowChartMultidocumentTextRect, sizeof( mso_sptFlowChartMultidocumentTextRect ) / sizeof( SvxMSDffTextRectangles ),
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     (SvxMSDffVertPair*)mso_sptFlowChartMultidocumentGluePoints, sizeof( mso_sptFlowChartMultidocumentGluePoints ) / sizeof( SvxMSDffVertPair ),
     NULL, 0     // handles
 };
@@ -4876,7 +4881,7 @@
     NULL,
     (SvxMSDffTextRectangles*)mso_sptFlowChartTerminatorTextRect, sizeof( mso_sptFlowChartTerminatorTextRect ) / sizeof( SvxMSDffTextRectangles ),
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     (SvxMSDffVertPair*)mso_sptStandardGluePoints, sizeof( mso_sptStandardGluePoints ) / sizeof( SvxMSDffVertPair ),
     NULL, 0     // handles
 };
@@ -4898,7 +4903,7 @@
     NULL,
     (SvxMSDffTextRectangles*)mso_sptFlowChartPreparationTextRect, sizeof( mso_sptFlowChartPreparationTextRect ) / sizeof( SvxMSDffTextRectangles ),
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     (SvxMSDffVertPair*)mso_sptStandardGluePoints, sizeof( mso_sptStandardGluePoints ) / sizeof( SvxMSDffVertPair ),
     NULL, 0     // handles
 };
@@ -4923,7 +4928,7 @@
     NULL,
     (SvxMSDffTextRectangles*)mso_sptFlowChartManualInputTextRect, sizeof( mso_sptFlowChartManualInputTextRect ) / sizeof( SvxMSDffTextRectangles ),
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     (SvxMSDffVertPair*)mso_sptFlowChartManualInputGluePoints, sizeof( mso_sptFlowChartManualInputGluePoints ) / sizeof( SvxMSDffVertPair ),
     NULL, 0     // handles
 };
@@ -4948,7 +4953,7 @@
     NULL,
     (SvxMSDffTextRectangles*)mso_sptFlowChartManualOperationTextRect, sizeof( mso_sptFlowChartManualOperationTextRect ) / sizeof( SvxMSDffTextRectangles ),
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     (SvxMSDffVertPair*)mso_sptFlowChartManualOperationGluePoints, sizeof( mso_sptFlowChartManualOperationGluePoints ) / sizeof( SvxMSDffVertPair ),
     NULL, 0     // handles
 };
@@ -4973,7 +4978,7 @@
     NULL,
     (SvxMSDffTextRectangles*)mso_sptFlowChartConnectorTextRect, sizeof( mso_sptFlowChartConnectorTextRect ) / sizeof( SvxMSDffTextRectangles ),
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     (SvxMSDffVertPair*)mso_sptEllipseGluePoints, sizeof( mso_sptEllipseGluePoints ) / sizeof( SvxMSDffVertPair ),
     NULL, 0     // handles
 };
@@ -4995,7 +5000,7 @@
     NULL,
     (SvxMSDffTextRectangles*)mso_sptFlowChartOffpageConnectorTextRect, sizeof( mso_sptFlowChartOffpageConnectorTextRect ) / sizeof( SvxMSDffTextRectangles ),
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     (SvxMSDffVertPair*)mso_sptStandardGluePoints, sizeof( mso_sptStandardGluePoints ) / sizeof( SvxMSDffVertPair ),
     NULL, 0     // handles
 };
@@ -5017,7 +5022,7 @@
     NULL,
     (SvxMSDffTextRectangles*)mso_sptFlowChartPunchedCardTextRect, sizeof( mso_sptFlowChartPunchedCardTextRect ) / sizeof( SvxMSDffTextRectangles ),
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     (SvxMSDffVertPair*)mso_sptStandardGluePoints, sizeof( mso_sptStandardGluePoints ) / sizeof( SvxMSDffVertPair ),
     NULL, 0     // handles
 };
@@ -5055,7 +5060,7 @@
     NULL,
     (SvxMSDffTextRectangles*)mso_sptFlowChartPunchedTapeTextRect, sizeof( mso_sptFlowChartPunchedTapeTextRect ) / sizeof( SvxMSDffTextRectangles ),
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     (SvxMSDffVertPair*)mso_sptFlowChartPunchedTapeGluePoints, sizeof( mso_sptFlowChartPunchedTapeGluePoints ) / sizeof( SvxMSDffVertPair ),
     NULL, 0     // handles
 };
@@ -5088,7 +5093,7 @@
     NULL,
     (SvxMSDffTextRectangles*)mso_sptFlowChartSummingJunctionTextRect, sizeof( mso_sptFlowChartSummingJunctionTextRect ) / sizeof( SvxMSDffTextRectangles ),
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     (SvxMSDffVertPair*)mso_sptEllipseGluePoints, sizeof( mso_sptEllipseGluePoints ) / sizeof( SvxMSDffVertPair ),
     NULL, 0     // handles
 };
@@ -5119,7 +5124,7 @@
     NULL,
     (SvxMSDffTextRectangles*)mso_sptFlowChartOrTextRect, sizeof( mso_sptFlowChartOrTextRect ) / sizeof( SvxMSDffTextRectangles ),
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     (SvxMSDffVertPair*)mso_sptEllipseGluePoints, sizeof( mso_sptEllipseGluePoints ) / sizeof( SvxMSDffVertPair ),
     NULL, 0     // handles
 };
@@ -5144,7 +5149,7 @@
     NULL,
     (SvxMSDffTextRectangles*)mso_sptFlowChartCollateTextRect, sizeof( mso_sptFlowChartCollateTextRect ) / sizeof( SvxMSDffTextRectangles ),
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     (SvxMSDffVertPair*)mso_sptFlowChartCollateGluePoints, sizeof( mso_sptFlowChartCollateGluePoints ) / sizeof( SvxMSDffVertPair ),
     NULL, 0     // handles
 };
@@ -5172,7 +5177,7 @@
     NULL,
     (SvxMSDffTextRectangles*)mso_sptFlowChartSortTextRect, sizeof( mso_sptFlowChartSortTextRect ) / sizeof( SvxMSDffTextRectangles ),
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     NULL, 0,
     NULL, 0     // handles
 };
@@ -5197,7 +5202,7 @@
     NULL,
     (SvxMSDffTextRectangles*)mso_sptFlowChartExtractTextRect, sizeof( mso_sptFlowChartExtractTextRect ) / sizeof( SvxMSDffTextRectangles ),
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     (SvxMSDffVertPair*)mso_sptFlowChartExtractGluePoints, sizeof( mso_sptFlowChartExtractGluePoints ) / sizeof( SvxMSDffVertPair ),
     NULL, 0     // handles
 };
@@ -5218,7 +5223,7 @@
     NULL,
     (SvxMSDffTextRectangles*)mso_sptFlowChartMergeTextRect, sizeof( mso_sptFlowChartMergeTextRect ) / sizeof( SvxMSDffTextRectangles ),
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     (SvxMSDffVertPair*)mso_sptFlowChartExtractGluePoints, sizeof( mso_sptFlowChartExtractGluePoints ) / sizeof( SvxMSDffVertPair ),
     NULL, 0     // handles
 };
@@ -5248,7 +5253,7 @@
     NULL,
     (SvxMSDffTextRectangles*)mso_sptFlowChartOnlineStorageTextRect, sizeof( mso_sptFlowChartOnlineStorageTextRect ) / sizeof( SvxMSDffTextRectangles ),
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     (SvxMSDffVertPair*)mso_sptFlowChartOnlineStorageGluePoints, sizeof( mso_sptFlowChartOnlineStorageGluePoints ) / sizeof( SvxMSDffVertPair ),
     NULL, 0     // handles
 };
@@ -5274,7 +5279,7 @@
     NULL,
     (SvxMSDffTextRectangles*)mso_sptFlowChartDelayTextRect, sizeof( mso_sptFlowChartDelayTextRect ) / sizeof( SvxMSDffTextRectangles ),
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     (SvxMSDffVertPair*)mso_sptStandardGluePoints, sizeof( mso_sptStandardGluePoints ) / sizeof( SvxMSDffVertPair ),
     NULL, 0     // handles
 };
@@ -5303,7 +5308,7 @@
     NULL,
     (SvxMSDffTextRectangles*)mso_sptFlowChartMagneticTapeTextRect, sizeof( mso_sptFlowChartMagneticTapeTextRect ) / sizeof( SvxMSDffTextRectangles ),
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     (SvxMSDffVertPair*)mso_sptStandardGluePoints, sizeof( mso_sptStandardGluePoints ) / sizeof( SvxMSDffVertPair ),
     NULL, 0     // handles
 };
@@ -5336,7 +5341,7 @@
     NULL,
     (SvxMSDffTextRectangles*)mso_sptFlowChartMagneticDiskTextRect, sizeof( mso_sptFlowChartMagneticDiskTextRect ) / sizeof( SvxMSDffTextRectangles ),
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     (SvxMSDffVertPair*)mso_sptFlowChartMagneticDiskGluePoints, sizeof( mso_sptFlowChartMagneticDiskGluePoints ) / sizeof( SvxMSDffVertPair ),
     NULL, 0     // handles
 };
@@ -5369,7 +5374,7 @@
     NULL,
     (SvxMSDffTextRectangles*)mso_sptFlowChartMagneticDrumTextRect, sizeof( mso_sptFlowChartMagneticDrumTextRect ) / sizeof( SvxMSDffTextRectangles ),
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     (SvxMSDffVertPair*)mso_sptFlowChartMagneticDrumGluePoints, sizeof( mso_sptFlowChartMagneticDrumGluePoints ) / sizeof( SvxMSDffVertPair ),
     NULL, 0     // handles
 };
@@ -5395,7 +5400,7 @@
     NULL,
     (SvxMSDffTextRectangles*)mso_sptFlowChartDisplayTextRect, sizeof( mso_sptFlowChartDisplayTextRect ) / sizeof( SvxMSDffTextRectangles ),
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     (SvxMSDffVertPair*)mso_sptStandardGluePoints, sizeof( mso_sptStandardGluePoints ) / sizeof( SvxMSDffVertPair ),
     NULL, 0     // handles
 };
@@ -5477,7 +5482,7 @@
 {
     {
         0,
-        0x100, 0x101, 10800, 10800, 0x80000000, 0x7fffffff, 0x80000000, 0x7fffffff
+        0x100, 0x101, 10800, 10800, MIN_INT32, 0x7fffffff, MIN_INT32, 0x7fffffff
     }
 };
 static const mso_CustomShape msoWedgeRectCallout =
@@ -5488,7 +5493,7 @@
     (sal_Int32*)mso_sptWedgeRectCalloutDefault,
     (SvxMSDffTextRectangles*)mso_sptWedgeRectCalloutTextRect, sizeof( mso_sptWedgeRectCalloutTextRect ) / sizeof( SvxMSDffTextRectangles ),
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     (SvxMSDffVertPair*)mso_sptWedgeRectCalloutGluePoints, sizeof( mso_sptWedgeRectCalloutGluePoints ) / sizeof( SvxMSDffVertPair ),
     (SvxMSDffHandle*)mso_sptCalloutHandle, sizeof( mso_sptCalloutHandle ) / sizeof( SvxMSDffHandle )        // handles
 };
@@ -5524,7 +5529,7 @@
     (sal_Int32*)mso_sptWedgeRectCalloutDefault,
     (SvxMSDffTextRectangles*)mso_sptWedgeRRectCalloutTextRect, sizeof( mso_sptWedgeRRectCalloutTextRect ) / sizeof( SvxMSDffTextRectangles ),
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     NULL, 0,
     (SvxMSDffHandle*)mso_sptCalloutHandle, sizeof( mso_sptCalloutHandle ) / sizeof( SvxMSDffHandle )        // handles
 };
@@ -5548,7 +5553,7 @@
 {
     {
         MSDFF_HANDLE_FLAGS_RANGE,
-        0x100, 1, 10800, 10800, 0, 8990, 0x80000000, 0x7fffffff
+        0x100, 1, 10800, 10800, 0, 8990, MIN_INT32, 0x7fffffff
     }
 };
 static const SvxMSDffTextRectangles mso_sptBalloonTextRect[] =
@@ -5563,7 +5568,7 @@
     (sal_Int32*)mso_sptWedgeRectCalloutDefault,
     (SvxMSDffTextRectangles*)mso_sptBalloonTextRect, sizeof( mso_sptBalloonTextRect ) / sizeof( SvxMSDffTextRectangles ),
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     NULL, 0,
     (SvxMSDffHandle*)mso_sptBalloonHandle, sizeof( mso_sptBalloonHandle ) / sizeof( SvxMSDffHandle )        // handles
 };
@@ -5622,7 +5627,7 @@
     (sal_Int32*)mso_sptWedgeEllipseCalloutDefault,
     (SvxMSDffTextRectangles*)mso_sptWedgeEllipseCalloutTextRect, sizeof( mso_sptWedgeEllipseCalloutTextRect ) / sizeof( SvxMSDffTextRectangles ),
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     (SvxMSDffVertPair*)mso_sptWedgeEllipseCalloutGluePoints, sizeof( mso_sptWedgeEllipseCalloutGluePoints ) / sizeof( SvxMSDffVertPair ),
     (SvxMSDffHandle*)mso_sptCalloutHandle, sizeof( mso_sptCalloutHandle ) / sizeof( SvxMSDffHandle )        // handles
 };
@@ -5727,7 +5732,7 @@
     (sal_Int32*)mso_sptCloudCalloutDefault,
     (SvxMSDffTextRectangles*)mso_sptCloudCalloutTextRect, sizeof( mso_sptCloudCalloutTextRect ) / sizeof( SvxMSDffTextRectangles ),
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     NULL, 0,
     (SvxMSDffHandle*)mso_sptCalloutHandle, sizeof( mso_sptCalloutHandle ) / sizeof( SvxMSDffHandle )        // handles
 };
@@ -5785,9 +5790,9 @@
 static const SvxMSDffHandle mso_sptWaveHandle[] =
 {
     {   MSDFF_HANDLE_FLAGS_RANGE,
-        0, 0x100, 10800, 10800, 0x80000000, 0x7fffffff, 0, 4460 },
+        0, 0x100, 10800, 10800, MIN_INT32, 0x7fffffff, 0, 4460 },
     {   MSDFF_HANDLE_FLAGS_RANGE,
-        0x101, 21600, 10800, 10800, 8640, 12960, 0x80000000, 0x7fffffff }
+        0x101, 21600, 10800, 10800, 8640, 12960, MIN_INT32, 0x7fffffff }
 };
 static const sal_Int32 mso_sptWaveDefault[] =
 {
@@ -5805,7 +5810,7 @@
     (sal_Int32*)mso_sptWaveDefault,
     (SvxMSDffTextRectangles*)mso_sptWaveTextRect, sizeof( mso_sptWaveTextRect ) / sizeof( SvxMSDffTextRectangles ),
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     (SvxMSDffVertPair*)mso_sptWaveGluePoints, sizeof( mso_sptWaveGluePoints ) / sizeof( SvxMSDffVertPair ),
     (SvxMSDffHandle*)mso_sptWaveHandle, sizeof( mso_sptWaveHandle ) / sizeof( SvxMSDffHandle )
 };
@@ -5867,9 +5872,9 @@
 static const SvxMSDffHandle mso_sptDoubleWaveHandle[] =
 {
     {   MSDFF_HANDLE_FLAGS_RANGE,
-        0, 0x100, 10800, 10800, 0x80000000, 0x7fffffff, 0, 2230 },
+        0, 0x100, 10800, 10800, MIN_INT32, 0x7fffffff, 0, 2230 },
     {   MSDFF_HANDLE_FLAGS_RANGE,
-        0x101, 21600, 10800, 10800, 8640, 12960, 0x80000000, 0x7fffffff }
+        0x101, 21600, 10800, 10800, 8640, 12960, MIN_INT32, 0x7fffffff }
 };
 static const sal_Int32 mso_sptDoubleWaveDefault[] =
 {
@@ -5887,7 +5892,7 @@
     (sal_Int32*)mso_sptDoubleWaveDefault,
     (SvxMSDffTextRectangles*)mso_sptDoubleWaveTextRect, sizeof( mso_sptDoubleWaveTextRect ) / sizeof( SvxMSDffTextRectangles ),
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     (SvxMSDffVertPair*)mso_sptDoubleWaveGluePoints, sizeof( mso_sptDoubleWaveGluePoints ) / sizeof( SvxMSDffVertPair ),
     (SvxMSDffHandle*)mso_sptDoubleWaveHandle, sizeof( mso_sptDoubleWaveHandle ) / sizeof( SvxMSDffHandle )
 };
@@ -5985,7 +5990,7 @@
     NULL,
     (SvxMSDffTextRectangles*)mso_sptFontWorkTextRect, sizeof( mso_sptFontWorkTextRect ) / sizeof( SvxMSDffTextRectangles ),
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     NULL, 0,
     NULL, 0 // Handles
 };
@@ -6013,7 +6018,7 @@
 static const SvxMSDffHandle mso_sptTextPlainTextHandle[] =
 {
     {   MSDFF_HANDLE_FLAGS_RANGE,
-        0x100, 21600, 10800, 10800, 6629, 14971, 0x80000000, 0x7fffffff }
+        0x100, 21600, 10800, 10800, 6629, 14971, MIN_INT32, 0x7fffffff }
 };
 static const mso_CustomShape msoTextPlainText =
 {
@@ -6023,7 +6028,7 @@
     (sal_Int32*)mso_sptDefault10800,
     (SvxMSDffTextRectangles*)mso_sptFontWorkTextRect, sizeof( mso_sptFontWorkTextRect ) / sizeof( SvxMSDffTextRectangles ),
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     NULL, 0,
     (SvxMSDffHandle*)mso_sptTextPlainTextHandle, sizeof( mso_sptTextPlainTextHandle ) / sizeof( SvxMSDffHandle )
 };
@@ -6050,7 +6055,7 @@
 static const SvxMSDffHandle mso_sptTextStopHandle[] =
 {
     {   MSDFF_HANDLE_FLAGS_RANGE,
-        0, 0x100, 10800, 10800, 0x80000000, 0x7fffffff, 3080, 10800 }
+        0, 0x100, 10800, 10800, MIN_INT32, 0x7fffffff, 3080, 10800 }
 };
 static const mso_CustomShape msoTextStop =
 {
@@ -6060,7 +6065,7 @@
     (sal_Int32*)mso_sptTextStopDefault,
     (SvxMSDffTextRectangles*)mso_sptFontWorkTextRect, sizeof( mso_sptFontWorkTextRect ) / sizeof( SvxMSDffTextRectangles ),
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     NULL, 0,
     (SvxMSDffHandle*)mso_sptTextStopHandle, sizeof( mso_sptTextStopHandle ) / sizeof( SvxMSDffHandle )
 };
@@ -6081,7 +6086,7 @@
 static const SvxMSDffHandle mso_sptTextTriangleHandle[] =
 {
     {   MSDFF_HANDLE_FLAGS_RANGE,
-        0, 0x100, 10800, 10800, 0x80000000, 0x7fffffff, 0, 21600 }
+        0, 0x100, 10800, 10800, MIN_INT32, 0x7fffffff, 0, 21600 }
 };
 static const mso_CustomShape msoTextTriangle =
 {
@@ -6091,7 +6096,7 @@
     (sal_Int32*)mso_sptDefault10800,
     (SvxMSDffTextRectangles*)mso_sptFontWorkTextRect, sizeof( mso_sptFontWorkTextRect ) / sizeof( SvxMSDffTextRectangles ),
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     NULL, 0,
     (SvxMSDffHandle*)mso_sptTextTriangleHandle, sizeof( mso_sptTextTriangleHandle ) / sizeof( SvxMSDffHandle )
 };
@@ -6112,7 +6117,7 @@
     (sal_Int32*)mso_sptDefault10800,
     (SvxMSDffTextRectangles*)mso_sptFontWorkTextRect, sizeof( mso_sptFontWorkTextRect ) / sizeof( SvxMSDffTextRectangles ),
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     NULL, 0,
     (SvxMSDffHandle*)mso_sptTextTriangleHandle, sizeof( mso_sptTextTriangleHandle ) / sizeof( SvxMSDffHandle )
 };
@@ -6134,7 +6139,7 @@
 static const SvxMSDffHandle mso_sptTextChevronHandle[] =
 {
     {   MSDFF_HANDLE_FLAGS_RANGE,
-        0, 0x100, 10800, 10800, 0x80000000, 0x7fffffff, 0, 10800 }
+        0, 0x100, 10800, 10800, MIN_INT32, 0x7fffffff, 0, 10800 }
 };
 static const mso_CustomShape msoTextChevron =
 {
@@ -6144,7 +6149,7 @@
     (sal_Int32*)mso_sptDefault5400,
     (SvxMSDffTextRectangles*)mso_sptFontWorkTextRect, sizeof( mso_sptFontWorkTextRect ) / sizeof( SvxMSDffTextRectangles ),
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     NULL, 0,
     (SvxMSDffHandle*)mso_sptTextChevronHandle, sizeof( mso_sptTextChevronHandle ) / sizeof( SvxMSDffHandle )
 };
@@ -6166,7 +6171,7 @@
 static const SvxMSDffHandle mso_sptTextChevronInvertedHandle[] =
 {
     {   MSDFF_HANDLE_FLAGS_RANGE,
-        0, 0x100, 10800, 10800, 0x80000000, 0x7fffffff, 10800, 21600 }
+        0, 0x100, 10800, 10800, MIN_INT32, 0x7fffffff, 10800, 21600 }
 };
 static const mso_CustomShape msoTextChevronInverted =
 {
@@ -6176,7 +6181,7 @@
     (sal_Int32*)mso_sptDefault16200,
     (SvxMSDffTextRectangles*)mso_sptFontWorkTextRect, sizeof( mso_sptFontWorkTextRect ) / sizeof( SvxMSDffTextRectangles ),
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     NULL, 0,
     (SvxMSDffHandle*)mso_sptTextChevronInvertedHandle, sizeof( mso_sptTextChevronInvertedHandle ) / sizeof( SvxMSDffHandle )
 };
@@ -6199,7 +6204,7 @@
 static const SvxMSDffHandle mso_sptTextRingOutsideHandle[] =
 {
     {   MSDFF_HANDLE_FLAGS_RANGE,
-        10800, 0x100, 10800, 10800, 0x80000000, 0x7fffffff, 10800, 21600 }
+        10800, 0x100, 10800, 10800, MIN_INT32, 0x7fffffff, 10800, 21600 }
 };
 static const mso_CustomShape msoTextRingOutside =
 {
@@ -6209,7 +6214,7 @@
     (sal_Int32*)mso_sptDefault16200,
     (SvxMSDffTextRectangles*)mso_sptFontWorkTextRect, sizeof( mso_sptFontWorkTextRect ) / sizeof( SvxMSDffTextRectangles ),
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     NULL, 0,
     (SvxMSDffHandle*)mso_sptTextRingOutsideHandle, sizeof( mso_sptTextRingOutsideHandle ) / sizeof( SvxMSDffHandle )
 };
@@ -6231,7 +6236,7 @@
 static const SvxMSDffHandle mso_sptTextFadeRightHandle[] =
 {
     {   MSDFF_HANDLE_FLAGS_RANGE,
-        21600, 0x100, 10800, 10800, 0x80000000, 0x7fffffff, 0, 10800 }
+        21600, 0x100, 10800, 10800, MIN_INT32, 0x7fffffff, 0, 10800 }
 };
 static const mso_CustomShape msoTextFadeRight =
 {
@@ -6241,7 +6246,7 @@
     (sal_Int32*)mso_sptDefault7200,
     (SvxMSDffTextRectangles*)mso_sptFontWorkTextRect, sizeof( mso_sptFontWorkTextRect ) / sizeof( SvxMSDffTextRectangles ),
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     NULL, 0,
     (SvxMSDffHandle*)mso_sptTextFadeRightHandle, sizeof( mso_sptTextFadeRightHandle ) / sizeof( SvxMSDffHandle )
 };
@@ -6253,7 +6258,7 @@
 static const SvxMSDffHandle mso_sptTextFadeLeftHandle[] =
 {
     {   MSDFF_HANDLE_FLAGS_RANGE,
-        0, 0x100, 10800, 10800, 0x80000000, 0x7fffffff, 0, 10800 }
+        0, 0x100, 10800, 10800, MIN_INT32, 0x7fffffff, 0, 10800 }
 };
 static const mso_CustomShape msoTextFadeLeft =
 {
@@ -6263,7 +6268,7 @@
     (sal_Int32*)mso_sptDefault7200,
     (SvxMSDffTextRectangles*)mso_sptFontWorkTextRect, sizeof( mso_sptFontWorkTextRect ) / sizeof( SvxMSDffTextRectangles ),
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     NULL, 0,
     (SvxMSDffHandle*)mso_sptTextFadeLeftHandle, sizeof( mso_sptTextFadeLeftHandle ) / sizeof( SvxMSDffHandle )
 };
@@ -6275,7 +6280,7 @@
 static const SvxMSDffHandle mso_sptTextFadeUpHandle[] =
 {
     {   MSDFF_HANDLE_FLAGS_RANGE,
-        0x100, 0, 10800, 10800, 0, 10800, 0x80000000, 0x7fffffff }
+        0x100, 0, 10800, 10800, 0, 10800, MIN_INT32, 0x7fffffff }
 };
 static const mso_CustomShape msoTextFadeUp =
 {
@@ -6285,7 +6290,7 @@
     (sal_Int32*)mso_sptDefault7200,
     (SvxMSDffTextRectangles*)mso_sptFontWorkTextRect, sizeof( mso_sptFontWorkTextRect ) / sizeof( SvxMSDffTextRectangles ),
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     NULL, 0,
     (SvxMSDffHandle*)mso_sptTextFadeUpHandle, sizeof( mso_sptTextFadeUpHandle ) / sizeof( SvxMSDffHandle )
 };
@@ -6297,7 +6302,7 @@
 static const SvxMSDffHandle mso_sptTextFadeDownHandle[] =
 {
     {   MSDFF_HANDLE_FLAGS_RANGE,
-        0x100, 21600, 10800, 10800, 0, 10800, 0x80000000, 0x7fffffff }
+        0x100, 21600, 10800, 10800, 0, 10800, MIN_INT32, 0x7fffffff }
 };
 static const mso_CustomShape msoTextFadeDown =
 {
@@ -6307,7 +6312,7 @@
     (sal_Int32*)mso_sptDefault7200,
     (SvxMSDffTextRectangles*)mso_sptFontWorkTextRect, sizeof( mso_sptFontWorkTextRect ) / sizeof( SvxMSDffTextRectangles ),
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     NULL, 0,
     (SvxMSDffHandle*)mso_sptTextFadeDownHandle, sizeof( mso_sptTextFadeDownHandle ) / sizeof( SvxMSDffHandle )
 };
@@ -6319,7 +6324,7 @@
 static const SvxMSDffHandle mso_sptTextSlantUpHandle[] =
 {
     {   MSDFF_HANDLE_FLAGS_RANGE,
-        0, 0x100, 10800, 10800, 0x80000000, 0x7fffffff, 0, 15400 }
+        0, 0x100, 10800, 10800, MIN_INT32, 0x7fffffff, 0, 15400 }
 };
 static const mso_CustomShape msoTextSlantUp =
 {
@@ -6329,7 +6334,7 @@
     (sal_Int32*)mso_sptDefault12000,
     (SvxMSDffTextRectangles*)mso_sptFontWorkTextRect, sizeof( mso_sptFontWorkTextRect ) / sizeof( SvxMSDffTextRectangles ),
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     NULL, 0,
     (SvxMSDffHandle*)mso_sptTextSlantUpHandle, sizeof( mso_sptTextSlantUpHandle ) / sizeof( SvxMSDffHandle )
 };
@@ -6341,7 +6346,7 @@
 static const SvxMSDffHandle mso_sptTextSlantDownHandle[] =
 {
     {   MSDFF_HANDLE_FLAGS_RANGE,
-        0, 0x100, 10800, 10800, 0x80000000, 0x7fffffff, 6200, 21600 }
+        0, 0x100, 10800, 10800, MIN_INT32, 0x7fffffff, 6200, 21600 }
 };
 static const mso_CustomShape msoTextSlantDown =
 {
@@ -6351,7 +6356,7 @@
     (sal_Int32*)mso_sptDefault12000,
     (SvxMSDffTextRectangles*)mso_sptFontWorkTextRect, sizeof( mso_sptFontWorkTextRect ) / sizeof( SvxMSDffTextRectangles ),
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     NULL, 0,
     (SvxMSDffHandle*)mso_sptTextSlantDownHandle, sizeof( mso_sptTextSlantDownHandle ) / sizeof( SvxMSDffHandle )
 };
@@ -6369,7 +6374,7 @@
 static const SvxMSDffHandle mso_sptTextCascadeUpHandle[] =
 {
     {   MSDFF_HANDLE_FLAGS_RANGE,
-        21600, 0x100, 10800, 10800, 0x80000000, 0x7fffffff, 6200, 21600 }
+        21600, 0x100, 10800, 10800, MIN_INT32, 0x7fffffff, 6200, 21600 }
 };
 static const mso_CustomShape msoTextCascadeUp =
 {
@@ -6379,7 +6384,7 @@
     (sal_Int32*)mso_sptDefault9600,
     (SvxMSDffTextRectangles*)mso_sptFontWorkTextRect, sizeof( mso_sptFontWorkTextRect ) / sizeof( SvxMSDffTextRectangles ),
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     NULL, 0,
     (SvxMSDffHandle*)mso_sptTextCascadeUpHandle, sizeof( mso_sptTextCascadeUpHandle ) / sizeof( SvxMSDffHandle )
 };
@@ -6391,7 +6396,7 @@
 static const SvxMSDffHandle mso_sptTextCascadeDownHandle[] =
 {
     {   MSDFF_HANDLE_FLAGS_RANGE,
-        0, 0x100, 10800, 10800, 0x80000000, 0x7fffffff, 6200, 21600 }
+        0, 0x100, 10800, 10800, MIN_INT32, 0x7fffffff, 6200, 21600 }
 };
 static const mso_CustomShape msoTextCascadeDown =
 {
@@ -6401,7 +6406,7 @@
     (sal_Int32*)mso_sptDefault9600,
     (SvxMSDffTextRectangles*)mso_sptFontWorkTextRect, sizeof( mso_sptFontWorkTextRect ) / sizeof( SvxMSDffTextRectangles ),
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     NULL, 0,
     (SvxMSDffHandle*)mso_sptTextCascadeDownHandle, sizeof( mso_sptTextCascadeDownHandle ) / sizeof( SvxMSDffHandle )
 };
@@ -6425,7 +6430,7 @@
 static const SvxMSDffHandle mso_sptTextArchUpCurveHandle[] =
 {
     {   MSDFF_HANDLE_FLAGS_POLAR,
-        10800, 0x100, 10800, 10800, 0, 10800, 0x80000000, 0x7fffffff }
+        10800, 0x100, 10800, 10800, 0, 10800, MIN_INT32, 0x7fffffff }
 };
 static const sal_Int32 mso_sptTextArchUpCurveDefault[] =
 {
@@ -6439,7 +6444,7 @@
     (sal_Int32*)mso_sptTextArchUpCurveDefault,
     (SvxMSDffTextRectangles*)mso_sptFontWorkTextRect, sizeof( mso_sptFontWorkTextRect ) / sizeof( SvxMSDffTextRectangles ),
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     NULL, 0,
     (SvxMSDffHandle*)mso_sptTextArchUpCurveHandle, sizeof( mso_sptTextArchUpCurveHandle ) / sizeof( SvxMSDffHandle )
 };
@@ -6455,7 +6460,7 @@
 static const SvxMSDffHandle mso_sptTextArchDownCurveHandle[] =
 {
     {   MSDFF_HANDLE_FLAGS_POLAR,
-        10800, 0x100, 10800, 10800, 0, 10800, 0x80000000, 0x7fffffff }
+        10800, 0x100, 10800, 10800, 0, 10800, MIN_INT32, 0x7fffffff }
 };
 static const sal_Int32 mso_sptTextArchDownCurveDefault[] =
 {
@@ -6469,7 +6474,7 @@
     (sal_Int32*)mso_sptTextArchDownCurveDefault,
     (SvxMSDffTextRectangles*)mso_sptFontWorkTextRect, sizeof( mso_sptFontWorkTextRect ) / sizeof( SvxMSDffTextRectangles ),
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     NULL, 0,
     (SvxMSDffHandle*)mso_sptTextArchDownCurveHandle, sizeof( mso_sptTextArchDownCurveHandle ) / sizeof( SvxMSDffHandle )
 };
@@ -6493,7 +6498,7 @@
 static const SvxMSDffHandle mso_sptTextCircleCurveHandle[] =
 {
     {   MSDFF_HANDLE_FLAGS_POLAR,
-        10800, 0x100, 10800, 10800, 0, 10800, 0x80000000, 0x7fffffff }
+        10800, 0x100, 10800, 10800, 0, 10800, MIN_INT32, 0x7fffffff }
 };
 static const sal_Int32 mso_sptTextCircleCurveDefault[] =
 {
@@ -6507,7 +6512,7 @@
     (sal_Int32*)mso_sptTextCircleCurveDefault,
     (SvxMSDffTextRectangles*)mso_sptFontWorkTextRect, sizeof( mso_sptFontWorkTextRect ) / sizeof( SvxMSDffTextRectangles ),
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     NULL, 0,
     (SvxMSDffHandle*)mso_sptTextCircleCurveHandle, sizeof( mso_sptTextCircleCurveHandle ) / sizeof( SvxMSDffHandle )
 };
@@ -6536,7 +6541,7 @@
 static const SvxMSDffHandle mso_sptTextButtonCurveHandle[] =
 {
     {   MSDFF_HANDLE_FLAGS_POLAR,
-        10800, 0x100, 10800, 10800, 0, 10800, 0x80000000, 0x7fffffff }
+        10800, 0x100, 10800, 10800, 0, 10800, MIN_INT32, 0x7fffffff }
 };
 static const sal_Int32 mso_sptTextButtonCurveDefault[] =
 {
@@ -6550,7 +6555,7 @@
     (sal_Int32*)mso_sptTextButtonCurveDefault,
     (SvxMSDffTextRectangles*)mso_sptFontWorkTextRect, sizeof( mso_sptFontWorkTextRect ) / sizeof( SvxMSDffTextRectangles ),
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     NULL, 0,
     (SvxMSDffHandle*)mso_sptTextButtonCurveHandle, sizeof( mso_sptTextButtonCurveHandle ) / sizeof( SvxMSDffHandle )
 };
@@ -6582,7 +6587,7 @@
 static const SvxMSDffHandle mso_sptTextArchPourHandle[] =
 {
     {   MSDFF_HANDLE_FLAGS_POLAR | MSDFF_HANDLE_FLAGS_RADIUS_RANGE,
-        0x101, 0x100, 10800, 10800, 0, 10800, 0x80000000, 0x7fffffff }
+        0x101, 0x100, 10800, 10800, 0, 10800, MIN_INT32, 0x7fffffff }
 };
 static const sal_Int32 mso_sptTextArchUpPourDefault[] =
 {
@@ -6596,7 +6601,7 @@
     (sal_Int32*)mso_sptTextArchUpPourDefault,
     (SvxMSDffTextRectangles*)mso_sptFontWorkTextRect, sizeof( mso_sptFontWorkTextRect ) / sizeof( SvxMSDffTextRectangles ),
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     NULL, 0,
     (SvxMSDffHandle*)mso_sptTextArchPourHandle, sizeof( mso_sptTextArchPourHandle ) / sizeof( SvxMSDffHandle )
 };
@@ -6622,7 +6627,7 @@
     (sal_Int32*)mso_sptTextArchDownPourDefault,
     (SvxMSDffTextRectangles*)mso_sptFontWorkTextRect, sizeof( mso_sptFontWorkTextRect ) / sizeof( SvxMSDffTextRectangles ),
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     NULL, 0,
     (SvxMSDffHandle*)mso_sptTextArchPourHandle, sizeof( mso_sptTextArchPourHandle ) / sizeof( SvxMSDffHandle )
 };
@@ -6655,7 +6660,7 @@
 static const SvxMSDffHandle mso_sptTextCirclePourHandle[] =
 {
     {   MSDFF_HANDLE_FLAGS_POLAR | MSDFF_HANDLE_FLAGS_RADIUS_RANGE,
-        0x101, 0x100, 10800, 10800, 0, 10800, 0x80000000, 0x7fffffff }
+        0x101, 0x100, 10800, 10800, 0, 10800, MIN_INT32, 0x7fffffff }
 };
 static const sal_Int32 mso_sptTextCirclePourDefault[] =
 {
@@ -6669,7 +6674,7 @@
     (sal_Int32*)mso_sptTextCirclePourDefault,
     (SvxMSDffTextRectangles*)mso_sptFontWorkTextRect, sizeof( mso_sptFontWorkTextRect ) / sizeof( SvxMSDffTextRectangles ),
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     NULL, 0,
     (SvxMSDffHandle*)mso_sptTextCirclePourHandle, sizeof( mso_sptTextCirclePourHandle ) / sizeof( SvxMSDffHandle )
 };
@@ -6723,7 +6728,7 @@
 static const SvxMSDffHandle mso_sptTextButtonPourHandle[] =
 {
     {   MSDFF_HANDLE_FLAGS_POLAR | MSDFF_HANDLE_FLAGS_RADIUS_RANGE,
-        0x101, 0x100, 10800, 10800, 4320, 10800, 0x80000000, 0x7fffffff }
+        0x101, 0x100, 10800, 10800, 4320, 10800, MIN_INT32, 0x7fffffff }
 };
 static const sal_Int32 mso_sptTextButtonPourDefault[] =
 {
@@ -6737,7 +6742,7 @@
     (sal_Int32*)mso_sptTextButtonPourDefault,
     (SvxMSDffTextRectangles*)mso_sptFontWorkTextRect, sizeof( mso_sptFontWorkTextRect ) / sizeof( SvxMSDffTextRectangles ),
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     NULL, 0,
     (SvxMSDffHandle*)mso_sptTextButtonPourHandle, sizeof( mso_sptTextButtonPourHandle ) / sizeof( SvxMSDffHandle )
 };
@@ -6763,7 +6768,7 @@
 static const SvxMSDffHandle mso_sptTextCurveUpHandle[] =
 {
     {   MSDFF_HANDLE_FLAGS_RANGE,
-        0, 0x100, 10800, 10800, 0x80000000, 0x7fffffff, 0, 12170 }
+        0, 0x100, 10800, 10800, MIN_INT32, 0x7fffffff, 0, 12170 }
 };
 static const sal_Int32 mso_sptTextCurveUpDefault[] =
 {
@@ -6777,7 +6782,7 @@
     (sal_Int32*)mso_sptTextCurveUpDefault,
     (SvxMSDffTextRectangles*)mso_sptFontWorkTextRect, sizeof( mso_sptFontWorkTextRect ) / sizeof( SvxMSDffTextRectangles ),
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     NULL, 0,
     (SvxMSDffHandle*)mso_sptTextCurveUpHandle, sizeof( mso_sptTextCurveUpHandle ) / sizeof( SvxMSDffHandle )
 };
@@ -6793,7 +6798,7 @@
 static const SvxMSDffHandle mso_sptTextCurveDownHandle[] =
 {
     {   MSDFF_HANDLE_FLAGS_RANGE,
-        21600, 0x100, 10800, 10800, 0x80000000, 0x7fffffff, 0, 12170 }
+        21600, 0x100, 10800, 10800, MIN_INT32, 0x7fffffff, 0, 12170 }
 };
 static const mso_CustomShape msoTextCurveDown =
 {
@@ -6803,7 +6808,7 @@
     (sal_Int32*)mso_sptTextCurveUpDefault,
     (SvxMSDffTextRectangles*)mso_sptFontWorkTextRect, sizeof( mso_sptFontWorkTextRect ) / sizeof( SvxMSDffTextRectangles ),
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     NULL, 0,
     (SvxMSDffHandle*)mso_sptTextCurveDownHandle, sizeof( mso_sptTextCurveDownHandle ) / sizeof( SvxMSDffHandle )
 };
@@ -6829,7 +6834,7 @@
 static const SvxMSDffHandle mso_sptTextCanUpHandle[] =
 {
     {   MSDFF_HANDLE_FLAGS_RANGE,
-        10800, 0x100, 10800, 10800, 0x80000000, 0x7fffffff, 14400, 21600 }
+        10800, 0x100, 10800, 10800, MIN_INT32, 0x7fffffff, 14400, 21600 }
 };
 static const sal_Int32 mso_sptTextCanUpDefault[] =
 {
@@ -6843,7 +6848,7 @@
     (sal_Int32*)mso_sptTextCanUpDefault,
     (SvxMSDffTextRectangles*)mso_sptFontWorkTextRect, sizeof( mso_sptFontWorkTextRect ) / sizeof( SvxMSDffTextRectangles ),
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     NULL, 0,
     (SvxMSDffHandle*)mso_sptTextCanUpHandle, sizeof( mso_sptTextCanUpHandle ) / sizeof( SvxMSDffHandle )
 };
@@ -6862,7 +6867,7 @@
 static const SvxMSDffHandle mso_sptTextCanDownHandle[] =
 {
     {   MSDFF_HANDLE_FLAGS_RANGE,
-        10800, 0x100, 10800, 10800, 0x80000000, 0x7fffffff, 0, 7200 }
+        10800, 0x100, 10800, 10800, MIN_INT32, 0x7fffffff, 0, 7200 }
 };
 static const sal_Int32 mso_sptTextCanDownDefault[] =
 {
@@ -6876,7 +6881,7 @@
     (sal_Int32*)mso_sptTextCanDownDefault,
     (SvxMSDffTextRectangles*)mso_sptFontWorkTextRect, sizeof( mso_sptFontWorkTextRect ) / sizeof( SvxMSDffTextRectangles ),
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     NULL, 0,
     (SvxMSDffHandle*)mso_sptTextCanDownHandle, sizeof( mso_sptTextCanDownHandle ) / sizeof( SvxMSDffHandle )
 };
@@ -6896,7 +6901,7 @@
 static const SvxMSDffHandle mso_sptTextInflateHandle[] =
 {
     {   MSDFF_HANDLE_FLAGS_RANGE,
-        0, 0x100, 10800, 10800, 0x80000000, 0x7fffffff, 0, 4650 }
+        0, 0x100, 10800, 10800, MIN_INT32, 0x7fffffff, 0, 4650 }
 };
 static const sal_Int32 mso_sptTextInflateDefault[] =
 {
@@ -6910,7 +6915,7 @@
     (sal_Int32*)mso_sptTextInflateDefault,
     (SvxMSDffTextRectangles*)mso_sptFontWorkTextRect, sizeof( mso_sptFontWorkTextRect ) / sizeof( SvxMSDffTextRectangles ),
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     NULL, 0,
     (SvxMSDffHandle*)mso_sptTextInflateHandle, sizeof( mso_sptTextInflateHandle ) / sizeof( SvxMSDffHandle )
 };
@@ -6930,7 +6935,7 @@
 static const SvxMSDffHandle mso_sptTextDeflateHandle[] =
 {
     {   MSDFF_HANDLE_FLAGS_RANGE,
-        10800, 0x100, 10800, 10800, 0x80000000, 0x7fffffff, 0, 8100 }
+        10800, 0x100, 10800, 10800, MIN_INT32, 0x7fffffff, 0, 8100 }
 };
 static const mso_CustomShape msoTextDeflate =
 {
@@ -6940,7 +6945,7 @@
     (sal_Int32*)mso_sptDefault8100,
     (SvxMSDffTextRectangles*)mso_sptFontWorkTextRect, sizeof( mso_sptFontWorkTextRect ) / sizeof( SvxMSDffTextRectangles ),
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     NULL, 0,
     (SvxMSDffHandle*)mso_sptTextDeflateHandle, sizeof( mso_sptTextDeflateHandle ) / sizeof( SvxMSDffHandle )
 };
@@ -6965,7 +6970,7 @@
 static const SvxMSDffHandle mso_sptTextInflateBottomHandle[] =
 {
     {   MSDFF_HANDLE_FLAGS_RANGE,
-        0, 0x100, 10800, 10800, 0x80000000, 0x7fffffff, 11150, 21600 }
+        0, 0x100, 10800, 10800, MIN_INT32, 0x7fffffff, 11150, 21600 }
 };
 static const sal_Int32 mso_sptTextInflateBottomDefault[] =
 {
@@ -6979,7 +6984,7 @@
     (sal_Int32*)mso_sptTextInflateBottomDefault,
     (SvxMSDffTextRectangles*)mso_sptFontWorkTextRect, sizeof( mso_sptFontWorkTextRect ) / sizeof( SvxMSDffTextRectangles ),
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     NULL, 0,
     (SvxMSDffHandle*)mso_sptTextInflateBottomHandle, sizeof( mso_sptTextInflateBottomHandle ) / sizeof( SvxMSDffHandle )
 };
@@ -7004,7 +7009,7 @@
 static const SvxMSDffHandle mso_sptTextDeflateBottomHandle[] =
 {
     {   MSDFF_HANDLE_FLAGS_RANGE,
-        10800, 0x100, 10800, 10800, 0x80000000, 0x7fffffff, 1350, 21600 }
+        10800, 0x100, 10800, 10800, MIN_INT32, 0x7fffffff, 1350, 21600 }
 };
 static const sal_Int32 mso_sptTextDeflateBottomDefault[] =
 {
@@ -7018,7 +7023,7 @@
     (sal_Int32*)mso_sptTextDeflateBottomDefault,
     (SvxMSDffTextRectangles*)mso_sptFontWorkTextRect, sizeof( mso_sptFontWorkTextRect ) / sizeof( SvxMSDffTextRectangles ),
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     NULL, 0,
     (SvxMSDffHandle*)mso_sptTextDeflateBottomHandle, sizeof( mso_sptTextDeflateBottomHandle ) / sizeof( SvxMSDffHandle )
 };
@@ -7041,7 +7046,7 @@
 static const SvxMSDffHandle mso_sptTextInflateTopHandle[] =
 {
     {   MSDFF_HANDLE_FLAGS_RANGE,
-        0, 0x100, 10800, 10800, 0x80000000, 0x7fffffff, 0, 10450 }
+        0, 0x100, 10800, 10800, MIN_INT32, 0x7fffffff, 0, 10450 }
 };
 static const sal_Int32 mso_sptTextInflateTopDefault[] =
 {
@@ -7055,7 +7060,7 @@
     (sal_Int32*)mso_sptTextInflateTopDefault,
     (SvxMSDffTextRectangles*)mso_sptFontWorkTextRect, sizeof( mso_sptFontWorkTextRect ) / sizeof( SvxMSDffTextRectangles ),
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     NULL, 0,
     (SvxMSDffHandle*)mso_sptTextInflateTopHandle, sizeof( mso_sptTextInflateTopHandle ) / sizeof( SvxMSDffHandle )
 };
@@ -7078,7 +7083,7 @@
 static const SvxMSDffHandle mso_sptTextDeflateTopHandle[] =
 {
     {   MSDFF_HANDLE_FLAGS_RANGE,
-        10800, 0x100, 10800, 10800, 0x80000000, 0x7fffffff, 0, 20250 }
+        10800, 0x100, 10800, 10800, MIN_INT32, 0x7fffffff, 0, 20250 }
 };
 static const sal_Int32 mso_sptTextDeflateTopDefault[] =
 {
@@ -7092,7 +7097,7 @@
     (sal_Int32*)mso_sptTextDeflateTopDefault,
     (SvxMSDffTextRectangles*)mso_sptFontWorkTextRect, sizeof( mso_sptFontWorkTextRect ) / sizeof( SvxMSDffTextRectangles ),
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     NULL, 0,
     (SvxMSDffHandle*)mso_sptTextDeflateTopHandle, sizeof( mso_sptTextDeflateTopHandle ) / sizeof( SvxMSDffHandle )
 };
@@ -7124,7 +7129,7 @@
 static const SvxMSDffHandle mso_sptTextDeflateInflateHandle[] =
 {
     {   MSDFF_HANDLE_FLAGS_RANGE,
-        10800, 0x100, 10800, 10800, 0x80000000, 0x7fffffff, 1300, 20300 }
+        10800, 0x100, 10800, 10800, MIN_INT32, 0x7fffffff, 1300, 20300 }
 };
 static const sal_Int32 mso_sptTextDeflateInflateDefault[] =
 {
@@ -7138,7 +7143,7 @@
     (sal_Int32*)mso_sptTextDeflateInflateDefault,
     (SvxMSDffTextRectangles*)mso_sptFontWorkTextRect, sizeof( mso_sptFontWorkTextRect ) / sizeof( SvxMSDffTextRectangles ),
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     NULL, 0,
     (SvxMSDffHandle*)mso_sptTextDeflateInflateHandle, sizeof( mso_sptTextDeflateInflateHandle ) / sizeof( SvxMSDffHandle )
 };
@@ -7178,7 +7183,7 @@
 static const SvxMSDffHandle mso_sptTextDeflateInflateDeflateHandle[] =
 {
     {   MSDFF_HANDLE_FLAGS_RANGE,
-        10800, 0x100, 10800, 10800, 0x80000000, 0x7fffffff, 850, 9550 }
+        10800, 0x100, 10800, 10800, MIN_INT32, 0x7fffffff, 850, 9550 }
 };
 static const sal_Int32 mso_sptTextDeflateInflateDeflateDefault[] =
 {
@@ -7192,7 +7197,7 @@
     (sal_Int32*)mso_sptTextDeflateInflateDeflateDefault,
     (SvxMSDffTextRectangles*)mso_sptFontWorkTextRect, sizeof( mso_sptFontWorkTextRect ) / sizeof( SvxMSDffTextRectangles ),
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     NULL, 0,
     (SvxMSDffHandle*)mso_sptTextDeflateInflateDeflateHandle, sizeof( mso_sptTextDeflateInflateDeflateHandle ) / sizeof( SvxMSDffHandle )
 };
@@ -7215,7 +7220,7 @@
     (sal_Int32*)mso_sptWaveDefault,
     (SvxMSDffTextRectangles*)mso_sptFontWorkTextRect, sizeof( mso_sptFontWorkTextRect ) / sizeof( SvxMSDffTextRectangles ),
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     (SvxMSDffVertPair*)mso_sptWaveGluePoints, sizeof( mso_sptWaveGluePoints ) / sizeof( SvxMSDffVertPair ),
     (SvxMSDffHandle*)mso_sptWaveHandle, sizeof( mso_sptWaveHandle ) / sizeof( SvxMSDffHandle )
 };
@@ -7233,7 +7238,7 @@
     (sal_Int32*)mso_sptWaveDefault,
     (SvxMSDffTextRectangles*)mso_sptFontWorkTextRect, sizeof( mso_sptFontWorkTextRect ) / sizeof( SvxMSDffTextRectangles ),
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     (SvxMSDffVertPair*)mso_sptWaveGluePoints, sizeof( mso_sptWaveGluePoints ) / sizeof( SvxMSDffVertPair ),
     (SvxMSDffHandle*)mso_sptWaveHandle, sizeof( mso_sptWaveHandle ) / sizeof( SvxMSDffHandle )
 };
@@ -7256,7 +7261,7 @@
     (sal_Int32*)mso_sptDoubleWaveDefault,
     (SvxMSDffTextRectangles*)mso_sptDoubleWaveTextRect, sizeof( mso_sptDoubleWaveTextRect ) / sizeof( SvxMSDffTextRectangles ),
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     (SvxMSDffVertPair*)mso_sptDoubleWaveGluePoints, sizeof( mso_sptDoubleWaveGluePoints ) / sizeof( SvxMSDffVertPair ),
     (SvxMSDffHandle*)mso_sptDoubleWaveHandle, sizeof( mso_sptDoubleWaveHandle ) / sizeof( SvxMSDffHandle )
 };
@@ -7274,7 +7279,7 @@
     (sal_Int32*)mso_sptDoubleWaveDefault,
     (SvxMSDffTextRectangles*)mso_sptDoubleWaveTextRect, sizeof( mso_sptDoubleWaveTextRect ) / sizeof( SvxMSDffTextRectangles ),
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     (SvxMSDffVertPair*)mso_sptDoubleWaveGluePoints, sizeof( mso_sptDoubleWaveGluePoints ) / sizeof( SvxMSDffVertPair ),
     (SvxMSDffHandle*)mso_sptDoubleWaveHandle, sizeof( mso_sptDoubleWaveHandle ) / sizeof( SvxMSDffHandle )
 };
@@ -7302,9 +7307,9 @@
 static const SvxMSDffHandle mso_sptCalloutHandle1[] =
 {
     {   0,
-        0x100, 0x101, 10800, 10800, 0x80000000, 0x7fffffff, 0x80000000, 0x7fffffff },
+        0x100, 0x101, 10800, 10800, MIN_INT32, 0x7fffffff, MIN_INT32, 0x7fffffff },
     {   0,
-        0x102, 0x103, 10800, 10800, 0x80000000, 0x7fffffff, 0x80000000, 0x7fffffff }
+        0x102, 0x103, 10800, 10800, MIN_INT32, 0x7fffffff, MIN_INT32, 0x7fffffff }
 };
 static const sal_uInt16 mso_sptCalloutSegm1a[] =
 {
@@ -7343,11 +7348,11 @@
 static const SvxMSDffHandle mso_sptCalloutHandle2[] =
 {
     {   0,
-        0x100, 0x101, 10800, 10800, 0x80000000, 0x7fffffff, 0x80000000, 0x7fffffff },
+        0x100, 0x101, 10800, 10800, MIN_INT32, 0x7fffffff, MIN_INT32, 0x7fffffff },
     {   0,
-        0x102, 0x103, 10800, 10800, 0x80000000, 0x7fffffff, 0x80000000, 0x7fffffff },
+        0x102, 0x103, 10800, 10800, MIN_INT32, 0x7fffffff, MIN_INT32, 0x7fffffff },
     {   0,
-        0x104, 0x105, 10800, 10800, 0x80000000, 0x7fffffff, 0x80000000, 0x7fffffff }
+        0x104, 0x105, 10800, 10800, MIN_INT32, 0x7fffffff, MIN_INT32, 0x7fffffff }
 };
 static const sal_uInt16 mso_sptCallout2Segm1a[] =
 {
@@ -7390,13 +7395,13 @@
 static const SvxMSDffHandle mso_sptCalloutHandle3[] =
 {
     {   0,
-        0x100, 0x101, 10800, 10800, 0x80000000, 0x7fffffff, 0x80000000, 0x7fffffff },
+        0x100, 0x101, 10800, 10800, MIN_INT32, 0x7fffffff, MIN_INT32, 0x7fffffff },
     {   0,
-        0x102, 0x103, 10800, 10800, 0x80000000, 0x7fffffff, 0x80000000, 0x7fffffff },
+        0x102, 0x103, 10800, 10800, MIN_INT32, 0x7fffffff, MIN_INT32, 0x7fffffff },
     {   0,
-        0x104, 0x105, 10800, 10800, 0x80000000, 0x7fffffff, 0x80000000, 0x7fffffff },
+        0x104, 0x105, 10800, 10800, MIN_INT32, 0x7fffffff, MIN_INT32, 0x7fffffff },
     {   0,
-        0x106, 0x107, 10800, 10800, 0x80000000, 0x7fffffff, 0x80000000, 0x7fffffff }
+        0x106, 0x107, 10800, 10800, MIN_INT32, 0x7fffffff, MIN_INT32, 0x7fffffff }
 };
 static const sal_uInt16 mso_sptCallout3Segm1a[] =
 {
@@ -7441,7 +7446,7 @@
     (sal_Int32*)mso_sptCalloutDefault1,
     NULL, 0,
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     NULL, 0,
     (SvxMSDffHandle*)mso_sptCalloutHandle1, sizeof( mso_sptCalloutHandle1 ) / sizeof( SvxMSDffHandle )
 };
@@ -7453,7 +7458,7 @@
     (sal_Int32*)mso_sptCalloutDefault2,
     NULL, 0,
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     NULL, 0,
     (SvxMSDffHandle*)mso_sptCalloutHandle1, sizeof( mso_sptCalloutHandle1 ) / sizeof( SvxMSDffHandle )
 };
@@ -7465,7 +7470,7 @@
     (sal_Int32*)mso_sptCalloutDefault3,
     NULL, 0,
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     NULL, 0,
     (SvxMSDffHandle*)mso_sptCalloutHandle2, sizeof( mso_sptCalloutHandle2 ) / sizeof( SvxMSDffHandle )
 };
@@ -7477,7 +7482,7 @@
     (sal_Int32*)mso_sptCalloutDefault4,
     NULL, 0,
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     NULL, 0,
     (SvxMSDffHandle*)mso_sptCalloutHandle3, sizeof( mso_sptCalloutHandle3 ) / sizeof( SvxMSDffHandle )
 };
@@ -7489,7 +7494,7 @@
     (sal_Int32*)mso_sptCalloutDefault1,
     NULL, 0,
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     NULL, 0,
     (SvxMSDffHandle*)mso_sptCalloutHandle1, sizeof( mso_sptCalloutHandle1 ) / sizeof( SvxMSDffHandle )
 };
@@ -7501,7 +7506,7 @@
     (sal_Int32*)mso_sptCalloutDefault2,
     NULL, 0,
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     NULL, 0,
     (SvxMSDffHandle*)mso_sptCalloutHandle1, sizeof( mso_sptCalloutHandle1 ) / sizeof( SvxMSDffHandle )
 };
@@ -7513,7 +7518,7 @@
     (sal_Int32*)mso_sptCalloutDefault3,
     NULL, 0,
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     NULL, 0,
     (SvxMSDffHandle*)mso_sptCalloutHandle2, sizeof( mso_sptCalloutHandle2 ) / sizeof( SvxMSDffHandle )
 };
@@ -7525,7 +7530,7 @@
     (sal_Int32*)mso_sptCalloutDefault4,
     NULL, 0,
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     NULL, 0,
     (SvxMSDffHandle*)mso_sptCalloutHandle3, sizeof( mso_sptCalloutHandle3 ) / sizeof( SvxMSDffHandle )
 };
@@ -7537,7 +7542,7 @@
     (sal_Int32*)mso_sptCalloutDefault1,
     NULL, 0,
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     NULL, 0,
     (SvxMSDffHandle*)mso_sptCalloutHandle1, sizeof( mso_sptCalloutHandle1 ) / sizeof( SvxMSDffHandle )
 };
@@ -7549,7 +7554,7 @@
     (sal_Int32*)mso_sptCalloutDefault2,
     NULL, 0,
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     NULL, 0,
     (SvxMSDffHandle*)mso_sptCalloutHandle1, sizeof( mso_sptCalloutHandle1 ) / sizeof( SvxMSDffHandle )
 };
@@ -7561,7 +7566,7 @@
     (sal_Int32*)mso_sptCalloutDefault3,
     NULL, 0,
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     NULL, 0,
     (SvxMSDffHandle*)mso_sptCalloutHandle2, sizeof( mso_sptCalloutHandle2 ) / sizeof( SvxMSDffHandle )
 };
@@ -7573,7 +7578,7 @@
     (sal_Int32*)mso_sptCalloutDefault4,
     NULL, 0,
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     NULL, 0,
     (SvxMSDffHandle*)mso_sptCalloutHandle3, sizeof( mso_sptCalloutHandle3 ) / sizeof( SvxMSDffHandle )
 };
@@ -7585,7 +7590,7 @@
     (sal_Int32*)mso_sptCalloutDefault1,
     NULL, 0,
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     NULL, 0,
     (SvxMSDffHandle*)mso_sptCalloutHandle1, sizeof( mso_sptCalloutHandle1 ) / sizeof( SvxMSDffHandle )
 };
@@ -7597,7 +7602,7 @@
     (sal_Int32*)mso_sptCalloutDefault2,
     NULL, 0,
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     NULL, 0,
     (SvxMSDffHandle*)mso_sptCalloutHandle1, sizeof( mso_sptCalloutHandle1 ) / sizeof( SvxMSDffHandle )
 };
@@ -7609,7 +7614,7 @@
     (sal_Int32*)mso_sptCalloutDefault3,
     NULL, 0,
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     NULL, 0,
     (SvxMSDffHandle*)mso_sptCalloutHandle2, sizeof( mso_sptCalloutHandle2 ) / sizeof( SvxMSDffHandle )
 };
@@ -7621,7 +7626,7 @@
     (sal_Int32*)mso_sptCalloutDefault4,
     NULL, 0,
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     NULL, 0,
     (SvxMSDffHandle*)mso_sptCalloutHandle3, sizeof( mso_sptCalloutHandle3 ) / sizeof( SvxMSDffHandle )
 };
@@ -7642,7 +7647,7 @@
     (sal_Int32*)NULL,
     NULL, 0,
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     NULL, 0,
     (SvxMSDffHandle*)NULL, 0
 };
@@ -7663,7 +7668,7 @@
     (sal_Int32*)NULL,
     NULL, 0,
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     NULL, 0,
     (SvxMSDffHandle*)NULL, 0
 };
@@ -7687,7 +7692,7 @@
 static const SvxMSDffHandle mso_sptBentConnector3Handle[] =
 {
     {   MSDFF_HANDLE_FLAGS_RANGE,
-        0x100, 10800, 10800, 10800, 0x80000000, 0x7fffffff, 0x80000000, 0x7fffffff }
+        0x100, 10800, 10800, 10800, MIN_INT32, 0x7fffffff, MIN_INT32, 0x7fffffff }
 };
 static const mso_CustomShape msoBentConnector3 =
 {
@@ -7697,7 +7702,7 @@
     (sal_Int32*)mso_sptBentConnector3Default,
     NULL, 0,
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     NULL, 0,
     (SvxMSDffHandle*)mso_sptBentConnector3Handle, sizeof( mso_sptBentConnector3Handle ) / sizeof( SvxMSDffHandle )
 };
@@ -7725,9 +7730,9 @@
 static const SvxMSDffHandle mso_sptBentConnector4Handle[] =
 {
     {   MSDFF_HANDLE_FLAGS_RANGE | MSDFF_HANDLE_FLAGS_RANGE_Y_MIN_IS_SPECIAL | MSDFF_HANDLE_FLAGS_RANGE_Y_MAX_IS_SPECIAL,
-        0x100, 4 + 3, 10800, 10800, 0x80000000, 0x7fffffff, 4 + 3, 4 + 3 },
+        0x100, 4 + 3, 10800, 10800, MIN_INT32, 0x7fffffff, 4 + 3, 4 + 3 },
     {   MSDFF_HANDLE_FLAGS_RANGE | MSDFF_HANDLE_FLAGS_RANGE_X_MIN_IS_SPECIAL | MSDFF_HANDLE_FLAGS_RANGE_X_MAX_IS_SPECIAL,
-        3 + 3, 0x101, 10800, 10800, 3 + 3, 3 + 3, 0x80000000, 0x7fffffff }
+        3 + 3, 0x101, 10800, 10800, 3 + 3, 3 + 3, MIN_INT32, 0x7fffffff }
 };
 static const mso_CustomShape msoBentConnector4 =
 {
@@ -7737,7 +7742,7 @@
     (sal_Int32*)mso_sptBentConnector4Default,
     NULL, 0,
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     NULL, 0,
     (SvxMSDffHandle*)mso_sptBentConnector4Handle, sizeof( mso_sptBentConnector4Handle ) / sizeof( SvxMSDffHandle )
 };
@@ -7768,11 +7773,11 @@
 static const SvxMSDffHandle mso_sptBentConnector5Handle[] =
 {
     {   MSDFF_HANDLE_FLAGS_RANGE | MSDFF_HANDLE_FLAGS_RANGE_Y_MIN_IS_SPECIAL | MSDFF_HANDLE_FLAGS_RANGE_Y_MAX_IS_SPECIAL,
-        0x100, 5 + 3, 10800, 10800, 0x80000000, 0x7fffffff, 5 + 3, 5 + 3 },
+        0x100, 5 + 3, 10800, 10800, MIN_INT32, 0x7fffffff, 5 + 3, 5 + 3 },
     {   MSDFF_HANDLE_FLAGS_RANGE | MSDFF_HANDLE_FLAGS_RANGE_X_MIN_IS_SPECIAL | MSDFF_HANDLE_FLAGS_RANGE_X_MAX_IS_SPECIAL,
-        3 + 3, 0x101, 10800, 10800, 3 + 3, 3 + 3, 0x80000000, 0x7fffffff },
+        3 + 3, 0x101, 10800, 10800, 3 + 3, 3 + 3, MIN_INT32, 0x7fffffff },
     {   MSDFF_HANDLE_FLAGS_RANGE | MSDFF_HANDLE_FLAGS_RANGE_Y_MIN_IS_SPECIAL | MSDFF_HANDLE_FLAGS_RANGE_Y_MAX_IS_SPECIAL,
-        0x102, 7 + 3, 10800, 10800, 0x80000000, 0x7fffffff, 7 + 3, 7 + 3 }
+        0x102, 7 + 3, 10800, 10800, MIN_INT32, 0x7fffffff, 7 + 3, 7 + 3 }
 };
 static const mso_CustomShape msoBentConnector5 =
 {
@@ -7782,7 +7787,7 @@
     (sal_Int32*)mso_sptBentConnector5Default,
     NULL, 0,
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     NULL, 0,
     (SvxMSDffHandle*)mso_sptBentConnector5Handle, sizeof( mso_sptBentConnector5Handle ) / sizeof( SvxMSDffHandle )
 };
@@ -7803,7 +7808,7 @@
     (sal_Int32*)NULL,
     NULL, 0,
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     NULL, 0,
     (SvxMSDffHandle*)NULL, 0
 };
@@ -7830,7 +7835,7 @@
 static const SvxMSDffHandle mso_sptCurvedConnector3Handle[] =
 {
     {   MSDFF_HANDLE_FLAGS_RANGE,
-        0x100, 10800, 10800, 10800, 0x80000000, 0x7fffffff, 0x80000000, 0x7fffffff }
+        0x100, 10800, 10800, 10800, MIN_INT32, 0x7fffffff, MIN_INT32, 0x7fffffff }
 };
 static const mso_CustomShape msoCurvedConnector3 =
 {
@@ -7840,7 +7845,7 @@
     (sal_Int32*)mso_sptCurvedConnector3Default,
     NULL, 0,
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     NULL, 0,
     (SvxMSDffHandle*)mso_sptCurvedConnector3Handle, sizeof( mso_sptCurvedConnector3Handle ) / sizeof( SvxMSDffHandle )
 };
@@ -7881,9 +7886,9 @@
 static const SvxMSDffHandle mso_sptCurvedConnector4Handle[] =
 {
     {   MSDFF_HANDLE_FLAGS_RANGE | MSDFF_HANDLE_FLAGS_RANGE_Y_MIN_IS_SPECIAL | MSDFF_HANDLE_FLAGS_RANGE_Y_MAX_IS_SPECIAL,
-        0x100, 9 + 3, 10800, 10800, 0x80000000, 0x7fffffff, 9 + 3, 9 + 3 },
+        0x100, 9 + 3, 10800, 10800, MIN_INT32, 0x7fffffff, 9 + 3, 9 + 3 },
     {   MSDFF_HANDLE_FLAGS_RANGE | MSDFF_HANDLE_FLAGS_RANGE_X_MIN_IS_SPECIAL | MSDFF_HANDLE_FLAGS_RANGE_X_MAX_IS_SPECIAL,
-        3 + 3, 0x101, 10800, 10800, 3 + 3, 3 + 3, 0x80000000, 0x7fffffff }
+        3 + 3, 0x101, 10800, 10800, 3 + 3, 3 + 3, MIN_INT32, 0x7fffffff }
 };
 static const mso_CustomShape msoCurvedConnector4 =
 {
@@ -7893,7 +7898,7 @@
     (sal_Int32*)mso_sptCurvedConnector4Default,
     NULL, 0,
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     NULL, 0,
     (SvxMSDffHandle*)mso_sptCurvedConnector4Handle, sizeof( mso_sptCurvedConnector4Handle ) / sizeof( SvxMSDffHandle )
 };
@@ -7942,11 +7947,11 @@
 static const SvxMSDffHandle mso_sptCurvedConnector5Handle[] =
 {
     {   MSDFF_HANDLE_FLAGS_RANGE | MSDFF_HANDLE_FLAGS_RANGE_Y_MIN_IS_SPECIAL | MSDFF_HANDLE_FLAGS_RANGE_Y_MAX_IS_SPECIAL,
-        0x100, 11 + 3, 10800, 10800, 0x80000000, 0x7fffffff, 11 + 3, 11 + 3 },
+        0x100, 11 + 3, 10800, 10800, MIN_INT32, 0x7fffffff, 11 + 3, 11 + 3 },
     {   MSDFF_HANDLE_FLAGS_RANGE | MSDFF_HANDLE_FLAGS_RANGE_X_MIN_IS_SPECIAL | MSDFF_HANDLE_FLAGS_RANGE_X_MAX_IS_SPECIAL,
-        3 + 3, 0x101, 10800, 10800, 3 + 3, 3 + 3, 0x80000000, 0x7fffffff },
+        3 + 3, 0x101, 10800, 10800, 3 + 3, 3 + 3, MIN_INT32, 0x7fffffff },
     {   MSDFF_HANDLE_FLAGS_RANGE | MSDFF_HANDLE_FLAGS_RANGE_Y_MIN_IS_SPECIAL | MSDFF_HANDLE_FLAGS_RANGE_Y_MAX_IS_SPECIAL,
-        0x102, 16 + 3, 10800, 10800, 0x80000000, 0x7fffffff, 16 + 3, 16 + 3 }
+        0x102, 16 + 3, 10800, 10800, MIN_INT32, 0x7fffffff, 16 + 3, 16 + 3 }
 };
 static const mso_CustomShape msoCurvedConnector5 =
 {
@@ -7956,7 +7961,7 @@
     (sal_Int32*)mso_sptCurvedConnector5Default,
     NULL, 0,
     21600, 21600,
-    0x80000000, 0x80000000,
+    MIN_INT32, MIN_INT32,
     NULL, 0,
     (SvxMSDffHandle*)mso_sptCurvedConnector5Handle, sizeof( mso_sptCurvedConnector5Handle ) / sizeof( SvxMSDffHandle )
 };
