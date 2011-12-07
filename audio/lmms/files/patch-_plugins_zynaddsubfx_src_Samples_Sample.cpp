--- plugins/zynaddsubfx/src/Samples/Sample.cpp	2011-07-02 13:14:01.000000000 +0000
+++ plugins/zynaddsubfx/src/Samples/Sample.cpp.new	2011-09-30 21:17:49.000000000 +0000
@@ -116,7 +116,7 @@
 
 void Sample::resize(unsigned int nsize)
 {
-    if(bufferSize == nsize)
+    if(bufferSize == (int)nsize)
         return;
     else {//resampling occurs here
         float ratio = (nsize * 1.0) / (bufferSize * 1.0);
