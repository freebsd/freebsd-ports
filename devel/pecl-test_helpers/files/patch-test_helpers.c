--- ./test_helpers.c.orig	2014-05-16 23:36:31.000000000 +0800
+++ ./test_helpers.c	2014-05-16 23:36:38.000000000 +0800
@@ -92,37 +92,69 @@
 
 #undef EX
 #define EX(element) execute_data->element
-#define EX_T(offset) (*(temp_variable *)((char *) EX(Ts) + offset))
 
-static zval *pth_get_zval_ptr(znode *node, zval **freeval, zend_execute_data *execute_data TSRMLS_DC) /* {{{ */
+#if PHP_VERSION_ID >= 50500
+# define EX_T(offset) (*EX_TMP_VAR(execute_data, offset))
+#else
+# define EX_T(offset) (*(temp_variable *)((char*)execute_data->Ts + offset))
+#endif
+
+#if PHP_VERSION_ID >= 50399
+# define PTH_ZNODE znode_op
+# define PTH_TYPE(t) t##_type
+#else
+# define PTH_ZNODE znode
+# define PTH_TYPE(t) t.op_type
+#endif
+
+zval *pth_get_zval_ptr(int node_type, PTH_ZNODE *node, zval **freeval, zend_execute_data *execute_data TSRMLS_DC)
 {
 	*freeval = NULL;
 
-	switch (node->op_type) {
-	case IS_CONST:
-		return &(node->u.constant);
-	case IS_VAR:
-		return EX_T(node->u.var).var.ptr;
-	case IS_TMP_VAR:
-		return (*freeval = &EX_T(node->u.var).tmp_var);
-	case IS_CV:
-		{
-		zval ***ret = &execute_data->CVs[node->u.var];
-		if (!*ret) {
-				zend_compiled_variable *cv = &EG(active_op_array)->vars[node->u.var];
-				if (zend_hash_quick_find(EG(active_symbol_table), cv->name, cv->name_len+1, cv->hash_value, (void**)ret)==FAILURE) {
-					zend_error(E_NOTICE, "Undefined variable: %s", cv->name);
-					return &EG(uninitialized_zval);
-				}
-		}
-		return **ret;
+	switch (node_type) {
+		case IS_CONST:
+#if PHP_VERSION_ID >= 50399
+			return node->zv;
+#else
+			return &node->u.constant;
+#endif
+			break;
+
+		case IS_VAR:
+#if PHP_VERSION_ID >= 50399
+			if (EX_T(node->var).var.ptr) {
+				return EX_T(node->var).var.ptr;
+#else
+			if (EX_T(node->u.var).var.ptr) {
+				return EX_T(node->u.var).var.ptr;
+#endif
+			}
+			break;
+
+		case IS_TMP_VAR:
+#if PHP_VERSION_ID >= 50399
+			return (*freeval = &EX_T(node->var).tmp_var);
+#else
+			return (*freeval = &EX_T(node->u.var).tmp_var);
+#endif
+			break;
+
+		case IS_CV: {
+			zval **tmp;
+#if PHP_VERSION_ID >= 50399
+			tmp = zend_get_compiled_variable_value(execute_data, node->constant);
+#else
+			tmp = zend_get_compiled_variable_value(execute_data, node->u.constant.value.lval);
+#endif
+			if (tmp) {
+				return *tmp;
+			}
+			break;
 		}
-	case IS_UNUSED:
-	default:
-		return NULL;
 	}
+
+	return NULL;
 }
-/* }}} */
 
 static void test_helpers_free_handler(zend_fcall_info *fci) /* {{{ */
 {
@@ -165,7 +197,11 @@
 		}
 	}
 
+#if ZEND_EXTENSION_API_NO >= 220100525
+	old_ce = EX_T(opline->op1.var).class_entry;
+#else
 	old_ce = EX_T(opline->op1.u.var).class_entry;
+#endif
 
 	MAKE_STD_ZVAL(arg);
 	ZVAL_STRINGL(arg, old_ce->name, old_ce->name_length, 1);
@@ -189,7 +225,11 @@
 	zval_ptr_dtor(&retval);
 
 
+#if ZEND_EXTENSION_API_NO >= 220100525
+	EX_T(opline->op1.var).class_entry = *new_ce;
+#else
 	EX_T(opline->op1.u.var).class_entry = *new_ce;
+#endif
 
 	if (old_new_handler) {
 		return old_new_handler(ZEND_OPCODE_HANDLER_ARGS_PASSTHRU);
@@ -202,6 +242,7 @@
 static int pth_exit_handler(ZEND_OPCODE_HANDLER_ARGS) /* {{{ */
 {
 	zval *msg, *freeop;
+	zend_op *opline = EX(opline);
 	zval *retval;
 
 	if (THG(exit_fci).function_name == NULL) {
@@ -212,7 +253,7 @@
 		}
 	}
 
-	msg = pth_get_zval_ptr(&EX(opline)->op1, &freeop, execute_data TSRMLS_CC);
+	msg = pth_get_zval_ptr(opline->PTH_TYPE(op1), &opline->op1, &freeop, execute_data TSRMLS_CC);
 
 	if (msg) {
 		zend_fcall_info_argn(&THG(exit_fci) TSRMLS_CC, 1, &msg);
