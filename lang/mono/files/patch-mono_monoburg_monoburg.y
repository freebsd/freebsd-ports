--- mono/monoburg/monoburg.y.orig	Sat Nov 30 14:21:57 2002
+++ mono/monoburg/monoburg.y	Sat Nov 30 14:22:31 2002
@@ -50,7 +50,7 @@
 	| IDENT ':' tree optcost optcode optcfunc { create_rule ($1, $3, $5, $4, $6); } decls 
 	;
 
-optcode : /* empty */ { $$ = NULL }
+optcode : /* empty */ { $$ = NULL; }
 	| CODE 
 	;
 
