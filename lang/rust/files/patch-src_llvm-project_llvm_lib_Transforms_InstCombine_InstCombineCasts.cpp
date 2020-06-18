From f8e146f3430de3a6cd904f3f3f7aa1bfaefee14c Mon Sep 17 00:00:00 2001
From: Bjorn Pettersson <bjorn.a.pettersson@ericsson.com>
Date: Thu, 28 Nov 2019 23:18:28 +0100
Subject: [PATCH] [InstCombine] Fix big-endian miscompile of (bitcast
 (zext/trunc (bitcast)))

Summary:
optimizeVectorResize is rewriting patterns like:
  %1 = bitcast vector %src to integer
  %2 = trunc/zext %1
  %dst = bitcast %2 to vector

Since bitcasting between integer an vector types gives
different integer values depending on endianness, we need
to take endianness into account. As it happens the old
implementation only produced the correct result for little
endian targets.

Fixes: https://bugs.llvm.org/show_bug.cgi?id=44178

Reviewers: spatel, lattner, lebedev.ri

Reviewed By: spatel, lebedev.ri

Subscribers: lebedev.ri, hiraditya, uabelho, llvm-commits

Tags: #llvm

Differential Revision: https://reviews.llvm.org/D70844

(cherry picked from commit a9d6b0e5444741d08ff1df7cf71d1559e7fefc1f)
---
 .../InstCombine/InstCombineCasts.cpp          | 79 +++++++++++++------
 llvm/test/Transforms/InstCombine/cast.ll      |  6 +-
 2 files changed, 60 insertions(+), 25 deletions(-)

--- src/llvm-project/llvm/lib/Transforms/InstCombine/InstCombineCasts.cpp.orig	2020-04-07 15:52:51 UTC
+++ src/llvm-project/llvm/lib/Transforms/InstCombine/InstCombineCasts.cpp
@@ -18,6 +18,7 @@
 #include "llvm/IR/DIBuilder.h"
 #include "llvm/IR/PatternMatch.h"
 #include "llvm/Support/KnownBits.h"
+#include <numeric>
 using namespace llvm;
 using namespace PatternMatch;
 
@@ -1820,12 +1821,24 @@ Instruction *InstCombiner::visitPtrToInt(PtrToIntInst 
 }
 
 /// This input value (which is known to have vector type) is being zero extended
-/// or truncated to the specified vector type.
+/// or truncated to the specified vector type. Since the zext/trunc is done
+/// using an integer type, we have a (bitcast(cast(bitcast))) pattern,
+/// endianness will impact which end of the vector that is extended or
+/// truncated.
+///
+/// A vector is always stored with index 0 at the lowest address, which
+/// corresponds to the most significant bits for a big endian stored integer and
+/// the least significant bits for little endian. A trunc/zext of an integer
+/// impacts the big end of the integer. Thus, we need to add/remove elements at
+/// the front of the vector for big endian targets, and the back of the vector
+/// for little endian targets.
+///
 /// Try to replace it with a shuffle (and vector/vector bitcast) if possible.
 ///
 /// The source and destination vector types may have different element types.
