--- ext/standard/string.c.orig	2011/04/13 03:32:19
+++ ext/standard/string.c	2011/04/13 06:32:41
@@ -2352,20 +2352,35 @@
 
 		zend_hash_internal_pointer_reset_ex(Z_ARRVAL_PP(str), &pos_str);
 		while (zend_hash_get_current_data_ex(Z_ARRVAL_PP(str), (void **) &tmp_str, &pos_str) == SUCCESS) {
-			convert_to_string_ex(tmp_str);
+			zval *orig_str;
+			zval dummy;
+			if(Z_TYPE_PP(tmp_str) != IS_STRING) {
+				dummy = **tmp_str;
+				orig_str = &dummy;
+				zval_copy_ctor(orig_str);
+				convert_to_string(orig_str);
+			} else {
+				orig_str = *tmp_str;
+			}
 
 			if (Z_TYPE_PP(from) == IS_ARRAY) {
 				if (SUCCESS == zend_hash_get_current_data_ex(Z_ARRVAL_PP(from), (void **) &tmp_from, &pos_from)) {
-					convert_to_long_ex(tmp_from);
+					if(Z_TYPE_PP(tmp_from) != IS_LONG) {
+						zval dummy = **tmp_from;
+						zval_copy_ctor(&dummy);
+						convert_to_long(&dummy);
+						f = Z_LVAL(dummy);
+					} else {
+						f = Z_LVAL_PP(tmp_from);
+					}
 
-					f = Z_LVAL_PP(tmp_from);
 					if (f < 0) {
-						f = Z_STRLEN_PP(tmp_str) + f;
+						f = Z_STRLEN_P(orig_str) + f;
 						if (f < 0) {
 							f = 0;
 						}
-					} else if (f > Z_STRLEN_PP(tmp_str)) {
-						f = Z_STRLEN_PP(tmp_str);
+					} else if (f > Z_STRLEN_P(orig_str)) {
+						f = Z_STRLEN_P(orig_str);
 					}
 					zend_hash_move_forward_ex(Z_ARRVAL_PP(from), &pos_from);
 				} else {
@@ -2374,72 +2389,94 @@
 			} else {
 				f = Z_LVAL_PP(from);
 				if (f < 0) {
-					f = Z_STRLEN_PP(tmp_str) + f;
+					f = Z_STRLEN_P(orig_str) + f;
 					if (f < 0) {
 						f = 0;
 					}
-				} else if (f > Z_STRLEN_PP(tmp_str)) {
-					f = Z_STRLEN_PP(tmp_str);
+				} else if (f > Z_STRLEN_P(orig_str)) {
+					f = Z_STRLEN_P(orig_str);
 				}
 			}
 
 			if (argc > 3 && Z_TYPE_PP(len) == IS_ARRAY) {
 				if (SUCCESS == zend_hash_get_current_data_ex(Z_ARRVAL_PP(len), (void **) &tmp_len, &pos_len)) {
-					convert_to_long_ex(tmp_len);
+					if(Z_TYPE_PP(tmp_len) != IS_LONG) {
+						zval dummy = **tmp_len;
+						zval_copy_ctor(&dummy);
+						convert_to_long(&dummy);
+						l = Z_LVAL(dummy);
+					} else {
+						l = Z_LVAL_PP(tmp_len);
+					}
 
 					l = Z_LVAL_PP(tmp_len);
 					zend_hash_move_forward_ex(Z_ARRVAL_PP(len), &pos_len);
 				} else {
-					l = Z_STRLEN_PP(tmp_str);
+					l = Z_STRLEN_P(orig_str);
 				}
 			} else if (argc > 3) { 
 				l = Z_LVAL_PP(len);
 			} else {
-				l = Z_STRLEN_PP(tmp_str);
+				l = Z_STRLEN_P(orig_str);
 			}
 
 			if (l < 0) {
-				l = (Z_STRLEN_PP(tmp_str) - f) + l;
+				l = (Z_STRLEN_P(orig_str) - f) + l;
 				if (l < 0) {
 					l = 0;
 				}
 			}
 
-			if ((f + l) > Z_STRLEN_PP(tmp_str)) {
-				l = Z_STRLEN_PP(tmp_str) - f;
+			if ((f + l) > Z_STRLEN_P(orig_str)) {
+				l = Z_STRLEN_P(orig_str) - f;
 			}
 
-			result_len = Z_STRLEN_PP(tmp_str) - l;
+			result_len = Z_STRLEN_P(orig_str) - l;
 
 			if (Z_TYPE_PP(repl) == IS_ARRAY) {
 				if (SUCCESS == zend_hash_get_current_data_ex(Z_ARRVAL_PP(repl), (void **) &tmp_repl, &pos_repl)) {
-					convert_to_string_ex(tmp_repl);
-					result_len += Z_STRLEN_PP(tmp_repl);
+					zval *repl_str;
+					zval zrepl;
+					if(Z_TYPE_PP(tmp_repl) != IS_STRING) {
+						zrepl = **tmp_repl;
+						repl_str = &zrepl;
+						zval_copy_ctor(repl_str);
+						convert_to_string(repl_str);
+					} else {
+						repl_str = *tmp_repl;
+					}
+
+					result_len += Z_STRLEN_P(repl_str);
 					zend_hash_move_forward_ex(Z_ARRVAL_PP(repl), &pos_repl);	
 					result = emalloc(result_len + 1);
 
-					memcpy(result, Z_STRVAL_PP(tmp_str), f);
-					memcpy((result + f), Z_STRVAL_PP(tmp_repl), Z_STRLEN_PP(tmp_repl));
-					memcpy((result + f + Z_STRLEN_PP(tmp_repl)), Z_STRVAL_PP(tmp_str) + f + l, Z_STRLEN_PP(tmp_str) - f - l);
+					memcpy(result, Z_STRVAL_P(orig_str), f);
+					memcpy((result + f), Z_STRVAL_P(repl_str), Z_STRLEN_P(repl_str));
+					memcpy((result + f + Z_STRLEN_P(repl_str)), Z_STRVAL_P(orig_str) + f + l, Z_STRLEN_P(orig_str) - f - l);
+					if(Z_TYPE_PP(tmp_repl) != IS_STRING) {
+						zval_dtor(repl_str);
+					}
 				} else {
 					result = emalloc(result_len + 1);
 	
-					memcpy(result, Z_STRVAL_PP(tmp_str), f);
-					memcpy((result + f), Z_STRVAL_PP(tmp_str) + f + l, Z_STRLEN_PP(tmp_str) - f - l);
+					memcpy(result, Z_STRVAL_P(orig_str), f);
+					memcpy((result + f), Z_STRVAL_P(orig_str) + f + l, Z_STRLEN_P(orig_str) - f - l);
 				}
 			} else {
 				result_len += Z_STRLEN_PP(repl);
 
 				result = emalloc(result_len + 1);
 
-				memcpy(result, Z_STRVAL_PP(tmp_str), f);
+				memcpy(result, Z_STRVAL_P(orig_str), f);
 				memcpy((result + f), Z_STRVAL_PP(repl), Z_STRLEN_PP(repl));
-				memcpy((result + f + Z_STRLEN_PP(repl)), Z_STRVAL_PP(tmp_str) + f + l, Z_STRLEN_PP(tmp_str) - f - l);
+				memcpy((result + f + Z_STRLEN_PP(repl)), Z_STRVAL_P(orig_str) + f + l, Z_STRLEN_P(orig_str) - f - l);
 			}
 
 			result[result_len] = '\0';
 			add_next_index_stringl(return_value, result, result_len, 0);
-
+			if(Z_TYPE_PP(tmp_str) != IS_STRING) {
+				zval_dtor(orig_str);
+			}
 			zend_hash_move_forward_ex(Z_ARRVAL_PP(str), &pos_str);
 		} /*while*/
 	} /* if */
