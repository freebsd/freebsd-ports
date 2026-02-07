--- main.c.orig	2004-08-15 13:39:01 UTC
+++ main.c
@@ -62,6 +62,10 @@ extern char *parallel_dev;
 extern char *serial_dev;
 #endif
 extern char *parallel_dev;
+#if LPPIPES
+extern char *auxpipe;
+extern char *prnpipe;
+#endif
 int got_drive=0;
 int chunky=0;
 int timer_a=0;
@@ -221,6 +225,22 @@ void process_args (int argc, char *argv[], int is_rc)
 		error("para needs a device as argument (/dev/lp0 for example)\n");
 	    parallel_dev = strdup(argv[++i]);
 	}
+#if LPPIPES
+	else if (EQ(x,"auxpipe"))
+	{
+	    if (i == argc-1)
+		error("auxpipe needs a pipe as argument ('cat > ~tmp/pipe.aux' for example)\n");
+	    auxpipe = strdup(argv[++i]);
+	    fprintf(stderr, "auxpipe: %s\n", auxpipe);
+	}
+	else if (EQ(x,"prnpipe"))
+	{
+	    if (i == argc-1)
+		error("prnpipe needs a pipe as argument ('lp' for example)\n");
+	    prnpipe = strdup(argv[++i]);
+	    fprintf(stderr, "prnpipe: %s\n", prnpipe);
+	}
+#endif
 	else if (EQ(x,"noaudio"))
 	{
 	    audio=0;
@@ -328,6 +348,12 @@ void process_args (int argc, char *argv[], int is_rc)
 #if MODEM1
 		     " -serial <file>            Use <file> as the serial port device\n"
 #endif
+#if LPPIPES
+		     " -prnpipe <pipe>           print through GEMDOS(PRN:) to unix pipe\n"
+		     "                           'lp' for example\n"
+		     " -auxpipe <pipe>           print through GEMDOS(AUX:) to unix pipe\n"
+		     "                           'cat > ~/tmp/pipe.aux' for example (need quotes)\n"
+#endif
 #if MONITOR
 		     " -monitor                  Start in Monitor\n"
 #endif
@@ -358,6 +384,44 @@ void process_args (int argc, char *argv[], int is_rc)
     }
 }
 
+int readstrtok(FILE *fp, char *dest, char *home, int max)
+{
+    char ch = EOF, qc = 0;
+    int i = 0;
+
+    /* if quoted argument, copy full quote
+       expand ~ to home path */
+    while (i < max && (ch = fgetc(fp)) != EOF) {
+	if (ch == '\'' || ch == '"') {
+	    if (!qc) {
+		qc = ch;
+		continue;
+	    } else {
+		break;
+	    }
+	} else if (ch == '~' && home) {
+	    int n = 0;
+	    while (i < max && home[n]) 
+		dest[i++] = home[n++];
+	} else {
+	    if (!qc)
+		if (ch == ' ' || ch == '\t')
+		    ch = '\n';
+	    if (ch == '\n') {
+		if (!i)
+		    continue;
+		break;
+	    }
+	    dest[i++] = ch;
+	}
+    }
+    dest[i]='\0';
+    /* fprintf (stderr, "<%s>\n", dest); */
+    if (ch == EOF)
+	return EOF;
+    return 0;
+}
+
 void process_stonxrc(void)
 {	
     char *home;
@@ -391,7 +455,7 @@ void process_stonxrc(void)
 	    int i,c=1;	
 	    char *args[1024];
 	    for (i=1;i<1024;i++) args[i] = (char*)malloc(sizeof(char)*256);
-	    while (fscanf(rc,"%s",args[c]) != EOF) {
+	    while (readstrtok(rc, args[c], home, 256) != EOF) {
 		if (args[c][0] == '#' && 
 		    strcmp(args[c],"#ifmachine") && strcmp(args[c],"#fi")) {
 		    int ch;
