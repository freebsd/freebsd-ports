--- libevmasm/Instruction.h.orig	2020-12-16 17:41:40 UTC
+++ libevmasm/Instruction.h
@@ -27,6 +27,8 @@
 #include <libsolutil/Assertions.h>
 #include <functional>
 
+#undef MSIZE // remove MSIZE definition from <sys/params.h>, included by boost 1.66.0
+
 namespace solidity::evmasm
 {
 
