--- gdb/arch/arm-get-next-pcs.c.orig	2018-03-15 10:02:33.823447000 +0100
+++ gdb/arch/arm-get-next-pcs.c	2018-03-15 10:29:48.532027000 +0100
@@ -49,7 +49,7 @@
 thumb_deal_with_atomic_sequence_raw (struct arm_get_next_pcs *self)
 {
   int byte_order_for_code = self->byte_order_for_code;
-  CORE_ADDR breaks[2] = {-1, -1};
+  CORE_ADDR breaks[2] = {static_cast<CORE_ADDR>(-1), static_cast<CORE_ADDR>(-1)};
   CORE_ADDR pc = regcache_read_pc (self->regcache);
   CORE_ADDR loc = pc;
   unsigned short insn1, insn2;
@@ -187,7 +187,7 @@
 arm_deal_with_atomic_sequence_raw (struct arm_get_next_pcs *self)
 {
   int byte_order_for_code = self->byte_order_for_code;
-  CORE_ADDR breaks[2] = {-1, -1};
+  CORE_ADDR breaks[2] = {static_cast<CORE_ADDR>(-1), static_cast<CORE_ADDR>(-1)};
   CORE_ADDR pc = regcache_read_pc (self->regcache);
   CORE_ADDR loc = pc;
   unsigned int insn;
