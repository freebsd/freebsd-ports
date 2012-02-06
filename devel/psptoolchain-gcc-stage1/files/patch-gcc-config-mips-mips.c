--- ./gcc/config/mips/mips.c.orig	2011-05-29 17:48:14.000000000 +0000
+++ ./gcc/config/mips/mips.c	2012-01-21 14:11:18.000000000 +0000
@@ -239,7 +239,12 @@
   MIPS_BUILTIN_CMP_SINGLE,
 
   /* For generating bposge32 branch instructions in MIPS32 DSP ASE.  */
-  MIPS_BUILTIN_BPOSGE32
+  MIPS_BUILTIN_BPOSGE32,
+
+  /* The builtin corresponds to the ALLEGREX cache instruction.  Operand 0
+     is the function code (must be less than 32) and operand 1 is the base
+     address.  */
+  MIPS_BUILTIN_CACHE
 };
 
 /* Invoke MACRO (COND) for each C.cond.fmt condition.  */
@@ -516,6 +521,10 @@
    normal branch.  */
 static bool mips_branch_likely;
 
+/* Preferred stack boundary for proper stack vars alignment */
+unsigned int mips_preferred_stack_boundary;
+unsigned int mips_preferred_stack_align;
+
 /* The current instruction-set architecture.  */
 enum processor mips_arch;
 const struct mips_cpu_info *mips_arch_info;
@@ -691,6 +700,7 @@
 
   /* MIPS II processors.  */
   { "r6000", PROCESSOR_R6000, 2, 0 },
+  { "allegrex", PROCESSOR_ALLEGREX, 2, 0 },
 
   /* MIPS III processors.  */
   { "r4000", PROCESSOR_R4000, 3, 0 },
@@ -969,6 +979,9 @@
 		     1,           /* branch_cost */
 		     4            /* memory_latency */
   },
+  { /* Allegrex */
+    DEFAULT_COSTS
+  },
   { /* Loongson-2E */
     DEFAULT_COSTS
   },
@@ -12605,6 +12618,7 @@
 AVAIL_NON_MIPS16 (dspr2_32, !TARGET_64BIT && TARGET_DSPR2)
 AVAIL_NON_MIPS16 (loongson, TARGET_LOONGSON_VECTORS)
 AVAIL_NON_MIPS16 (cache, TARGET_CACHE_BUILTIN)
