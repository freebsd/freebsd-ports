--- lashd/conn_mgr.c.orig	2007-04-08 21:18:23 UTC
+++ lashd/conn_mgr.c
@@ -759,7 +759,11 @@ conn_mgr_recv_run(void *data)
 
 			fprintf(stderr, "%s: error calling select(): %s\n", __FUNCTION__,
 					strerror(errno));
-			return NULL;
+
+			if (errno == EBADF)
+				continue;
+			else
+				return NULL;
 		}
 
 		if (conn_mgr->quit)
