--- assembler.y.orig	Tue Jan 22 10:33:01 2002
+++ assembler.y	Tue Jan 22 10:33:09 2002
@@ -491,16 +491,10 @@
 	: SETTARGET STRING		{ $$ = writeByte(SWFACTION_SETTARGET);
 					  $$ +=	writeShort(strlen($2)+1);
 					  $$ +=	writeString($2); }
-	  statements_opt END		{ $$ = $4 + writeByte(SWFACTION_SETTARGET);
-					  $$ +=	$<len>3	+ writeShort(1);
-					  $$ +=	writeByte(0); }
 	;
 
 settargetexpression
 	: SETTARGETEXPR			{ $$ = writeByte(SWFACTION_SETTARGETEXPRESSION); }
-	  statements_opt END		{ $$ = $3 + writeByte(SWFACTION_SETTARGET);
-					  $$ +=	$<len>2	+ writeShort(1);
-					  $$ +=	writeByte(0); }
 	;
 
 push_item
