--- yyscan.l.orig
+++ yyscan.l
@@ -35,8 +35,6 @@
 #include "objects.h"
 #include "yyscan.h"
 
-#define yywrap() 1
-
 float yyfloatval;		/* value of a TOK_FLOAT */
 char yystrval[MAX_TEXT_LEN+1];	/* text of a text argument or align argument */
 Unit yyunit;			/* value of a TOK_UNIT */
@@ -66,6 +64,9 @@
 
 %}
 
+%option nounput
+%option noyywrap
+%option noyymore
 
 %s  inPictEnv  inPut  lookOut
 
