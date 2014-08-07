--- set.c.orig	2014-08-06 20:08:41.000000000 -0400
+++ set.c	2014-08-06 20:09:47.000000000 -0400
@@ -43,7 +43,7 @@
 extern string				pager, anon_password, prompt;
 extern str32				curtypename;
 extern long					logsize;
-extern FILE					*logf;
+extern FILE					*logfile;
 extern longstring			rcname, logfname, lcwd;
 extern int					auto_binary, ansi_escapes, debug;
 extern int					mprompt, remote_is_unix, verbose;
@@ -131,13 +131,13 @@
 
 void set_log(char *fname, int unset)
 {
-	if (logf) {
-		(void) fclose(logf);
-		logf = NULL;
+	if (logfile) {
+		(void) fclose(logfile);
+		logfile = NULL;
 	}
 	if (!unset && fname) {
 		(void) Strncpy(logfname, fname);
-		logf = fopen (LocalDotPath(logfname), "a");
+		logfile = fopen (LocalDotPath(logfname), "a");
 	}
 }	/* set_log */
 
