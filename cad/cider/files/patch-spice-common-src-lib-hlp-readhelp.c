--- spice/common/src/lib/hlp/readhelp.c.orig	Sun Jan 30 03:44:53 1994
+++ spice/common/src/lib/hlp/readhelp.c	Fri Dec 22 20:58:15 2006
@@ -41,8 +41,8 @@
 
 static char *getsubject();
 static toplink *getsubtoplink();
-extern void sortlist(), tlfree();
-extern int sortcmp();
+static void sortlist(), tlfree();
+static int sortcmp();
 
 static topic *alltopics = NULL;
 
