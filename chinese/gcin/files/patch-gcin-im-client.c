--- im-client/gcin-im-client.c.orig	Fri Mar 25 16:52:27 2005
+++ im-client/gcin-im-client.c	Sat Apr 23 21:43:56 2005
@@ -71,7 +71,7 @@
 #if 	FREEBSD
         setgrp();
 #else
-        setpgrp();
+        setpgrp(0, getpid());
 #endif
         execl(execbin, "gcin", NULL);
       } else {
