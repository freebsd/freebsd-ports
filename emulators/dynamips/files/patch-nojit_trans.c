--- nojit_trans.c.orig	Tue Nov 14 04:12:11 2006
+++ nojit_trans.c	Tue Nov 14 04:12:21 2006
@@ -51,7 +51,7 @@
 EMPTY(void mips64_set_pc(insn_block_t *b,m_uint64_t new_pc));
 EMPTY(void mips64_set_ra(insn_block_t *b,m_uint64_t ret_pc));
 EMPTY(void mips64_emit_breakpoint(insn_block_t *b));
-EMPTY(void mips64_emit_invalid_delay_slot(insn_block_t *b));
+EMPTY(int mips64_emit_invalid_delay_slot(insn_block_t *b));
 EMPTY(void mips64_inc_cp0_count_reg(insn_block_t *b));
 EMPTY(void mips64_check_pending_irq(insn_block_t *b));
 EMPTY(void mips64_inc_perf_counter(insn_block_t *b));
