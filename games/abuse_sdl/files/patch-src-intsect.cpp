--- src/intsect.cpp.orig	2011-05-02 13:55:06.000000000 +0200
+++ src/intsect.cpp	2012-09-10 22:33:43.000000000 +0200
@@ -13,6 +13,7 @@
 #endif
 
 #include <stdlib.h>
+#include <inttypes.h>
 
 void pushback(int32_t x1,int32_t y1,int32_t &x2,int32_t &y2,
              int32_t xp1, int32_t yp1, int32_t xp2, int32_t yp2, int xdir, int ydir, int inside)
