--- parser_gram.c.orig	2011-09-06 17:22:21 UTC
+++ parser_gram.c
@@ -114,7 +114,7 @@ static GetLine *gl;
 /* executable name to execute worker processes later */
 char *execname;
 
-static int dofile = DOFILE_FALSE;
+int dofile = DOFILE_FALSE;
 static FILE *parentscript;
 
 static char *fbbasepath = FILEBENCHDIR;
