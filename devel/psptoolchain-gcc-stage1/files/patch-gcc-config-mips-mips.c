--- gcc/config/mips/mips.c.orig	2005-12-09 08:15:58.000000000 +0000
+++ gcc/config/mips/mips.c	2006-05-07 18:37:50.000000000 +0100
@@ -179,6 +179,12 @@
   MIPS_VOID_FTYPE_V2HI_V2HI,
   MIPS_VOID_FTYPE_V4QI_V4QI,
 
+  /* For the Sony ALLEGREX.  */
+  MIPS_SI_FTYPE_QI,
+  MIPS_SI_FTYPE_HI,
+  MIPS_VOID_FTYPE_VOID,
+  MIPS_SI_FTYPE_SF,
+
   /* The last type.  */
   MIPS_MAX_FTYPE_MAX
 };
@@ -220,6 +226,11 @@
   /* As above, but the instruction only sets a single $fcc register.  */
   MIPS_BUILTIN_CMP_SINGLE,
 
+   /* The builtin corresponds to the ALLEGREX cache instruction.  Operand 0
+      is the function code (must be less than 32) and operand 1 is the base
+      address.  */
+   MIPS_BUILTIN_CACHE,
+
   /* For generating bposge32 branch instructions in MIPS32 DSP ASE.  */
   MIPS_BUILTIN_BPOSGE32
 };
@@ -405,6 +416,7 @@
 static rtx mips_expand_builtin_compare (enum mips_builtin_type,
 					enum insn_code, enum mips_fp_condition,
 					rtx, tree);
+static rtx mips_expand_builtin_cache (enum insn_code icode, rtx, tree);
 static rtx mips_expand_builtin_bposge (enum mips_builtin_type, rtx);
 static void mips_encode_section_info (tree, rtx, int);
 
@@ -721,6 +733,7 @@
 
   /* MIPS II */
   { "r6000", PROCESSOR_R6000, 2 },
+  { "allegrex", PROCESSOR_ALLEGREX, 2 },
 
   /* MIPS III */
   { "r4000", PROCESSOR_R4000, 3 },
@@ -10169,6 +10182,67 @@
   BPOSGE_BUILTIN (32, MASK_DSP)
 };
 
