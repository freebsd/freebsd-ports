Author: dpatel
Date: Thu Sep 20 18:01:50 2007
New Revision: 42178

Log:
Don't increment invalid iterator.

==============================================================================
--- lib/Transforms/Scalar/LoopIndexSplit.cpp (original)
+++ lib/Transforms/Scalar/LoopIndexSplit.cpp Thu Sep 20 18:01:50 2007
@@ -928,8 +928,9 @@
   while (!WorkList.empty()) {
     BasicBlock *BB = WorkList.back(); WorkList.pop_back();
     for(BasicBlock::iterator BBI = BB->begin(), BBE = BB->end(); 
-        BBI != BBE; ++BBI) {
+        BBI != BBE; ) {
       Instruction *I = BBI;
+      ++BBI;
       I->replaceAllUsesWith(UndefValue::get(I->getType()));
       I->eraseFromParent();
     }
