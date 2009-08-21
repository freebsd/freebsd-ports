--- include/opcode/mips.h.orig	2005-03-03 11:58:10.000000000 +0000
+++ include/opcode/mips.h	2006-05-09 02:55:36.000000000 +0100
@@ -171,6 +171,228 @@
 #define MDMX_FMTSEL_VEC_QH	0x15
 #define MDMX_FMTSEL_VEC_OB	0x16
 
+#include "vfpu.h"
+
+#define VF_MASK_VT		0x7f
+#define VF_SH_VT		16
+#define VF_MASK_VS		0x7f
+#define VF_SH_VS		8
+#define VF_MASK_VD		0x7f
+#define VF_SH_VD		0
+#define VF_MASK_VML		0x1f
+#define VF_SH_VML		16
+#define VF_MASK_VMH		0x3
+#define VF_SH_VMH		0
+#define VF_MASK_VNL		0x1f
+#define VF_SH_VNL		16
+#define VF_MASK_VNH		0x1
+#define VF_SH_VNH		0
+#define VF_MASK_OFFSET		0x3fff
+#define VF_SH_OFFSET		2
+#define VF_MASK_CC		0xf
+#define VF_SH_CC		0
+#define VF_MASK_CONST		0x1f
+#define VF_SH_CONST		16
+#define VF_MASK_SCALE		0x1f
+#define VF_SH_SCALE		16
+#define VF_MASK_BCOND		0x7
+#define VF_SH_BCOND		18
+#define VF_MASK_MCOND		0x7
+#define VF_SH_MCOND		16
+#define VF_MASK_VCD		0xff
+#define VF_SH_VCD		0
+#define VF_MASK_VCS		0xff
+#define VF_SH_VCS		8
+#define VF_MASK_ROT		0x1f
+#define VF_SH_ROT		16
+#define VF_MASK_WRAP		0xff
+#define VF_SH_WRAP		16
+#define VF_MASK_TSIGN		0x1
+#define VF_SH_TSIGN		5
+#define VF_MASK_BMCOND		0x1f
+#define VF_SH_BMCOND		0
+#define VF_MASK_HFLOAT		0xffff
+#define VF_SH_HFLOAT		0
+#define VF_MASK_PFX		0xffffff
+#define VF_SH_PFX		0
+#define VF_MASK_RWB		0x1
+#define VF_SH_RWB		1
+
+#define	VF_MASK_PFX_SWZ		0x3
+#define	VF_SH_PFX_SWZ		0
+#define	VF_MASK_PFX_ABS		0x1
+#define	VF_SH_PFX_ABS		8
+#define	VF_MASK_PFX_CST		0x1
+#define	VF_SH_PFX_CST		12
+#define	VF_MASK_PFX_NEG		0x1
+#define	VF_SH_PFX_NEG		16
+#define	VF_MASK_PFX_SAT		0x3
+#define	VF_SH_PFX_SAT		0
+#define	VF_MASK_PFX_MSK		0x1
+#define	VF_SH_PFX_MSK		8
+
+#define	VF_MASK_ROT_COS		0x3
+#define	VF_SH_ROT_COS		0
+#define	VF_MASK_ROT_SIN		0x3
+#define	VF_SH_ROT_SIN		2
+#define	VF_MASK_ROT_NEG		0x1
+#define	VF_SH_ROT_NEG		4
+
+#define	VF_MASK_MR_MTX		0x7
+#define	VF_SH_MR_MTX		2
+#define	VF_MASK_MR_IDX		0x3
+#define	VF_SH_MR_IDX		0
+#define	VF_MASK_MR_FSL		0x3
+#define	VF_SH_MR_FSL		5
+#define	VF_MASK_MR_RXC		0x1
+#define	VF_SH_MR_RXC		5
+#define	VF_MASK_MR_VFSL		0x1
+#define	VF_SH_MR_VFSL		6
+
+#define	VF_MAX_MR_MTX		7
+#define	VF_MAX_MR_IDX		3
+#define	VF_MAX_MR_FSL		3
+#define	VF_MAX_MR_VIDX		1
+#define	VF_MAX_MR_VFSL		1
+
+#define	VF_MIN_MR		0
+#define	VF_MAX_MR		127
+#define	VF_MIN_CR		128
+#define	VF_MAX_CR		255
+#define	VF_MIN_VCR		128
+#define	VF_MAX_VCR		143
+#define	VF_MIN_CC		0
+#define	VF_MAX_CC		15
+#define	VF_MIN_CONST		1
+#define	VF_MAX_CONST		19
+#define	VF_MIN_SCALE		0
+#define	VF_MAX_SCALE		31
+#define	VF_MIN_BCOND		0
+#define	VF_MAX_BCOND		5
+#define	VF_MIN_MCOND		0
+#define	VF_MAX_MCOND		6
+#define	VF_MIN_WRAP		0
+#define	VF_MAX_WRAP		255
+#define	VF_MIN_ROT		0
+#define	VF_MAX_ROT		31
+#define	VF_MIN_TSIGN		0
+#define	VF_MAX_TSIGN		1
+#define	VF_MIN_BMCOND		0
+#define	VF_MAX_BMCOND		31
+#define	VF_MIN_HFLOAT		0
+#define	VF_MAX_HFLOAT		0xffff
+
+#define	VF_MASK_F32_SIGN	0x1
+#define	VF_SH_F32_SIGN		31
+#define	VF_MASK_F32_EXP		0xff
+#define	VF_SH_F32_EXP		23
+#define	VF_MASK_F32_FRA		0x7fffff
+#define	VF_SH_F32_FRA		0
+#define	VF_MASK_F16_SIGN	0x1
+#define	VF_SH_F16_SIGN		15
+#define	VF_MASK_F16_EXP		0x1f
+#define	VF_SH_F16_EXP		10
+#define	VF_MASK_F16_FRA		0x3ff
+#define	VF_SH_F16_FRA		0
+
+#define	VF_MIN_F32_EXP		0
+#define	VF_MAX_F32_EXP		255
+#define	VF_BIAS_F32_EXP		127
+#define	VF_MIN_F16_EXP		0
+#define	VF_MAX_F16_EXP		31
+#define	VF_BIAS_F16_EXP		15
+
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
+/* VFPU condition codes.  FL and TR accept no arguments, while any conditions
+   above and including EZ only accept one argument.  The rest require two
+   arguments.  */
+enum
+{
+  VFPU_COND_FL, VFPU_COND_EQ, VFPU_COND_LT, VFPU_COND_LE,
+  VFPU_COND_TR, VFPU_COND_NE, VFPU_COND_GE, VFPU_COND_GT,
+  VFPU_COND_EZ, VFPU_COND_EN, VFPU_COND_EI, VFPU_COND_ES,
+  VFPU_COND_NZ, VFPU_COND_NN, VFPU_COND_NI, VFPU_COND_NS,
+  VFPU_NUM_CONDS
+};
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
+#define VFPU_SH_PFX_SWZ_CSTLO	0
+#define VFPU_MASK_PFX_SWZ_CSTLO	0x3	/* Swizzle/Constant (bits 0-1). */
+#define VFPU_SH_PFX_MASK	8
+#define VFPU_MASK_PFX_MASK	0x1	/* Mask. */
+#define VFPU_SH_PFX_SAT		0
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
@@ -258,6 +480,29 @@
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
@@ -442,6 +687,8 @@
 #define INSN_5400		  0x01000000
 /* NEC VR5500 instruction.  */
 #define INSN_5500		  0x02000000
