--- src/intsect.cpp.orig	2011-05-02 20:55:06.000000000 +0900
+++ src/intsect.cpp	2011-07-24 19:43:40.000000000 +0900
@@ -12,7 +12,9 @@
 #   include "config.h"
 #endif
 
+
 #include <stdlib.h>
+#include <inttypes.h>
 
 void pushback(int32_t x1,int32_t y1,int32_t &x2,int32_t &y2,
              int32_t xp1, int32_t yp1, int32_t xp2, int32_t yp2, int xdir, int ydir, int inside)
