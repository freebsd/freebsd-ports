--- spice3f5/common/src/lib/hlp/readhelp.c.orig	1994-01-29 18:44:53 UTC
+++ spice3f5/common/src/lib/hlp/readhelp.c
@@ -41,8 +41,8 @@ Author: 1986 Wayne A. Christopher, U. C.
 
 static char *getsubject();
 static toplink *getsubtoplink();
-extern void sortlist(), tlfree();
-extern int sortcmp();
+static void sortlist(), tlfree();
+static int sortcmp();
 
 static topic *alltopics = NULL;
 
