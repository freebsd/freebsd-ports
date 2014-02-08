--- src/ptlib/unix/shmvideo.cxx.orig	2007-10-19 06:22:32.000000000 +0000
+++ src/ptlib/unix/shmvideo.cxx
@@ -46,6 +46,7 @@
 
 #define P_FORCE_STATIC_PLUGIN
 
+#include <fcntl.h>
 #include <ptlib.h>
 #include <ptlib/videoio.h>
 #include <ptlib/vconvert.h>
