--- mips64_nojit_trans.c.orig	Fri Mar 30 17:33:19 2007
+++ mips64_nojit_trans.c	Fri Mar 30 17:42:29 2007
@@ -53,10 +53,11 @@
 EMPTY(void mips64_set_pc(mips64_jit_tcb_t *b,m_uint64_t new_pc));
 EMPTY(void mips64_set_ra(mips64_jit_tcb_t *b,m_uint64_t ret_pc));
 EMPTY(void mips64_emit_breakpoint(mips64_jit_tcb_t *b));
-EMPTY(void mips64_emit_invalid_delay_slot(mips64_jit_tcb_t *b));
+EMPTY(int mips64_emit_invalid_delay_slot(mips64_jit_tcb_t *b));
 EMPTY(void mips64_inc_cp0_count_reg(mips64_jit_tcb_t *b));
 EMPTY(void mips64_check_pending_irq(mips64_jit_tcb_t *b));
 EMPTY(void mips64_inc_perf_counter(mips64_jit_tcb_t *b));
+EMPTY(void mips64_emit_single_step(mips64_jit_tcb_t *b,mips_insn_t insn));
 
 /* MIPS instruction array */
 struct mips64_insn_tag mips64_insn_tags[] = {
