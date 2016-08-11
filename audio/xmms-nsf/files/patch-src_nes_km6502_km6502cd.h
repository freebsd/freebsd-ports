--- src/nes/km6502/km6502cd.h.orig	2001-01-07 04:18:05 UTC
+++ src/nes/km6502/km6502cd.h
@@ -361,27 +361,27 @@ static void OpsubCall KM_TST(__CONTEXT_ 
 
 /* --- ADC ---  */
 #if BUILD_HUC6280
-#define DEF_ADC(i,p,a) static void OpcodeCall Opcode##i##(__CONTEXT) \
-{ KMI_ADC(__THISP_ K_READ##p##(__THISP_ a(__THISP))); } \
-static void OpcodeCall D_Opco##i##(__CONTEXT) \
-{ KMI_ADC_D(__THISP_ K_READ##p##(__THISP_ a(__THISP))); } \
-static void OpcodeCall T_Opco##i##(__CONTEXT) \
+#define DEF_ADC(i,p,a) static void OpcodeCall Opcode##i (__CONTEXT) \
+{ KMI_ADC(__THISP_ K_READ##p (__THISP_ a(__THISP))); } \
+static void OpcodeCall D_Opco##i (__CONTEXT) \
+{ KMI_ADC_D(__THISP_ K_READ##p (__THISP_ a(__THISP))); } \
+static void OpcodeCall T_Opco##i (__CONTEXT) \
 { \
 	Uword saveA = KMI_PRET(__THISP); \
-	KMI_ADC(__THISP_ K_READ##p##(__THISP_ a(__THISP))); \
+	KMI_ADC(__THISP_ K_READ##p (__THISP_ a(__THISP))); \
 	KMI_POSTT(__THISP_ saveA); \
 } \
-static void OpcodeCall TD_Opc##i##(__CONTEXT) \
+static void OpcodeCall TD_Opc##i (__CONTEXT) \
 { \
 	Uword saveA = KMI_PRET(__THISP); \
-	KMI_ADC_D(__THISP_ K_READ##p##(__THISP_ a(__THISP))); \
+	KMI_ADC_D(__THISP_ K_READ##p (__THISP_ a(__THISP))); \
 	KMI_POSTT(__THISP_ saveA); \
 }
 #else
-#define DEF_ADC(i,p,a) static void OpcodeCall Opcode##i##(__CONTEXT) \
-{ KMI_ADC(__THISP_ K_READ##p##(__THISP_ a(__THISP))); } \
-static void OpcodeCall D_Opco##i##(__CONTEXT) \
-{ KMI_ADC_D(__THISP_ K_READ##p##(__THISP_ a(__THISP))); }
+#define DEF_ADC(i,p,a) static void OpcodeCall Opcode##i (__CONTEXT) \
+{ KMI_ADC(__THISP_ K_READ##p (__THISP_ a(__THISP))); } \
+static void OpcodeCall D_Opco##i (__CONTEXT) \
+{ KMI_ADC_D(__THISP_ K_READ##p (__THISP_ a(__THISP))); }
 #endif
 DEF_ADC(61,NP,KA_INDX)	/* 61 - ADC - (Indirect,X) */
 DEF_ADC(65,ZP,KA_ZP)	/* 65 - ADC - Zero Page */
@@ -397,17 +397,17 @@ DEF_ADC(72,NP,KA_IND)	/* 72 - ADC - (Ind
 
 /* --- AND ---  */
 #if BUILD_HUC6280
-#define DEF_AND(i,p,a) static void OpcodeCall Opcode##i##(__CONTEXT) \
-{ KM_AND(__THISP_ K_READ##p##(__THISP_ a(__THISP))); } \
-static void OpcodeCall T_Opco##i##(__CONTEXT) \
+#define DEF_AND(i,p,a) static void OpcodeCall Opcode##i (__CONTEXT) \
+{ KM_AND(__THISP_ K_READ##p (__THISP_ a(__THISP))); } \
+static void OpcodeCall T_Opco##i (__CONTEXT) \
 { \
 	Uword saveA = KMI_PRET(__THISP); \
-	KM_AND(__THISP_ K_READ##p##(__THISP_ a(__THISP))); \
+	KM_AND(__THISP_ K_READ##p (__THISP_ a(__THISP))); \
 	KMI_POSTT(__THISP_ saveA); \
 }
 #else
-#define DEF_AND(i,p,a) static void OpcodeCall Opcode##i##(__CONTEXT) \
-{ KM_AND(__THISP_ K_READ##p##(__THISP_ a(__THISP))); }
+#define DEF_AND(i,p,a) static void OpcodeCall Opcode##i (__CONTEXT) \
+{ KM_AND(__THISP_ K_READ##p (__THISP_ a(__THISP))); }
 #endif
 DEF_AND(21,NP,KA_INDX)	/* 21 - AND - (Indirect,X) */
 DEF_AND(25,ZP,KA_ZP)	/* 25 - AND - Zero Page */
@@ -422,10 +422,10 @@ DEF_AND(32,NP,KA_IND)	/* 32 - AND - (Ind
 #endif
 
 /* --- ASL ---  */
-#define DEF_ASL(i,p,a) static void OpcodeCall Opcode##i##(__CONTEXT) \
+#define DEF_ASL(i,p,a) static void OpcodeCall Opcode##i (__CONTEXT) \
 { \
 	Uword adr = a(__THISP); \
-	K_WRITE##p##(__THISP_ adr, KM_ASL(__THISP_ K_READ##p##(__THISP_ adr))); \
+	K_WRITE##p (__THISP_ adr, KM_ASL(__THISP_ K_READ##p (__THISP_ adr))); \
 }
 DEF_ASL(06,ZP,KA_ZP)	/* 06 - ASL - Zero Page */
 DEF_ASL(0E,NP,KA_ABS)	/* 0E - ASL - Absolute */
@@ -436,7 +436,7 @@ static void OpcodeCall Opcode0A(__CONTEX
 
 #if BUILD_HUC6280
 /* --- BBRi --- */
-#define DEF_BBR(i,y) static void OpcodeCall Opcode##i##(__CONTEXT) \
+#define DEF_BBR(i,y) static void OpcodeCall Opcode##i (__CONTEXT) \
 { \
 	Uword adr = KA_ZP(__THISP); \
 	Uword rel = K_READ(__THISP_ KA_IMM(__THISP)); \
@@ -451,7 +451,7 @@ DEF_BBR(5F,5)			/* 5F - BBR5 */
 DEF_BBR(6F,6)			/* 6F - BBR6 */
 DEF_BBR(7F,7)			/* 7F - BBR7 */
 /* --- BBSi --- */
-#define DEF_BBS(i,y) static void OpcodeCall Opcode##i##(__CONTEXT) \
+#define DEF_BBS(i,y) static void OpcodeCall Opcode##i (__CONTEXT) \
 { \
 	Uword adr = KA_ZP(__THISP); \
 	Uword rel = K_READ(__THISP_ KA_IMM(__THISP)); \
@@ -468,8 +468,8 @@ DEF_BBS(FF,7)			/* FF - BBS7 */
 #endif
 
 /* --- BIT ---  */
-#define DEF_BIT(i,p,a) static void OpcodeCall Opcode##i##(__CONTEXT) \
-{ KM_BIT(__THISP_ K_READ##p##(__THISP_ a(__THISP))); }
+#define DEF_BIT(i,p,a) static void OpcodeCall Opcode##i (__CONTEXT) \
+{ KM_BIT(__THISP_ K_READ##p (__THISP_ a(__THISP))); }
 DEF_BIT(24,ZP,KA_ZP)	/* 24 - BIT - Zero Page */
 DEF_BIT(2C,NP,KA_ABS)	/* 2C - BIT - Absolute */
 #if BUILD_HUC6280 || BUILD_M65C02
@@ -479,7 +479,7 @@ DEF_BIT(89,NP,KA_IMM)	/* 89 - BIT - Imme
 #endif
 
 /* --- Bcc ---  */
-#define DEF_BRA(i,a) static void OpcodeCall Opcode##i##(__CONTEXT) \
+#define DEF_BRA(i,a) static void OpcodeCall Opcode##i (__CONTEXT) \
 { \
 	Uword rel = K_READ(__THISP_ KA_IMM(__THISP)); \
 	if (a) KM_BRA(__THISP_ rel); \
@@ -536,8 +536,8 @@ static void OpcodeCall OpcodeB8(__CONTEX
 { __THIS__.P &= ~V_FLAG; }
 
 /* --- CMP --- */
-#define DEF_CMP(i,p,a) static void OpcodeCall Opcode##i##(__CONTEXT) \
-{ KM_CMP(__THISP_ K_READ##p##(__THISP_ a(__THISP))); }
+#define DEF_CMP(i,p,a) static void OpcodeCall Opcode##i (__CONTEXT) \
+{ KM_CMP(__THISP_ K_READ##p (__THISP_ a(__THISP))); }
 DEF_CMP(C1,NP,KA_INDX)	/* C1 - CMP - (Indirect,X) */
 DEF_CMP(C5,ZP,KA_ZP)	/* C5 - CMP - Zero Page */
 DEF_CMP(C9,NP,KA_IMM)	/* C9 - CMP - Immediate */
@@ -551,24 +551,24 @@ DEF_CMP(D2,NP,KA_IND)	/* D2 - CMP - (Ind
 #endif
 
 /* --- CPX --- */
-#define DEF_CPX(i,p,a) static void OpcodeCall Opcode##i##(__CONTEXT) \
-{ KM_CPX(__THISP_ K_READ##p##(__THISP_ a(__THISP))); }
+#define DEF_CPX(i,p,a) static void OpcodeCall Opcode##i (__CONTEXT) \
+{ KM_CPX(__THISP_ K_READ##p (__THISP_ a(__THISP))); }
 DEF_CPX(E0,NP,KA_IMM)	/* E0 - CPX - Immediate */
 DEF_CPX(E4,ZP,KA_ZP)	/* E4 - CPX - Zero Page */
 DEF_CPX(EC,NP,KA_ABS)	/* EC - CPX - Absolute */
 
 /* --- CPY --- */
-#define DEF_CPY(i,p,a) static void OpcodeCall Opcode##i##(__CONTEXT) \
-{ KM_CPY(__THISP_ K_READ##p##(__THISP_ a(__THISP))); }
+#define DEF_CPY(i,p,a) static void OpcodeCall Opcode##i (__CONTEXT) \
+{ KM_CPY(__THISP_ K_READ##p (__THISP_ a(__THISP))); }
 DEF_CPY(C0,NP,KA_IMM)	/* C0 - CPY - Immediate */
 DEF_CPY(C4,ZP,KA_ZP)	/* C4 - CPY - Zero Page */
 DEF_CPY(CC,NP,KA_ABS)	/* CC - CPY - Absolute */
 
 /* --- DEC ---  */
-#define DEF_DEC(i,p,a) static void OpcodeCall Opcode##i##(__CONTEXT) \
+#define DEF_DEC(i,p,a) static void OpcodeCall Opcode##i (__CONTEXT) \
 { \
 	Uword adr = a(__THISP); \
-	K_WRITE##p##(__THISP_ adr, KM_DEC(__THISP_ K_READ##p##(__THISP_ adr))); \
+	K_WRITE##p (__THISP_ adr, KM_DEC(__THISP_ K_READ##p (__THISP_ adr))); \
 }
 DEF_DEC(C6,ZP,KA_ZP)	/* C6 - DEC - Zero Page */
 DEF_DEC(CE,NP,KA_ABS)	/* CE - DEC - Absolute */
@@ -585,17 +585,17 @@ static void OpcodeCall Opcode88(__CONTEX
 
 /* --- EOR ---  */
 #if BUILD_HUC6280
-#define DEF_EOR(i,p,a) static void OpcodeCall Opcode##i##(__CONTEXT) \
-{ KM_EOR(__THISP_ K_READ##p##(__THISP_ a(__THISP))); } \
-static void OpcodeCall T_Opco##i##(__CONTEXT) \
+#define DEF_EOR(i,p,a) static void OpcodeCall Opcode##i (__CONTEXT) \
+{ KM_EOR(__THISP_ K_READ##p (__THISP_ a(__THISP))); } \
+static void OpcodeCall T_Opco##i (__CONTEXT) \
 { \
 	Uword saveA = KMI_PRET(__THISP); \
-	KM_EOR(__THISP_ K_READ##p##(__THISP_ a(__THISP))); \
+	KM_EOR(__THISP_ K_READ##p (__THISP_ a(__THISP))); \
 	KMI_POSTT(__THISP_ saveA); \
 }
 #else
-#define DEF_EOR(i,p,a) static void OpcodeCall Opcode##i##(__CONTEXT) \
-{ KM_EOR(__THISP_ K_READ##p##(__THISP_ a(__THISP))); }
+#define DEF_EOR(i,p,a) static void OpcodeCall Opcode##i (__CONTEXT) \
+{ KM_EOR(__THISP_ K_READ##p (__THISP_ a(__THISP))); }
 #endif
 DEF_EOR(41,NP,KA_INDX)	/* 41 - EOR - (Indirect,X) */
 DEF_EOR(45,ZP,KA_ZP)	/* 45 - EOR - Zero Page */
@@ -610,10 +610,10 @@ DEF_EOR(52,NP,KA_IND)	/* 52 - EOR - (Ind
 #endif
 
 /* --- INC ---  */
-#define DEF_INC(i,p,a) static void OpcodeCall Opcode##i##(__CONTEXT) \
+#define DEF_INC(i,p,a) static void OpcodeCall Opcode##i (__CONTEXT) \
 { \
 	Uword adr = a(__THISP); \
-	K_WRITE##p##(__THISP_ adr, KM_INC(__THISP_ K_READ##p##(__THISP_ adr))); \
+	K_WRITE##p (__THISP_ adr, KM_INC(__THISP_ K_READ##p (__THISP_ adr))); \
 }
 DEF_INC(E6,ZP,KA_ZP)	/* E6 - INC - Zero Page */
 DEF_INC(EE,NP,KA_ABS)	/* EE - INC - Absolute */
@@ -629,12 +629,12 @@ static void OpcodeCall OpcodeC8(__CONTEX
 { __THIS__.Y = KM_INC(__THISP_ __THIS__.Y); }
 
 /* --- JMP ---  */
-#define DEF_JMP(i,a) static void OpcodeCall Opcode##i##(__CONTEXT) \
+#define DEF_JMP(i,a) static void OpcodeCall Opcode##i (__CONTEXT) \
 { __THIS__.PC = KI_READWORD(__THISP_ a(__THISP)); }
 #if BUILD_HUC6280 || BUILD_M65C02
 #define DEF_JMPBUG(i,a) DEF_JMP(i,a)
 #else
-#define DEF_JMPBUG(i,a) static void OpcodeCall Opcode##i##(__CONTEXT) \
+#define DEF_JMPBUG(i,a) static void OpcodeCall Opcode##i (__CONTEXT) \
 { __THIS__.PC = KI_READWORDBUG(__THISP_ a(__THISP)); }
 #endif
 DEF_JMP(4C,KA_IMM16)	/* 4C - JMP - Immediate */
@@ -653,8 +653,8 @@ static void OpcodeCall Opcode20(__CONTEX
 }
 
 /* --- LDA --- */
-#define DEF_LDA(i,p,a) static void OpcodeCall Opcode##i##(__CONTEXT) \
-{ __THIS__.A = KM_LD(__THISP_ K_READ##p##(__THISP_ a(__THISP))); }
+#define DEF_LDA(i,p,a) static void OpcodeCall Opcode##i (__CONTEXT) \
+{ __THIS__.A = KM_LD(__THISP_ K_READ##p (__THISP_ a(__THISP))); }
 DEF_LDA(A1,NP,KA_INDX)	/* A1 - LDA - (Indirect,X) */
 DEF_LDA(A5,ZP,KA_ZP)	/* A5 - LDA - Zero Page */
 DEF_LDA(A9,NP,KA_IMM)	/* A9 - LDA - Immediate */
@@ -668,8 +668,8 @@ DEF_LDA(B2,NP,KA_IND)	/* B2 - LDA - (Ind
 #endif
 
 /* --- LDX ---  */
-#define DEF_LDX(i,p,a) static void OpcodeCall Opcode##i##(__CONTEXT) \
-{ __THIS__.X = KM_LD(__THISP_ K_READ##p##(__THISP_ a(__THISP))); }
+#define DEF_LDX(i,p,a) static void OpcodeCall Opcode##i (__CONTEXT) \
+{ __THIS__.X = KM_LD(__THISP_ K_READ##p (__THISP_ a(__THISP))); }
 DEF_LDX(A2,NP,KA_IMM)	/* A2 - LDX - Immediate */
 DEF_LDX(A6,ZP,KA_ZP)	/* A6 - LDX - Zero Page */
 DEF_LDX(AE,NP,KA_ABS)	/* AE - LDX - Absolute */
@@ -677,8 +677,8 @@ DEF_LDX(B6,ZP,KA_ZPY)	/* B6 - LDX - Zero
 DEF_LDX(BE,NP,KA_ABSY_)	/* BE - LDX - Absolute,Y */
 
 /* --- LDY ---  */
-#define DEF_LDY(i,p,a) static void OpcodeCall Opcode##i##(__CONTEXT) \
-{ __THIS__.Y = KM_LD(__THISP_ K_READ##p##(__THISP_ a(__THISP))); }
+#define DEF_LDY(i,p,a) static void OpcodeCall Opcode##i (__CONTEXT) \
+{ __THIS__.Y = KM_LD(__THISP_ K_READ##p (__THISP_ a(__THISP))); }
 DEF_LDY(A0,NP,KA_IMM)	/* A0 - LDY - Immediate */
 DEF_LDY(A4,ZP,KA_ZP)	/* A4 - LDY - Zero Page */
 DEF_LDY(AC,NP,KA_ABS)	/* AC - LDY - Absolute */
@@ -686,10 +686,10 @@ DEF_LDY(B4,ZP,KA_ZPX)	/* B4 - LDY - Zero
 DEF_LDY(BC,NP,KA_ABSX_)	/* BC - LDY - Absolute,X */
 
 /* --- LSR ---  */
-#define DEF_LSR(i,p,a) static void OpcodeCall Opcode##i##(__CONTEXT) \
+#define DEF_LSR(i,p,a) static void OpcodeCall Opcode##i (__CONTEXT) \
 { \
 	Uword adr = a(__THISP); \
-	K_WRITE##p##(__THISP_ adr, KM_LSR(__THISP_ K_READ##p##(__THISP_ adr))); \
+	K_WRITE##p (__THISP_ adr, KM_LSR(__THISP_ K_READ##p (__THISP_ adr))); \
 }
 DEF_LSR(46,ZP,KA_ZP)	/* 46 - LSR - Zero Page */
 DEF_LSR(4E,NP,KA_ABS)	/* 4E - LSR - Absolute */
@@ -705,17 +705,17 @@ static void OpcodeCall OpcodeEA(__CONTEX
 
 /* --- ORA ---  */
 #if BUILD_HUC6280
-#define DEF_ORA(i,p,a) static void OpcodeCall Opcode##i##(__CONTEXT) \
-{ KM_ORA(__THISP_ K_READ##p##(__THISP_ a(__THISP))); } \
-static void OpcodeCall T_Opco##i##(__CONTEXT) \
+#define DEF_ORA(i,p,a) static void OpcodeCall Opcode##i (__CONTEXT) \
+{ KM_ORA(__THISP_ K_READ##p (__THISP_ a(__THISP))); } \
+static void OpcodeCall T_Opco##i (__CONTEXT) \
 { \
 	Uword saveA = KMI_PRET(__THISP); \
-	KM_ORA(__THISP_ K_READ##p##(__THISP_ a(__THISP))); \
+	KM_ORA(__THISP_ K_READ##p (__THISP_ a(__THISP))); \
 	KMI_POSTT(__THISP_ saveA); \
 }
 #else
-#define DEF_ORA(i,p,a) static void OpcodeCall Opcode##i##(__CONTEXT) \
-{ KM_ORA(__THISP_ K_READ##p##(__THISP_ a(__THISP))); }
+#define DEF_ORA(i,p,a) static void OpcodeCall Opcode##i (__CONTEXT) \
+{ KM_ORA(__THISP_ K_READ##p (__THISP_ a(__THISP))); }
 #endif
 DEF_ORA(01,NP,KA_INDX)	/* 01 - ORA - (Indirect,X) */
 DEF_ORA(05,ZP,KA_ZP)	/* 05 - ORA - Zero Page */
@@ -751,7 +751,7 @@ static void OpcodeCall Opcode7A(__CONTEX
 
 #if BUILD_HUC6280
 /* --- RMBi --- */
-#define DEF_RMB(i,y) static void OpcodeCall Opcode##i##(__CONTEXT) \
+#define DEF_RMB(i,y) static void OpcodeCall Opcode##i (__CONTEXT) \
 { \
 	Uword adr = KA_ZP(__THISP); \
 	K_WRITEZP(__THISP_ adr, (Uword)(K_READZP(__THISP_ adr) & (~(1 << y)))); \
@@ -765,7 +765,7 @@ DEF_RMB(57,5)	/* 57 - RMB5 */
 DEF_RMB(67,6)	/* 67 - RMB6 */
 DEF_RMB(77,7)	/* 77 - RMB7 */
 /* --- SMBi --- */
-#define DEF_SMB(i,y) static void OpcodeCall Opcode##i##(__CONTEXT) \
+#define DEF_SMB(i,y) static void OpcodeCall Opcode##i (__CONTEXT) \
 { \
 	Uword adr = KA_ZP(__THISP); \
 	K_WRITEZP(__THISP_ adr, (Uword)(K_READZP(__THISP_ adr) | (1 << y))); \
@@ -781,10 +781,10 @@ DEF_SMB(F7,7)	/* F7 - SMB7 */
 #endif
 
 /* --- ROL ---  */
-#define DEF_ROL(i,p,a) static void OpcodeCall Opcode##i##(__CONTEXT) \
+#define DEF_ROL(i,p,a) static void OpcodeCall Opcode##i (__CONTEXT) \
 { \
 	Uword adr = a(__THISP); \
-	K_WRITE##p##(__THISP_ adr, KM_ROL(__THISP_ K_READ##p##(__THISP_ adr))); \
+	K_WRITE##p (__THISP_ adr, KM_ROL(__THISP_ K_READ##p (__THISP_ adr))); \
 }
 DEF_ROL(26,ZP,KA_ZP)	/* 26 - ROL - Zero Page */
 DEF_ROL(2E,NP,KA_ABS)	/* 2E - ROL - Absolute */
@@ -794,10 +794,10 @@ static void OpcodeCall Opcode2A(__CONTEX
 { __THIS__.A = KM_ROL(__THISP_ __THIS__.A); }
 
 /* --- ROR ---  */
-#define DEF_ROR(i,p,a) static void OpcodeCall Opcode##i##(__CONTEXT) \
+#define DEF_ROR(i,p,a) static void OpcodeCall Opcode##i (__CONTEXT) \
 { \
 	Uword adr = a(__THISP); \
-	K_WRITE##p##(__THISP_ adr, KM_ROR(__THISP_ K_READ##p##(__THISP_ adr))); \
+	K_WRITE##p (__THISP_ adr, KM_ROR(__THISP_ K_READ##p (__THISP_ adr))); \
 }
 DEF_ROR(66,ZP,KA_ZP)	/* 66 - ROR - Zero Page */
 DEF_ROR(6E,NP,KA_ABS)	/* 6E - ROR - Absolute */
@@ -841,10 +841,10 @@ static void OpcodeCall Opcode02(__CONTEX
 #endif
 
 /* --- SBC ---  */
-#define DEF_SBC(i,p,a) static void OpcodeCall Opcode##i##(__CONTEXT) \
-{ KMI_SBC(__THISP_ K_READ##p##(__THISP_ a(__THISP))); } \
-static void OpcodeCall D_Opco##i##(__CONTEXT) \
-{ KMI_SBC_D(__THISP_ K_READ##p##(__THISP_ a(__THISP))); }
+#define DEF_SBC(i,p,a) static void OpcodeCall Opcode##i (__CONTEXT) \
+{ KMI_SBC(__THISP_ K_READ##p (__THISP_ a(__THISP))); } \
+static void OpcodeCall D_Opco##i (__CONTEXT) \
+{ KMI_SBC_D(__THISP_ K_READ##p (__THISP_ a(__THISP))); }
 DEF_SBC(E1,NP,KA_INDX)	/* E1 - SBC - (Indirect,X) */
 DEF_SBC(E5,ZP,KA_ZP)	/* E5 - SBC - Zero Page */
 DEF_SBC(E9,NP,KA_IMM)	/* E9 - SBC - Immediate */
@@ -883,8 +883,8 @@ static void OpcodeCall Opcode23(__CONTEX
 #endif
 
 /* --- STA --- */
-#define DEF_STA(i,p,a) static void OpcodeCall Opcode##i##(__CONTEXT) \
-{ K_WRITE##p##(__THISP_ a(__THISP), __THIS__.A); }
+#define DEF_STA(i,p,a) static void OpcodeCall Opcode##i (__CONTEXT) \
+{ K_WRITE##p (__THISP_ a(__THISP), __THIS__.A); }
 DEF_STA(81,NP,KA_INDX)	/* 81 - STA - (Indirect,X) */
 DEF_STA(85,ZP,KA_ZP)	/* 85 - STA - Zero Page */
 DEF_STA(8D,NP,KA_ABS)	/* 8D - STA - Absolute */
@@ -897,23 +897,23 @@ DEF_STA(92,NP,KA_IND)	/* 92 - STA - (Ind
 #endif
 
 /* --- STX ---  */
-#define DEF_STX(i,p,a) static void OpcodeCall Opcode##i##(__CONTEXT) \
-{ K_WRITE##p##(__THISP_ a(__THISP), __THIS__.X); }
+#define DEF_STX(i,p,a) static void OpcodeCall Opcode##i (__CONTEXT) \
+{ K_WRITE##p (__THISP_ a(__THISP), __THIS__.X); }
 DEF_STX(86,ZP,KA_ZP)	/* 86 - STX - Zero Page */
 DEF_STX(8E,NP,KA_ABS)	/* 8E - STX - Absolute */
 DEF_STX(96,ZP,KA_ZPY)	/* 96 - STX - Zero Page,Y */
 
 /* --- STY ---  */
-#define DEF_STY(i,p,a) static void OpcodeCall Opcode##i##(__CONTEXT) \
-{ K_WRITE##p##(__THISP_ a(__THISP), __THIS__.Y); }
+#define DEF_STY(i,p,a) static void OpcodeCall Opcode##i (__CONTEXT) \
+{ K_WRITE##p (__THISP_ a(__THISP), __THIS__.Y); }
 DEF_STY(84,ZP,KA_ZP)	/* 84 - STY - Zero Page */
 DEF_STY(8C,NP,KA_ABS)	/* 8C - STY - Absolute */
 DEF_STY(94,ZP,KA_ZPX)	/* 94 - STY - Zero Page,X */
 
 #if BUILD_HUC6280 || BUILD_M65C02
 /* --- STZ ---  */
-#define DEF_STZ(i,p,a) static void OpcodeCall Opcode##i##(__CONTEXT) \
-{ K_WRITE##p##(__THISP_ a(__THISP), 0); }
+#define DEF_STZ(i,p,a) static void OpcodeCall Opcode##i (__CONTEXT) \
+{ K_WRITE##p (__THISP_ a(__THISP), 0); }
 DEF_STZ(64,ZP,KA_ZP)	/* 64 - STZ - Zero Page */
 DEF_STZ(9C,NP,KA_ABS)	/* 9C - STZ - Absolute */
 DEF_STZ(74,ZP,KA_ZPX)	/* 74 - STZ - Zero Page,X */
@@ -931,18 +931,18 @@ static void OpcodeCall Opcode43(__CONTEX
 
 #if BUILD_HUC6280 || BUILD_M65C02
 /* --- TRB --- */
-#define DEF_TRB(i,p,a) static void OpcodeCall Opcode##i##(__CONTEXT) \
+#define DEF_TRB(i,p,a) static void OpcodeCall Opcode##i (__CONTEXT) \
 { \
 	Uword adr = a(__THISP); \
-	K_WRITE##p##(__THISP_ adr, KM_TRB(__THISP_ K_READ##p##(__THISP_ adr))); \
+	K_WRITE##p (__THISP_ adr, KM_TRB(__THISP_ K_READ##p (__THISP_ adr))); \
 }
 DEF_TRB(14,ZP,KA_ZP)	/* 14 - TRB - Zero Page */
 DEF_TRB(1C,NP,KA_ABS)	/* 1C - TRB - Absolute */
 /* --- TSB --- */
-#define DEF_TSB(i,p,a) static void OpcodeCall Opcode##i##(__CONTEXT) \
+#define DEF_TSB(i,p,a) static void OpcodeCall Opcode##i (__CONTEXT) \
 { \
 	Uword adr = a(__THISP); \
-	K_WRITE##p##(__THISP_ adr, KM_TSB(__THISP_ K_READ##p##(__THISP_ adr))); \
+	K_WRITE##p (__THISP_ adr, KM_TSB(__THISP_ K_READ##p (__THISP_ adr))); \
 }
 DEF_TSB(04,ZP,KA_ZP)	/* 04 - TSB - Zero Page */
 DEF_TSB(0C,NP,KA_ABS)	/* 0C - TSB - Absolute */
@@ -950,10 +950,10 @@ DEF_TSB(0C,NP,KA_ABS)	/* 0C - TSB - Abso
 
 #if BUILD_HUC6280
 /* --- TST --- */
-#define DEF_TST(i,p,a) static void OpcodeCall Opcode##i##(__CONTEXT) \
+#define DEF_TST(i,p,a) static void OpcodeCall Opcode##i (__CONTEXT) \
 { \
 	Uword imm = K_READ(__THISP_ KA_IMM(__THISP)); \
-	KM_TST(__THISP_ imm, K_READ##p##(__THISP_ a(__THISP))); \
+	KM_TST(__THISP_ imm, K_READ##p (__THISP_ a(__THISP))); \
 }
 DEF_TST(83,ZP,KA_ZP)	/* 83 - TST - Zero Page */
 DEF_TST(93,NP,KA_ABS)	/* 93 - TST - Absolute */
