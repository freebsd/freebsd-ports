--- plugins/zynaddsubfx/src/Misc/Util.cpp.orig	2011-10-04 13:23:12.000000000 +0000
+++ plugins/zynaddsubfx/src/Misc/Util.cpp	2011-10-04 13:23:28.000000000 +0000
@@ -115,7 +115,7 @@
 
 void invSignal(REALTYPE *sig, size_t len)
 {
-    for(int i = 0; i < len; i++)
+    for(unsigned int i = 0; i < len; i++)
         sig[i] *= -1.0f;
 }
 
