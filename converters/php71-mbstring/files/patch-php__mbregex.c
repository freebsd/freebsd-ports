--- php_mbregex.c.orig	2018-02-28 11:19:22 UTC
+++ php_mbregex.c
@@ -452,7 +452,7 @@ static php_mb_regex_t *php_mbregex_compi
 	OnigUChar err_str[ONIG_MAX_ERROR_MESSAGE_LEN];
 
 	rc = zend_hash_str_find_ptr(&MBREX(ht_rc), (char *)pattern, patlen);
-	if (!rc || rc->options != options || rc->enc != enc || rc->syntax != syntax) {
+	if (!rc || onig_get_options(rc) != options || onig_get_encoding(rc) != enc || onig_get_syntax(rc) != syntax) {
 		if ((err_code = onig_new(&retval, (OnigUChar *)pattern, (OnigUChar *)(pattern + patlen), options, enc, syntax, &err_info)) != ONIG_NORMAL) {
 			onig_error_code_to_str(err_str, err_code, &err_info);
 			php_error_docref(NULL, E_WARNING, "mbregex compile err: %s", err_str);
