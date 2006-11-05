--- config.y.orig	Wed Apr  6 15:42:48 2005
+++ config.y	Wed Nov  1 15:04:08 2006
@@ -109,6 +109,7 @@
 		{ $$ = RLIM_INFINITY; }
 		| D_NUMBER
 		{ $$ = $1; }
+		;
 
 topst:		topopt semicolon
 		| server
