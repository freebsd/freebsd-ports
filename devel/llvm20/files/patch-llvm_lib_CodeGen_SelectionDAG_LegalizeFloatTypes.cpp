Backport of llvm-project 5b6b4fdb4b07e1d0d9a647f40a30d47f26178e09:
DAG: Fix promote of half freeze (#131844)

--- llvm/lib/CodeGen/SelectionDAG/LegalizeFloatTypes.cpp.orig
+++ llvm/lib/CodeGen/SelectionDAG/LegalizeFloatTypes.cpp
@@ -2708,6 +2708,7 @@
       report_fatal_error("Do not know how to promote this operator's result!");
 
     case ISD::BITCAST:    R = PromoteFloatRes_BITCAST(N); break;
+    case ISD::FREEZE:     R = PromoteFloatRes_FREEZE(N); break;
     case ISD::ConstantFP: R = PromoteFloatRes_ConstantFP(N); break;
     case ISD::EXTRACT_VECTOR_ELT:
                           R = PromoteFloatRes_EXTRACT_VECTOR_ELT(N); break;
@@ -2819,6 +2820,18 @@
   return DAG.getNode(GetPromotionOpcode(VT, NVT), SDLoc(N), NVT, Cast);
 }
 
+SDValue DAGTypeLegalizer::PromoteFloatRes_FREEZE(SDNode *N) {
+  EVT VT = N->getValueType(0);
+  EVT NVT = TLI.getTypeToTransformTo(*DAG.getContext(), VT);
+  // Input type isn't guaranteed to be a scalar int so bitcast if not. The
+  // bitcast will be legalized further if necessary.
+  EVT IVT = EVT::getIntegerVT(*DAG.getContext(),
+                              N->getOperand(0).getValueType().getSizeInBits());
+  SDValue Cast = DAG.getBitcast(IVT, N->getOperand(0));
+  return DAG.getNode(GetPromotionOpcode(VT, NVT), SDLoc(N), NVT,
+                     DAG.getFreeze(Cast));
+}
+
 SDValue DAGTypeLegalizer::PromoteFloatRes_ConstantFP(SDNode *N) {
   ConstantFPSDNode *CFPNode = cast<ConstantFPSDNode>(N);
   EVT VT = N->getValueType(0);
