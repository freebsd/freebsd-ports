--- src/calc/parser.h	Thu May 31 18:54:07 2001
+++ src/calc/parser.h	Tue Jun 26 22:27:15 2001
@@ -29,7 +29,7 @@
 
 /* Structure passed do yyparse. */
 typedef struct {
-  FILE *input;
+  const char *input;
   expression_t *expr;
   symbol_dict_t *dict;
 } parser_control;
