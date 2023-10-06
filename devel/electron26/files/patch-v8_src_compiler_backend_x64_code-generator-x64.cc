--- v8/src/compiler/backend/x64/code-generator-x64.cc.orig	2023-08-10 01:51:22 UTC
+++ v8/src/compiler/backend/x64/code-generator-x64.cc
@@ -6594,7 +6594,7 @@ void CodeGenerator::AssembleArchTableSwitch(Instructio
   __ cmpl(input, Immediate(case_count));
   __ j(above_equal, GetLabel(i.InputRpo(1)));
   __ leaq(kScratchRegister, Operand(table));
-  __ jmp(Operand(kScratchRegister, input, times_8, 0));
+  __ jmp(Operand(kScratchRegister, input, times_8, 0), /*notrack=*/true);
 }
 
 void CodeGenerator::AssembleArchSelect(Instruction* instr,
