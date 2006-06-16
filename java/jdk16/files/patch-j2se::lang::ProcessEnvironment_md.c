$FreeBSD$

--- ../../j2se/src/solaris/native/java/lang/ProcessEnvironment_md.c.orig	Tue Oct 19 15:02:09 2004
+++ ../../j2se/src/solaris/native/java/lang/ProcessEnvironment_md.c	Thu Jun 15 17:58:34 2006
@@ -32,7 +32,7 @@
 
     for (i = 0; environ[i]; i++) {
 	/* Ignore corrupted environment variables */
-	if (strchr(environ[i], '=') != NULL)
+	if (strchr(environ[i], '=') != NULL && *environ[i] != '=')
 	    count++;
     }
 
@@ -43,7 +43,7 @@
 	jsize len = strlen(environ[i]);
 	const char * varEnd = strchr(environ[i], '=');
 	/* Ignore corrupted environment variables */
-	if (varEnd != NULL) {
+	if (varEnd != NULL && varEnd != environ[i]) {
 	    jbyteArray var, val;
 	    const char * valBeg = varEnd + 1;
 	    jsize varLength = varEnd - environ[i];
