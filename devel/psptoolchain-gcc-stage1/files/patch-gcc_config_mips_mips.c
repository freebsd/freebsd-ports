--- gcc/config/mips/mips.c.orig	2014-03-08 09:27:23 UTC
+++ gcc/config/mips/mips.c
@@ -248,7 +248,12 @@ enum mips_builtin_type {
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
@@ -574,6 +579,10 @@ struct mips_asm_switch mips_noat = { "at", 0 };
    normal branch.  */
 static bool mips_branch_likely;
 
+/* Preferred stack boundary for proper stack vars alignment */
+unsigned int mips_preferred_stack_boundary;
+unsigned int mips_preferred_stack_align;
+
 /* The current instruction-set architecture.  */
 enum processor mips_arch;
 const struct mips_cpu_info *mips_arch_info;
@@ -919,6 +928,9 @@ static const struct mips_rtx_cost_data
 		     1,           /* branch_cost */
 		     4            /* memory_latency */
   },
+  { /* Allegrex */
+    DEFAULT_COSTS
+  },
   { /* Loongson-2E */
     DEFAULT_COSTS
   },
@@ -13780,6 +13792,7 @@ AVAIL_NON_MIPS16 (dsp_64, TARGET_64BIT && TARGET_DSP)
 AVAIL_NON_MIPS16 (dspr2_32, !TARGET_64BIT && TARGET_DSPR2)
 AVAIL_NON_MIPS16 (loongson, TARGET_LOONGSON_VECTORS)
 AVAIL_NON_MIPS16 (cache, TARGET_CACHE_BUILTIN)
+AVAIL_NON_MIPS16 (allegrex, TARGET_ALLEGREX)
 
 /* Construct a mips_builtin_description from the given arguments.
 
@@ -13876,6 +13889,30 @@ AVAIL_NON_MIPS16 (cache, TARGET_CACHE_BUILTIN)
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
@@ -14122,6 +14159,38 @@ static const struct mips_builtin_description mips_buil
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
@@ -14273,6 +14342,8 @@ mips_build_cvpointer_type (void)
 /* Standard mode-based argument types.  */
 #define MIPS_ATYPE_UQI unsigned_intQI_type_node
 #define MIPS_ATYPE_SI intSI_type_node
+#define MIPS_ATYPE_HI intHI_type_node
+#define MIPS_ATYPE_QI intQI_type_node
 #define MIPS_ATYPE_USI unsigned_intSI_type_node
 #define MIPS_ATYPE_DI intDI_type_node
 #define MIPS_ATYPE_UDI unsigned_intDI_type_node
@@ -14575,6 +14646,26 @@ mips_expand_builtin_bposge (enum mips_builtin_type bui
 				       const1_rtx, const0_rtx);
 }
 
+/* Expand a __builtin_allegrex_cache() function.  Make sure the passed
+   cache function code is less than 32.  */
+
+static rtx
+mips_expand_builtin_cache (enum insn_code icode, rtx target, tree exp)
+{
+  int argno;
+  struct expand_operand ops[2];
+
+  for (argno = 0; argno < 2; argno++)
+    mips_prepare_builtin_arg (&ops[argno], exp, argno);
+
+  if (GET_CODE(ops[0].value) != CONST_INT ||
+      INTVAL(ops[0].value) < 0 || INTVAL(ops[0].value) > 0x1f)
+    error("Invalid first argument for cache builtin (0 <= arg <= 31)");
+
+  emit_insn(mips_expand_builtin_insn (icode, 2, ops, false));
+  return target;
+}
+
 /* Implement TARGET_EXPAND_BUILTIN.  */
 
 static rtx
@@ -14620,6 +14711,9 @@ mips_expand_builtin (tree exp, rtx target, rtx subtarg
 
     case MIPS_BUILTIN_BPOSGE32:
       return mips_expand_builtin_bposge (d->builtin_type, target);
+
+    case MIPS_BUILTIN_CACHE:
+      return mips_expand_builtin_cache (d->icode, target, exp);
     }
   gcc_unreachable ();
 }
@@ -17376,6 +17470,22 @@ mips_option_override (void)
 
   if (TARGET_HARD_FLOAT_ABI && TARGET_MIPS5900)
     REAL_MODE_FORMAT (SFmode) = &spu_single_format;
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
 
 /* Swap the register information for registers I and I + 1, which
