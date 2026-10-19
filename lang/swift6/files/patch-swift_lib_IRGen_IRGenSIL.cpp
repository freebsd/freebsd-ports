--- swift/lib/IRGen/IRGenSIL.cpp.orig	2026-10-10 18:48:34 UTC
+++ swift/lib/IRGen/IRGenSIL.cpp
@@ -4067,10 +4067,37 @@
     // Zero the error slot to maintain the invariant that it always
     // contains null.  This will frequently become a dead store.
     auto nullError = llvm::Constant::getNullValue(errorValue->getType());
+
+    // On targets that do not reserve a swifterror register, a typed error slot
+    // has the error's concrete storage type, which may be a non-scalar
+    // aggregate.  Such a value cannot be used with icmp/ptrtoint, and storing
+    // its zero-initializer gets scalarized into invalid `extractvalue <agg>
+    // null` sequences that crash instruction selection.  In that case operate
+    // on an integer view of the slot of the same size instead.
+    bool errorIsScalar = errorValue->getType()->isPointerTy() ||
+                         errorValue->getType()->isIntegerTy();
+    llvm::IntegerType *errorIntTy = nullptr;
+    Address errorIntSlot;
+    if (!errorIsScalar) {
+      auto sizeInBits =
+          IGM.DataLayout.getTypeSizeInBits(errorValue->getType());
+      errorIntTy = llvm::IntegerType::get(IGM.getLLVMContext(),
+                                          sizeInBits.getFixedValue());
+      errorIntSlot = Address(calleeErrorSlot.getAddress(), errorIntTy,
+                             calleeErrorSlot.getAlignment());
+    }
+    auto zeroErrorSlot = [&] {
+      if (errorIsScalar)
+        Builder.CreateStore(nullError, calleeErrorSlot);
+      else
+        Builder.CreateStore(llvm::ConstantInt::get(errorIntTy, 0),
+                            errorIntSlot);
+    };
+
     if (!tryApplyInst->getErrorBB()->getSinglePredecessorBlock()) {
       // Only do that here if we can't move the store to the error block.
       // See below.
-      Builder.CreateStore(nullError, calleeErrorSlot);
+      zeroErrorSlot();
     }
     auto hasTypedDirectError =
         substConv.isTypedError() && !substConv.hasIndirectSILErrorResults();
@@ -4080,14 +4107,37 @@
     }
 
     // If the error value is non-null, branch to the error destination.
-    auto hasError = Builder.CreateICmpNE(errorValue, nullError);
+    llvm::Value *hasError;
+    if (errorIsScalar) {
+      hasError = Builder.CreateICmpNE(errorValue, nullError);
 
-    // Create a dummy use of 'errorValue' in the catch BB to workaround an
-    // LLVM miscompile that ends up taking the wrong branch if there are no
-    // uses of 'errorValue' in the catch block.
-    // FIXME: Remove this when the following radar is fixed: rdar://116636601
-    Builder.CreatePtrToInt(errorValue, IGM.IntPtrTy);
+      // Create a dummy use of 'errorValue' in the catch BB to workaround an
+      // LLVM miscompile that ends up taking the wrong branch if there are no
+      // uses of 'errorValue' in the catch block.
+      // FIXME: Remove this when the following radar is fixed: rdar://116636601
+      Builder.CreatePtrToInt(errorValue, IGM.IntPtrTy);
+    } else {
+      // Compare the raw storage bits against zero through the integer view.
+      auto *errorBits = Builder.CreateLoad(errorIntSlot);
+      hasError = Builder.CreateICmpNE(errorBits,
+                                      llvm::ConstantInt::get(errorIntTy, 0));
+    }
 
+    // Precompute the value fed to the single error-edge PHI (see below) while
+    // we are still in the predecessor block, before the conditional branch.
+    // The PHI is typed with the error's native representation, which may differ
+    // from the slot's storage type; reinterpret the slot through the PHI's type
+    // when they disagree.
+    llvm::Value *errorPHIValue = errorValue;
+    if (!errorIsScalar && !typedErrorLoadBB && errorDest.phis.size() == 1) {
+      auto *phiTy = errorDest.phis[0]->getType();
+      if (errorPHIValue->getType() != phiTy) {
+        Address phiSlot(calleeErrorSlot.getAddress(), phiTy,
+                        calleeErrorSlot.getAlignment());
+        errorPHIValue = Builder.CreateLoad(phiSlot);
+      }
+    }
+
     // Emit profile metadata if available.
     llvm::MDNode *Weights = nullptr;
     auto NormalBBCount = tryApplyInst->getNormalBBCount();
@@ -4112,7 +4162,7 @@
              (substConv.hasIndirectSILErrorResults() &&
               errorDest.phis.empty()));
       if (errorDest.phis.size() == 1)
-        errorDest.phis[0]->addIncoming(errorValue, Builder.GetInsertBlock());
+        errorDest.phis[0]->addIncoming(errorPHIValue, Builder.GetInsertBlock());
     } else {
       Builder.emitBlock(typedErrorLoadBB);
 
@@ -4161,7 +4211,7 @@
       // that it will become a dead store.
       auto origBB = Builder.GetInsertBlock();
       Builder.SetInsertPoint(errorDest.bb);
-      Builder.CreateStore(nullError, calleeErrorSlot);
+      zeroErrorSlot();
       Builder.SetInsertPoint(origBB);
     }
   }
