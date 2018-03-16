--- gdb/aarch64-tdep.c.orig	2018-03-15 16:44:16.746186000 +0100
+++ gdb/aarch64-tdep.c	2018-03-15 16:44:52.315010000 +0100
@@ -2412,7 +2412,7 @@
   const int insn_size = 4;
   const int atomic_sequence_length = 16; /* Instruction sequence length.  */
   CORE_ADDR pc = regcache_read_pc (regcache);
-  CORE_ADDR breaks[2] = { -1, -1 };
+  CORE_ADDR breaks[2] = { static_cast<CORE_ADDR>(-1), static_cast<CORE_ADDR>(-1) };
   CORE_ADDR loc = pc;
   CORE_ADDR closing_insn = 0;
   uint32_t insn = read_memory_unsigned_integer (loc, insn_size,
