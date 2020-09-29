--- src/perpet.c.orig	2015-04-02 06:04:02 UTC
+++ src/perpet.c
@@ -85,7 +85,7 @@ extern void yyrestart(FILE*);
 /* function created by yacc */
 extern int yyparse(void);
 
-int yydebug;
+extern int yydebug;
 
 /* compilation options */
 bool compile_only; 	/* just compile into C, don't run the linker */
