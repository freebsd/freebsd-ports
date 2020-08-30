--- src/lattice.cpp.orig	2020-08-30 14:33:39 UTC
+++ src/lattice.cpp
@@ -32,6 +32,10 @@
 #include "display.hpp"
 #include "spiFlash.hpp"
 
+#ifndef ETIME
+#define ETIME 9935
+#endif
+
 using namespace std;
 
 #define ISC_ENABLE				0xc6
