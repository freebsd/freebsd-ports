# Backport of LLVM commit 6c0c62f51e3c ([LV] Have ExtractValue match the shape of the operand,
# https://github.com/llvm/llvm-project/pull/229927) to the bundled LLVM 23.1:
# the loop vectorizer narrowed an extractvalue of a widened struct-returning
# intrinsic (e.g. llvm.sadd.with.overflow) to a single scalar, producing invalid IR
# ("Cannot select: i64 = sign_extend v4i32" in ISel). Hit on powerpc64le by every
# consumer of the libbz2-rs-sys crate (devel/py-maturin, security/proton-pass-cli).

--- src/llvm-project/llvm/lib/Transforms/Vectorize/VPlanRecipes.cpp.orig
+++ src/llvm-project/llvm/lib/Transforms/Vectorize/VPlanRecipes.cpp
@@ -1669,6 +1669,7 @@
     return Op == getOperand(1) || Op == getOperand(2);
   case Instruction::PHI:
     return true;
+  case Instruction::ExtractValue:
   case Instruction::FCmp:
   case Instruction::ICmp:
   case Instruction::Select:
