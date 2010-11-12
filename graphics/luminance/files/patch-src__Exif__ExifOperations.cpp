--- ./src/Exif/ExifOperations.cpp.orig	2010-04-12 20:58:25.000000000 +0400
+++ ./src/Exif/ExifOperations.cpp	2010-11-12 14:20:53.446299319 +0300
@@ -23,6 +23,7 @@
 
 #include <image.hpp>
 #include <cmath>
+#include "../arch/freebsd/math.h"
 
 #include "ExifOperations.h"
 
