--- parser_gram.c.orig	2010-12-30 21:42:39 UTC
+++ parser_gram.c
@@ -114,7 +114,7 @@ static GetLine *gl;
 /* executable name to execute worker processes later */
 char *execname;
 
-static int dofile = DOFILE_FALSE;
+int dofile = DOFILE_FALSE;
 static FILE *parentscript;
 
 static char *fbbasepath = FILEBENCHDIR;
