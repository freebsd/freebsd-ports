--- main/reg68k.c.orig
+++ main/reg68k.c
@@ -18,8 +18,8 @@
 
 /*** global variables ***/
 
-#if (!(defined(PROCESSOR_ARM) || defined(PROCESSOR_SPARC) \
-       || defined(PROCESSOR_INTEL)))
+#if ((!(defined(PROCESSOR_ARM) || defined(PROCESSOR_SPARC) \
+       || defined(PROCESSOR_INTEL))) || defined(__clang__))
 uint32 reg68k_pc;
 uint32 *reg68k_regs;
 t_sr reg68k_sr;
