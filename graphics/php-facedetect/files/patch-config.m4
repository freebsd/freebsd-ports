--- config.m4.orig	2011-06-28 15:05:08.566341757 +0200
+++ config.m4	2011-06-28 15:06:08.526112463 +0200
@@ -25,15 +25,12 @@
   PHP_ADD_INCLUDE($FACEDETECT_DIR/include)
 
   AC_CHECK_HEADER([$FACEDETECT_DIR/include/opencv/cv.h], [], AC_MSG_ERROR('opencv/cv.h' header not found))
-  AC_CHECK_HEADER([$FACEDETECT_DIR/include/opencv/cvver.h], [], AC_MSG_ERROR('opencv/cvver.h' header not found))
+  AC_CHECK_HEADER([$FACEDETECT_DIR/include/opencv2/core/version.hpp], [], AC_MSG_ERROR('opencv2/core/version.hpp' header not found))
   AC_CHECK_HEADER([$FACEDETECT_DIR/include/opencv/highgui.h], [], AC_MSG_ERROR('opencv/highgui.h' header not found))
 
-  PHP_CHECK_LIBRARY(cv, cvLoad,
+  PHP_CHECK_LIBRARY(opencv_legacy, cvLoad,
   [
-    PHP_ADD_LIBRARY_WITH_PATH(cv, $FACEDETECT_DIR/lib, FACEDETECT_SHARED_LIBADD)
-    PHP_ADD_LIBRARY_WITH_PATH(cvaux, $FACEDETECT_DIR/lib, FACEDETECT_SHARED_LIBADD)
-    PHP_ADD_LIBRARY_WITH_PATH(highgui, $FACEDETECT_DIR/lib, FACEDETECT_SHARED_LIBADD)
-    PHP_ADD_LIBRARY_WITH_PATH(cxcore, $FACEDETECT_DIR/lib, FACEDETECT_SHARED_LIBADD)
+    PHP_ADD_LIBRARY_WITH_PATH(opencv_legacy, $FACEDETECT_DIR/lib, FACEDETECT_SHARED_LIBADD)
     AC_DEFINE(HAVE_FACEDETECT, 1, [ ])
   ],[
     AC_MSG_ERROR([wrong OpenCV version or OpenCV not found])
