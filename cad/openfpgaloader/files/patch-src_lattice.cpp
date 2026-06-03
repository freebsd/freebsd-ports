--- src/lattice.cpp.orig	2026-03-01 10:27:31 UTC
+++ src/lattice.cpp
@@ -27,6 +27,10 @@
 #include "part.hpp"
 #include "spiFlash.hpp"
 
+#ifndef ETIME
+#define ETIME 9935
+#endif
+
 using namespace std;
 
 #define ISC_ENABLE					0xC6		/* ISC_ENABLE - Offline Mode */
