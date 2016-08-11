--- regutil.c.orig	2004-01-16 14:57:12 UTC
+++ regutil.c
@@ -52,7 +52,7 @@ static void gettimeofday(struct timeval 
 
 struct {
     char * name;
-    APIRET (APIENTRY*funcptr)(PUCHAR fname, ULONG argc, PRXSTRING argv, PSZ pSomething, PRXSTRING result);
+    APIRET (APIENTRY*funcptr)(PCSZ fname, ULONG argc, PRXSTRING argv, PCSZ pSomething, PRXSTRING result);
 } funclist[] = {
     {"SYSADDREXXMACRO", sysaddrexxmacro},
     {"SYSCLEARREXXMACROSPACE", sysclearrexxmacrospace},
