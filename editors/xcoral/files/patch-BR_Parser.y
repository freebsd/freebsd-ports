--- BR_Parser.y.orig	2002-12-18 07:21:52 UTC
+++ BR_Parser.y
@@ -79,7 +79,7 @@
 
 #define YYDEBUG                 1
 
-#define BR_YYERROR              YYFAIL
+#define BR_YYERROR              YYERROR
 
 
    /*-----------------------------------------------------------------------*/
