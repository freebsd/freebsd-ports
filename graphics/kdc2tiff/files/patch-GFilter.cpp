--- GFilter.cpp.orig	Mon Dec 23 04:20:42 2002
+++ GFilter.cpp	Mon Dec 23 04:21:00 2002
@@ -26,7 +26,7 @@
   green = *(short*)(((char*)table)+(green&0xFFFE));
   blue = *(short*)(((char*)table)+(blue&0xFFFE));
 }
-void GFilter_GammaCorrection::setGammaCorrection(float gamma=1) {
+void GFilter_GammaCorrection::setGammaCorrection(float gamma) {
   // create table
   if (table)
     delete[] table;
