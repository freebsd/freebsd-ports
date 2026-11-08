--- swift/lib/IRGen/GenCall.cpp.orig	2026-10-10 18:48:34 UTC
+++ swift/lib/IRGen/GenCall.cpp
@@ -5508,8 +5508,13 @@
 
   // Initialize at the alloca point.
   if (setSwiftErrorFlag) {
-    auto nullError = llvm::ConstantPointerNull::get(
-        cast<llvm::PointerType>(errorStorageType));
+    // errorStorageType is a pointer for the swifterror flag, but on targets
+    // that do not reserve a swifterror register a typed error slot has the
+    // error's concrete (possibly non-pointer aggregate) storage type.
+    // getNullValue produces the correct zero for either case; a
+    // ConstantPointerNull carrying an aggregate type is ill-formed and gets
+    // scalarized into invalid `extractvalue <agg> null` stores downstream.
+    auto *nullError = llvm::Constant::getNullValue(errorStorageType);
     builder.CreateStore(nullError, addr);
   }
 
