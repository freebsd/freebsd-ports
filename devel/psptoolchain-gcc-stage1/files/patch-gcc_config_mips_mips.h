--- gcc/config/mips/mips.h.orig	2015-02-26 10:40:06 UTC
+++ gcc/config/mips/mips.h
@@ -231,6 +231,7 @@ struct mips_cpu_info {
 #define TARGET_SB1                  (mips_arch == PROCESSOR_SB1		\
 				     || mips_arch == PROCESSOR_SB1A)
 #define TARGET_SR71K                (mips_arch == PROCESSOR_SR71000)
+#define TARGET_ALLEGREX             (mips_arch == PROCESSOR_ALLEGREX)
 #define TARGET_XLP                  (mips_arch == PROCESSOR_XLP)
 
 /* Scheduling target defines.  */
@@ -260,6 +261,7 @@ struct mips_cpu_info {
 				     || mips_tune == PROCESSOR_OCTEON2)
 #define TUNE_SB1                    (mips_tune == PROCESSOR_SB1		\
 				     || mips_tune == PROCESSOR_SB1A)
+#define TUNE_ALLEGREX               (mips_tune == PROCESSOR_ALLEGREX)
 
 /* Whether vector modes and intrinsics for ST Microelectronics
    Loongson-2E/2F processors should be enabled.  In o32 pairs of
@@ -868,6 +870,9 @@ struct mips_cpu_info {
 				 && !TARGET_MIPS5900			\
 				 && !TARGET_MIPS16)
 
+/* ISA has just the integer condition move instructions (movn,movz) */
+#define ISA_HAS_INT_CONDMOVE   (TARGET_ALLEGREX)
+
 /* ISA has the mips4 FP condition code instructions: FP-compare to CC,
    branch on CC, and move (both FP and non-FP) on CC.  */
 #define ISA_HAS_8CC		(ISA_MIPS4				\
@@ -895,6 +900,7 @@ struct mips_cpu_info {
 
 /* ISA has conditional trap instructions.  */
 #define ISA_HAS_COND_TRAP	(!ISA_MIPS1				\
+				 && !TARGET_ALLEGREX				\
 				 && !TARGET_MIPS16)
 
 /* ISA has integer multiply-accumulate instructions, madd and msub.  */
@@ -938,6 +944,7 @@ struct mips_cpu_info {
 /* ISA has count leading zeroes/ones instruction (not implemented).  */
 #define ISA_HAS_CLZ_CLO		((ISA_MIPS32				\
 				  || ISA_MIPS32R2			\
+				  || TARGET_ALLEGREX		\
 				  || ISA_MIPS64				\
 				  || ISA_MIPS64R2)			\
 				 && !TARGET_MIPS16)
@@ -983,6 +990,7 @@ struct mips_cpu_info {
 				  || TARGET_MIPS5400			\
 				  || TARGET_MIPS5500			\
 				  || TARGET_SR71K			\
+				  || TARGET_ALLEGREX			\
 				  || TARGET_SMARTMIPS)			\
 				 && !TARGET_MIPS16)
 
@@ -1014,11 +1022,13 @@ struct mips_cpu_info {
 
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
 
@@ -1084,7 +1094,8 @@ struct mips_cpu_info {
 				 || ISA_MIPS64R2			\
 				 || TARGET_MIPS5500			\
 				 || TARGET_MIPS5900			\
-				 || TARGET_LOONGSON_2EF)
+				 || TARGET_LOONGSON_2EF		\
+				 || TARGET_ALLEGREX)
 
 /* ISA includes synci, jr.hb and jalr.hb.  */
 #define ISA_HAS_SYNCI ((ISA_MIPS32R2		\
@@ -2209,7 +2220,7 @@ enum reg_class
    `crtl->outgoing_args_size'.  */
 #define OUTGOING_REG_PARM_STACK_SPACE(FNTYPE) 1
 
-#define STACK_BOUNDARY (TARGET_NEWABI ? 128 : 64)
+#define STACK_BOUNDARY (mips_preferred_stack_boundary)
 
 /* Symbolic macros for the registers used to return integer and floating
    point values.  */
@@ -2321,7 +2332,7 @@ typedef struct mips_args {
 /* Treat LOC as a byte offset from the stack pointer and round it up
    to the next fully-aligned offset.  */
 #define MIPS_STACK_ALIGN(LOC) \
-  (TARGET_NEWABI ? ((LOC) + 15) & -16 : ((LOC) + 7) & -8)
+  (((LOC) + (mips_preferred_stack_align - 1)) & -(mips_preferred_stack_align))
 
 
 /* Output assembler code to FILE to increment profiler label # LABELNO
@@ -2936,6 +2947,9 @@ while (0)
 	.set pop\n\
 	" TEXT_SECTION_ASM_OP);
 #endif
+
+extern unsigned int mips_preferred_stack_boundary;
+extern unsigned int mips_preferred_stack_align;
 
 #ifndef HAVE_AS_TLS
 #define HAVE_AS_TLS 0
