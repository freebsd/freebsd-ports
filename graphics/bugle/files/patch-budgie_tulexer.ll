------------------------------------------------------------------------
r1215 | bmerry | 2015-06-27 03:12:35 +0900 (Sat, 27 Jun 2015) | 1 line

Fix compilation on GCC 5.1

https://sourceforge.net/p/bugle/tickets/114/

--- budgie/tulexer.ll.orig	2009-05-06 17:00:19 UTC
+++ budgie/tulexer.ll
@@ -150,6 +150,7 @@ rest of the record, find the length, the
 
 "lngt: "{DIGIT}+	{ yylnode->length = atoi(yytext + 6); }
 "prec: "{DIGIT}+	{ yylnode->prec = atoi(yytext + 6); }
+"int: "-?{DIGIT}+	{ yylnode->low = atoi(yytext + 5); }
 "low : "-?{DIGIT}+	{ yylnode->low = atoi(yytext + 6); }
 "high: "-?{DIGIT}+	{ yylnode->high = atoi(yytext + 6); }
 
