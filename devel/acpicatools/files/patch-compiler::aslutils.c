--- acpica-unix-20030523/compiler/aslutils.c.orig	Thu Jun 12 15:48:25 2003
+++ acpica-unix-20030523/compiler/aslutils.c	Thu Jun 12 15:48:34 2003
@@ -126,7 +126,7 @@
 
 #ifdef _USE_BERKELEY_YACC
 extern const char * const       AslCompilername[];
-static const char * const       *yytname = &AslCompilername[255];
+static const char * const       *yytname = &AslCompilername[254];
 #else
 extern const char * const       yytname[];
 #endif
