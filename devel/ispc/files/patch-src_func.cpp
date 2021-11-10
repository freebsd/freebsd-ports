Regressed by https://github.com/intel/vc-intrinsics/commit/8ee879314584

src/func.cpp:490:44: error: no member named 'Reserved_0' in 'llvm::genx::KernelMDOp'
            mdArgs[llvm::genx::KernelMDOp::Reserved_0] =
                   ~~~~~~~~~~~~~~~~~~~~~~~~^

--- src/func.cpp.orig	2021-07-15 23:04:31 UTC
+++ src/func.cpp
@@ -487,7 +487,7 @@ void Function::emitCode(FunctionEmitContext *ctx, llvm
                 llvm::ValueAsMetadata::get(llvm::ConstantInt::getNullValue(i32Type));
             mdArgs[llvm::genx::KernelMDOp::ArgIOKinds] = llvm::MDNode::get(fContext, argInOutKinds);
             mdArgs[llvm::genx::KernelMDOp::ArgTypeDescs] = llvm::MDNode::get(fContext, argTypeDescs);
-            mdArgs[llvm::genx::KernelMDOp::Reserved_0] =
+            mdArgs[llvm::genx::KernelMDOp::NBarrierCnt] =
                 llvm::ValueAsMetadata::get(llvm::ConstantInt::getNullValue(i32Type));
             mdArgs[llvm::genx::KernelMDOp::BarrierCnt] =
                 llvm::ValueAsMetadata::get(llvm::ConstantInt::getNullValue(i32Type));
