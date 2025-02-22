--- src/dbus.c.orig	2025-02-21 14:41:34 UTC
+++ src/dbus.c
@@ -745,7 +745,6 @@ static DBusMessage *dbus_get_server_metrics(DBusMessag
     if (!(serv->flags & SERV_MARK))
       {
 	unsigned int port;
-	unsigned int queries = 0, failed_queries = 0, nxdomain_replies = 0, retrys = 0;
 	unsigned int sigma_latency = 0, count_latency = 0;
 	
 	struct server *serv1;
@@ -754,10 +753,6 @@ static DBusMessage *dbus_get_server_metrics(DBusMessag
 	  if (!(serv1->flags & SERV_MARK) && sockaddr_isequal(&serv->addr, &serv1->addr))
 	    {
 	      serv1->flags |= SERV_MARK;
-	      queries += serv1->queries;
-	      failed_queries += serv1->failed_queries;
-	      nxdomain_replies += serv1->nxdomain_replies;
-	      retrys += serv1->retrys;
 	      sigma_latency += serv1->query_latency;
 	      count_latency++;
 	    }
