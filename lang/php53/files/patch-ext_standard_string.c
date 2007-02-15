--- ext/standard/string.c.orig	Thu Feb 15 07:50:09 2007
+++ ext/standard/string.c	Thu Feb 15 07:50:33 2007
@@ -3148,7 +3148,7 @@
 	}
 	
 	Z_STRLEN_P(result) = len + (char_count * (to_len - 1));
-	Z_STRVAL_P(result) = target = safe_emalloc(char_count, to_len, len);
+	Z_STRVAL_P(result) = target = safe_emalloc(char_count, to_len, len + 1);
 	Z_TYPE_P(result) = IS_STRING;
 
 	if (case_sensitivity) {
