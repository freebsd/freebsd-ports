--- main/php_variables.c.orig	2026-10-21 15:33:56 UTC
+++ main/php_variables.c
@@ -213,7 +213,7 @@ PHPAPI void php_register_variable_ex(const char *var_n
 			}
 
 			if (!index) {
-				array_init(&gpc_element);
+				array_init_singleton(&gpc_element);
 				if ((gpc_element_p = zend_hash_next_index_insert(symtable1, &gpc_element)) == NULL) {
 					zend_array_destroy(Z_ARR(gpc_element));
 					zval_ptr_dtor_nogc(val);
@@ -224,7 +224,7 @@ PHPAPI void php_register_variable_ex(const char *var_n
 				gpc_element_p = zend_symtable_str_find(symtable1, index, index_len);
 				if (!gpc_element_p) {
 					zval tmp;
-					array_init(&tmp);
+					array_init_singleton(&tmp);
 					gpc_element_p = zend_symtable_str_update_ind(symtable1, index, index_len, &tmp);
 				} else {
 					if (Z_TYPE_P(gpc_element_p) == IS_INDIRECT) {
@@ -232,7 +232,7 @@ PHPAPI void php_register_variable_ex(const char *var_n
 					}
 					if (Z_TYPE_P(gpc_element_p) != IS_ARRAY) {
 						zval_ptr_dtor_nogc(gpc_element_p);
-						array_init(gpc_element_p);
+						array_init_singleton(gpc_element_p);
 					} else {
 						SEPARATE_ARRAY(gpc_element_p);
 					}
@@ -424,7 +424,7 @@ SAPI_API SAPI_TREAT_DATA_FUNC(php_default_treat_data)
 		case PARSE_POST:
 		case PARSE_GET:
 		case PARSE_COOKIE:
-			array_init(&array);
+			array_init_singleton(&array);
 			switch (arg) {
 				case PARSE_POST:
 					zval_ptr_dtor_nogc(&PG(http_globals)[TRACK_VARS_POST]);
