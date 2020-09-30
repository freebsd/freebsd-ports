--- util.h.orig	2002-12-11 22:21:48 UTC
+++ util.h
@@ -57,7 +57,7 @@ extern void lappend(List **, void*);
 extern void ldel(List **, int);
 extern void lapply(List *, void(*)(void *));
 
-extern char *newString(char *);
+#define newString(t)	strdup(t)
 extern int doTest(enum Heuristics);
 
 #endif
