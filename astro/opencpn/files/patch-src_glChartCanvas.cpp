--- src/glChartCanvas.cpp.orig	2020-10-22 23:20:06 UTC
+++ src/glChartCanvas.cpp
@@ -57,7 +57,7 @@ class OCPNStopWatch (private)
 
 #if defined(__OCPN__ANDROID__)
 #include "androidUTIL.h"
-#elif defined(__WXQT__)
+#else
 #include <GL/glx.h>
 #endif
 
