--- src/image/tim_png.cpp.orig	2012-04-25 06:16:33.000000000 +0200
+++ src/image/tim_png.cpp	2012-04-25 06:16:57.000000000 +0200
@@ -26,6 +26,7 @@
 #include <string.h>
 #include "tim.h"
 #include "png.h"
+#include "zlib.h"
 
 /*==============================================================================
 Types
