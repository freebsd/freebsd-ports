--- v8/src/codegen/x64/assembler-x64.cc.orig	2023-10-19 20:00:34 UTC
+++ v8/src/codegen/x64/assembler-x64.cc
@@ -1316,6 +1316,14 @@ void Assembler::hlt() {
   emit(0xF4);
 }
 
+void Assembler::endbr64() {
+  EnsureSpace ensure_space(this);
+  emit(0xF3);
+  emit(0x0f);
+  emit(0x1e);
+  emit(0xfa);
+}
+
 void Assembler::emit_idiv(Register src, int size) {
   EnsureSpace ensure_space(this);
   emit_rex(src, size);
@@ -1583,16 +1591,22 @@ void Assembler::jmp(Handle<Code> target, RelocInfo::Mo
   emitl(code_target_index);
 }
 
-void Assembler::jmp(Register target) {
+void Assembler::jmp(Register target, bool notrack) {
   EnsureSpace ensure_space(this);
+  if (notrack) {
+    emit(0x3e);
+  }
   // Opcode FF/4 r64.
   emit_optional_rex_32(target);
   emit(0xFF);
   emit_modrm(0x4, target);
 }
 
-void Assembler::jmp(Operand src) {
+void Assembler::jmp(Operand src, bool notrack) {
   EnsureSpace ensure_space(this);
+  if (notrack) {
+    emit(0x3e);
+  }
   // Opcode FF/4 m64.
   emit_optional_rex_32(src);
   emit(0xFF);
