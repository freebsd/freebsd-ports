# Backport of LLVM commit 6c0c62f51e3c ([LV] Have ExtractValue match the shape of the operand,
# https://github.com/llvm/llvm-project/pull/229927) to the bundled LLVM 23.1:
# the loop vectorizer narrowed an extractvalue of a widened struct-returning
# intrinsic (e.g. llvm.sadd.with.overflow) to a single scalar, producing invalid IR
# ("Cannot select: i64 = sign_extend v4i32" in ISel). Hit on powerpc64le by every
# consumer of the libbz2-rs-sys crate (devel/py-maturin, security/proton-pass-cli).

--- src/llvm-project/llvm/lib/Transforms/Vectorize/VPlanTransforms.cpp.orig
+++ src/llvm-project/llvm/lib/Transforms/Vectorize/VPlanTransforms.cpp
@@ -551,11 +551,24 @@
   VPBlockUtils::insertTwoBlocksAfter(Pred, Exiting, Entry);
   VPBlockUtils::connectBlocks(Pred, Exiting);
 
-  if (!PredRecipe->user_empty()) {
-    auto *PHIRecipe = new VPPredInstPHIRecipe(RecipeWithoutMask,
-                                              RecipeWithoutMask->getDebugLoc());
+  PredRecipe->replaceAllUsesWith(RecipeWithoutMask);
+  // Move the extracts of a struct result into the region, so only scalars
+  // leave it.
+  SmallVector<VPUser *> Defs = {RecipeWithoutMask};
+  if (RecipeWithoutMask->getScalarType()->isStructTy())
+    Defs = to_vector(RecipeWithoutMask->users());
+  for (VPUser *U : Defs) {
+    auto *Def = cast<VPReplicateRecipe>(U);
+    assert((Def == RecipeWithoutMask ||
+            Def->getOpcode() == Instruction::ExtractValue) &&
+           "only extracts can use a predicated struct");
+    Def->moveBefore(*Pred, Pred->end());
+    if (Def->user_empty())
+      continue;
+    auto *PHIRecipe = new VPPredInstPHIRecipe(Def, Def->getDebugLoc());
     Exiting->appendRecipe(PHIRecipe);
-    PredRecipe->replaceAllUsesWith(PHIRecipe);
+    Def->replaceAllUsesWith(PHIRecipe);
+    PHIRecipe->setOperand(0, Def);
   }
   PredRecipe->eraseFromParent();
   return Region;
@@ -7513,6 +7526,11 @@
       if (VPI->mayHaveSideEffects())
         continue;
 
+      // ExtractValue takes the shape of its aggregate, decided in
+      // tryToCreateWidenNonPhiRecipe.
+      if (VPI->getOpcode() == Instruction::ExtractValue)
+        continue;
+
       // We want to drop the mask operand, verify we can safely do that.
       if (VPI->isMasked() && !VPI->isSafeToSpeculativelyExecute())
         continue;
