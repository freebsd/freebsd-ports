--- src/ftdispi.cpp.orig	2026-03-01 10:27:31 UTC
+++ src/ftdispi.cpp
@@ -14,6 +14,10 @@
 #include "ftdipp_mpsse.hpp"
 #include "ftdispi.hpp"
 
+#ifndef ETIME
+#define ETIME 9935
+#endif
+
 /*
  * SCLK -> ADBUS0
  * MOSI -> ADBUS1
