--- main/php_ini.c.orig	2017-06-14 13:23:49 UTC
+++ main/php_ini.c
@@ -280,7 +280,7 @@ static void php_ini_parser_cb(zval *arg1
 				size_t key_len;
 
 				/* PATH sections */
-				if (zend_string_equals_literal_ci(Z_STR_P(arg1), "PATH")) {
+				if (!zend_binary_strncasecmp(Z_STRVAL_P(arg1), Z_STRLEN_P(arg1), "PATH", sizeof("PATH") - 1, sizeof("PATH") - 1)) {
 					key = Z_STRVAL_P(arg1);
 					key = key + sizeof("PATH") - 1;
 					key_len = Z_STRLEN_P(arg1) - sizeof("PATH") + 1;
@@ -291,7 +291,7 @@ static void php_ini_parser_cb(zval *arg1
 					TRANSLATE_SLASHES_LOWER(key);
 
 				/* HOST sections */
-				} else if (zend_string_equals_literal_ci(Z_STR_P(arg1), "HOST")) {
+				} else if (!zend_binary_strncasecmp(Z_STRVAL_P(arg1), Z_STRLEN_P(arg1), "HOST", sizeof("HOST") - 1, sizeof("HOST") - 1)) {
 					key = Z_STRVAL_P(arg1);
 					key = key + sizeof("HOST") - 1;
 					key_len = Z_STRLEN_P(arg1) - sizeof("HOST") + 1;
@@ -328,7 +328,9 @@ static void php_ini_parser_cb(zval *arg1
 						zend_hash_init(Z_ARRVAL(section_arr), 8, NULL, (dtor_func_t) config_zval_dtor, 1);
 						entry = zend_hash_str_update(target_hash, key, key_len, &section_arr);
 					}
-					active_ini_hash = Z_ARRVAL_P(entry);
+					if (Z_TYPE_P(entry) == IS_ARRAY) {
+						active_ini_hash = Z_ARRVAL_P(entry);
+					}
 				}
 			}
 			break;
@@ -638,7 +640,7 @@ int php_init_config(void)
 			}
 			if (!debpath[0]) {
 				/* empty string means default builtin value
-				   to allow "/foo/php.d:" or ":/foo/php.d" */
+				   to allow "/foo/phd.d:" or ":/foo/php.d" */
 				debpath = PHP_CONFIG_FILE_SCAN_DIR;
 			}
 			lenpath = (int)strlen(debpath);
