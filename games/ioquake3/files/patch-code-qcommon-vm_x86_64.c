--- code/qcommon/vm_x86_64.c.orig	2009-08-30 20:50:41.000000000 +0200
+++ code/qcommon/vm_x86_64.c	2009-08-30 20:51:43.000000000 +0200
@@ -246,7 +246,7 @@
 #else
 #define JMPIARG \
 	emit("movq $%lu, %%rax", vm->codeBase+vm->instructionPointers[iarg]); \
-	emit("jmpq *%rax");
+	emit("jmpq *%%rax");
 #endif
  
 // integer compare and jump
