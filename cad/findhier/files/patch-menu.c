--- menu.c.orig	Sun Apr 29 00:54:06 2007
+++ menu.c	Sun Apr 29 00:54:30 2007
@@ -9,7 +9,7 @@
 #include <errno.h>
 #ifndef _UNIX_
 #include <process.h>
-#endif _UNIX_
+#endif /* _UNIX_ */
 
 #define PROMPT "FindHier>"
 /*
@@ -102,7 +102,7 @@
 	(void)sprintf(tmpfname,"/tmp/FindHier_%d",getpid());
 #else
 	(void)sprintf(tmpfname,".\\findhier.%3x",getpid() & 0xfff);
-#endif _UNIX_
+#endif /* _UNIX_ */
 	pager=getenv("PAGER");
 	if (pager==NULL) {
 		pager=(char *)myalloc(sizeof("more"),"menu");
@@ -112,7 +112,7 @@
 	(void)sprintf(pagercmd,"%s %s",pager,tmpfname);
 #else
 	(void)sprintf(pagercmd,"%s < %s",pager,tmpfname);
-#endif _UNIX_
+#endif /* _UNIX_ */
 
 	for(;;) {
 
