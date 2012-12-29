--- ./test_helpers.c.orig	2010-10-25 15:05:08.000000000 +0800
+++ ./test_helpers.c	2012-10-08 17:41:40.355030000 +0800
@@ -102,14 +102,30 @@
 	case IS_CONST:
 		return &(node->u.constant);
 	case IS_VAR:
+#if ZEND_EXTENSION_API_NO >= 220100525
+		return EX_T(node->u.op.var).var.ptr;
+#else
 		return EX_T(node->u.var).var.ptr;
+#endif
 	case IS_TMP_VAR:
+#if ZEND_EXTENSION_API_NO >= 220100525
+		return (*freeval = &EX_T(node->u.op.var).tmp_var);
+#else
 		return (*freeval = &EX_T(node->u.var).tmp_var);
+#endif
 	case IS_CV:
 		{
+#if ZEND_EXTENSION_API_NO >= 220100525
+		zval ***ret = &execute_data->CVs[node->u.op.var];
+#else
 		zval ***ret = &execute_data->CVs[node->u.var];
+#endif
 		if (!*ret) {
+#if ZEND_EXTENSION_API_NO >= 220100525
+				zend_compiled_variable *cv = &EG(active_op_array)->vars[node->u.op.var];
+#else
 				zend_compiled_variable *cv = &EG(active_op_array)->vars[node->u.var];
+#endif
 				if (zend_hash_quick_find(EG(active_symbol_table), cv->name, cv->name_len+1, cv->hash_value, (void**)ret)==FAILURE) {
 					zend_error(E_NOTICE, "Undefined variable: %s", cv->name);
 					return &EG(uninitialized_zval);
@@ -165,7 +181,11 @@
 		}
 	}
 
+#if ZEND_EXTENSION_API_NO >= 220100525
+	old_ce = EX_T(opline->op1.var).class_entry;
+#else
 	old_ce = EX_T(opline->op1.u.var).class_entry;
+#endif
 
 	MAKE_STD_ZVAL(arg);
 	ZVAL_STRINGL(arg, old_ce->name, old_ce->name_length, 1);
@@ -189,7 +209,11 @@
 	zval_ptr_dtor(&retval);
 
 
+#if ZEND_EXTENSION_API_NO >= 220100525
+	EX_T(opline->op1.var).class_entry = *new_ce;
+#else
 	EX_T(opline->op1.u.var).class_entry = *new_ce;
+#endif
 
 	if (old_new_handler) {
 		return old_new_handler(ZEND_OPCODE_HANDLER_ARGS_PASSTHRU);
