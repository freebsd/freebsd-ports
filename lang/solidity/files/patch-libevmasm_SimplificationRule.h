--- libevmasm/SimplificationRule.h.orig	2022-03-24 17:18:35 UTC
+++ libevmasm/SimplificationRule.h
@@ -25,6 +25,8 @@
 #include <libsolutil/CommonData.h>
 #include <functional>
 
+#undef MSIZE // remove MSIZE definition from <sys/params.h>, included by boost 1.66.0
+
 namespace solidity::evmasm
 {
 
