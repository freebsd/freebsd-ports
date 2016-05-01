--- code/qcommon/vm_x86_64.c.orig	2008-08-06 16:09:29 UTC
+++ code/qcommon/vm_x86_64.c
@@ -246,7 +246,7 @@ void emit(const char* fmt, ...)
 #else
 #define JMPIARG \
 	emit("movq $%lu, %%rax", vm->codeBase+vm->instructionPointers[iarg]); \
-	emit("jmpq *%rax");
+	emit("jmpq *%%rax");
 #endif
  
 // integer compare and jump
