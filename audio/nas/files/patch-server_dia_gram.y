--- server/dia/gram.y	Mon Dec 22 21:00:04 2003
+++ server/dia/gram.y	Mon Oct 10 10:46:03 2005
@@ -4,4 +4,5 @@
 
 %{
+#include <inttypes.h>
 #include <stdio.h>
 #include <stdlib.h>
@@ -15,5 +16,5 @@
 
 static char	*ptr;
-static int parsebool(char *str);
+static intptr_t parsebool(const char *str);
 extern int yylineno;
 
@@ -22,5 +23,5 @@
 %union
 {
-    int num;
+    intptr_t num;
     char *ptr;
 };
@@ -239,30 +240,21 @@
 }
 
-static int parsebool(char *str)
+static intptr_t
+parsebool(const char *str)
 {
-  char *s;
-
-  s = str;
-
-  if (s == NULL)
+  if (str == NULL)
     return(-1);
 
-  while(*s)
-    {
-      *s = (char)tolower(*s);
-      s++;
-    }
-
-  if (((char *)strstr("false", str) != NULL) ||
-      ((char *)strstr("no", str) != NULL)    ||
-      ((char *)strstr("0", str) != NULL)     ||
-      ((char *)strstr("off", str) != NULL))
+  if (((char *)strcasestr("false", str) != NULL) ||
+      ((char *)strcasestr("no", str) != NULL)    ||
+      ((char *)strcasestr("0", str) != NULL)     ||
+      ((char *)strcasestr("off", str) != NULL))
     {
       return(FALSE);
     }
-  else if (((char *)strstr("true", str) != NULL) ||
-           ((char *)strstr("yes", str) != NULL)  ||
-           ((char *)strstr("1", str) != NULL)    ||
-           ((char *)strstr("on", str) != NULL))
+  else if (((char *)strcasestr("true", str) != NULL) ||
+           ((char *)strcasestr("yes", str) != NULL)  ||
+           ((char *)strcasestr("1", str) != NULL)    ||
+           ((char *)strcasestr("on", str) != NULL))
     {
       return(TRUE);
