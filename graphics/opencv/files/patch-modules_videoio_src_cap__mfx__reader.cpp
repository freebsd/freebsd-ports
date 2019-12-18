--- modules/videoio/src/cap_mfx_reader.cpp.orig	2018-02-23 08:38:33 UTC
+++ modules/videoio/src/cap_mfx_reader.cpp
@@ -6,6 +6,9 @@
 #include "opencv2/core/base.hpp"
 #include "cap_mfx_common.hpp"
 #include "opencv2/imgproc/hal/hal.hpp"
+#ifndef _WIN32
+#include <unistd.h> // sleep
+#endif
 
 using namespace cv;
 using namespace std;
