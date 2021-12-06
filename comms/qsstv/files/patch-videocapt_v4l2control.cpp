--- videocapt/v4l2control.cpp.orig	2019-04-18 21:15:23 UTC
+++ videocapt/v4l2control.cpp
@@ -32,7 +32,6 @@
 #include <cerrno>
 #include <cstring>
 //#include <libv4l2.h>
-#include <linux/types.h>          /* for videodev2.h */
 #include <linux/videodev2.h>
 
 #include <QPushButton>
