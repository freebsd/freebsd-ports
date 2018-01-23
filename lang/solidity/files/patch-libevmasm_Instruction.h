--- libevmasm/Instruction.h.orig	2018-01-23 11:51:18 UTC
+++ libevmasm/Instruction.h
@@ -26,6 +26,8 @@
 #include <libdevcore/Assertions.h>
 #include "Exceptions.h"
 
+#undef MSIZE // remove MSIZE definition from <sys/params.h>, included by boost 1.66.0
+
 namespace dev
 {
 namespace solidity
