--- src/tim/timtable.c.orig	Sat Oct 18 05:34:57 2003
+++ src/tim/timtable.c	Sat Oct 18 05:35:14 2003
@@ -86,7 +86,7 @@
 
         line = (char *)malloc(n*sizeof(char));;
         /* getline() is a GNU externsion */
-        while ((l = getline(&line, &n, fp)) > 0) {
+        while ((l = fgets(line, n, fp)) > 0) {
             l = preprocess_line(line, l);
             if (l > 0) {
                 char *p;
@@ -189,7 +189,7 @@
 
         line = (char *)malloc(n*sizeof(char));;
         /* getline() is a GNU externsion */
-        while ((l = getline(&line, &n, fp)) > 0) {
+        while ((l = fgets(line, n, fp)) > 0) {
             l = preprocess_line(line, l);
             if (l > 0) {
                 char *p;
