--- battlestar/init.c.old	Mon Dec 15 17:48:41 2003
+++ battlestar/init.c	Mon Dec 15 17:48:54 2003
@@ -62,7 +62,7 @@
 	puts("Admiral D.W. Riggle\n");
 	srandomdev();
 	getutmp(uname);
-	if (startup)
+	if (startup == NULL)
 		location = dayfile;
 	wiz = wizard(uname);
 	wordinit();
