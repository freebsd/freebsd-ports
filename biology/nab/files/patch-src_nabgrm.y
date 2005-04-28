--- src/nabgrm.y.orig	Thu Apr  7 20:17:27 2005
+++ src/nabgrm.y	Sun Apr 17 20:21:36 2005
@@ -41,6 +41,8 @@
 
 # define YYSTYPE_IS_DECLARED 1
 
+#define YYSTYPE_IS_DECLARED 1
+
 %}
 
 %token	<ival>	SYM_ADDRESS
@@ -299,7 +301,7 @@
 		  f_stmtpart SYM_RBRACE
 				{ CG_genestmts( TRUE );
 				  CG_genop( NULL, SYM_RBRACE ); }
-		  SYM_SEMICOLON ;
+		  SYM_SEMICOLON { CG_gennull ( ); } ;
 f_defpart	: lv_decls 
 		| 		{ $$ = NULL; } ;
 lv_decls	: var_decl
