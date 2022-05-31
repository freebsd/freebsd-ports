Fix a SIGFPE when building sysutils/exa
https://github.com/ogham/exa/issues/1068
https://bugs.gentoo.org/847421

From fe8a27acd716a42667f5a572f52f2b04636010ff Mon Sep 17 00:00:00 2001
From: Florian Hahn <flo@fhahn.com>
Date: Tue, 29 Mar 2022 22:52:42 +0100
Subject: [PATCH] [LV] Handle zero cost loops in selectInterleaveCount.

In some case, like in the added test case, we can reach
selectInterleaveCount with loops that actually have a cost of 0.

Unfortunately a loop cost of 0 is also used to communicate that the cost
has not been computed yet. To resolve the crash, bail out if the cost
remains zero after computing it.

This seems like the best option, as there are multiple code paths that
return a cost of 0 to force a computation in selectInterleaveCount.
Computing the cost at multiple places up front there would unnecessarily
complicate the logic.

Fixes #54413.

(cherry picked from commit ecb4171dcbf1b433c9963fd605a74898303e850d)
--- src/llvm-project/llvm/lib/Transforms/Vectorize/LoopVectorize.cpp.orig	2022-03-23 19:37:48.000000000 +0100
+++ src/llvm-project/llvm/lib/Transforms/Vectorize/LoopVectorize.cpp	2022-05-27 15:16:30.510761000 +0200
@@ -6035,6 +6035,18 @@ unsigned LoopVectorizationCostModel::selectInterleaveC
       !(InterleaveSmallLoopScalarReduction && HasReductions && VF.isScalar()))
     return 1;
 
+  // If we did not calculate the cost for VF (because the user selected the VF)
+  // then we calculate the cost of VF here.
+  if (LoopCost == 0) {
+    InstructionCost C = expectedCost(VF).first;
+    assert(C.isValid() && "Expected to have chosen a VF with valid cost");
+    LoopCost = *C.getValue();
+
+    // Loop body is free and there is no need for interleaving.
+    if (LoopCost == 0)
+      return 1;
+  }
+
   RegisterUsage R = calculateRegisterUsage({VF})[0];
   // We divide by these constants so assume that we have at least one
   // instruction that uses at least one register.
@@ -6125,16 +6137,6 @@ unsigned LoopVectorizationCostModel::selectInterleaveC
     IC = std::max(1u, IC);
 
   assert(IC > 0 && "Interleave count must be greater than 0.");
-
-  // If we did not calculate the cost for VF (because the user selected the VF)
-  // then we calculate the cost of VF here.
-  if (LoopCost == 0) {
-    InstructionCost C = expectedCost(VF).first;
-    assert(C.isValid() && "Expected to have chosen a VF with valid cost");
-    LoopCost = *C.getValue();
-  }
-
-  assert(LoopCost && "Non-zero loop cost expected");
 
   // Interleave if we vectorized this loop and there is a reduction that could
   // benefit from interleaving.
