--- src/main.c.orig	Thu Aug 14 11:36:18 2003
+++ src/main.c	Tue May 23 11:56:09 2006
@@ -101,6 +101,7 @@
 #endif
 char	temp1[PATHLEN + 1];	/* temporary file name */
 char	temp2[PATHLEN + 1];	/* temporary file name */
+char	tempdirpv[PATHLEN +1];	/* private temp directory */
 long	totalterms;		/* total inverted index terms */
 BOOL	trun_syms;		/* truncate symbols to 8 characters */
 char	tempstring[8192];	/* use this as a buffer, instead of 'yytext', 
@@ -131,6 +132,7 @@
 	int	c, i;
 	pid_t	pid;
 	struct stat	stat_buf;
+	mode_t orig_umask;
 	
 	yyin = stdin;
 	yyout = stdout;
@@ -330,9 +332,23 @@
 	}
 
 	/* create the temporary file names */
+	orig_umask = umask(S_IRWXG|S_IRWXO);
 	pid = getpid();
-	(void) sprintf(temp1, "%s/cscope%d.1", tmpdir, pid);
-	(void) sprintf(temp2, "%s/cscope%d.2", tmpdir, pid);
+	(void) snprintf(tempdirpv, sizeof(tempdirpv), "%s/cscope.%d", tmpdir, pid);
+	if(mkdir(tempdirpv,S_IRWXU)) 
+	{
+		fprintf(stderr, "cscope: Could not create private temp dir %s\n",tempdirpv);
+		myexit(1);
+	}
+	umask(orig_umask);
+
+	if ((strlen(tempdirpv) + strlen("/cscope.X")) > PATHLEN) {
+		fprintf(stderr, "cscope: Could not create private temp files\n");
+		myexit(1);
+	}
+
+	(void) snprintf(temp1, sizeof(temp1), "%s/cscope.1", tempdirpv);
+	(void) snprintf(temp2, sizeof(temp2), "%s/cscope.2", tempdirpv);
 
 	/* if running in the foreground */
 	if (signal(SIGINT, SIG_IGN) != SIG_IGN) {
@@ -834,6 +850,7 @@
 	if (temp1[0] != '\0') {
 		(void) unlink(temp1);
 		(void) unlink(temp2);
+		(void) rmdir(tempdirpv);		
 	}
 	/* restore the terminal to its original mode */
 	if (incurses == YES) {
