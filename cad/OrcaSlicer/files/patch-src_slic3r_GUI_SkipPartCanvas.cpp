--- src/slic3r/GUI/SkipPartCanvas.cpp.orig	2026-03-22 17:56:38 UTC
+++ src/slic3r/GUI/SkipPartCanvas.cpp
@@ -3,6 +3,7 @@
 
 #include <opencv2/opencv.hpp>
 #include <opencv2/core.hpp>
+#include <opencv2/imgcodecs.hpp>
 #include <opencv2/imgproc.hpp>
 #include <boost/log/trivial.hpp>
 #include <boost/thread/mutex.hpp>
@@ -694,4 +695,4 @@ void ModelSettingHelper::DataHandler(const XML_Char *s
     // do nothing
 }
 }
-}
\ No newline at end of file
+}
