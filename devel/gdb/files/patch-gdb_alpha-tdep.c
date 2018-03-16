--- gdb/alpha-tdep.c.orig	2018-03-15 16:45:58.726244000 +0100
+++ gdb/alpha-tdep.c	2018-03-15 16:46:30.051357000 +0100
@@ -769,7 +769,7 @@
 static std::vector<CORE_ADDR>
 alpha_deal_with_atomic_sequence (struct gdbarch *gdbarch, CORE_ADDR pc)
 {
-  CORE_ADDR breaks[2] = {-1, -1};
+  CORE_ADDR breaks[2] = {static_cast<CORE_ADDR>(-1), static_cast<CORE_ADDR>(-1)};
   CORE_ADDR loc = pc;
   CORE_ADDR closing_insn; /* Instruction that closes the atomic sequence.  */
   unsigned int insn = alpha_read_insn (gdbarch, loc);
