# Backport of LLVM commit 6c0c62f51e3c ([LV] Have ExtractValue match the shape of the operand,
# https://github.com/llvm/llvm-project/pull/229927) to the bundled LLVM 23.1:
# the loop vectorizer narrowed an extractvalue of a widened struct-returning
# intrinsic (e.g. llvm.sadd.with.overflow) to a single scalar, producing invalid IR
# ("Cannot select: i64 = sign_extend v4i32" in ISel). Hit on powerpc64le by every
# consumer of the libbz2-rs-sys crate (devel/py-maturin, security/proton-pass-cli).

--- src/llvm-project/llvm/lib/Transforms/Vectorize/VPlanUtils.cpp.orig
+++ src/llvm-project/llvm/lib/Transforms/Vectorize/VPlanUtils.cpp
@@ -391,6 +391,16 @@
   return Instruction::isUnaryOp(Opcode) || Instruction::isBinaryOp(Opcode);
 }
 
+bool vputils::doesGeneratePerAllLanes(const VPRecipeBase *R) {
+  if (auto *RepR = dyn_cast<VPReplicateRecipe>(R))
+    return !RepR->isSingleScalar();
+  if (auto *VPI = dyn_cast<VPInstruction>(R))
+    return VPI->doesGeneratePerAllLanes();
+  if (auto *SIVSteps = dyn_cast<VPScalarIVStepsRecipe>(R))
+    return !onlyFirstLaneUsed(SIVSteps);
+  return false;
+}
+
 bool vputils::isSingleScalar(const VPValue *VPV) {
   // Live-in, symbolic and canonical-IV region values are single-scalar.
   if (auto *RV = dyn_cast<VPRegionValue>(VPV))
