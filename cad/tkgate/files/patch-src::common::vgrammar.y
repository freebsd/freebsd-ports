--- src/common/vgrammar.y.orig	Mon Dec 23 13:16:56 2002
+++ src/common/vgrammar.y	Mon Dec 23 13:17:03 2002
@@ -127,7 +127,7 @@
 	;
 
 enddecl	: ANOTATE ENDDECLS ENDANOTATE		{ VerEndDecls(); }
-
+        ;
 bwidth	:					{ $$ = 1; }
 	| LBRACK NUMBER COLON NUMBER RBRACK	{ $$ = ($2-$4)+1; }
 	;
@@ -170,7 +170,7 @@
 
 tran_arg	: DOT LITERAL LPAREN obang LITERAL tran_range RPAREN { VerAttach($2,$5,$4); }
 		| obang LITERAL tran_range			{ VerAttach(0,$2,$1); }
-
+        ;
 tran_range	: LBRACK NUMBER RBRACK			{ VerTranRange($2,$2); }
 		|  LBRACK NUMBER COLON NUMBER RBRACK	{ VerTranRange($2,$4); }
 		;
