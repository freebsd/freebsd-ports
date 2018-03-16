--- gdb/rs6000-tdep.c.orig	2018-03-15 16:11:47.189448000 +0100
+++ gdb/rs6000-tdep.c	2018-03-15 16:12:36.114973000 +0100
@@ -1173,7 +1173,7 @@
   struct gdbarch *gdbarch = regcache->arch ();
   enum bfd_endian byte_order = gdbarch_byte_order (gdbarch);
   CORE_ADDR pc = regcache_read_pc (regcache);
-  CORE_ADDR breaks[2] = {-1, -1};
+  CORE_ADDR breaks[2] = {static_cast<CORE_ADDR>(-1),static_cast<CORE_ADDR>(-1)};
   CORE_ADDR loc = pc;
   CORE_ADDR closing_insn; /* Instruction that closes the atomic sequence.  */
   int insn = read_memory_integer (loc, PPC_INSN_SIZE, byte_order);
