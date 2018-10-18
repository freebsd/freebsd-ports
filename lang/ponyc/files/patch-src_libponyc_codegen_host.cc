--- src/libponyc/codegen/host.cc.orig	2018-10-17 11:42:19 UTC
+++ src/libponyc/codegen/host.cc
@@ -56,7 +56,14 @@ char* LLVMGetHostCPUFeatures()
 {
   StringMap<bool> features;
   bool got_features = sys::getHostCPUFeatures(features);
+#ifdef PLATFORM_IS_ARM
+  // LLVM might not have CPU features support on e.g. FreeBSD/aarch64
+  if (!got_features) {
+    features["neon"] = true;
+  }
+#else
   pony_assert(got_features);
+#endif
   (void)got_features;
 
   // Calculate the size of buffer that will be needed to return all features.
