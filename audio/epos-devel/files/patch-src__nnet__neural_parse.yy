--- src/nnet/neural_parse.yy.orig
+++ src/nnet/neural_parse.yy
@@ -104,7 +104,7 @@ make_tree (TTypedValue val = TTypedValue
 /*                    SYMBOLS                        */
 /* * * * * * * * * * * * * * * * * * * * * * * * * * */
 
-%token_table
+//%token_table -- unsupported by the base yacc(1) on some FreeBSD versions
 //%raw bison nefunguje s raw! (aspon yylex ne)
 
 %union {
@@ -255,7 +255,7 @@ unit_level: string_exp 
 
 int yyerror (char *s)
 {
-	shriek (812, fmt ("BISON:yyerror:bison_nnet parser: bison_row %i (not counting empty rows) '%s' is erroneous. %s\n", row_num, bison_row_buf, s));
+	shriek (812, fmt ("BISON:yyerror:bison_nnet parser: bison_row %i (not counting empty rows) '%s' is erroneous. %s\n", row_num, bison_row_buf.c_str(), s));
 	return -1;
 }

