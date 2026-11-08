--- swift/lib/SILOptimizer/Transforms/SILMem2Reg.cpp.orig	2026-09-26 07:21:23 UTC
+++ swift/lib/SILOptimizer/Transforms/SILMem2Reg.cpp
@@ -2334,6 +2334,13 @@ class SILMem2Reg : public SILFunctionTransform {
 
     SILFunction *f = getFunction();
 
+    // FIXME: We should be able to support ownership functions.
+    if (f->hasOwnership()) {
+      LLVM_DEBUG(llvm::dbgs() << "SILMem2Reg skipped for ownership function: "
+                              << f->getName() << "\n");
+      return;
+    }
+
     LLVM_DEBUG(llvm::dbgs()
                << "** Mem2Reg on function: " << f->getName() << " **\n");
 
