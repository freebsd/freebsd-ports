--- codes.c.orig	1993-09-20 15:13:22.000000000 +0200
+++ codes.c	2012-12-30 23:36:01.000000000 +0100
@@ -15,6 +15,7 @@ WITHOUT ANY EXPRESS OR IMPLIED WARRANTIE
 #include <stdio.h>
 #include <ctype.h>
 #include <config.h>
+#include <string.h>
 
 extern char *index();
 static char basis_64[] =
@@ -46,7 +47,9 @@ char c;
 /* the following gets a character, but fakes it properly into two chars if there's a newline character */
 static int InNewline=0;
 
-int nextcharin(infile, PortableNewlines)
+static void output64chunk(int c1, int c2, int c3, int pads, FILE *outfile);
+
+static int nextcharin(infile, PortableNewlines)
 FILE *infile;
 int PortableNewlines;
 {
@@ -69,6 +72,7 @@ int PortableNewlines;
 #endif
 }
 
+void
 to64(infile, outfile, PortableNewlines) 
 FILE *infile, *outfile;
 int PortableNewlines;
@@ -97,6 +101,7 @@ int PortableNewlines;
     fflush(outfile);
 }
 
+void
 output64chunk(c1, c2, c3, pads, outfile)
 FILE *outfile;
 {
@@ -114,6 +119,7 @@ FILE *outfile;
     }
 }
 
+static int
 PendingBoundary(s, Boundaries, BoundaryCt)
 char *s;
 char **Boundaries;
@@ -140,6 +146,7 @@ int *BoundaryCt;
 static int CRpending = 0;
 
 #ifdef NEWLINE_CHAR
+static void
 almostputc(c, outfile, PortableNewlines)
 int c;
 FILE *outfile;
@@ -165,6 +172,7 @@ int PortableNewlines;
     }
 }
 #else
+static void
 almostputc(c, outfile, PortableNewlines)
 int c;
 FILE *outfile;
@@ -174,6 +182,7 @@ int PortableNewlines;
 }
 #endif
 
+void
 from64(infile, outfile, boundaries, boundaryct, PortableNewlines) 
 FILE *infile, *outfile;
 char **boundaries;
@@ -275,6 +284,7 @@ char c;
 }
 */
 
+void
 toqp(infile, outfile) 
 FILE *infile, *outfile;
 {
@@ -350,6 +360,7 @@ FILE *infile, *outfile;
     }
 }
 
+void
 fromqp(infile, outfile, boundaries, boundaryct) 
 FILE *infile, *outfile;
 char **boundaries;
