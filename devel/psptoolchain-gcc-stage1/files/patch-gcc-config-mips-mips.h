--- ./gcc/config/mips/mips.h.orig	2011-03-08 20:51:11.000000000 +0000
+++ ./gcc/config/mips/mips.h	2012-01-21 14:11:18.000000000 +0000
@@ -231,6 +231,7 @@
 #define TARGET_SB1                  (mips_arch == PROCESSOR_SB1		\
 				     || mips_arch == PROCESSOR_SB1A)
 #define TARGET_SR71K                (mips_arch == PROCESSOR_SR71000)
+#define TARGET_ALLEGREX             (mips_arch == PROCESSOR_ALLEGREX)
 
 /* Scheduling target defines.  */
 #define TUNE_20KC		    (mips_tune == PROCESSOR_20KC)
@@ -258,6 +259,7 @@
 #define TUNE_OCTEON		    (mips_tune == PROCESSOR_OCTEON)
 #define TUNE_SB1                    (mips_tune == PROCESSOR_SB1		\
 				     || mips_tune == PROCESSOR_SB1A)
+#define TUNE_ALLEGREX               (mips_tune == PROCESSOR_ALLEGREX)
 
 /* Whether vector modes and intrinsics for ST Microelectronics
    Loongson-2E/2F processors should be enabled.  In o32 pairs of
@@ -852,6 +854,9 @@
 /* ISA has LDC1 and SDC1.  */
 #define ISA_HAS_LDC1_SDC1	(!ISA_MIPS1 && !TARGET_MIPS16)
 
+/* ISA has just the integer condition move instructions (movn,movz) */
+#define ISA_HAS_INT_CONDMOVE   (TARGET_ALLEGREX)
+
 /* ISA has the mips4 FP condition code instructions: FP-compare to CC,
    branch on CC, and move (both FP and non-FP) on CC.  */
 #define ISA_HAS_8CC		(ISA_MIPS4				\
@@ -874,6 +879,7 @@
 
 /* ISA has conditional trap instructions.  */
 #define ISA_HAS_COND_TRAP	(!ISA_MIPS1				\
+				 && !TARGET_ALLEGREX				\
 				 && !TARGET_MIPS16)
 
 /* ISA has integer multiply-accumulate instructions, madd and msub.  */
@@ -910,6 +916,7 @@
 /* ISA has count leading zeroes/ones instruction (not implemented).  */
 #define ISA_HAS_CLZ_CLO		((ISA_MIPS32				\
 				  || ISA_MIPS32R2			\
+				  || TARGET_ALLEGREX		\
 				  || ISA_MIPS64				\
 				  || ISA_MIPS64R2)			\
 				 && !TARGET_MIPS16)
@@ -955,6 +962,7 @@
 				  || TARGET_MIPS5400			\
 				  || TARGET_MIPS5500			\
 				  || TARGET_SR71K			\
+				  || TARGET_ALLEGREX			\
 				  || TARGET_SMARTMIPS)			\
 				 && !TARGET_MIPS16)
 
@@ -984,11 +992,13 @@
 
 /* ISA includes the MIPS32r2 seb and seh instructions.  */
 #define ISA_HAS_SEB_SEH		((ISA_MIPS32R2		\
+				  || TARGET_ALLEGREX	\
 				  || ISA_MIPS64R2)	\
 				 && !TARGET_MIPS16)
 
 /* ISA includes the MIPS32/64 rev 2 ext and ins instructions.  */
 #define ISA_HAS_EXT_INS		((ISA_MIPS32R2		\
+				  || TARGET_ALLEGREX	\
 				  || ISA_MIPS64R2)	\
 				 && !TARGET_MIPS16)
 
@@ -1038,7 +1048,8 @@
 				 || ISA_MIPS64				\
 				 || ISA_MIPS64R2			\
 				 || TARGET_MIPS5500			\
-				 || TARGET_LOONGSON_2EF)
+				 || TARGET_LOONGSON_2EF		\
+				 || TARGET_ALLEGREX)
 
 /* ISA includes synci, jr.hb and jalr.hb.  */
 #define ISA_HAS_SYNCI ((ISA_MIPS32R2		\
@@ -2133,7 +2144,7 @@
    `crtl->outgoing_args_size'.  */
 #define OUTGOING_REG_PARM_STACK_SPACE(FNTYPE) 1
 
-#define STACK_BOUNDARY (TARGET_NEWABI ? 128 : 64)
+#define STACK_BOUNDARY (mips_preferred_stack_boundary)
 
 /* Symbolic macros for the registers used to return integer and floating
    point values.  */
@@ -2259,7 +2270,7 @@
 /* Treat LOC as a byte offset from the stack pointer and round it up
    to the next fully-aligned offset.  */
 #define MIPS_STACK_ALIGN(LOC) \
-  (TARGET_NEWABI ? ((LOC) + 15) & -16 : ((LOC) + 7) & -8)
+  (((LOC) + (mips_preferred_stack_align - 1)) & -(mips_preferred_stack_align))
 
 
 /* Output assembler code to FILE to increment profiler label # LABELNO
@@ -2911,6 +2922,9 @@
 #endif
 #endif
 
+extern unsigned int mips_preferred_stack_boundary;
+extern unsigned int mips_preferred_stack_align;
+
 #ifndef HAVE_AS_TLS
 #define HAVE_AS_TLS 0
 #endif
