--- im-client/gcin-im-client.c.orig	Sat Feb 26 10:39:12 2005
+++ im-client/gcin-im-client.c	Tue Mar 15 00:15:47 2005
@@ -68,11 +68,7 @@
       save_old_sigaction_single(SIGCHLD, &ori_act);
 
       if ((pid=fork())==0) {
-#if 	FREEBSD
-        setgrp();
-#else
-        setpgrp();
-#endif
+        setpgrp(0, 0);
         execl(execbin, "gcin", NULL);
       } else {
         sleep(1);
