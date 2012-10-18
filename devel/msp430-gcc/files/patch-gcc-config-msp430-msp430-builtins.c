--- gcc/config/msp430/msp430-builtins.c	2012-09-26 12:24:42.000000000 +0800
+++ gcc/config/msp430/msp430-builtins.c	2012-09-26 12:28:31.000000000 +0800
@@ -59,6 +59,7 @@
   MSP430_BUILTIN_GET_WATCHDOG_CLEAR_VALUE,
   MSP430_BUILTIN_SET_WATCHDOG_CLEAR_VALUE,
   MSP430_BUILTIN_WATCHDOG_CLEAR,
+  MSP430_BUILTIN_EVEN_IN_RANGE,
   MSP430_BUILTIN_last_enum
 };
 
@@ -153,6 +154,13 @@
   add_builtin_function ("__watchdog_clear",
 			build_function_type_list (void_type_node, NULL_TREE),
 			MSP430_BUILTIN_WATCHDOG_CLEAR, BUILT_IN_MD, NULL, NULL_TREE);
+  add_builtin_function ("__even_in_range",
+			build_function_type_list (unsigned_type_node,
+						  unsigned_type_node,
+						  unsigned_type_node,
+						  NULL_TREE),
+			MSP430_BUILTIN_EVEN_IN_RANGE, BUILT_IN_MD,
+			NULL, NULL_TREE);
 }
 
 rtx
@@ -432,6 +440,30 @@
       emit_move_insn (retval, arg);
       insn = gen_bswaphi1 (retval);
       break;
+    case MSP430_BUILTIN_EVEN_IN_RANGE:
+      {
+	tree key_tree = CALL_EXPR_ARG (exp, 0);
+	tree limit_tree = CALL_EXPR_ARG (exp, 1);
+	rtx key;
+	HOST_WIDE_INT limit_val;
+	
+	need_insn = false;
+	if (!cst_and_fits_in_hwi (limit_tree)
+	    || (0 > ((limit_val = int_cst_value (limit_tree)))))
+	  {
+	    error
+	      ("__even_in_range second argument must be non-negative integer constant");
+	    break;
+	  }
+	key = expand_expr (key_tree, NULL_RTX, VOIDmode, EXPAND_NORMAL);
+	retval = gen_reg_rtx (HImode);
+	/* This is a stub.  To complete this, we need to attach notes
+	 * that assert that the value is, in fact, even and between 0
+	 * and the second argument.  No idea how to do that in a way
+	 * that gcc's tablejump will pay any attention to. */
+	emit_move_insn (retval, key);
+	break;
+      }
     }
 
   if (insn)
