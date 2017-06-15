--- actioncompiler/compile.h.orig	2002-06-24 12:21:54 UTC
+++ actioncompiler/compile.h
@@ -10,7 +10,7 @@ typedef struct _buffer *Buffer;
 #include "action.h"
 
 /* shut up bison.simple */
-void yyerror(char *msg);
+void yyerror(char *msg, char *yy_);
 int yylex();
 
 #ifndef max
