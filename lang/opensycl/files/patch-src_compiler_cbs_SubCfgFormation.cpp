- workaround for https://github.com/OpenSYCL/OpenSYCL/issues/1060

--- src/compiler/cbs/SubCfgFormation.cpp.orig	2023-06-07 04:07:11 UTC
+++ src/compiler/cbs/SubCfgFormation.cpp
@@ -367,7 +367,7 @@ class SubCFG { (public)
 
 // create new exiting block writing the exit's id to LastBarrierIdStorage_
 llvm::BasicBlock *
-SubCFG::createExitWithID(llvm::detail::DenseMapPair<llvm::BasicBlock *, size_t> BarrierPair,
+SubCFG::createExitWithID(llvm::detail::DenseMapPair<llvm::BasicBlock *, unsigned long> BarrierPair,
                          llvm::BasicBlock *After, llvm::BasicBlock *TargetBB) {
   HIPSYCL_DEBUG_INFO << "Create new exit with ID: " << BarrierPair.second << " at "
                      << After->getName() << "\n";
