--- sound.cc.orig	2018-07-31 18:02:19 UTC
+++ sound.cc
@@ -38,7 +38,7 @@
 #include <math.h>
 #include <limits.h>
 #include <gst/gst.h>
-#include <endian.h>
+#include <sys/endian.h>
 
 #include "sound.h"
 #include "global.h"
