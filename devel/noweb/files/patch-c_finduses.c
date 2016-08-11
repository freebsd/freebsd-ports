--- c/finduses.c.orig	2006-06-12 21:16:23 UTC
+++ c/finduses.c
@@ -49,7 +49,7 @@ main(int argc, char **argv) {
 #line 155 "finduses.nw"
 errormsg(Fatal, "%s: couldn't open temporary file\n", progname);
 #line 78 "finduses.nw"
-    while ((line = getline(stdin)) != NULL) {
+    while ((line = get_line(stdin)) != NULL) {
         if (fputs(line, tmp) == EOF) 
 #line 157 "finduses.nw"
 errormsg(Fatal, "%s: error writing temporary file\n", progname);
@@ -89,7 +89,7 @@ for (; i < argc; i++)
 #line 66 "finduses.nw"
 static void read_ids(FILE *in) {
     char *line;
-    while ((line = getline(in)) != NULL) {
+    while ((line = get_line(in)) != NULL) {
         if (line[strlen(line)-1] == '\n') line[strlen(line)-1] = 0;
         add_ident(nwindex, line);
     }
@@ -100,7 +100,7 @@ static void add_use_markers(FILE *in, FI
     int incode = 0;
     LineOut info; info.line = (char *)0; info.out = out;
     
-    while ((line = getline(in)) != NULL) {
+    while ((line = get_line(in)) != NULL) {
         if (is_begin(line, "code") || showquotes && is_keyword(line, "quote"))
             incode = 1;
         else if (is_end(line, "code") || is_keyword(line, "endquote"))
