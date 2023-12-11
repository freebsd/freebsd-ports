--- v8/src/builtins/x64/builtins-x64.cc.orig	2023-10-19 20:00:32 UTC
+++ v8/src/builtins/x64/builtins-x64.cc
@@ -44,6 +44,8 @@ namespace internal {
 #define __ ACCESS_MASM(masm)
 
 void Builtins::Generate_Adaptor(MacroAssembler* masm, Address address) {
+  __ CodeEntry();
+
   __ LoadAddress(kJavaScriptCallExtraArg1Register,
                  ExternalReference::Create(address));
   __ Jump(BUILTIN_CODE(masm->isolate(), AdaptorWithBuiltinExitFrame),
@@ -430,7 +432,7 @@ void Generate_JSEntryVariant(MacroAssembler* masm, Sta
   // Jump to a faked try block that does the invoke, with a faked catch
   // block that sets the pending exception.
   __ jmp(&invoke);
-  __ bind(&handler_entry);
+  __ BindExceptionHandler(&handler_entry);
 
   // Store the current pc as the handler offset. It's used later to create the
   // handler table.
@@ -3327,6 +3329,9 @@ void SwitchBackAndReturnPromise(MacroAssembler* masm, 
 void GenerateExceptionHandlingLandingPad(MacroAssembler* masm,
                                          Label* return_promise) {
   int catch_handler = __ pc_offset();
+
+  __ endbr64();
+
   // Restore rsp to free the reserved stack slots for the sections.
   __ leaq(rsp, MemOperand(rbp, StackSwitchFrameConstants::kLastSpillOffset));
 
@@ -3658,6 +3663,7 @@ void Builtins::Generate_WasmSuspend(MacroAssembler* ma
   LoadJumpBuffer(masm, jmpbuf, true);
   __ Trap();
   __ bind(&resume);
+  __ endbr64();
   __ LeaveFrame(StackFrame::STACK_SWITCH);
   __ ret(0);
 }
@@ -3790,6 +3796,7 @@ void Generate_WasmResumeHelper(MacroAssembler* masm, w
   }
   __ Trap();
   __ bind(&suspend);
+  __ endbr64();
   __ LeaveFrame(StackFrame::STACK_SWITCH);
   // Pop receiver + parameter.
   __ ret(2 * kSystemPointerSize);
