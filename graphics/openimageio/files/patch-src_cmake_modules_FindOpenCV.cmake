--- src/cmake/modules/FindOpenCV.cmake.orig	2018-02-02 19:00:47 UTC
+++ src/cmake/modules/FindOpenCV.cmake
@@ -55,7 +55,7 @@ set (opencv_components opencv_imgproc op
 if (NOT ${OpenCV_VERSION} VERSION_LESS 3.0.0)
     set (opencv_components opencv_videoio ${opencv_components})
 else (NOT ${OpenCV_VERSION} VERSION_LESS 3.0.0)
-    set (opencv_components opencv_videoio ${opencv_components})
+    set (opencv_components opencv_highgui ${opencv_components})
 endif ()
 foreach (component ${opencv_components})
     find_library (${component}_lib
