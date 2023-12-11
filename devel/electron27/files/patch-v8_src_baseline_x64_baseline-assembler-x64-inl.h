--- v8/src/baseline/x64/baseline-assembler-x64-inl.h.orig	2023-08-10 01:51:22 UTC
+++ v8/src/baseline/x64/baseline-assembler-x64-inl.h
@@ -73,9 +73,7 @@ MemOperand BaselineAssembler::FeedbackVectorOperand() 
 
 void BaselineAssembler::Bind(Label* label) { __ bind(label); }
 
-void BaselineAssembler::JumpTarget() {
-  // NOP on x64.
-}
+void BaselineAssembler::JumpTarget() { __ endbr64(); }
 
 void BaselineAssembler::Jump(Label* target, Label::Distance distance) {
   __ jmp(target, distance);
