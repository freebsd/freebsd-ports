Backport of llvm-project 5b6b4fdb4b07e1d0d9a647f40a30d47f26178e09:
DAG: Fix promote of half freeze (#131844)

--- llvm/lib/CodeGen/SelectionDAG/LegalizeTypes.h.orig
+++ llvm/lib/CodeGen/SelectionDAG/LegalizeTypes.h
@@ -746,6 +746,7 @@
 
   void PromoteFloatResult(SDNode *N, unsigned ResNo);
   SDValue PromoteFloatRes_BITCAST(SDNode *N);
+  SDValue PromoteFloatRes_FREEZE(SDNode *N);
   SDValue PromoteFloatRes_BinOp(SDNode *N);
   SDValue PromoteFloatRes_UnaryWithTwoFPResults(SDNode *N);
   SDValue PromoteFloatRes_ConstantFP(SDNode *N);