-static Instruction *optimizeVectorResize(Value *InVal, VectorType *DestTy,
-                                         InstCombiner &IC) {
+static Instruction *optimizeVectorResizeWithIntegerBitCasts(Value *InVal,
+                                                            VectorType *DestTy,
+                                                            InstCombiner &IC) {
   // We can only do this optimization if the output is a multiple of the input
   // element size, or the input is a multiple of the output element size.
   // Convert the input type to have the same element type as the output.
@@ -1844,31 +1857,53 @@ static Instruction *optimizeVectorResize(Value *InVal,
     InVal = IC.Builder.CreateBitCast(InVal, SrcTy);
   }
 
+  bool IsBigEndian = IC.getDataLayout().isBigEndian();
+  unsigned SrcElts = SrcTy->getNumElements();
+  unsigned DestElts = DestTy->getNumElements();
+
+  assert(SrcElts != DestElts && "Element counts should be different.");
+
   // Now that the element types match, get the shuffle mask and RHS of the
   // shuffle to use, which depends on whether we're increasing or decreasing the
   // size of the input.
-  SmallVector<uint32_t, 16> ShuffleMask;
+  SmallVector<uint32_t, 16> ShuffleMaskStorage;
+  ArrayRef<uint32_t> ShuffleMask;
   Value *V2;
 
-  if (SrcTy->getNumElements() > DestTy->getNumElements()) {
-    // If we're shrinking the number of elements, just shuffle in the low
-    // elements from the input and use undef as the second shuffle input.
-    V2 = UndefValue::get(SrcTy);
-    for (unsigned i = 0, e = DestTy->getNumElements(); i != e; ++i)
-      ShuffleMask.push_back(i);
+  // Produce an identify shuffle mask for the src vector.
+  ShuffleMaskStorage.resize(SrcElts);
+  std::iota(ShuffleMaskStorage.begin(), ShuffleMaskStorage.end(), 0);
 
+  if (SrcElts > DestElts) {
+    // If we're shrinking the number of elements (rewriting an integer
+    // truncate), just shuffle in the elements corresponding to the least
+    // significant bits from the input and use undef as the second shuffle
+    // input.
+    V2 = UndefValue::get(SrcTy);
+    // Make sure the shuffle mask selects the "least significant bits" by
+    // keeping elements from back of the src vector for big endian, and from the
+    // front for little endian.
+    ShuffleMask = ShuffleMaskStorage;
+    if (IsBigEndian)
+      ShuffleMask = ShuffleMask.take_back(DestElts);
+    else
+      ShuffleMask = ShuffleMask.take_front(DestElts);
   } else {
-    // If we're increasing the number of elements, shuffle in all of the
-    // elements from InVal and fill the rest of the result elements with zeros
-    // from a constant zero.
+    // If we're increasing the number of elements (rewriting an integer zext),
+    // shuffle in all of the elements from InVal. Fill the rest of the result
+    // elements with zeros from a constant zero.
     V2 = Constant::getNullValue(SrcTy);
-    unsigned SrcElts = SrcTy->getNumElements();
-    for (unsigned i = 0, e = SrcElts; i != e; ++i)
-      ShuffleMask.push_back(i);
-
-    // The excess elements reference the first element of the zero input.
-    for (unsigned i = 0, e = DestTy->getNumElements()-SrcElts; i != e; ++i)
-      ShuffleMask.push_back(SrcElts);
+    // Use first elt from V2 when indicating zero in the shuffle mask.
+    uint32_t NullElt = SrcElts;
+    // Extend with null values in the "most significant bits" by adding elements
+    // in front of the src vector for big endian, and at the back for little
+    // endian.
+    unsigned DeltaElts = DestElts - SrcElts;
+    if (IsBigEndian)
+      ShuffleMaskStorage.insert(ShuffleMaskStorage.begin(), DeltaElts, NullElt);
+    else
+      ShuffleMaskStorage.append(DeltaElts, NullElt);
+    ShuffleMask = ShuffleMaskStorage;
   }
 
   return new ShuffleVectorInst(InVal, V2,
@@ -2396,8 +2431,8 @@ Instruction *InstCombiner::visitBitCast(BitCastInst &C
         CastInst *SrcCast = cast<CastInst>(Src);
         if (BitCastInst *BCIn = dyn_cast<BitCastInst>(SrcCast->getOperand(0)))
           if (isa<VectorType>(BCIn->getOperand(0)->getType()))
-            if (Instruction *I = optimizeVectorResize(BCIn->getOperand(0),
-                                               cast<VectorType>(DestTy), *this))
+            if (Instruction *I = optimizeVectorResizeWithIntegerBitCasts(
+                    BCIn->getOperand(0), cast<VectorType>(DestTy), *this))
               return I;
       }
 
