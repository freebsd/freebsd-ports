# Backport of LLVM commit 6c0c62f51e3c ([LV] Have ExtractValue match the shape of the operand,
# https://github.com/llvm/llvm-project/pull/229927) to the bundled LLVM 23.1:
# the loop vectorizer narrowed an extractvalue of a widened struct-returning
# intrinsic (e.g. llvm.sadd.with.overflow) to a single scalar, producing invalid IR
# ("Cannot select: i64 = sign_extend v4i32" in ISel). Hit on powerpc64le by every
# consumer of the libbz2-rs-sys crate (devel/py-maturin, security/proton-pass-cli).

--- src/llvm-project/llvm/lib/Transforms/Vectorize/LoopVectorize.cpp.orig
+++ src/llvm-project/llvm/lib/Transforms/Vectorize/LoopVectorize.cpp
@@ -6472,6 +6472,19 @@
                        VPI->getOpcode()) &&
          "Should have been handled prior to this!");
 
+  // An extractvalue takes the shape of its operand: we cannot extract a lane
+  // from a widened struct, nor build a struct from replicated lanes.
+  if (VPI->getOpcode() == Instruction::ExtractValue &&
+      !vputils::isSingleScalar(VPI->getOperand(0)))
+    if (VPRecipeBase *OpR = VPI->getOperand(0)->getDefiningRecipe())
+      if (!vputils::doesGeneratePerAllLanes(OpR))
+        return tryToWiden(VPI);
+  if (VPI->getOpcode() == Instruction::ExtractValue)
+    return new VPReplicateRecipe(Instr, VPI->operandsWithoutMask(),
+                                 vputils::isSingleScalar(VPI->getOperand(0)),
+                                 /*Mask=*/nullptr, *VPI, *VPI,
+                                 VPI->getDebugLoc());
+
   if (!shouldWiden(Instr, Range))
     return nullptr;
 
