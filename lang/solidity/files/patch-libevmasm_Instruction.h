--- libevmasm/Instruction.h.orig	2025-05-07 10:46:47 UTC
+++ libevmasm/Instruction.h
@@ -28,6 +28,8 @@
 #include <liblangutil/EVMVersion.h>
 #include <liblangutil/Exceptions.h>
 
+#undef MSIZE // remove MSIZE definition from <sys/params.h>, included by boost 1.66.0
+
 namespace solidity::evmasm
 {
 
