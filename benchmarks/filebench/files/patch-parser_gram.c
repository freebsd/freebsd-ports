--- parser_gram.c.orig	2013-01-18 18:18:01.000000000 +0100
+++ parser_gram.c	2013-01-18 18:18:07.000000000 +0100
@@ -114,7 +114,7 @@
 /* executable name to execute worker processes later */
 char *execname;
 
-static int dofile = DOFILE_FALSE;
+int dofile = DOFILE_FALSE;
 static FILE *parentscript;
 
 static char *fbbasepath = FILEBENCHDIR;
