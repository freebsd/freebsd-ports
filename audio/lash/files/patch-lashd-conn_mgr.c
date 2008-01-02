--- lashd/conn_mgr.c.orig	2008-01-02 20:26:00.000000000 +0100
+++ lashd/conn_mgr.c	2008-01-02 20:27:11.000000000 +0100
@@ -759,7 +759,11 @@
 
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
