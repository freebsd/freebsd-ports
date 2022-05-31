Fix a SIGFPE when building sysutils/exa
https://github.com/ogham/exa/issues/1068 
https://bugs.gentoo.org/847421 


From 67a290460c374d5e0d18a06c798896cac0b19e59 Mon Sep 17 00:00:00 2001
From: Fraser Cormack <fraser@codeplay.com>
Date: Wed, 16 Mar 2022 10:14:07 +0000
Subject: [PATCH] [VectorCombine] Insert addrspacecast when crossing address
 space boundaries

We can not bitcast pointers across different address spaces. This was
previously fixed in D89577 but then in D93229 an enhancement was added
which peeks further through the ponter operand, opening up the
possibility that address-space violations could be introduced.

Instead of bailing as the previous fix did, simply insert an
addrspacecast cast instruction.

Reviewed By: lebedev.ri

Differential Revision: https://reviews.llvm.org/D121787

(cherry picked from commit 2e44b7872bc638ed884ae4aa86e38b3b47e0b65a)
--- src/llvm-project/llvm/lib/Transforms/Vectorize/VectorCombine.cpp.orig	2022-03-23 19:37:48.000000000 +0100
+++ src/llvm-project/llvm/lib/Transforms/Vectorize/VectorCombine.cpp	2022-05-27 15:16:24.686183000 +0200
@@ -152,12 +152,7 @@ bool VectorCombine::vectorizeLoadInsert(Instruction &I
   Value *SrcPtr = Load->getPointerOperand()->stripPointerCasts();
   assert(isa<PointerType>(SrcPtr->getType()) && "Expected a pointer type");
 
-  // If original AS != Load's AS, we can't bitcast the original pointer and have
-  // to use Load's operand instead. Ideally we would want to strip pointer casts
-  // without changing AS, but there's no API to do that ATM.
   unsigned AS = Load->getPointerAddressSpace();
-  if (AS != SrcPtr->getType()->getPointerAddressSpace())
-    SrcPtr = Load->getPointerOperand();
 
   // We are potentially transforming byte-sized (8-bit) memory accesses, so make
   // sure we have all of our type-based constraints in place for this target.
@@ -245,7 +240,8 @@ bool VectorCombine::vectorizeLoadInsert(Instruction &I
   // It is safe and potentially profitable to load a vector directly:
   // inselt undef, load Scalar, 0 --> load VecPtr
   IRBuilder<> Builder(Load);
-  Value *CastedPtr = Builder.CreateBitCast(SrcPtr, MinVecTy->getPointerTo(AS));
+  Value *CastedPtr = Builder.CreatePointerBitCastOrAddrSpaceCast(
+      SrcPtr, MinVecTy->getPointerTo(AS));
   Value *VecLd = Builder.CreateAlignedLoad(MinVecTy, CastedPtr, Alignment);
   VecLd = Builder.CreateShuffleVector(VecLd, Mask);
 
