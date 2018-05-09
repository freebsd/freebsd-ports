--- facedetect.c.orig	2018-05-02 21:46:34.553339000 +0000
+++ facedetect.c	2018-05-02 21:46:52.704512000 +0000
@@ -25,6 +25,7 @@
 
 #include <opencv/cv.h>
 #include <opencv/highgui.h>
+#include <opencv2/core/version.hpp>
 
 /* {{{ facedetect_functions[]
  *
