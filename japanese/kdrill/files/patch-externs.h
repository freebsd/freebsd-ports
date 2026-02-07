--- externs.h.orig	2002-10-01 06:52:38 UTC
+++ externs.h
@@ -35,7 +35,7 @@ extern void ClearCheat();
 
 /* other "usefull" general functions */
 extern int xtoi(char *);
-extern int getline(FILE *, unsigned char *);
+extern int get_line(FILE *, unsigned char *);
 extern void setstatus(char *);
 
 extern int FindIndex(char *);
