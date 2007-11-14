--- ircd/s_service.c.orig	2007-11-14 03:09:34.000000000 +0600
+++ ircd/s_service.c	2007-11-14 03:09:42.000000000 +0600
@@ -70,7 +70,7 @@
 			free_server(serv->servp, cptr);
 		if (serv->server)
 			MyFree(serv->server);
-		MyFree((char *)serv);
+		MyFree(serv);
 		cptr->service = NULL;
 	    }
 }
