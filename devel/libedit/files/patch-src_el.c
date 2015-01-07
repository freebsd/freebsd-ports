--- src/el.c.orig	2014-06-18 19:06:35 UTC
+++ src/el.c
@@ -121,7 +121,7 @@ el_init_fd(const char *prog, FILE *fin, 
          */
 	el->el_flags = 0;
 #ifdef WIDECHAR
-	if (setlocale(LC_CTYPE, NULL) != NULL){
+	if (setlocale(LC_CTYPE, "") != NULL){
 		if (strcmp(nl_langinfo(CODESET), "UTF-8") == 0)
 			el->el_flags |= CHARSET_IS_UTF8;
 	}
