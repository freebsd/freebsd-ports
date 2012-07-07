--- src/SystemInfo.c.orig	1999-06-16 11:53:35.000000000 +0200
+++ src/SystemInfo.c	2012-07-07 15:30:50.000000000 +0200
@@ -117,7 +117,7 @@
 		free(sysinfo);
 	}
 	else {
-		wsyserror(_("Trying to free non-existent SystemInfo struct"));
+		werror(_("Trying to free non-existent SystemInfo struct"));
 	}
 }
 
