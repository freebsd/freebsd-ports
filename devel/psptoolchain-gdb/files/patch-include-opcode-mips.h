--- include/opcode/mips.h.orig	2005-09-06 19:42:58.000000000 +0100
+++ include/opcode/mips.h	2007-02-08 20:06:04.000000000 +0000
@@ -203,6 +203,83 @@
 #define MDMX_FMTSEL_VEC_QH	0x15
 #define MDMX_FMTSEL_VEC_OB	0x16
 
+#define OP_SH_VFPU_DELTA	0
+#define OP_MASK_VFPU_DELTA	0xfffc
+#define OP_SH_VFPU_IMM3		16
+#define OP_MASK_VFPU_IMM3	0x7
+#define OP_SH_VFPU_IMM5		16
+#define OP_MASK_VFPU_IMM5	0x1f
+#define OP_SH_VFPU_IMM8		16
+#define OP_MASK_VFPU_IMM8	0xff
+#define OP_SH_VFPU_CC		18	/* Condition code. */
+#define OP_MASK_VFPU_CC		0x7
+#define OP_SH_VFPU_CONST	16
+#define OP_MASK_VFPU_CONST	0x1f
+#define OP_SH_VFPU_COND		0	/* Conditional compare. */
+#define OP_MASK_VFPU_COND	0xf
+#define OP_SH_VFPU_VMTVC	0
+#define OP_MASK_VFPU_VMTVC	0xff
+#define OP_SH_VFPU_VMFVC	8
+#define OP_MASK_VFPU_VMFVC	0xff
+#define OP_SH_VFPU_RWB		1
+#define OP_MASK_VFPU_RWB	0x1
+#define OP_SH_VFPU_ROT		16	/* Rotators used in vrot. */
+#define OP_MASK_VFPU_ROT	0x1f
+#define OP_SH_VFPU_FLOAT16	0
+#define OP_MASK_VFPU_FLOAT16	0xffff
+
+/* VFPU registers. */
+#define OP_SH_VFPU_VD		0
+#define OP_MASK_VFPU_VD		0x7f
+#define OP_SH_VFPU_VS		8
+#define OP_MASK_VFPU_VS		0x7f
+#define OP_SH_VFPU_VT		16
+#define OP_MASK_VFPU_VT		0x7f
+#define OP_SH_VFPU_VT_LO	16	/* Bits 0-4 of vt. */
+#define OP_MASK_VFPU_VT_LO	0x1f
+#define OP_SH_VFPU_VT_HI	5	/* Right-shifted. */
+#define OP_MASK_VFPU_VT_HI1	0x1	/* Bit 5 of vt. */
+#define OP_MASK_VFPU_VT_HI2	0x3	/* Bits 5-6 of vt. */
+/* Special handling of vs in vmmul instructions. */
+#define VFPU_OP_VT_VS_VD	0xff800000
+#define VFPU_OPCODE_VMMUL	0xf0000000
+
+/* VFPU prefix instruction operands.  The *_SH_* values really specify where
+   the bitfield begins, as VFPU prefix instructions have four operands
+   encoded within the immediate field. */
+#define VFPU_SH_PFX_NEG		16
+#define VFPU_MASK_PFX_NEG	0x1	/* Negation. */
+#define VFPU_SH_PFX_CST		12
+#define VFPU_MASK_PFX_CST	0x1	/* Constant. */
+#define VFPU_SH_PFX_ABS_CSTHI	8
+#define VFPU_MASK_PFX_ABS_CSTHI	0x1	/* Abs/Constant (bit 2). */
+#define VFPU_MASK_PFX_SWZ_CSTLO	0x3	/* Swizzle/Constant (bits 0-1). */
+#define VFPU_SH_PFX_MASK	8
+#define VFPU_MASK_PFX_MASK	0x1	/* Mask. */
+#define VFPU_MASK_PFX_SAT	0x3	/* Saturation. */
+
+/* Special handling of the vrot instructions. */
+#define VFPU_MASK_OP_SIZE	0x8080	/* Masks the operand size (pair, triple, quad). */
+#define VFPU_OP_SIZE_PAIR	0x80
+#define VFPU_OP_SIZE_TRIPLE	0x8000
+#define VFPU_OP_SIZE_QUAD	0x8080
+/* Note that these are within the rotators field, and not the full opcode. */
+#define VFPU_SH_ROT_HI		2
+#define VFPU_MASK_ROT_HI	0x3
+#define VFPU_SH_ROT_LO		0
+#define VFPU_MASK_ROT_LO	0x3
+#define VFPU_SH_ROT_NEG		4	/* Negation. */
+#define VFPU_MASK_ROT_NEG	0x1
+
+/* VFPU 16-bit floating-point format. */
+#define VFPU_FLOAT16_EXP_MAX	0x1f
+#define VFPU_SH_FLOAT16_SIGN	15
+#define VFPU_MASK_FLOAT16_SIGN	0x1
+#define VFPU_SH_FLOAT16_EXP	10
+#define VFPU_MASK_FLOAT16_EXP	0x1f
+#define VFPU_SH_FLOAT16_FRAC	0
+#define VFPU_MASK_FLOAT16_FRAC	0x3ff
+
 /* This structure holds information for a particular instruction.  */
 
 struct mips_opcode
