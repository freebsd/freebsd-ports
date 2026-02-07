--- llvm/include/llvm/Analysis/TargetTransformInfo.h.orig	2021-06-28 16:23:38 UTC
+++ llvm/include/llvm/Analysis/TargetTransformInfo.h
@@ -94,6 +94,7 @@ struct HardwareLoopInfo {
   Loop *L = nullptr;
   BasicBlock *ExitBlock = nullptr;
   BranchInst *ExitBranch = nullptr;
+  const SCEV *ExitCount = nullptr;
   const SCEV *TripCount = nullptr;
   IntegerType *CountType = nullptr;
   Value *LoopDecrement = nullptr; // Decrement the loop counter by this
