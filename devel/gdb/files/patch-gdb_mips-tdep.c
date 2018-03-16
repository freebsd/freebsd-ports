--- gdb/mips-tdep.c.orig	2018-03-15 11:15:08.500010000 +0100
+++ gdb/mips-tdep.c	2018-03-15 11:16:05.745083000 +0100
@@ -3882,7 +3882,7 @@
 static std::vector<CORE_ADDR>
 mips_deal_with_atomic_sequence (struct gdbarch *gdbarch, CORE_ADDR pc)
 {
-  CORE_ADDR breaks[2] = {-1, -1};
+  CORE_ADDR breaks[2] = {static_cast<CORE_ADDR>(-1), static_cast<CORE_ADDR>(-1)};
   CORE_ADDR loc = pc;
   CORE_ADDR branch_bp; /* Breakpoint at branch instruction's destination.  */
   ULONGEST insn;
@@ -3985,7 +3985,7 @@
 {
   const int atomic_sequence_length = 16; /* Instruction sequence length.  */
   int last_breakpoint = 0; /* Defaults to 0 (no breakpoints placed).  */
-  CORE_ADDR breaks[2] = {-1, -1};
+  CORE_ADDR breaks[2] = {static_cast<CORE_ADDR>(-1), static_cast<CORE_ADDR>(-1)};
   CORE_ADDR branch_bp = 0; /* Breakpoint at branch instruction's
 			      destination.  */
   CORE_ADDR loc = pc;
