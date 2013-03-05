diff --git parsekit.c parsekit.c
index cfc45e7..5ddd3a7 100644
--- parsekit.c
+++ parsekit.c
@@ -78,18 +78,18 @@ static void php_parsekit_parse_node(zval *return_value, zend_op_array *op_array,
 #ifdef IS_CV
 /* PHP >= 5.1 */
 	} else if (node->op_type == IS_CV) {
-		add_assoc_long(return_value, "var", node->u.var);
-		add_assoc_stringl(return_value, "varname", op_array->vars[node->u.var].name, op_array->vars[node->u.var].name_len, 1);
+		add_assoc_long(return_value, "var", node->u.op.var);
+		add_assoc_stringl(return_value, "varname", op_array->vars[node->u.op.var].name, op_array->vars[node->u.op.var].name_len, 1);
 #endif
 	} else {
 		/* IS_VAR || IS_TMP_VAR || IS_UNUSED */
 		char sop[(sizeof(void *) * 2) + 1];
 
-		snprintf(sop, (sizeof(void *) * 2) + 1, "%X", (unsigned int)node->u.var); 
+		snprintf(sop, (sizeof(void *) * 2) + 1, "%X", (unsigned int)node->u.op.var); 
 
 		if ((flags & PHP_PARSEKIT_VAR) ||
 			(options & PHP_PARSEKIT_ALL_ELEMENTS)) {
-			add_assoc_long(return_value, "var", node->u.var / sizeof(temp_variable));
+			add_assoc_long(return_value, "var", node->u.op.var / sizeof(temp_variable));
 		} else if (options & PHP_PARSEKIT_ALWAYS_SET) {
 			add_assoc_null(return_value, "var");
 		}
@@ -114,7 +114,7 @@ static void php_parsekit_parse_node(zval *return_value, zend_op_array *op_array,
 			(options & PHP_PARSEKIT_ALL_ELEMENTS)) {
 			add_assoc_string(return_value, "jmp_addr", sop, 1);
 			snprintf(sop, sizeof(sop)-1, "%u",
-					((unsigned int)((char*)node->u.var - (char*)op_array->opcodes))/sizeof(zend_op));
+					((unsigned int)((char*)node->u.op.var - (char*)op_array->opcodes))/sizeof(zend_op));
 			add_assoc_string(return_value, "jmp_offset", sop, 1); 
 		} else if (options & PHP_PARSEKIT_ALWAYS_SET) {
 			add_assoc_null(return_value, "jmp_addr");
@@ -123,9 +123,9 @@ static void php_parsekit_parse_node(zval *return_value, zend_op_array *op_array,
 
 		if ((flags & PHP_PARSEKIT_EA_TYPE) ||
 			(options & PHP_PARSEKIT_ALL_ELEMENTS)) {
-			add_assoc_long(return_value, "EA.type", node->u.EA.type);
+			add_assoc_long(return_value, "EA", node->EA);
 		} else if (options & PHP_PARSEKIT_ALWAYS_SET) {
-			add_assoc_null(return_value, "EA.type");
+			add_assoc_null(return_value, "EA");
 		}
 	}
 }
@@ -300,7 +300,7 @@ static void php_parsekit_parse_op_array(zval *return_value, zend_op_array *ops,
 	}
 	add_assoc_long(return_value, "num_args", ops->num_args);
 	add_assoc_long(return_value, "required_num_args", ops->required_num_args);
