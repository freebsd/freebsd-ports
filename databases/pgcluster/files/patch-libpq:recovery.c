--- src/backend/libpq/recovery.c.orig	Fri Feb 20 11:38:39 2004
+++ src/backend/libpq/recovery.c	Mon Feb 23 14:44:15 2004
@@ -756,14 +756,14 @@
 
 	if (Debug_pretty_print)
 	{
-		elog(DEBUG1,"no = %d\n",packet->packet_no);
-		elog(DEBUG1,"max_connect = %d\n",packet->max_connect);
-		elog(DEBUG1,"port = %d\n",packet->port);
-		elog(DEBUG1,"recoveryPort = %d\n",packet->recoveryPort);
+		elog(DEBUG1,"no = %d",packet->packet_no);
+		elog(DEBUG1,"max_connect = %d",packet->max_connect);
+		elog(DEBUG1,"port = %d",packet->port);
+		elog(DEBUG1,"recoveryPort = %d",packet->recoveryPort);
 		if (packet->hostName != NULL)
-			elog(DEBUG1,"hostName = %s\n",packet->hostName);
+			elog(DEBUG1,"hostName = %s",packet->hostName);
 		if (packet->pg_data != NULL)
-			elog(DEBUG1,"pg_data = %s\n",packet->pg_data);
+			elog(DEBUG1,"pg_data = %s",packet->pg_data);
 	}
 }
 
