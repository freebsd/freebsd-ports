--- lib/Image/ObjectDetect.xs.orig	2018-05-02 21:42:52.771732000 +0000
+++ lib/Image/ObjectDetect.xs	2018-05-02 21:43:03.658941000 +0000
@@ -7,6 +7,8 @@
 #include "cv.h"
 #include "highgui.h"
 
+#include <opencv2/imgcodecs/imgcodecs_c.h>
+
 MODULE = Image::ObjectDetect		PACKAGE = Image::ObjectDetect
 
 PROTOTYPES: ENABLE
@@ -54,11 +56,7 @@
         storage = cvCreateMemStorage(0);
         cascade = INT2PTR(CvHaarClassifierCascade *, SvIV(SvRV(self)));
         objects = cvHaarDetectObjects(gray, cascade, storage,
-#if (CV_MAJOR_VERSION < 2 || (CV_MAJOR_VERSION == 2 && CV_MINOR_VERSION < 1))
-                1.1, 2, CV_HAAR_DO_CANNY_PRUNING, cvSize(0, 0));
-#else
                 1.1, 2, CV_HAAR_DO_CANNY_PRUNING, cvSize(0, 0), cvSize(0, 0));
-#endif
 
         retval = newAV();
         for (i = 0; i < (objects ? objects->total : 0); i++) {
