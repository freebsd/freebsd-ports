--- src/actioncompiler/swf5compiler.y.orig	2006-02-08 23:48:38.000000000 +0100
+++ src/actioncompiler/swf5compiler.y	2009-03-06 11:32:10.000000000 +0100
@@ -1795,7 +1795,7 @@ opcode_list
 
 with
 	: WITH
-				{ $$ = bufferWriteOp(asmBuffer,
+				{ $<len>$ = bufferWriteOp(asmBuffer,
 						     SWFACTION_WITH); }
 	  opcode_list END	{ $$ = $<len>2 + $3;
 				  bufferPatchLength(asmBuffer, $3); }
@@ -1828,9 +1828,9 @@ push_list
 	;
 
 opcode
-	: PUSH 			{ $$ = bufferWriteOp(asmBuffer,
+	: PUSH 			{ $<len>$ = bufferWriteOp(asmBuffer,
 						     SWFACTION_PUSH);
-				  $$ += bufferWriteS16(asmBuffer, 0); }
+				  $<len>$ += bufferWriteS16(asmBuffer, 0); }
 	  push_list		{ $$ = $<len>2 + $3;
 				  bufferPatchLength(asmBuffer, $3); }
 
