--- ftp.c.orig	2014-08-06 20:08:32.000000000 -0400
+++ ftp.c	2014-08-06 20:09:24.000000000 -0400
@@ -89,7 +89,7 @@
 										 */
 
 /* ftp.c externs */
-extern FILE					*logf;
+extern FILE					*logfile;
 extern string				anon_password;
 extern longstring			cwd, lcwd;
 extern Hostname				hostname;
@@ -365,9 +365,9 @@
 #endif
 
 	/* Save which sites we opened to the user's logfile. */
-	if (logf != NULL) {
+	if (logfile != NULL) {
 		(void) time(&now);
-		(void) fprintf(logf, "%s opened at %s",
+		(void) fprintf(logfile, "%s opened at %s",
 					   hostname,
 					   ctime(&now));
 	}
@@ -887,8 +887,8 @@
     } else
         (void) Strncpy(fullRemote, remote);
 
-    if (logf != NULL) {
-        (void) fprintf(logf, "\t-> \"%s\" %s, %s\n",
+    if (logfile != NULL) {
+        (void) fprintf(logfile, "\t-> \"%s\" %s, %s\n",
             fullRemote, direction, bsstr);
     }
 #ifdef SYSLOG
