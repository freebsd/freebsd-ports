--- src/nabgrm.y.orig	Tue Oct 29 13:04:56 2002
+++ src/nabgrm.y	Tue Oct 29 13:40:29 2002
@@ -244,7 +244,7 @@
 expr_stmt	: expr SYM_SEMICOLON
 				{ CG_genmain(); CG_genexpr( $1 );
 				  CG_genop( NULL, SYM_SEMICOLON ); } ;
-if_stmt		: if_hdr stmt ;
+if_stmt		: if_hdr stmt
 		| if_hdr stmt SYM_ELSE
 				{ CG_genrword( SYM_ELSE ); } stmt ;
 for_stmt	: for_hdr stmt ;
