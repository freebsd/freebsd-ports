--- src/xilinx.cpp.orig	2020-12-17 12:58:30 UTC
+++ src/xilinx.cpp
@@ -47,6 +47,10 @@ Xilinx::~Xilinx() {}
 #define ISC_DISABLE 0x16
 #define BYPASS   0x3f
 
+#ifndef ETIME
+#define ETIME 9935
+#endif
+
 void Xilinx::reset()
 {
 	_jtag->shiftIR(JSHUTDOWN, 6);
