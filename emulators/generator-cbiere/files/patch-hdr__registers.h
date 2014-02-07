--- hdr/registers.h.orig
+++ hdr/registers.h
@@ -6,17 +6,17 @@
    call a C function, then when that C function returns these registers are
    still what they were before we made the call. */
 
-#ifdef PROCESSOR_ARM
+#if defined(PROCESSOR_ARM) && !defined(__clang__)
      register uint32 reg68k_pc asm ("r7");
      register uint32 *reg68k_regs asm ("r8");
      register t_sr reg68k_sr asm ("r9");
 #else
-#  ifdef PROCESSOR_SPARC
+#  if defined(PROCESSOR_SPARC) && !defined(__clang__)
        register uint32 reg68k_pc asm ("5");
        register uint32 *reg68k_regs asm ("6");
        register t_sr reg68k_sr asm ("7");
 #  else
-#    ifdef PROCESSOR_INTEL
+#    if defined(PROCESSOR_INTEL) && !defined(__clang__)
          register uint32 reg68k_pc asm ("%ebx");
          register uint32 *reg68k_regs asm ("%edi");
          register t_sr reg68k_sr asm ("%esi");
