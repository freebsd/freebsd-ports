--- libevmasm/Instruction.h.orig	2020-01-28 10:08:51 UTC
+++ libevmasm/Instruction.h
@@ -26,6 +26,8 @@
 #include <libsolutil/Assertions.h>
 #include <functional>
 
+#undef MSIZE // remove MSIZE definition from <sys/params.h>, included by boost 1.66.0
+
 namespace solidity::evmasm
 {
 
