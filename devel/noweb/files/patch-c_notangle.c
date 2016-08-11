--- c/notangle.c.orig	2006-06-12 21:16:23 UTC
+++ c/notangle.c
@@ -44,7 +44,7 @@ void read_defs(FILE *in) {
     char *line = NULL;          /* buffer for input */
     Location loc;
 
-    while ((line = getline(in)) != NULL) {
+    while ((line = get_line(in)) != NULL) {
         if (is_keyword(line, "fatal")) exit(1);
         
 #line 101 "notangle.nw"
@@ -90,7 +90,7 @@ if (!is_begin(line, "code"))
 #line 66 "notangle.nw"
         
 #line 97 "notangle.nw"
-do { line = getline(in);
+do { line = get_line(in);
 } while (line != NULL && !is_keyword(line,"defn") && !is_keyword(line,"text"));
 #line 67 "notangle.nw"
         insist(line,"defn","code chunk had no definition line");
@@ -102,10 +102,10 @@ modname[strlen(modname)-1]='\0';
         warn_dots(modname);       /* names ending in ... aren't like web */
         modptr = insert(modname); /* find or add module in table */
 
-        line = getline(in);
+        line = get_line(in);
         insist(line,"nl","definition line not followed by newline");
         loc.lineno++;
-        line = getline(in);
+        line = get_line(in);
         while (line != NULL && !is_end(line,"code")) {
             if (is_keyword(line,"nl")) {
                 addnewline(modptr);
@@ -157,7 +157,7 @@ modname[strlen(modname)-1]='\0';
 #line 182 "notangle.nw"
 errorat(loc.filename, loc.lineno, Error, "botched code chunk `%s'", line);
 #line 90 "notangle.nw"
-            line = getline(in);
+            line = get_line(in);
         }
         
 #line 176 "notangle.nw"
