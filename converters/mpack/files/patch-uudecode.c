--- uudecode.c.orig	Mon Jul 21 23:46:37 2003
+++ uudecode.c	Mon Mar 27 17:27:52 2006
@@ -23,8 +23,10 @@
  * SOFTWARE.
  */
 #include <stdio.h>
+#include <stdlib.h>
 #include <ctype.h>
 #include <string.h>
+#include <unistd.h>
 #include "xmalloc.h"
 #include "common.h"
 #include "part.h"
@@ -32,9 +34,25 @@
 extern char *os_idtodir(char *id);
 extern FILE *os_newtypedfile(char *fname, char *contentType, int flags, params contentParams);
 extern FILE *os_createnewfile(char *fname);
+extern int os_binhex(struct part *inpart, int part, int nparts);
+extern void os_closetypedfile(FILE *outfile);
+extern void os_donewithdir(char *dir);
+extern void os_perror(char *str);
+extern void chat(char *s);
+
+extern void part_ungets(char *s, struct part *part);
+extern void part_close(struct part *part);
+extern int handleMessage(struct part *inpart, char *defaultContentType,
+			 int inAppleDouble, int extractText);
 
 static FILE *startDescFile(char *fname);
+static void uudecodeline(char *line, FILE *outfile);
 
+int parseSubject(unsigned char *subject, char **fnamep, int *partp, int *npartsp);
+int saveUuFile(struct part *inpart, char *fname, int part, int nparts,
+	       char *firstline);
+int descEnd(char *line);
+int uudecodefiles(char *dir, int nparts);
 
 /* Length of a normal uuencoded line, including newline */
 #define UULENGTH 62
@@ -266,7 +284,7 @@
 	}
 	else if (part == 1 && fname && !descfile &&
 		 !strncasecmp(buf, "x-file-desc: ", 13)) {
-	    if (descfile = startDescFile(fname)) {
+	    if ((descfile = startDescFile(fname))) {
 		fputs(buf+13, descfile);
 		fclose(descfile);
 		descfile = 0;
@@ -454,7 +472,7 @@
     /* Retrieve any previously saved number of the last part */
     if (nparts == 0) {
 	sprintf(buf, "%sCT", dir);
-	if (partfile = fopen(buf, "r")) {
+	if ((partfile = fopen(buf, "r"))) {
 	    if (fgets(buf, sizeof(buf), partfile)) {
 		nparts = atoi(buf);
 		if (nparts < 0) nparts = 0;
@@ -487,9 +505,9 @@
  * split-uuencoded data.
  */
 int
-parseSubject(char *subject, char **fnamep, int *partp, int *npartsp)
+parseSubject(unsigned char *subject, char **fnamep, int *partp, int *npartsp)
 {
-    char *scan, *bak, *start;
+    unsigned char *scan, *bak, *start;
     int part = -1, nparts = 0, hasdot = 0;
 
     /* No subject header */
@@ -722,7 +740,7 @@
 		if (!*fname) return 1;
 
 		/* Guess the content-type of common filename extensions */
-		if (p = strrchr(fname, '.')) {
+		if ((p = strrchr(fname, '.'))) {
 		    if (!strcasecmp(p, ".gif")) contentType = "image/gif";
 		    if (!strcasecmp(p, ".jpg")) contentType = "image/jpeg";
 		    if (!strcasecmp(p, ".jpeg")) contentType = "image/jpeg";
@@ -826,7 +844,7 @@
 /*
  * Decode a uuencoded line to 'outfile'
  */
-int uudecodeline(char *line, FILE *outfile)
+static void uudecodeline(char *line, FILE *outfile)
 {
     int c, len;
 
@@ -845,7 +863,6 @@
 	}
 	line += 4;
     }
-    return;
 }
 
     
