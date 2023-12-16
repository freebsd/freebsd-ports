--- v8/src/codegen/x64/assembler-x64.h.orig	2023-10-19 20:00:34 UTC
+++ v8/src/codegen/x64/assembler-x64.h
@@ -860,6 +860,7 @@ class V8_EXPORT_PRIVATE Assembler : public AssemblerBa
   void ret(int imm16);
   void ud2();
   void setcc(Condition cc, Register reg);
+  void endbr64();
 
   void pblendw(XMMRegister dst, Operand src, uint8_t mask);
   void pblendw(XMMRegister dst, XMMRegister src, uint8_t mask);
@@ -917,8 +918,8 @@ class V8_EXPORT_PRIVATE Assembler : public AssemblerBa
   void jmp(Handle<Code> target, RelocInfo::Mode rmode);
 
   // Jump near absolute indirect (r64)
-  void jmp(Register adr);
-  void jmp(Operand src);
+  void jmp(Register adr, bool notrack = false);
+  void jmp(Operand src, bool notrack = false);
 
   // Unconditional jump relative to the current address. Low-level routine,
   // use with caution!
