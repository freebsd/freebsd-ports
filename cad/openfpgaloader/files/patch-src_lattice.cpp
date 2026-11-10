--- src/lattice.cpp.orig	2026-11-08 18:38:20 UTC
+++ src/lattice.cpp
@@ -27,6 +27,9 @@
 #include "part.hpp"
 #include "spiFlash.hpp"
 
+#ifndef ETIME
+#define ETIME 9935
+#endif
 
 #define ISC_ENABLE					0xC6		/* ISC_ENABLE - Offline Mode */
 #  define ISC_ENABLE_FLASH_MODE		(1 << 3)