+/* Builtin functions for the Sony ALLEGREX processor.
+
+   These have the `__builtin_allgrex_' prefix instead of `__builtin_mips_'
+   to maintain compatibility with Sony's ALLEGREX GCC port.
+
+   Some of the builtins may seem redundant, but they are the same as the
+   builtins defined in the Sony compiler.  I chose to map redundant and
+   trivial builtins to the original instruction instead of creating
+   duplicate patterns specifically for the ALLEGREX (as Sony does).  */
+
+/* Define a MIPS_BUILTIN_DIRECT function for instruction CODE_FOR_allegrex_<INSN>.
+   FUNCTION_TYPE and TARGET_FLAGS are builtin_description fields.  */
+#define DIRECT_ALLEGREX_BUILTIN(INSN, FUNCTION_TYPE, TARGET_FLAGS)	\
+  { CODE_FOR_allegrex_ ## INSN, 0, "__builtin_allegrex_" #INSN,		\
+    MIPS_BUILTIN_DIRECT, FUNCTION_TYPE, TARGET_FLAGS }
+
+/* Same as the above, but mapped to an instruction that doesn't share the
+   NAME.  NAME is the name of the builtin without the builtin prefix.  */
+#define DIRECT_ALLEGREX_NAMED_BUILTIN(NAME, INSN, FUNCTION_TYPE, TARGET_FLAGS)	\
+  { CODE_FOR_ ## INSN, 0, "__builtin_allegrex_" #NAME,				\
+    MIPS_BUILTIN_DIRECT, FUNCTION_TYPE, TARGET_FLAGS }
+
+/* Define a MIPS_BUILTIN_DIRECT_NO_TARGET function for instruction
+   CODE_FOR_allegrex_<INSN>.  FUNCTION_TYPE and TARGET_FLAGS are
+   builtin_description fields.  */
+#define DIRECT_ALLEGREX_NO_TARGET_BUILTIN(INSN, FUNCTION_TYPE, TARGET_FLAGS)	\
+  { CODE_FOR_allegrex_ ## INSN, 0, "__builtin_allegrex_" #INSN,			\
+    MIPS_BUILTIN_DIRECT_NO_TARGET, FUNCTION_TYPE, TARGET_FLAGS }
+
+/* Define a builtin with a specific function TYPE.  */
+#define SPECIAL_ALLEGREX_BUILTIN(TYPE, INSN, FUNCTION_TYPE, TARGET_FLAGS)	\
+  { CODE_FOR_allegrex_ ## INSN, 0, "__builtin_allegrex_" #INSN,			\
+    MIPS_BUILTIN_ ## TYPE, FUNCTION_TYPE, TARGET_FLAGS }
+
+static const struct builtin_description allegrex_bdesc[] =
+{
+  DIRECT_ALLEGREX_BUILTIN(bitrev, MIPS_SI_FTYPE_SI, 0),
+  DIRECT_ALLEGREX_BUILTIN(wsbh, MIPS_SI_FTYPE_SI, 0),
+  DIRECT_ALLEGREX_BUILTIN(wsbw, MIPS_SI_FTYPE_SI, 0),
+  DIRECT_ALLEGREX_NAMED_BUILTIN(clz, clzsi2, MIPS_SI_FTYPE_SI, 0),
+  DIRECT_ALLEGREX_BUILTIN(clo, MIPS_SI_FTYPE_SI, 0),
+  DIRECT_ALLEGREX_NAMED_BUILTIN(ctz, ctzsi2, MIPS_SI_FTYPE_SI, 0),
+  DIRECT_ALLEGREX_BUILTIN(cto, MIPS_SI_FTYPE_SI, 0),
+  DIRECT_ALLEGREX_NAMED_BUILTIN(rotr, rotrsi3, MIPS_SI_FTYPE_SI_SI, 0),
+  DIRECT_ALLEGREX_NAMED_BUILTIN(rotl, rotlsi3, MIPS_SI_FTYPE_SI_SI, 0),
+
+  DIRECT_ALLEGREX_NAMED_BUILTIN(seb, extendqisi2, MIPS_SI_FTYPE_QI, 0),
+  DIRECT_ALLEGREX_NAMED_BUILTIN(seh, extendhisi2, MIPS_SI_FTYPE_HI, 0),
+  DIRECT_ALLEGREX_NAMED_BUILTIN(max, smaxsi3, MIPS_SI_FTYPE_SI_SI, 0),
+  DIRECT_ALLEGREX_NAMED_BUILTIN(min, sminsi3, MIPS_SI_FTYPE_SI_SI, 0),
+
+  DIRECT_ALLEGREX_NO_TARGET_BUILTIN(sync, MIPS_VOID_FTYPE_VOID, 0),
+  SPECIAL_ALLEGREX_BUILTIN(CACHE, cache, MIPS_VOID_FTYPE_SI_SI, 0),
+
+  DIRECT_ALLEGREX_NAMED_BUILTIN(sqrt_s, sqrtsf2, MIPS_SF_FTYPE_SF, 0),
+  DIRECT_ALLEGREX_BUILTIN(ceil_w_s, MIPS_SI_FTYPE_SF, 0),
+  DIRECT_ALLEGREX_BUILTIN(floor_w_s, MIPS_SI_FTYPE_SF, 0),
+  DIRECT_ALLEGREX_BUILTIN(round_w_s, MIPS_SI_FTYPE_SF, 0),
+  DIRECT_ALLEGREX_NAMED_BUILTIN(trunc_w_s, fix_truncsfsi2_insn, MIPS_SI_FTYPE_SF, 0)
+};
+
 /* This helps provide a mapping from builtin function codes to bdesc
    arrays.  */
 
@@ -10189,6 +10263,7 @@
 {
   { mips_bdesc, ARRAY_SIZE (mips_bdesc), PROCESSOR_MAX },
   { sb1_bdesc, ARRAY_SIZE (sb1_bdesc), PROCESSOR_SB1 },
+  { allegrex_bdesc, ARRAY_SIZE (allegrex_bdesc), PROCESSOR_ALLEGREX },
   { dsp_bdesc, ARRAY_SIZE (dsp_bdesc), PROCESSOR_MAX }
 };
 
@@ -10292,6 +10367,9 @@
     case MIPS_BUILTIN_BPOSGE32:
       return mips_expand_builtin_bposge (type, target);
 
+    case MIPS_BUILTIN_CACHE:
+      return mips_expand_builtin_cache (icode, target, arglist);
+
     default:
       return 0;
     }
