https://github.com/opencv/opencv_contrib/commit/4e10bc5dae62

--- modules/stereo/src/descriptor.cpp.orig	2018-02-22 13:38:31 UTC
+++ modules/stereo/src/descriptor.cpp
@@ -226,8 +226,8 @@ namespace cv
         //integral image computation used in the Mean Variation Census Transform
         void imageMeanKernelSize(const Mat &image, int windowSize, Mat &cost)
         {
-            CV_Assert(image.size > 0);
-            CV_Assert(cost.size > 0);
+            CV_Assert(!image.empty());
+            CV_Assert(!cost.empty());
             CV_Assert(windowSize % 2 != 0);
             int win = windowSize / 2;
             float scalling = ((float) 1) / (windowSize * windowSize);
