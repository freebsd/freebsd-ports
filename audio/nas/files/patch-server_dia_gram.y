--- server/dia/gram.y.orig	2007-06-16 23:03:22.000000000 +0400
+++ server/dia/gram.y	2008-05-14 22:51:53.000000000 +0400
@@ -3,6 +3,7 @@
 
 
 %{
+#include <inttypes.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
@@ -14,14 +15,14 @@
 #include "misc.h"
 
 static char     *ptr;
-static int parsebool(char *str);
+static intptr_t parsebool(const char *str);
 extern int yylineno;
 
 %}
 
 %union
 {
-    int num;
+    intptr_t num;
     char *ptr;
 };
 
@@ -250,30 +251,21 @@
     *o = '\0';
 }
 
-static int
-parsebool(char *str)
+static intptr_t
+parsebool(const char *str)
 {
-    char *s;
-
-    s = str;
-
-    if (s == NULL)
+    if (str == NULL)
         return (-1);
 
-    while (*s) {
-        *s = (char) tolower(*s);
-        s++;
-    }
-
-    if (((char *) strstr("false", str) != NULL) ||
-        ((char *) strstr("no", str) != NULL) ||
-        ((char *) strstr("0", str) != NULL) ||
-        ((char *) strstr("off", str) != NULL)) {
+    if (((char *) strcasestr("false", str) != NULL) ||
+        ((char *) strcasestr("no", str) != NULL) ||
+        ((char *) strcasestr("0", str) != NULL) ||
+        ((char *) strcasestr("off", str) != NULL)) {
         return (FALSE);
-    } else if (((char *) strstr("true", str) != NULL) ||
-               ((char *) strstr("yes", str) != NULL) ||
-               ((char *) strstr("1", str) != NULL) ||
-               ((char *) strstr("on", str) != NULL)) {
+    } else if (((char *) strcasestr("true", str) != NULL) ||
+               ((char *) strcasestr("yes", str) != NULL) ||
+               ((char *) strcasestr("1", str) != NULL) ||
+               ((char *) strcasestr("on", str) != NULL)) {
         return (TRUE);
     } else {
         fprintf(stderr, "parsebool(): error parsing '%s', \n\t%s\n",
