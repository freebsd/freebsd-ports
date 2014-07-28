--- utrans.c.orig	Sun Oct 20 14:28:59 2002
+++ utrans.c	Sun Oct 20 14:29:45 2002
@@ -45,9 +45,9 @@
 static int binary  = 1;
 static unsigned int line = 1;
 static unsigned int character = 1;
-static FILE *input   = stdin;
-static FILE *output  = stdout;
-static FILE *page    = NULL;
+static FILE *input;
+static FILE *output;
+static FILE *page;
 static char *charmap = NULL;
 static char buffer[9];
 
@@ -149,6 +149,10 @@
 	char *outp = NULL;
 	char *pg   = NULL;
 	char *cp;
+ 
+	input   = stdin;
+	output  = stdout;
+	page    = NULL;
 
 	for (i = 1; i < argc; i++) {
 		if (argv[i][0] != '-')