@@ -10310,8 +10388,8 @@
   tree V4QI_type_node;
   unsigned int offset;
 
-  /* We have only builtins for -mpaired-single, -mips3d and -mdsp.  */
-  if (!TARGET_PAIRED_SINGLE_FLOAT && !TARGET_DSP)
+  /* We have only builtins for -mpaired-single, -mips3d and -mdsp and the Sony ALLEGREX.  */
+  if (!TARGET_PAIRED_SINGLE_FLOAT && !TARGET_DSP && !TARGET_ALLEGREX)
     return;
 
   if (TARGET_PAIRED_SINGLE_FLOAT)
@@ -10376,6 +10454,44 @@
 				    double_type_node, double_type_node, NULL_TREE);
     }
 
+   if (TARGET_ALLEGREX)
+     {
+       types[MIPS_SI_FTYPE_QI]
+ 	= build_function_type_list (intSI_type_node,
+ 				    intQI_type_node,
+ 				    NULL_TREE);
+ 
+       types[MIPS_SI_FTYPE_HI]
+ 	= build_function_type_list (intSI_type_node,
+ 				    intHI_type_node,
+ 				    NULL_TREE);
+ 
+       types[MIPS_SI_FTYPE_SI]
+ 	= build_function_type_list (intSI_type_node,
+ 				    intSI_type_node,
+ 				    NULL_TREE);
+ 
+       types[MIPS_SI_FTYPE_SI_SI]
+ 	= build_function_type_list (intSI_type_node,
+ 				    intSI_type_node, intSI_type_node,
+ 				    NULL_TREE);
+ 
+       types[MIPS_VOID_FTYPE_VOID]
+ 	= build_function_type_list (void_type_node, void_type_node, NULL_TREE);
+ 
+       types[MIPS_VOID_FTYPE_SI_SI]
+ 	= build_function_type_list (void_type_node,
+ 				    intSI_type_node, intSI_type_node, NULL_TREE);
+ 
+       types[MIPS_SF_FTYPE_SF]
+ 	= build_function_type_list (float_type_node,
+ 				    float_type_node, NULL_TREE);
+ 
+       types[MIPS_SI_FTYPE_SF]
+ 	= build_function_type_list (intSI_type_node,
+ 				    float_type_node, NULL_TREE);
+     }
+
   if (TARGET_DSP)
     {
       V2HI_type_node = build_vector_type_for_mode (intHI_type_node, V2HImode);
@@ -10557,6 +10673,10 @@
 
   switch (i)
     {
+     case 0:
+       emit_insn (GEN_FCN (icode) (0));
+       break;
+
     case 2:
       emit_insn (GEN_FCN (icode) (ops[0], ops[1]));
       break;
@@ -10767,4 +10887,26 @@
     }
 }
 
+/* Expand a __builtin_allegrex_cache() function.  Make sure the passed
+   cache function code is less than 32.  */
+
+static rtx
+mips_expand_builtin_cache (enum insn_code icode, rtx target, tree arglist)
+{
+  rtx op0, op1;
+
+  op0 = mips_prepare_builtin_arg (icode, 0, &arglist);
+  op1 = mips_prepare_builtin_arg (icode, 1, &arglist);
+
+  if (GET_CODE (op0) == CONST_INT)
+    if (INTVAL (op0) < 0 || INTVAL (op0) > 0x1f)
+      {
+	error ("invalid function code '%d'", INTVAL (op0));
+	return const0_rtx;
+      }
+
+  emit_insn (GEN_FCN (icode) (op0, op1));
+  return target;
+}
+
 #include "gt-mips.h"
