--- opcodes/crx-opc.c.orig	2013-03-07 10:35:06.000000000 +0100
+++ opcodes/crx-opc.c	2013-03-07 10:40:31.000000000 +0100
@@ -632,7 +632,7 @@
 const reg_entry crx_copregtab[] =
 {
 /* Build a Coprocessor register c<N>.  */
-#define REG_C(N)    REG(CONCAT2(c,N), N, CRX_C_REGTYPE)
+#define REG_C(N)    REG((reg)CONCAT2(c,N), N, CRX_C_REGTYPE)
 
   REG_C(0),  REG_C(1),	REG_C(2),  REG_C(3),
   REG_C(4),  REG_C(5),	REG_C(6),  REG_C(7),
@@ -640,7 +640,7 @@
   REG_C(12), REG_C(13), REG_C(14), REG_C(15),
 
 /* Build a Coprocessor Special register cs<N>.  */
-#define REG_CS(N)    REG(CONCAT2(cs,N), N, CRX_CS_REGTYPE)
+#define REG_CS(N)    REG((reg)CONCAT2(cs,N), N, CRX_CS_REGTYPE)
 
   REG_CS(0),  REG_CS(1),  REG_CS(2),  REG_CS(3),
   REG_CS(4),  REG_CS(5),  REG_CS(6),  REG_CS(7),
