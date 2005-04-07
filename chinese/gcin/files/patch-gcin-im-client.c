--- im-client/gcin-im-client.c.orig	Thu Apr  7 09:18:13 2005
+++ im-client/gcin-im-client.c	Thu Apr  7 09:18:27 2005
@@ -71,7 +71,7 @@
 #if 	FREEBSD
         setgrp();
 #else
-        setpgrp();
+        setpgrp(0, 0);
 #endif
         execl(execbin, "gcin", NULL);
       } else {
