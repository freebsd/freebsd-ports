--- src/xilinx.cpp.orig	2020-07-11 06:47:54 UTC
+++ src/xilinx.cpp
@@ -33,6 +33,10 @@ Xilinx::~Xilinx() {}
 #define ISC_DISABLE 0x16
 #define BYPASS   0x3f
 
+#ifndef ETIME
+#define ETIME 9935
+#endif
+
 void Xilinx::reset()
 {
 	_jtag->shiftIR(JSHUTDOWN, 6);
