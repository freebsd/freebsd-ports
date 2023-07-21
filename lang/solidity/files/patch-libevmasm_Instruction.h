--- libevmasm/Instruction.h.orig	2023-07-19 09:24:46 UTC
+++ libevmasm/Instruction.h
@@ -27,6 +27,8 @@
 #include <libsolutil/Assertions.h>
 #include <liblangutil/EVMVersion.h>
 
+#undef MSIZE // remove MSIZE definition from <sys/params.h>, included by boost 1.66.0
+
 namespace solidity::evmasm
 {
 
