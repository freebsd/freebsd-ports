--- ptrans.c.orig	Sun Oct 20 14:32:45 2002
+++ ptrans.c	Sun Oct 20 14:33:30 2002
@@ -45,9 +45,9 @@
 static int eightbit = 1;
 static unsigned int line      = 1;
 static unsigned int character = 0;
-static FILE *input   = stdin;
-static FILE *output  = stdout;
-static FILE *page    = NULL;
+static FILE *input;
+static FILE *output;
+static FILE *page;
 static char *charmap = NULL;
 static char buffer[9];
 static int uni[256] = {
@@ -748,6 +748,10 @@
 	char *outp = NULL;
 	char *pg   = NULL;
 	char *cp;
+
+	input = stdin;
+	output = stdout;
+	page = NULL;
 
 	for (i = 1; i < argc; i++) {
 		if (argv[i][0] != '-')
