# Backport of LLVM commit 6c0c62f51e3c ([LV] Have ExtractValue match the shape of the operand,
# https://github.com/llvm/llvm-project/pull/229927) to the bundled LLVM 23.1:
# the loop vectorizer narrowed an extractvalue of a widened struct-returning
# intrinsic (e.g. llvm.sadd.with.overflow) to a single scalar, producing invalid IR
# ("Cannot select: i64 = sign_extend v4i32" in ISel). Hit on powerpc64le by every
# consumer of the libbz2-rs-sys crate (devel/py-maturin, security/proton-pass-cli).

--- src/llvm-project/llvm/lib/Transforms/Vectorize/VPlanUtils.h.orig
+++ src/llvm-project/llvm/lib/Transforms/Vectorize/VPlanUtils.h
@@ -32,6 +32,9 @@
 /// Returns true if only scalar values of \p Def are used by all users.
 bool onlyScalarValuesUsed(const VPValue *Def);
 
+/// Returns true if \p R produces scalar values for all VF lanes.
+bool doesGeneratePerAllLanes(const VPRecipeBase *R);
+
 /// Get or create a VPValue that corresponds to the expansion of \p Expr. If \p
 /// Expr is a SCEVConstant or SCEVUnknown, return a VPValue wrapping the live-in
 /// value. Otherwise return a VPExpandSCEVRecipe to expand \p Expr. If \p Plan's
