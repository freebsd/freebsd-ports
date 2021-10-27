--- llvm/lib/CodeGen/HardwareLoops.cpp.orig	2021-06-28 16:23:38 UTC
+++ llvm/lib/CodeGen/HardwareLoops.cpp
@@ -187,7 +187,7 @@ namespace {
                  const DataLayout &DL,
                  OptimizationRemarkEmitter *ORE) :
       SE(SE), DL(DL), ORE(ORE), L(Info.L), M(L->getHeader()->getModule()),
-      TripCount(Info.TripCount),
+      ExitCount(Info.ExitCount),
       CountType(Info.CountType),
       ExitBranch(Info.ExitBranch),
       LoopDecrement(Info.LoopDecrement),
@@ -202,7 +202,7 @@ namespace {
     OptimizationRemarkEmitter *ORE = nullptr;
     Loop *L                 = nullptr;
     Module *M               = nullptr;
-    const SCEV *TripCount   = nullptr;
+    const SCEV *ExitCount   = nullptr;
     Type *CountType         = nullptr;
     BranchInst *ExitBranch  = nullptr;
     Value *LoopDecrement    = nullptr;
@@ -298,7 +298,7 @@ bool HardwareLoops::TryConvertLoop(HardwareLoopInfo &H
   }
 
   assert(
-      (HWLoopInfo.ExitBlock && HWLoopInfo.ExitBranch && HWLoopInfo.TripCount) &&
+      (HWLoopInfo.ExitBlock && HWLoopInfo.ExitBranch && HWLoopInfo.ExitCount) &&
       "Hardware Loop must have set exit info.");
 
   BasicBlock *Preheader = L->getLoopPreheader();
@@ -384,12 +384,18 @@ Value *HardwareLoop::InitLoopCount() {
 
   SCEVExpander SCEVE(SE, DL, "loopcnt");
 
+  if (!ExitCount->getType()->isPointerTy() &&
+       ExitCount->getType() != CountType)
+    ExitCount = SE.getZeroExtendExpr(ExitCount, CountType);
+
+  ExitCount = SE.getAddExpr(ExitCount, SE.getOne(CountType));
+
   // If we're trying to use the 'test and set' form of the intrinsic, we need
   // to replace a conditional branch that is controlling entry to the loop. It
   // is likely (guaranteed?) that the preheader has an unconditional branch to
   // the loop header, so also check if it has a single predecessor.
-  if (SE.isLoopEntryGuardedByCond(L, ICmpInst::ICMP_NE, TripCount,
-                                  SE.getZero(TripCount->getType()))) {
+  if (SE.isLoopEntryGuardedByCond(L, ICmpInst::ICMP_NE, ExitCount,
+			          SE.getZero(ExitCount->getType()))) {
     LLVM_DEBUG(dbgs() << " - Attempting to use test.set counter.\n");
     UseLoopGuard |= ForceGuardLoopEntry;
   } else
@@ -401,19 +407,19 @@ Value *HardwareLoop::InitLoopCount() {
     BasicBlock *Predecessor = BB->getSinglePredecessor();
     // If it's not safe to create a while loop then don't force it and create a
     // do-while loop instead
-    if (!isSafeToExpandAt(TripCount, Predecessor->getTerminator(), SE))
+    if (!isSafeToExpandAt(ExitCount, Predecessor->getTerminator(), SE))
         UseLoopGuard = false;
     else
         BB = Predecessor;
   }
 
-  if (!isSafeToExpandAt(TripCount, BB->getTerminator(), SE)) {
-    LLVM_DEBUG(dbgs() << "- Bailing, unsafe to expand TripCount "
-               << *TripCount << "\n");
+  if (!isSafeToExpandAt(ExitCount, BB->getTerminator(), SE)) {
+    LLVM_DEBUG(dbgs() << "- Bailing, unsafe to expand ExitCount "
+               << *ExitCount << "\n");
     return nullptr;
   }
 
-  Value *Count = SCEVE.expandCodeFor(TripCount, CountType,
+  Value *Count = SCEVE.expandCodeFor(ExitCount, CountType,
                                      BB->getTerminator());
 
   // FIXME: We've expanded Count where we hope to insert the counter setting
