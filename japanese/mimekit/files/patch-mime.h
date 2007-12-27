--- mime.h.orig	2007-11-11 17:53:39.000000000 +0900
+++ mime.h	2007-11-11 17:54:14.000000000 +0900
@@ -23,6 +23,7 @@
 extern char *MimeKit_Version;
 
 #include <stdio.h>
+#include <stdlib.h>
 #include <ctype.h>
 #include "ystring.h"
 
@@ -31,8 +32,6 @@
 #endif
 #define substr(s1,s2)	(strncasecmp(s1,s2,strlen(s2)) == 0)
 
-extern char *malloc();
-extern char *realloc();
 extern char *findFieldValue();
 extern FILE *TMPFILE();
 
