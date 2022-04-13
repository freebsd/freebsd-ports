--- libevmasm/Instruction.h.orig	2022-03-16 14:18:52 UTC
+++ libevmasm/Instruction.h
@@ -26,6 +26,8 @@
 #include <libsolutil/Common.h>
 #include <libsolutil/Assertions.h>
 
+#undef MSIZE // remove MSIZE definition from <sys/params.h>, included by boost 1.66.0
+
 namespace solidity::evmasm
 {
 
