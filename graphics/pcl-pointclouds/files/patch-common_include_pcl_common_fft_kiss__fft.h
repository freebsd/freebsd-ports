--- common/include/pcl/common/fft/kiss_fft.h.orig	2017-08-08 06:04:14 UTC
+++ common/include/pcl/common/fft/kiss_fft.h
@@ -7,7 +7,7 @@
 #include <string.h>
 
 #if !defined(__APPLE__)
-#include <malloc.h>
+#include <stdlib.h>
 #endif
 
 #include <pcl/pcl_exports.h>
