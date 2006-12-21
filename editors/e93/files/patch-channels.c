--- ./channels.c.orig	Sat May 29 12:01:41 2004
+++ ./channels.c	Wed Dec 20 14:35:21 2006
@@ -54,7 +54,7 @@
 	return(TCL_OK);		// nothing for us to do, but this proc must exist
 }
 
-static int StdoutOutputProc(ClientData clientData,const char *buf,int charsToWrite,int *errorCode)
+static int StdoutOutputProc(ClientData clientData,char *buf,int charsToWrite,int *errorCode)
 // Writes the given output on the IO channel. Returns count of how
 // many characters were actually written, and an error indication.
 {
@@ -76,7 +76,7 @@
 	return(charsWritten);
 }
 
-static int StderrOutputProc(ClientData clientData,const char *buf,int charsToWrite,int *errorCode)
+static int StderrOutputProc(ClientData clientData,char *buf,int charsToWrite,int *errorCode)
 // Writes the given output on the IO channel. Returns count of how
 // many characters were actually written, and an error indication.
 {
