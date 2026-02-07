--- flagvars.h.orig	2002-12-11 22:22:22 UTC
+++ flagvars.h
@@ -14,7 +14,7 @@
 extern int failed;
 
 extern int lineNumber;
-extern char *currentfile;
+extern const char *currentfile;
 
 extern int compout;
 extern int noquotes;
@@ -63,11 +63,11 @@ extern int noheuristics;
 extern int nocommand;
 extern int trystrings;
 
-extern char *style;
-extern char *pstyle;
-extern char *contString;
+extern const char *style;
+extern const char *pstyle;
+extern const char *contString;
 
-extern char *locale;
+extern const char *locale;
 extern FILE *msgfile;
 extern FILE *specfile;
 
