--- psconv.c.orig	1994-05-11 08:00:59 UTC
+++ psconv.c
@@ -64,9 +64,11 @@ static char *sccsid = "@(#)psconv.c 1.7 
  */
 
 #include <stdio.h>
+#include <stdlib.h>
 #include <string.h>
 #include <ctype.h>
 #include <signal.h>
+#include <unistd.h>
 #include <sys/types.h>
 #include <sys/stat.h>
 
@@ -591,7 +593,7 @@ void convert(fp)
     dostart = 1;
     done = 0;
 
-    while ((end = getline(fp)) > 0) {
+    while ((end = get_line(fp)) > 0) {
 	for (i = 0; i < end; i++) {
 	    intmask = 1;
 	    /*
@@ -647,14 +649,14 @@ void convert(fp)
 
 /*-==(spec:\\:":":\(:\):\[:\]::::psconv)==-----------------------------
     NAME
-	getline
+	get_line
     DESCRIPTION
 	Reads characters onto cbuf[] upto NEWLINE, FORMFEED, escape
 	sequence or EOF.
 	An attribute of each character is set onto abuf[].
 	No checking on buffer overflow.
  ---------------------------------------------------------------------*/
-int getline(fp)
+int get_line(fp)
     FILE *fp;
 {
     register int c;
