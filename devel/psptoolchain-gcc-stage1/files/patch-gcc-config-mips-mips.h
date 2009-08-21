--- gcc/config/mips/mips.h.orig	2006-02-17 21:38:59.000000000 +0000
+++ gcc/config/mips/mips.h	2006-05-07 18:37:54.000000000 +0100
@@ -59,6 +59,7 @@
   PROCESSOR_R9000,
   PROCESSOR_SB1,
   PROCESSOR_SR71000,
+  PROCESSOR_ALLEGREX,
   PROCESSOR_MAX
 };
 
@@ -194,6 +195,7 @@
 #define TARGET_MIPS9000             (mips_arch == PROCESSOR_R9000)
 #define TARGET_SB1                  (mips_arch == PROCESSOR_SB1)
 #define TARGET_SR71K                (mips_arch == PROCESSOR_SR71000)
+#define TARGET_ALLEGREX             (mips_arch == PROCESSOR_ALLEGREX)
 
 /* Scheduling target defines.  */
 #define TUNE_MIPS3000               (mips_tune == PROCESSOR_R3000)
@@ -208,6 +210,7 @@
 #define TUNE_MIPS7000               (mips_tune == PROCESSOR_R7000)
 #define TUNE_MIPS9000               (mips_tune == PROCESSOR_R9000)
 #define TUNE_SB1                    (mips_tune == PROCESSOR_SB1)
+#define TUNE_ALLEGREX               (mips_tune == PROCESSOR_ALLEGREX)
 
 /* True if the pre-reload scheduler should try to create chains of
    multiply-add or multiply-subtract instructions.  For example,
@@ -578,6 +581,9 @@
                                  && !TARGET_MIPS5500                    \
 				 && !TARGET_MIPS16)
 
+/* ISA has just the integer condition move instructions (movn,movz) */
+#define ISA_HAS_INT_CONDMOVE	(TARGET_ALLEGREX)
+
 /* ISA has the mips4 FP condition code instructions: FP-compare to CC,
    branch on CC, and move (both FP and non-FP) on CC.  */
 #define ISA_HAS_8CC		(ISA_MIPS4				\
@@ -594,7 +600,8 @@
 
 /* ISA has conditional trap instructions.  */
 #define ISA_HAS_COND_TRAP	(!ISA_MIPS1				\
-				 && !TARGET_MIPS16)
+				 && !TARGET_MIPS16			\
+				 && !TARGET_ALLEGREX) 
 
 /* ISA has integer multiply-accumulate instructions, madd and msub.  */
 #define ISA_HAS_MADD_MSUB       ((ISA_MIPS32				\
@@ -612,6 +619,7 @@
 #define ISA_HAS_CLZ_CLO         ((ISA_MIPS32				\
                                   || ISA_MIPS32R2			\
                                   || ISA_MIPS64				\
+                                  || TARGET_ALLEGREX			\
                                  ) && !TARGET_MIPS16)
 
 /* ISA has double-word count leading zeroes/ones instruction (not
@@ -659,6 +667,7 @@
                                      || TARGET_MIPS5400                 \
                                      || TARGET_MIPS5500                 \
                                      || TARGET_SR71K                    \
+                                     || TARGET_ALLEGREX                 \
                                      ))
 
 /* ISA has 64-bit rotate right instruction.  */
@@ -692,11 +701,13 @@
 /* ISA includes the MIPS32r2 seb and seh instructions.  */
 #define ISA_HAS_SEB_SEH         (!TARGET_MIPS16                        \
                                  && (ISA_MIPS32R2                      \
+                                     || TARGET_ALLEGREX                \
                                      ))
 
 /* ISA includes the MIPS32/64 rev 2 ext and ins instructions.  */
 #define ISA_HAS_EXT_INS         (!TARGET_MIPS16                        \
                                  && (ISA_MIPS32R2                      \
+                                     || TARGET_ALLEGREX                \
                                      ))
 
 /* True if the result of a load is not available to the next instruction.
@@ -727,7 +738,8 @@
 #define ISA_HAS_HILO_INTERLOCKS	(ISA_MIPS32				\
 				 || ISA_MIPS32R2			\
 				 || ISA_MIPS64				\
-				 || TARGET_MIPS5500)
+				 || TARGET_MIPS5500			\
+				 || TARGET_ALLEGREX)
 
 /* Add -G xx support.  */
 
@@ -1143,6 +1155,11 @@
 #define CLZ_DEFINED_VALUE_AT_ZERO(MODE, VALUE) \
   ((VALUE) = GET_MODE_BITSIZE (MODE), true)
 
+/* The [d]clz instructions have the natural values at 0.  */
+
+#define CLZ_DEFINED_VALUE_AT_ZERO(MODE, VALUE) \
+  ((VALUE) = GET_MODE_BITSIZE (MODE), true)
+
 /* Standard register usage.  */
 
 /* Number of hardware registers.  We have:
