--- json-glib/json-scanner.c.orig	2020-08-18 18:22:53 UTC
+++ json-glib/json-scanner.c
@@ -925,7 +925,7 @@ json_scanner_get_token_i (JsonScanner	*scanner,
       
     case G_TOKEN_SYMBOL:
       if (scanner->config->symbol_2_token)
-	*token_p = (GTokenType) value_p->v_symbol;
+	*token_p = GPOINTER_TO_INT (value_p->v_symbol);
       break;
       
     case G_TOKEN_BINARY:
