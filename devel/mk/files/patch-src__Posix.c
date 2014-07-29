--- src/Posix.c.orig	Thu Jul  3 16:08:16 2003
+++ src/Posix.c	Thu Jul  3 16:08:31 2003
@@ -276,14 +276,6 @@
 		signal(sigmsgs[i].sig, notifyf);
 }
 
-char*
-maketmp(void)
-{
-	static char temp[L_tmpnam];
-
-	return tmpnam(temp);
-}
-
 int
 chgtime(char *name)
 {

