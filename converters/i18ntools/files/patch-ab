--- uhtrans.c~	Mon Apr  5 23:00:00 1999
+++ uhtrans.c	Sun Oct 20 14:31:19 2002
@@ -41,8 +41,8 @@
 
 static unsigned int line = 1;
 static unsigned int numerrors = 0;
-static FILE *input   = stdin;
-static FILE *output  = stdout;
+static FILE *input;
+static FILE *output;
 
 int usage() {
 	fprintf(stderr, "Usage: uhtrans [ -i inputfile][ -o outputfile]\n");
@@ -63,6 +63,9 @@
 	unsigned int c;
 	char *inp  = NULL;
 	char *outp = NULL;
+
+	input = stdin;
+	output = stdout;
 
 	for (i = 1; i < argc; i++) {
 		if (argv[i][0] != '-')