+/* Sony Allegrex instruction.  */
+#define INSN_ALLEGREX		  0x10000000
 
 /* MIPS ISA defines, use instead of hardcoding ISA level.  */
 
@@ -489,6 +736,7 @@
 #define CPU_MIPS64      64
 #define CPU_MIPS64R2	65
 #define CPU_SB1         12310201        /* octal 'SB', 01.  */
+#define CPU_ALLEGREX    10111431        /* octal 'AL', 31.  */
 
 /* Test for membership in an ISA including chip specific ISAs.  INSN
    is pointer to an element of the opcode table; ISA is the specified
@@ -510,6 +758,7 @@
      || (cpu == CPU_VR4120 && ((insn)->membership & INSN_4120) != 0)	\
      || (cpu == CPU_VR5400 && ((insn)->membership & INSN_5400) != 0)	\
      || (cpu == CPU_VR5500 && ((insn)->membership & INSN_5500) != 0)	\
+     || (cpu == CPU_ALLEGREX && ((insn)->membership & INSN_ALLEGREX) != 0)	\
      || 0)	/* Please keep this term for easier source merging.  */
 
 /* This is a list of macro expanded instructions.
@@ -622,9 +871,25 @@
   M_LI_DD,
   M_LI_S,
   M_LI_SS,
+  M_LVHI_S_SS,
+  M_LVHI_P_SS,
+  M_LVI_S_SS,
+  M_LVI_P_SS,
+  M_LVI_T_SS,
+  M_LVI_Q_SS,
   M_LL_AB,
   M_LLD_AB,
   M_LS_A,
+  M_LVHI_P,
+  M_LVHI_S,
+  M_LVI_P,
+  M_LVI_Q,
+  M_LVI_S,
+  M_LVI_T,
+  M_LVL_Q_AB,
+  M_LVR_Q_AB,
+  M_LV_Q_AB,
+  M_LV_Q_AB_2,
   M_LW_A,
   M_LW_AB,
   M_LWC0_A,
@@ -635,6 +900,7 @@
   M_LWC2_AB,
   M_LWC3_A,
   M_LWC3_AB,
+  M_LV_S_AB,
   M_LWL_A,
   M_LWL_AB,
   M_LWR_A,
@@ -714,6 +980,10 @@
   M_SUB_I,
   M_SUBU_I,
   M_SUBU_I_2,
+  M_SVL_Q_AB,
+  M_SV_Q_AB,
+  M_SVR_Q_AB,
+  M_SV_S_AB,
   M_TEQ_I,
   M_TGE_I,
   M_TGEU_I,
@@ -728,14 +998,24 @@
   M_ULH_A,
   M_ULHU,
   M_ULHU_A,
+  M_ULV_Q,
+  M_ULV_Q_AB,
+  M_ULV_S,
   M_ULW,
   M_ULW_A,
   M_USH,
   M_USH_A,
+  M_USV_Q,
+  M_USV_Q_AB,
+  M_USV_S,
   M_USW,
   M_USW_A,
   M_USD,
   M_USD_A,
+  M_VCMOV_P,
+  M_VCMOV_Q,
+  M_VCMOV_S,
+  M_VCMOV_T,
   M_XOR_I,
   M_COP0,
   M_COP1,
