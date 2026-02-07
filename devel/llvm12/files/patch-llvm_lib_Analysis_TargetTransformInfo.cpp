--- llvm/lib/Analysis/TargetTransformInfo.cpp.orig	2021-06-28 16:23:38 UTC
+++ llvm/lib/Analysis/TargetTransformInfo.cpp
@@ -217,10 +217,7 @@ bool HardwareLoopInfo::isHardwareLoopCandidate(ScalarE
     // Note that this block may not be the loop latch block, even if the loop
     // has a latch block.
     ExitBlock = BB;
-    TripCount = SE.getAddExpr(EC, SE.getOne(EC->getType()));
-
-    if (!EC->getType()->isPointerTy() && EC->getType() != CountType)
-      TripCount = SE.getZeroExtendExpr(TripCount, CountType);
+    ExitCount = EC;
 
     break;
   }
