--- iv/imageviewer.cpp.orig	2012-04-17 17:04:57.000000000 +0930
+++ iv/imageviewer.cpp	2012-04-17 17:05:43.000000000 +0930
@@ -49,6 +49,11 @@
 #include "sysutil.h"
 #include "filesystem.h"
 
+#if !defined(log2f)
+
+inline float log2f(float x) {return logf(x)*(float)1.4426950408889634;}
+
+#endif /* log2f */
 
 namespace
 {
