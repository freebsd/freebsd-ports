--- scripts/init.sl.orig	Sun Aug 22 03:22:41 1999
+++ scripts/init.sl	Sat Jan  6 21:23:30 2001
@@ -56,7 +56,7 @@
 		 return;
 	 }
 	 variable w = vf_write(irc_server, st);
-   if (w == strlen(st)) return;
+   if (w >= strlen(st)) return;
    irc_Inff("incomplete server write: %d/%d",w,strlen(st));
 %  () = fflush(irc_server);
 }
