--- src/server.c.orig	Sun May  2 22:33:54 2004
+++ src/server.c	Sun May  2 22:34:29 2004
@@ -718,8 +718,8 @@
 					pos(status.idhostname, '@') + 1;
 			} else {
 				/* Should we do something about this ? */
-				status.idhostname = strdup("miau");
-				status.goodhostname = 0;
+				status.idhostname = strdup("miau@miau");
+				status.goodhostname = 5;
 			}
 
 #ifdef UPTIME
