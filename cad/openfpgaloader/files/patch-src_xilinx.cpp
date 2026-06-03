--- src/xilinx.cpp.orig	2026-03-01 10:27:31 UTC
+++ src/xilinx.cpp
@@ -540,6 +540,10 @@ bool Xilinx::zynqmp_init(const std::string &family)
 	return true;
 }
 
+#ifndef ETIME
+#define ETIME 9935
+#endif
+
 void Xilinx::reset()
 {
 	_jtag->shiftIR(get_ircode(_ircode_map, "JSHUTDOWN"), NULL, _irlen);
