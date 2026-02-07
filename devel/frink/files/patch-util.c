--- util.c.orig	2002-12-11 23:07:50 UTC
+++ util.c
@@ -104,12 +104,6 @@ void lapply(List * l, void (*fn)(void *))
     }
 }
 
-char * newString(char *t)
-{
-    return strcpy(malloc(strlen(t)+1), t);
-}
-
-
 int doTest(enum Heuristics x)
 {
    extern int pragma;
