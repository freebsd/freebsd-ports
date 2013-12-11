--- src/parser.h.orig	2011-01-25 19:44:07.000000000 +0300
+++ src/parser.h	2013-11-28 04:22:09.853554221 +0400
@@ -54,7 +54,7 @@
  */
 void yyerror( const char *sub, ... )
 	__attribute__((format(printf, 1, 2)));
-extern int yyleng;			/* lex stuff */
+extern size_t yyleng;			/* lex stuff */
 
 /* Lex gathers tokens here for workspace.c
  */
