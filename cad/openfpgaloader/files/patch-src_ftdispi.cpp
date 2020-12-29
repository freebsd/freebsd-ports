--- src/ftdispi.cpp.orig	2020-12-29 13:50:17 UTC
+++ src/ftdispi.cpp
@@ -8,6 +8,10 @@
 #include "ftdipp_mpsse.hpp"
 #include "ftdispi.hpp"
 
+#ifndef ETIME
+#define ETIME 9935
+#endif
+
 /*
  * SCLK -> ADBUS0
  * MOSI -> ADBUS1
