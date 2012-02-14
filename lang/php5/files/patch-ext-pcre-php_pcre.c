--- ext/pcre/php_pcre.c	2012/01/01 13:15:04	321634
+++ ext/pcre/php_pcre.c	2012/02/06 18:18:53	323097
@@ -241,6 +241,7 @@
 	char				*pattern;
 	int					 do_study = 0;
 	int					 poptions = 0;
+	int				count = 0;
 	unsigned const char *tables = NULL;
 #if HAVE_SETLOCALE
 	char				*locale = setlocale(LC_CTYPE, NULL);
@@ -252,10 +253,10 @@
 	   back the compiled pattern, otherwise go on and compile it. */
 	if (zend_hash_find(&PCRE_G(pcre_cache), regex, regex_len+1, (void **)&pce) == SUCCESS) {
 		/*
-		 * We use a quick pcre_info() check to see whether cache is corrupted, and if it
+		 * We use a quick pcre_fullinfo() check to see whether cache is corrupted, and if it
 		 * is, we flush it and compile the pattern from scratch.
 		 */
-		if (pcre_info(pce->re, NULL, NULL) == PCRE_ERROR_BADMAGIC) {
+		if (pcre_fullinfo(pce->re, NULL, PCRE_INFO_CAPTURECOUNT, &count) == PCRE_ERROR_BADMAGIC) {
 			zend_hash_clean(&PCRE_G(pcre_cache));
 		} else {
 #if HAVE_SETLOCALE
