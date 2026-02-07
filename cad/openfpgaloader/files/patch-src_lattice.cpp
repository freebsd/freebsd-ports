--- src/lattice.cpp.orig	2020-12-17 12:58:30 UTC
+++ src/lattice.cpp
@@ -34,6 +34,10 @@
 #include "part.hpp"
 #include "spiFlash.hpp"
 
+#ifndef ETIME
+#define ETIME 9935
+#endif
+
 using namespace std;
 
 #define ISC_ENABLE				0xc6
