--- src/visualizer.h.orig	2012-04-01 20:49:09.000000000 +0400
+++ src/visualizer.h	2014-06-16 19:07:34.000000000 +0400
@@ -34,6 +34,8 @@
 # include <fftw3.h>
 #endif
 
+#include <sys/time.h>
+
 class Visualizer : public Screen<Window>
 {
 	public:
