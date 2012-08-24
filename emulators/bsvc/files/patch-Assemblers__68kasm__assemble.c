--- ./Assemblers/68kasm/assemble.c.orig	1998-11-09 04:39:28.000000000 +0100
+++ ./Assemblers/68kasm/assemble.c	2012-08-24 12:34:05.509913887 +0200
@@ -62,6 +62,8 @@
 extern FILE *listFile;		/* Listing file */
 extern char listFlag;
 
+void assemble(char *line, int *errorPtr);
+
 
 processFile()
 {
@@ -106,6 +108,7 @@
 }
 
 
+void
 assemble(line, errorPtr)
 char *line;
 int *errorPtr;