-	add_assoc_bool(return_value, "pass_rest_by_reference", ops->pass_rest_by_reference);
+	add_assoc_bool(return_value, "pass_rest_by_reference", ops->fn_flags & ZEND_ACC_PASS_REST_BY_REFERENCE);
 
 	if (ops->num_args && ops->arg_info) {
 		MAKE_STD_ZVAL(tmpzval);
@@ -374,15 +374,15 @@ static void php_parsekit_parse_op_array(zval *return_value, zend_op_array *ops,
 #endif
 /* ZE1 and ZE2 */
 
-	add_assoc_bool(return_value, "return_reference", ops->return_reference);
+	add_assoc_bool(return_value, "return_reference", ops->fn_flags & ZEND_ACC_RETURN_REFERENCE);
 	add_assoc_long(return_value, "refcount", *(ops->refcount));
 	add_assoc_long(return_value, "last", ops->last);
-	add_assoc_long(return_value, "size", ops->size);
+	add_assoc_long(return_value, "size", CG(context).opcodes_size);
 	add_assoc_long(return_value, "T", ops->T);
 	add_assoc_long(return_value, "last_brk_cont", ops->last_brk_cont);
-	add_assoc_long(return_value, "current_brk_cont", ops->current_brk_cont);
-	add_assoc_long(return_value, "backpatch_count", ops->backpatch_count);
-	add_assoc_bool(return_value, "done_pass_two", ops->done_pass_two);
+	add_assoc_long(return_value, "current_brk_cont", CG(context).current_brk_cont);
+	add_assoc_long(return_value, "backpatch_count", CG(context).backpatch_count);
+	add_assoc_bool(return_value, "done_pass_two", ops->fn_flags & ZEND_ACC_DONE_PASS_TWO);
 
 	if (ops->last_brk_cont > 0) {
 		MAKE_STD_ZVAL(tmpzval);
@@ -413,10 +413,10 @@ static void php_parsekit_parse_op_array(zval *return_value, zend_op_array *ops,
 		add_assoc_null(return_value, "static_variables");
 	}
 
-	if (ops->start_op) {
+	if (EG(start_op)) {
 		char sop[(sizeof(void *) * 2) + 1];
 
-		snprintf(sop, sizeof(sop), "%X", (unsigned int)ops->start_op); 
+		snprintf(sop, sizeof(sop), "%X", (unsigned int)EG(start_op));
 		add_assoc_string(return_value, "start_op", sop, 1);
 	} else if (options & PHP_PARSEKIT_ALWAYS_SET) {
 		add_assoc_null(return_value, "start_op");
@@ -431,7 +431,7 @@ static void php_parsekit_parse_op_array(zval *return_value, zend_op_array *ops,
 	/* Leave this last, it simplifies readability */
 	MAKE_STD_ZVAL(tmpzval);
 	array_init(tmpzval);
-	for(op = ops->opcodes, i = 0; op && i < ops->size; op++, i++) {
+	for(op = ops->opcodes, i = 0; op && i < CG(context).opcodes_size; op++, i++) {
 		zval *zop;
 
 		MAKE_STD_ZVAL(zop);
@@ -447,17 +447,17 @@ static void php_parsekit_parse_op_array(zval *return_value, zend_op_array *ops,
 static int php_parsekit_parse_node_simple(char **pret, zend_op_array *op_array, znode *node, zend_op_array *oparray TSRMLS_DC)
 {
 	if (node->op_type == IS_UNUSED) {
-		if (node->u.var) {
+		if (node->u.op.var) {
 #ifdef ZEND_ENGINE_2
-			if (node->u.jmp_addr >= oparray->opcodes &&
-				node->u.jmp_addr <= (oparray->opcodes + (sizeof(zend_op) * oparray->size))) 
+			if (node->u.op.jmp_addr >= oparray->opcodes &&
+				node->u.op.jmp_addr <= (oparray->opcodes + (sizeof(zend_op) * CG(context).opcodes_size)))
 			{
-				spprintf(pret, 0, "#%d", node->u.jmp_addr - oparray->opcodes);
+				spprintf(pret, 0, "#%d", node->u.op.jmp_addr - oparray->opcodes);
 			} 
 			else
 #endif
 			{
-				spprintf(pret, 0, "0x%X", node->u.var);
+				spprintf(pret, 0, "0x%X", node->u.op.var);
 			}
 			return 1;
 		} else {
@@ -514,7 +514,7 @@ static int php_parsekit_parse_node_simple(char **pret, zend_op_array *op_array,
 		}
 	}
 
-	spprintf(pret, 0, "T(%d)", node->u.var / sizeof(temp_variable));
+	spprintf(pret, 0, "T(%d)", node->u.op.var / sizeof(temp_variable));
 	return 1;
 }
 /* }}} */
@@ -528,7 +528,7 @@ static void php_parsekit_parse_op_array_simple(zval *return_value, zend_op_array
 
 	array_init(return_value);
 
-	for (op = ops->opcodes, i = 0; op && i < ops->size; op++, i++) {
+	for (op = ops->opcodes, i = 0; op && i < CG(context).opcodes_size; op++, i++) {
 		char *opline, *result, *op1, *op2;
 		int opline_len, freeit = 0;
 
@@ -633,7 +633,7 @@ static int php_parsekit_parse_class_entry(zval *return_value, zend_class_entry *
 	} else if (options & PHP_PARSEKIT_ALWAYS_SET) {
 		add_assoc_null(return_value, "parent");
 	}
-	add_assoc_bool(return_value, "constants_updated", ce->constants_updated);
+	add_assoc_bool(return_value, "constants_updated", ce->ce_flags & ZEND_ACC_CONSTANTS_UPDATED);
 #ifdef ZEND_ENGINE_2
 /* ZE2 class_entry members */
 	add_assoc_long(return_value, "ce_flags", ce->ce_flags);
@@ -691,12 +691,12 @@ static int php_parsekit_parse_class_entry(zval *return_value, zend_class_entry *
 		add_assoc_null(return_value, "properties_info");
 	}
 	
-	if (ce->static_members && zend_hash_num_elements(ce->static_members) > 0) {
+	if (ce->static_members_table && zend_hash_num_elements(ce->static_members_table) > 0) {
 		zval *tmp_zval;
 
 		MAKE_STD_ZVAL(tmpzval);
 		array_init(tmpzval);
-		zend_hash_copy(HASH_OF(tmpzval), ce->static_members, (copy_ctor_func_t) zval_add_ref, (void *) &tmp_zval, sizeof(zval *));	
+		zend_hash_copy(HASH_OF(tmpzval), ce->static_members_table, (copy_ctor_func_t) zval_add_ref, (void *) &tmp_zval, sizeof(zval *));
 		add_assoc_zval(return_value, "static_members", tmpzval);
 	} else if (options & PHP_PARSEKIT_ALWAYS_SET) {
 		add_assoc_null(return_value, "static_members");
@@ -724,11 +724,11 @@ static int php_parsekit_parse_class_entry(zval *return_value, zend_class_entry *
 		add_assoc_null(return_value, "interfaces");
 	}
 
-	add_assoc_string(return_value, "filename", ce->filename, 1);
-	add_assoc_long(return_value, "line_start", ce->line_start);
-	add_assoc_long(return_value, "line_end", ce->line_end);
-	if (ce->doc_comment) {
-		add_assoc_stringl(return_value, "doc_comment", ce->doc_comment, ce->doc_comment_len, 1);
+	add_assoc_string(return_value, "filename", ce->info.user.filename, 1);
+	add_assoc_long(return_value, "line_start", ce->info.user.line_start);
+	add_assoc_long(return_value, "line_end", ce->info.user.line_end);
+	if (ce->info.user.doc_comment) {
+		add_assoc_stringl(return_value, "doc_comment", ce->info.user.doc_comment, ce->info.user.doc_comment_len, 1);
 	} else if (options & PHP_PARSEKIT_ALWAYS_SET) {
 		add_assoc_null(return_value, "doc_comment");
 	}
@@ -757,12 +757,12 @@ static int php_parsekit_parse_class_entry(zval *return_value, zend_class_entry *
 		add_assoc_null(return_value, "function_table");
 	}
 
-	if (zend_hash_num_elements(&(ce->default_properties)) > 0) {
+	if (zend_hash_num_elements(&(ce->default_properties_table)) > 0) {
 		zval *tmp_zval;
 
 		MAKE_STD_ZVAL(tmpzval);
 		array_init(tmpzval);
-		zend_hash_copy(HASH_OF(tmpzval), &(ce->default_properties), (copy_ctor_func_t) zval_add_ref, (void *) &tmp_zval, sizeof(zval *));	
+		zend_hash_copy(HASH_OF(tmpzval), &(ce->default_properties_table), (copy_ctor_func_t) zval_add_ref, (void *) &tmp_zval, sizeof(zval *));	
 		add_assoc_zval(return_value, "default_properties", tmpzval);
 	} else if (options & PHP_PARSEKIT_ALWAYS_SET) {
 		add_assoc_null(return_value, "default_properties");
@@ -1131,7 +1131,7 @@ static unsigned char php_parsekit_second_arg_force_ref[] = { 3, BYREF_NONE, BYRE
 #endif
 
 /* {{{ function_entry */
-function_entry parsekit_functions[] = {
+zend_function_entry parsekit_functions[] = {
 	PHP_FE(parsekit_compile_string,			php_parsekit_second_arg_force_ref)
 	PHP_FE(parsekit_compile_file,			php_parsekit_second_arg_force_ref)
 	PHP_FE(parsekit_opcode_flags,			NULL)
