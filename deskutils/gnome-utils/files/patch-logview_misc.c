--- logview/misc.c.orig	Tue Apr 18 21:28:07 2006
+++ logview/misc.c	Tue Apr 18 21:28:30 2006
@@ -135,15 +135,15 @@ string_get_date (char *line)
 {
     GDate *date;
     struct tm tp;
-    int cp;
+    char *cp;
     
     if (line == NULL || line[0] == 0)
         return NULL;
 
     cp = strptime (line, "%b %d", &tp);
-    if (cp == 0) {
+    if (cp == NULL) {
         cp = strptime (line, "%F", &tp);
-        if (cp == 0) {
+        if (cp == NULL) {
             return NULL;
         }
     }
