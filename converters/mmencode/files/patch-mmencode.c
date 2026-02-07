--- mmencode.c.orig	2012-12-30 23:29:36.000000000 +0100
+++ mmencode.c	2012-12-30 23:30:33.000000000 +0100
@@ -14,6 +14,7 @@ WITHOUT ANY EXPRESS OR IMPLIED WARRANTIE
 */
 #include <stdio.h>
 #include <config.h>
+#include <stdlib.h>
 #ifdef MSDOS
 #include <fcntl.h>
 #endif
@@ -21,6 +22,12 @@ WITHOUT ANY EXPRESS OR IMPLIED WARRANTIE
 #define BASE64 1
 #define QP 2 /* quoted-printable */
 
+extern void to64(FILE *infile, FILE *outfile, int PortableNewlines);
+extern void from64(FILE *infile, FILE *outfile, char **boundaries, int *boundaryct, int PortableNewlines);
+extern void toqp(FILE *infile, FILE *outfile);
+extern void fromqp(FILE *infile, FILE *outfile, char **boundaries, int *boundaryct);
+
+int
 main(argc, argv)
 int argc;
 char **argv;
