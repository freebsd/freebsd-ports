--- src/nnet/neural_parse.yy.orig
+++ src/nnet/neural_parse.yy
@@ -255,7 +255,7 @@
 
 int yyerror (char *s)
 {
-	shriek (812, fmt ("BISON:yyerror:bison_nnet parser: bison_row %i (not counting empty rows) '%s' is erroneous. %s\n", row_num, bison_row_buf, s));
+	shriek (812, fmt ("BISON:yyerror:bison_nnet parser: bison_row %i (not counting empty rows) '%s' is erroneous. %s\n", row_num, bison_row_buf.c_str(), s));
 	return -1;
 }

