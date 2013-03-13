--- opcodes/cr16-opc.c.orig	2013-03-07 10:34:48.000000000 +0100
+++ opcodes/cr16-opc.c	2013-03-07 10:33:49.000000000 +0100
@@ -502,36 +502,36 @@
 const reg_entry cr16_pregtab[] =
 {
 /* Build a processor register.  */
-  REG(dbs,   0x0, CR16_P_REGTYPE),
-  REG(dsr,   0x1, CR16_P_REGTYPE),
-  REG(dcrl,  0x2, CR16_P_REGTYPE),
-  REG(dcrh,  0x3, CR16_P_REGTYPE),
-  REG(car0l, 0x4, CR16_P_REGTYPE),
-  REG(car0h, 0x5, CR16_P_REGTYPE),
-  REG(car1l, 0x6, CR16_P_REGTYPE),
-  REG(car1h, 0x7, CR16_P_REGTYPE),
-  REG(cfg,   0x8, CR16_P_REGTYPE),
-  REG(psr,   0x9, CR16_P_REGTYPE),
-  REG(intbasel, 0xa, CR16_P_REGTYPE),
-  REG(intbaseh, 0xb, CR16_P_REGTYPE),
-  REG(ispl,  0xc, CR16_P_REGTYPE),
-  REG(isph,  0xd, CR16_P_REGTYPE),
-  REG(uspl,  0xe, CR16_P_REGTYPE),
-  REG(usph,  0xf, CR16_P_REGTYPE),
+  REG((reg)dbs,   0x0, CR16_P_REGTYPE),
+  REG((reg)dsr,   0x1, CR16_P_REGTYPE),
+  REG((reg)dcrl,  0x2, CR16_P_REGTYPE),
+  REG((reg)dcrh,  0x3, CR16_P_REGTYPE),
+  REG((reg)car0l, 0x4, CR16_P_REGTYPE),
+  REG((reg)car0h, 0x5, CR16_P_REGTYPE),
+  REG((reg)car1l, 0x6, CR16_P_REGTYPE),
+  REG((reg)car1h, 0x7, CR16_P_REGTYPE),
+  REG((reg)cfg,   0x8, CR16_P_REGTYPE),
+  REG((reg)psr,   0x9, CR16_P_REGTYPE),
+  REG((reg)intbasel, 0xa, CR16_P_REGTYPE),
+  REG((reg)intbaseh, 0xb, CR16_P_REGTYPE),
+  REG((reg)ispl,  0xc, CR16_P_REGTYPE),
+  REG((reg)isph,  0xd, CR16_P_REGTYPE),
+  REG((reg)uspl,  0xe, CR16_P_REGTYPE),
+  REG((reg)usph,  0xf, CR16_P_REGTYPE),
 };
 
 const reg_entry cr16_pregptab[] =
 {
-  REG(dbs,   0, CR16_P_REGTYPE),
-  REG(dsr,   1, CR16_P_REGTYPE),
-  REG(dcr,   2, CR16_P_REGTYPE),
-  REG(car0,  4, CR16_P_REGTYPE),
-  REG(car1,  6, CR16_P_REGTYPE),
-  REG(cfg,   8, CR16_P_REGTYPE),
-  REG(psr,   9, CR16_P_REGTYPE),
-  REG(intbase, 10, CR16_P_REGTYPE),
-  REG(isp,   12, CR16_P_REGTYPE),
-  REG(usp,   14, CR16_P_REGTYPE),
+  REG((reg)dbs,   0, CR16_P_REGTYPE),
+  REG((reg)dsr,   1, CR16_P_REGTYPE),
+  REG((reg)dcr,   2, CR16_P_REGTYPE),
+  REG((reg)car0,  4, CR16_P_REGTYPE),
+  REG((reg)car1,  6, CR16_P_REGTYPE),
+  REG((reg)cfg,   8, CR16_P_REGTYPE),
+  REG((reg)psr,   9, CR16_P_REGTYPE),
+  REG((reg)intbase, 10, CR16_P_REGTYPE),
+  REG((reg)isp,   12, CR16_P_REGTYPE),
+  REG((reg)usp,   14, CR16_P_REGTYPE),
 };
 
 const unsigned int cr16_num_pregs =  ARRAY_SIZE (cr16_pregtab);
