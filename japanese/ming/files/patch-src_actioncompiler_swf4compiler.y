--- actioncompiler/swf4compiler.y.orig	Mon Dec  2 11:10:00 2002
+++ actioncompiler/swf4compiler.y	Mon Dec  2 11:12:15 2002
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
@@ -277,6 +277,7 @@
 		  bufferWriteS16($3, bufferLength($5));
 		  bufferConcat($3, $5);
 		  $$ = $3; }
+		  ;
 
 expr_opt
 	: /* empty */	{ $$ = NULL; }
