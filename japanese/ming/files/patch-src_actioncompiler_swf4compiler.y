--- actioncompiler/swf4compiler.y.orig	2002-06-24 12:21:54 UTC
+++ actioncompiler/swf4compiler.y
@@ -6,10 +6,10 @@
 #include <string.h>
 #include "compile.h"
 
-#define YYPARSE_PARAM buffer
-
 %}
 
+%parse-param {void *buffer}
+
 %union {
   Buffer action;
   char *str;
@@ -119,7 +119,6 @@
 %type <action> expr_opt
 %type <action> void_function_call
 %type <action> function_call
-%type <action> lhs_expr
 %type <action> pf_expr
 %type <action> lhs_expr
 %type <action> rhs_expr
@@ -140,6 +139,7 @@
 program
         : elems
 		{ *((Buffer *)buffer) = $1; }
+		;
 
 elems
 	: elem
@@ -277,6 +277,7 @@ if_stmt
 		  bufferWriteS16($3, bufferLength($5));
 		  bufferConcat($3, $5);
 		  $$ = $3; }
+		  ;
 
 expr_opt
 	: /* empty */	{ $$ = NULL; }
