--- arch/bfin/common/bfin-dis.c.orig
+++ arch/bfin/common/bfin-dis.c
@@ -310,7 +310,7 @@
 		REG_RL7,
 	REG_RH0, REG_RH1, REG_RH2, REG_RH3, REG_RH4, REG_RH5, REG_RH6,
 		REG_RH7,
-	REG_R0, REG_R1, REG_R2, REG_R3, REG_R4, REG_R5, REG_R6, REG_R7,
+	REG_RR0, REG_RR1, REG_RR2, REG_RR3, REG_RR4, REG_RR5, REG_RR6, REG_RR7,
 	REG_R1_0, REG_R3_2, REG_R5_4, REG_R7_6, REG_P0, REG_P1, REG_P2,
 		REG_P3,
 	REG_P4, REG_P5, REG_SP, REG_FP, REG_A0x, REG_A1x, REG_A0w, REG_A1w,
@@ -401,7 +401,7 @@
 
 /* R(0..7)  */
 static enum machine_registers decode_dregs[] = {
-	REG_R0, REG_R1, REG_R2, REG_R3, REG_R4, REG_R5, REG_R6, REG_R7,
+	REG_RR0, REG_RR1, REG_RR2, REG_RR3, REG_RR4, REG_RR5, REG_RR6, REG_RR7,
 };
 
 #define dregs(x) REGNAME(decode_dregs[(x) & 7])
@@ -497,7 +497,7 @@
 
 /* dregs pregs  */
 static enum machine_registers decode_dpregs[] = {
-	REG_R0, REG_R1, REG_R2, REG_R3, REG_R4, REG_R5, REG_R6, REG_R7,
+	REG_RR0, REG_RR1, REG_RR2, REG_RR3, REG_RR4, REG_RR5, REG_RR6, REG_RR7,
 	REG_P0, REG_P1, REG_P2, REG_P3, REG_P4, REG_P5, REG_SP, REG_FP,
 };
 
@@ -505,7 +505,7 @@
 
 /* [dregs pregs] */
 static enum machine_registers decode_gregs[] = {
-	REG_R0, REG_R1, REG_R2, REG_R3, REG_R4, REG_R5, REG_R6, REG_R7,
+	REG_RR0, REG_RR1, REG_RR2, REG_RR3, REG_RR4, REG_RR5, REG_RR6, REG_RR7,
 	REG_P0, REG_P1, REG_P2, REG_P3, REG_P4, REG_P5, REG_SP, REG_FP,
 };
 
@@ -513,7 +513,7 @@
 
 /* [dregs pregs (iregs mregs) (bregs lregs)]  */
 static enum machine_registers decode_regs[] = {
-	REG_R0, REG_R1, REG_R2, REG_R3, REG_R4, REG_R5, REG_R6, REG_R7,
+	REG_RR0, REG_RR1, REG_RR2, REG_RR3, REG_RR4, REG_RR5, REG_RR6, REG_RR7,
 	REG_P0, REG_P1, REG_P2, REG_P3, REG_P4, REG_P5, REG_SP, REG_FP,
 	REG_I0, REG_I1, REG_I2, REG_I3, REG_M0, REG_M1, REG_M2, REG_M3,
 	REG_B0, REG_B1, REG_B2, REG_B3, REG_L0, REG_L1, REG_L2, REG_L3,
@@ -626,7 +626,7 @@
 
 /* [dregs pregs (iregs mregs) (bregs lregs) 	         dregs2_sysregs1 open sysregs2 sysregs3] */
 static enum machine_registers decode_allregs[] = {
-	REG_R0, REG_R1, REG_R2, REG_R3, REG_R4, REG_R5, REG_R6, REG_R7,
+	REG_RR0, REG_RR1, REG_RR2, REG_RR3, REG_RR4, REG_RR5, REG_RR6, REG_RR7,
 	REG_P0, REG_P1, REG_P2, REG_P3, REG_P4, REG_P5, REG_SP, REG_FP,
 	REG_I0, REG_I1, REG_I2, REG_I3, REG_M0, REG_M1, REG_M2, REG_M3,
 	REG_B0, REG_B1, REG_B2, REG_B3, REG_L0, REG_L1, REG_L2, REG_L3,
@@ -685,7 +685,7 @@
 get_allreg (int grp, int reg)
 {
 	int fullreg = (grp << 3) | reg;
-	/* REG_R0, REG_R1, REG_R2, REG_R3, REG_R4, REG_R5, REG_R6, REG_R7,
+	/* REG_RR0, REG_RR1, REG_RR2, REG_RR3, REG_RR4, REG_RR5, REG_RR6, REG_RR7,
 	   REG_P0, REG_P1, REG_P2, REG_P3, REG_P4, REG_P5, REG_SP, REG_FP,
 	   REG_I0, REG_I1, REG_I2, REG_I3, REG_M0, REG_M1, REG_M2, REG_M3,
 	   REG_B0, REG_B1, REG_B2, REG_B3, REG_L0, REG_L1, REG_L2, REG_L3,
