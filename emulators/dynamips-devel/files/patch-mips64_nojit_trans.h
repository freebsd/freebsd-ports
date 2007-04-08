--- mips64_nojit_trans.h.orig	Fri Mar 30 17:27:32 2007
+++ mips64_nojit_trans.h	Fri Mar 30 17:27:48 2007
@@ -37,7 +37,7 @@
 void mips64_emit_breakpoint(mips64_jit_tcb_t *b);
 
 /* Emit unhandled instruction code */
-void mips64_emit_invalid_delay_slot(mips64_jit_tcb_t *b);
+int mips64_emit_invalid_delay_slot(mips64_jit_tcb_t *b);
 
 /* 
  * Increment count register and trigger the timer IRQ if value in compare 
