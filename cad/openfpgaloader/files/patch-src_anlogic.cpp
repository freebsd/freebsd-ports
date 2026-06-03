--- src/anlogic.cpp.orig	2026-03-01 10:27:31 UTC
+++ src/anlogic.cpp
@@ -15,6 +15,10 @@
 #include "progressBar.hpp"
 #include "spiFlash.hpp"
 
+#ifndef ETIME
+#define ETIME 9935
+#endif
+
 #define REFRESH      0x01
 #define IDCODE       0x06
 #define JTAG_PROGRAM 0x30
