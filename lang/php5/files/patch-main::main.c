--- main/main.c.orig    Sun Jun 22 11:16:39 2003
+++ main/main.c Sun Jun 22 11:17:00 2003

@@ -134,7 +134,6 @@ static int short_track_vars_names_length

 #define NUM_TRACK_VARS		(sizeof(short_track_vars_names_length)/sizeof(int))

-
 #define SAFE_FILENAME(f) ((f)?(f):"-")

 /* {{{ PHP_INI_MH
@@ -1362,7 +1361,7 @@ static void php_autoglobal_merge(HashTab
 static int php_hash_environment(TSRMLS_D)
 {
 	char *p;
-	unsigned char _gpc_flags[3] = {0, 0, 0};
+	int _gpc_flags[5] = {0, 0, 0, 0, 0};
 	zend_bool have_variables_order;
 	zval *dummy_track_vars_array = NULL;
 	zend_bool initialized_dummy_track_vars_array=0;
@@ -1409,42 +1408,48 @@ static int php_hash_environment(TSRMLS_D
 			case 'P':
 				if (!_gpc_flags[0] && !SG(headers_sent) && SG(request_info).request_method && !strcmp(SG(request_info).request_method, "POST")) {
 					sapi_module.treat_data(PARSE_POST, NULL, NULL TSRMLS_CC);	/* POST Data */
-					_gpc_flags[0]=1;
+					_gpc_flags[0]=TRACK_VARS_POST + 1;
 				}
 				break;
 			case 'c':
 			case 'C':
 				if (!_gpc_flags[1]) {
 					sapi_module.treat_data(PARSE_COOKIE, NULL, NULL TSRMLS_CC);	/* Cookie Data */
-					_gpc_flags[1]=1;
+					_gpc_flags[1]=TRACK_VARS_COOKIE + 1;
 				}
 				break;
 			case 'g':
 			case 'G':
 				if (!_gpc_flags[2]) {
 					sapi_module.treat_data(PARSE_GET, NULL, NULL TSRMLS_CC);	/* GET Data */
-					_gpc_flags[2]=1;
+					_gpc_flags[2]=TRACK_VARS_GET + 1;
 				}
 				break;
 			case 'e':
 			case 'E':
-				if (have_variables_order) {
-					ALLOC_ZVAL(PG(http_globals)[TRACK_VARS_ENV]);
-					array_init(PG(http_globals)[TRACK_VARS_ENV]);
-					INIT_PZVAL(PG(http_globals)[TRACK_VARS_ENV]);
-					php_import_environment_variables(PG(http_globals)[TRACK_VARS_ENV] TSRMLS_CC);
-				} else {
-					php_error_docref(NULL TSRMLS_CC, E_WARNING, "Unsupported 'e' element (environment) used in gpc_order - use variables_order instead");
+				if (!_gpc_flags[3]) {
+					if (have_variables_order) {
+						ALLOC_ZVAL(PG(http_globals)[TRACK_VARS_ENV]);
+						array_init(PG(http_globals)[TRACK_VARS_ENV]);
+						INIT_PZVAL(PG(http_globals)[TRACK_VARS_ENV]);
+						php_import_environment_variables(PG(http_globals)[TRACK_VARS_ENV] TSRMLS_CC);
+					} else {
+						php_error_docref(NULL TSRMLS_CC, E_WARNING, "Unsupported 'e' element (environment) used in gpc_order - use variables_order instead");
+					}
+					_gpc_flags[3]=TRACK_VARS_ENV + 1;
 				}
 				break;
 			case 's':
 			case 'S':
-				php_register_server_variables(TSRMLS_C);
+				if (!_gpc_flags[4]) {
+					php_register_server_variables(TSRMLS_C);
+					_gpc_flags[4]=TRACK_VARS_SERVER + 1;
+				}
 				break;
 		}
 	}

-	if (!have_variables_order) {
+	if (!have_variables_order && !PG(http_globals)[TRACK_VARS_SERVER]) {
 		php_register_server_variables(TSRMLS_C);
 	}

@@ -1453,6 +1458,14 @@ static int php_hash_environment(TSRMLS_D
 		php_build_argv(SG(request_info).query_string TSRMLS_CC);
 	}

+	if (PG(register_globals)) {
+		for (i = 0; i < 5; i++) {
+			if (PG(http_globals)[i]) {
+				php_autoglobal_merge(&EG(symbol_table), Z_ARRVAL_P(PG(http_globals)[i]) TSRMLS_CC);
+			}
+		}
+	}
+
 	for (i=0; i<NUM_TRACK_VARS; i++) {
 		if (!PG(http_globals)[i]) {
 			if (!initialized_dummy_track_vars_array) {
@@ -1478,39 +1491,12 @@ static int php_hash_environment(TSRMLS_D
 		array_init(form_variables);
 		INIT_PZVAL(form_variables);

-		for (p=variables_order; p && *p; p++) {
-			switch (*p) {
-				case 'g':
-				case 'G':
-					php_autoglobal_merge(Z_ARRVAL_P(form_variables), Z_ARRVAL_P(PG(http_globals)[TRACK_VARS_GET]) TSRMLS_CC);
-					break;
-				case 'p':
-				case 'P':
-					php_autoglobal_merge(Z_ARRVAL_P(form_variables), Z_ARRVAL_P(PG(http_globals)[TRACK_VARS_POST]) TSRMLS_CC);
-					break;
-				case 'c':
-				case 'C':
-					php_autoglobal_merge(Z_ARRVAL_P(form_variables), Z_ARRVAL_P(PG(http_globals)[TRACK_VARS_COOKIE]) TSRMLS_CC);
-					break;
-			}
-		}
-
-		if (PG(register_globals)) {
-			HashPosition pos;
-			zval **data;
-			char *string_key;
-			uint string_key_len;
-			ulong num_key;
-
-			zend_hash_internal_pointer_reset_ex(Z_ARRVAL_P(form_variables), &pos);
-			while (zend_hash_get_current_data_ex(Z_ARRVAL_P(form_variables), (void **)&data, &pos) == SUCCESS) {
-				/* we only register string keys, since we cannot have $1234 */
-				if (zend_hash_get_current_key_ex(Z_ARRVAL_P(form_variables), &string_key, &string_key_len, &num_key, 0, &pos) == HASH_KEY_IS_STRING) {
-					ZEND_SET_SYMBOL_WITH_LENGTH(&EG(symbol_table), string_key, string_key_len, *data, (*data)->refcount+1, 0);
-				}
-				zend_hash_move_forward_ex(Z_ARRVAL_P(form_variables), &pos);
+		for (i = 0; i < 3; i++) {
+			if (_gpc_flags[i]) {
+				php_autoglobal_merge(Z_ARRVAL_P(form_variables), Z_ARRVAL_P(PG(http_globals)[(_gpc_flags[i] - 1)]) TSRMLS_CC);
 			}
 		}
+
 		zend_hash_update(&EG(symbol_table), "_REQUEST", sizeof("_REQUEST"), &form_variables, sizeof(zval *), NULL);
 	}
