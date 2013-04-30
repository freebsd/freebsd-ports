--- src/lib/misc/string.c.orig	2013-05-01 03:50:59.000000000 +0900
+++ src/lib/misc/string.c	2013-05-01 03:58:30.000000000 +0900
@@ -148,13 +148,15 @@
         (*s)++;
     if (!**s)
         return (NULL);
-    while ((c = **s) && !isspace(c)) {
+    while ((c = **s)) {
 	if (c == '('/*)*/)
 	    paren += 1;
 	else if (c == /*(*/')')
 	    paren -= 1;
 	else if (c == ',' && paren < 1)
 	    break;
+	else if (isspace(c) && paren < 1)
+	    break;
         buf[i++] = *(*s)++;
     }
     buf[i] = '\0';