@@ -290,6 +367,29 @@
 	Requires that "+A" or "+E" occur first to set position.
 	Enforces: 32 < (pos+size) <= 64.
 
+   Sony Allegrex VFPU instructions:
+   "?o"
+   "?0" - "?3"
+   "?4" - "?7"
+   "?a"
+   "?b"
+   "?c"
+   "?e"
+   "?f"
+   "?i"
+   "?q"
+   "?r"
+   "?u"
+   "?w"
+   "?d"
+   "?m"
+   "?n"
+   "?s"
+   "?t"
+   "?v"
+   "?x"
+   "?z"
+
    Floating point instructions:
    "D" 5 bit destination register (OP_*_FD)
    "M" 3 bit compare condition code (OP_*_CCC) (only used for mips4 and up)
@@ -500,6 +600,8 @@
 #define INSN_5400		  0x01000000
 /* NEC VR5500 instruction.  */
 #define INSN_5500		  0x02000000
+/* Sony Allegrex instruction.  */
+#define INSN_ALLEGREX		  0x10000000
 /* MT ASE */
 #define INSN_MT                   0x04000000
 
@@ -549,6 +651,7 @@
 #define CPU_MIPS64      64
 #define CPU_MIPS64R2	65
 #define CPU_SB1         12310201        /* octal 'SB', 01.  */
+#define CPU_ALLEGREX    10111431        /* octal 'AL', 31.  */
 
 /* Test for membership in an ISA including chip specific ISAs.  INSN
    is pointer to an element of the opcode table; ISA is the specified
@@ -570,6 +673,7 @@
      || (cpu == CPU_VR4120 && ((insn)->membership & INSN_4120) != 0)	\
      || (cpu == CPU_VR5400 && ((insn)->membership & INSN_5400) != 0)	\
      || (cpu == CPU_VR5500 && ((insn)->membership & INSN_5500) != 0)	\
+     || (cpu == CPU_ALLEGREX && ((insn)->membership & INSN_ALLEGREX) != 0)	\
      || 0)	/* Please keep this term for easier source merging.  */
 
 /* This is a list of macro expanded instructions.
@@ -685,6 +789,16 @@
   M_LL_AB,
   M_LLD_AB,
   M_LS_A,
+  M_LVHIP,
+  M_LVHIS,
+  M_LVIP,
+  M_LVIQ,
+  M_LVIS,
+  M_LVIT,
+  M_LVLQ_AB,
+  M_LVRQ_AB,
+  M_LVQ_AB,
+  M_LVQ_AB_2,
   M_LW_A,
   M_LW_AB,
   M_LWC0_A,
@@ -774,6 +888,10 @@
   M_SUB_I,
   M_SUBU_I,
   M_SUBU_I_2,
+  M_SVLQ_AB,
+  M_SVQ_AB,
+  M_SVRQ_AB,
+  M_SVS_AB,
   M_TEQ_I,
   M_TGE_I,
   M_TGEU_I,
@@ -788,14 +906,24 @@
   M_ULH_A,
   M_ULHU,
   M_ULHU_A,
+  M_ULVQ,
+  M_ULVQ_AB,
+  M_ULVS,
   M_ULW,
   M_ULW_A,
   M_USH,
   M_USH_A,
+  M_USVQ,
+  M_USVQ_AB,
+  M_USVS,
   M_USW,
   M_USW_A,
   M_USD,
   M_USD_A,
+  M_VCMOVP,
+  M_VCMOVQ,
+  M_VCMOVS,
+  M_VCMOVT,
   M_XOR_I,
   M_COP0,
   M_COP1,
