--- actioncompiler/swf5compiler.y.orig	2002-06-24 12:21:54 UTC
+++ actioncompiler/swf5compiler.y
@@ -8,12 +8,12 @@
 #include "compile.h"
 #include "assembler.h"
 
-#define YYPARSE_PARAM buffer
-
 Buffer bf, bc;
 
 %}
 
+%parse-param {void *buffer}
+
 %union
 {
   Buffer action;
@@ -239,7 +239,7 @@ expr_opt
 
 switch_stmt
 	: SWITCH '(' expr ')' '{'
-		{ $$ = $3; }
+		{ $<action>$ = $3; }
 	  switch_cases '}'
 		{ bufferConcat($$, $7);
 		  bufferResolveJumps($$);
@@ -1422,7 +1422,7 @@ opcode_list
 
 with
 	: WITH
-				{ $$ = bufferWriteOp(asmBuffer,
+				{ $<len>$ = bufferWriteOp(asmBuffer,
 						     SWFACTION_WITH); }
 	  opcode_list END	{ $$ = $<len>2 + $3;
 				  bufferPatchLength(asmBuffer, $3); }
@@ -1455,9 +1455,9 @@ push_list
 	;
 
 opcode
-	: PUSH 			{ $$ = bufferWriteOp(asmBuffer,
+	: PUSH 			{ $<len>$ = bufferWriteOp(asmBuffer,
 						     SWFACTION_PUSHDATA);
-				  $$ += bufferWriteS16(asmBuffer, 0); }
+				  $<len>$ += bufferWriteS16(asmBuffer, 0); }
 	  push_list		{ $$ = $<len>2 + $3;
 				  bufferPatchLength(asmBuffer, $3); }
 
