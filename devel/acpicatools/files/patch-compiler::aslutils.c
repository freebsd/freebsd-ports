--- compiler/aslutils.c.orig	Fri Aug 16 09:25:16 2002
+++ compiler/aslutils.c	Thu Aug 22 17:41:16 2002
@@ -126,7 +126,7 @@
 
 #ifdef _USE_BERKELEY_YACC
 extern const char * const       AslCompilername[];
-static const char * const       *yytname = &AslCompilername[255];
+static const char * const       *yytname = &AslCompilername[254];
 #else
 extern const char * const       yytname[];
 #endif
