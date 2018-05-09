--- ./modules/highgui/src/window.cpp.orig	2018-05-02 14:34:06.721814000 -0400
+++ ./modules/highgui/src/window.cpp	2018-05-02 14:34:25.980873000 -0400
@@ -165,7 +165,7 @@ CV_IMPL double cvGetWindowProperty(const char* name, i
     }
 }
 
-cv::Rect cvGetWindowImageRect(const char* name)
+CvRect cvGetWindowImageRect(const char* name)
 {
     if (!name)
         return cv::Rect(-1, -1, -1, -1);
