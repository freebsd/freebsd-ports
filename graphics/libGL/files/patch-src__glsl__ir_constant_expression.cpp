--- ./src/glsl/ir_constant_expression.cpp.orig	2014-02-05 21:59:10.000000000 +0100
+++ ./src/glsl/ir_constant_expression.cpp	2014-02-23 22:01:50.000000000 +0100
@@ -60,6 +60,11 @@
 }
 #endif
 
+#include <sys/param.h>
+#if __FreeBSD_version <= 704100 || (__FreeBSD_version >= 800000 && __FreeBSD_version < 802502) || (__FreeBSD_version >= 900000 && __FreeBSD_version < 900027)
+#define log2(x) (log(x) / log(2))
+#endif
+
 static float
 dot(ir_constant *op0, ir_constant *op1)
 {
