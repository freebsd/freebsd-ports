--- v8/src/compiler/backend/ia32/instruction-selector-ia32.cc.orig	2022-05-11 07:18:04 UTC
+++ v8/src/compiler/backend/ia32/instruction-selector-ia32.cc
@@ -3019,6 +3019,7 @@ void InstructionSelector::VisitI8x16Shuffle(Node* node
   Emit(opcode, 1, &dst, input_count, inputs, temp_count, temps);
 }
 
+#if V8_ENABLE_WEBASSEMBLY
 void InstructionSelector::VisitI8x16Swizzle(Node* node) {
   InstructionCode op = kIA32I8x16Swizzle;
 
@@ -3072,6 +3073,9 @@ void VisitMinOrMax(InstructionSelector* selector, Node
 void InstructionSelector::VisitF32x4Pmin(Node* node) {
   VisitMinOrMax(this, node, kIA32Minps, true);
 }
+#else
+void InstructionSelector::VisitI8x16Swizzle(Node* node) { UNREACHABLE(); }
+#endif  // V8_ENABLE_WEBASSEMBLY
 
 void InstructionSelector::VisitF32x4Pmax(Node* node) {
   VisitMinOrMax(this, node, kIA32Maxps, true);