+AVAIL_NON_MIPS16 (allegrex, TARGET_ALLEGREX)
 
 /* Construct a mips_builtin_description from the given arguments.
 
@@ -12701,6 +12715,30 @@
   MIPS_BUILTIN (bposge, f, "bposge" #VALUE,				\
 		MIPS_BUILTIN_BPOSGE ## VALUE, MIPS_SI_FTYPE_VOID, AVAIL)
 
+/* Define a MIPS_BUILTIN_DIRECT function for instruction CODE_FOR_allegrex_<INSN>.
+   FUNCTION_TYPE and TARGET_FLAGS are builtin_description fields.  */
+#define DIRECT_ALLEGREX_BUILTIN(INSN, FUNCTION_TYPE, TARGET_FLAGS) \
+  { CODE_FOR_allegrex_ ## INSN, MIPS_FP_COND_f, "__builtin_allegrex_" #INSN,        \
+    MIPS_BUILTIN_DIRECT, FUNCTION_TYPE, mips_builtin_avail_allegrex }
+
+/* Same as the above, but mapped to an instruction that doesn't share the
+   NAME.  NAME is the name of the builtin without the builtin prefix.  */
+#define DIRECT_ALLEGREX_NAMED_BUILTIN(NAME, INSN, FUNCTION_TYPE, TARGET_FLAGS) \
+  { CODE_FOR_ ## INSN, MIPS_FP_COND_f, "__builtin_allegrex_" #NAME,             \
+    MIPS_BUILTIN_DIRECT, FUNCTION_TYPE, mips_builtin_avail_allegrex }
+
+/* Define a MIPS_BUILTIN_DIRECT_NO_TARGET function for instruction
+   CODE_FOR_allegrex_<INSN>.  FUNCTION_TYPE and TARGET_FLAGS are
+   builtin_description fields.  */
+#define DIRECT_ALLEGREX_NO_TARGET_BUILTIN(INSN, FUNCTION_TYPE, TARGET_FLAGS)   \
+  { CODE_FOR_allegrex_ ## INSN, MIPS_FP_COND_f, "__builtin_allegrex_" #INSN,            \
+    MIPS_BUILTIN_DIRECT_NO_TARGET, FUNCTION_TYPE, mips_builtin_avail_allegrex }
+
+/* Define a builtin with a specific function TYPE.  */
+#define SPECIAL_ALLEGREX_BUILTIN(TYPE, INSN, FUNCTION_TYPE, TARGET_FLAGS)  \
+  { CODE_FOR_allegrex_ ## INSN, MIPS_FP_COND_f, "__builtin_allegrex_" #INSN,            \
+    MIPS_BUILTIN_ ## TYPE, FUNCTION_TYPE, mips_builtin_avail_allegrex }
+
 /* Define a Loongson MIPS_BUILTIN_DIRECT function __builtin_loongson_<FN_NAME>
    for instruction CODE_FOR_loongson_<INSN>.  FUNCTION_TYPE is a
    builtin_description field.  */
@@ -12945,6 +12983,40 @@
   DIRECT_BUILTIN (dpsqx_s_w_ph, MIPS_DI_FTYPE_DI_V2HI_V2HI, dspr2_32),
   DIRECT_BUILTIN (dpsqx_sa_w_ph, MIPS_DI_FTYPE_DI_V2HI_V2HI, dspr2_32),
 
+/* Builtin functions for the Sony ALLEGREX processor.
+
+   These have the `__builtin_allegrex_' prefix instead of `__builtin_mips_'
+   to maintain compatibility with Sony's ALLEGREX GCC port.
+
+   Some of the builtins may seem redundant, but they are the same as the
+   builtins defined in the Sony compiler.  I chose to map redundant and
+   trivial builtins to the original instruction instead of creating
+   duplicate patterns specifically for the ALLEGREX (as Sony does).  */
+
+  DIRECT_ALLEGREX_BUILTIN(bitrev, MIPS_SI_FTYPE_SI, 0),
+  DIRECT_ALLEGREX_BUILTIN(wsbh, MIPS_SI_FTYPE_SI, 0),
+  DIRECT_ALLEGREX_NAMED_BUILTIN(wsbw, bswapsi2, MIPS_SI_FTYPE_SI, 0),
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
+  DIRECT_ALLEGREX_NAMED_BUILTIN(trunc_w_s, fix_truncsfsi2_insn, MIPS_SI_FTYPE_SF, 0),
+
   /* Builtin functions for ST Microelectronics Loongson-2E/2F cores.  */
   LOONGSON_BUILTIN (packsswh, MIPS_V4HI_FTYPE_V2SI_V2SI),
   LOONGSON_BUILTIN (packsshb, MIPS_V8QI_FTYPE_V4HI_V4HI),
@@ -13096,6 +13168,8 @@
 /* Standard mode-based argument types.  */
 #define MIPS_ATYPE_UQI unsigned_intQI_type_node
 #define MIPS_ATYPE_SI intSI_type_node
+#define MIPS_ATYPE_HI intHI_type_node
+#define MIPS_ATYPE_QI intQI_type_node
 #define MIPS_ATYPE_USI unsigned_intSI_type_node
 #define MIPS_ATYPE_DI intDI_type_node
 #define MIPS_ATYPE_UDI unsigned_intDI_type_node
@@ -13270,6 +13344,9 @@
 
   switch (opno)
     {
+    case 0:
+      emit_insn (GEN_FCN (icode) (0));
+      break;
     case 2:
       emit_insn (GEN_FCN (icode) (ops[0], ops[1]));
       break;
@@ -13439,6 +13516,28 @@
 				       const1_rtx, const0_rtx);
 }
 
+/* Expand a __builtin_allegrex_cache() function.  Make sure the passed
+   cache function code is less than 32.  */
+
+static rtx
+mips_expand_builtin_cache (enum insn_code icode, rtx target, tree exp)
+{
+  rtx op0, op1;
+
+  op0 = mips_prepare_builtin_arg (icode, 0, exp, 0);
+  op1 = mips_prepare_builtin_arg (icode, 1, exp, 1);
+
+  if (GET_CODE (op0) == CONST_INT)
+    if (INTVAL (op0) < 0 || INTVAL (op0) > 0x1f)
+      {
+   error ("invalid function code '%d'", INTVAL (op0));
+   return const0_rtx;
+      }
+
+  emit_insn (GEN_FCN (icode) (op0, op1));
+  return target;
+}
+
 /* Implement TARGET_EXPAND_BUILTIN.  */
 
 static rtx
@@ -13484,6 +13583,9 @@
 
     case MIPS_BUILTIN_BPOSGE32:
       return mips_expand_builtin_bposge (d->builtin_type, target);
+
+    case MIPS_BUILTIN_CACHE:
+      return mips_expand_builtin_cache (d->icode, target, exp);
     }
   gcc_unreachable ();
 }
@@ -15918,6 +16020,22 @@
      Do all CPP-sensitive stuff in non-MIPS16 mode; we'll switch to
      MIPS16 mode afterwards if need be.  */
   mips_set_mips16_mode (false);
+
+  /* Validate -mpreferred-stack-boundary= value, or provide default.
+     The default of 128-bit is for newABI else 64-bit.  */
+  mips_preferred_stack_boundary = (TARGET_NEWABI ? 128 : 64);
+  mips_preferred_stack_align = (TARGET_NEWABI ? 16 : 8);
+  if (mips_preferred_stack_boundary_string)
+    {
+      i = atoi (mips_preferred_stack_boundary_string);
+      if (i < 2 || i > 12)
+       error ("-mpreferred-stack-boundary=%d is not between 2 and 12", i);
+      else
+        {
+          mips_preferred_stack_align = (1 << i);
+          mips_preferred_stack_boundary = mips_preferred_stack_align * 8;
+        }
+    }
 }
 
 /* Implement TARGET_OPTION_OPTIMIZATION_TABLE.  */
