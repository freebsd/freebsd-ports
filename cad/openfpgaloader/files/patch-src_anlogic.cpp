--- src/anlogic.cpp.orig	2020-12-29 13:39:50 UTC
+++ src/anlogic.cpp
@@ -23,6 +23,10 @@
 #include "progressBar.hpp"
 #include "spiFlash.hpp"
 
+#ifndef ETIME
+#define ETIME 9935
+#endif
+
 #define REFRESH      0x01
 #define IDCODE       0x06
 #define JTAG_PROGRAM 0x30
