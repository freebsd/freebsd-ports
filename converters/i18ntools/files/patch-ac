--- hutrans.c.orig	Sun Oct 20 14:31:49 2002
+++ hutrans.c	Sun Oct 20 14:32:24 2002
@@ -42,8 +42,8 @@
 
 int inbuffer = 0;
 int nextchar = 0;
-static FILE *input   = stdin;
-static FILE *output  = stdout;
+static FILE *input;
+static FILE *output;
 static char buffer[BUFFERSIZE];
 
 /*
@@ -137,6 +137,9 @@
 	unsigned int c;
 	char *inp  = NULL;
 	char *outp = NULL;
+
+	input = stdin;
+	output = stdout;
 
 	for (i = 1; i < argc; i++) {
 		if (argv[i][0] != '-')
