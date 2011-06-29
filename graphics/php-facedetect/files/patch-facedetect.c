--- facedetect.c.orig	2010-03-15 01:07:12.000000000 +0100
+++ facedetect.c	2011-06-28 15:08:27.134914621 +0200
@@ -21,7 +21,7 @@
 #include "php_facedetect.h"
 
 #include <opencv/cv.h>
-#include <opencv/cvver.h>
+#include <opencv2/core/version.hpp>
 #include <opencv/highgui.h>
 
 /* {{{ facedetect_functions[]
@@ -104,7 +104,7 @@
 
 	storage = cvCreateMemStorage(0);
 
-	faces = cvHaarDetectObjects(gray, cascade, storage, 1.1, 2, CV_HAAR_DO_CANNY_PRUNING, cvSize(0, 0));
+	faces = cvHaarDetectObjects(gray, cascade, storage, 1.1, 2, CV_HAAR_DO_CANNY_PRUNING, cvSize(0, 0), cvSize(0, 0));
 
 	if(return_type) {
 
