--- bfd/elfnn-riscv.c.orig	2018-07-18 12:09:50 UTC
+++ bfd/elfnn-riscv.c
@@ -46,8 +46,8 @@
 /* The name of the dynamic interpreter.  This is put in the .interp
    section.  */
 
-#define ELF64_DYNAMIC_INTERPRETER "/lib/ld.so.1"
-#define ELF32_DYNAMIC_INTERPRETER "/lib32/ld.so.1"
+#define ELF64_DYNAMIC_INTERPRETER "/libexec/ld-elf.so.1"
+#define ELF32_DYNAMIC_INTERPRETER "/libexec/ld-elf32.so.1"
 
 #define ELF_ARCH			bfd_arch_riscv
 #define ELF_TARGET_ID			RISCV_ELF_DATA
