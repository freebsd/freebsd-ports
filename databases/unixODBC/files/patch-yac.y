--- sqp/yac.y.orig	Tue Dec 10 18:24:32 2002
+++ sqp/yac.y	Tue Dec 10 18:24:55 2002
@@ -214,7 +214,7 @@
 y_escape:
 		/* optional */				{ $$ = NULL; }
 	|	ESCAPE STRING				{ $$ = $2;   }
-
+	;
 y_comparisons:
 		y_comparisons OR y_comparisons		{ $$ = sqpStoreCond( sqpor,   $1,   $3,   NULL ); }
 	|	y_comparisons AND y_comparisons		{ $$ = sqpStoreCond( sqpand,  $1,   $3,   NULL ); }
