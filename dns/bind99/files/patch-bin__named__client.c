--- bin/named/client.c.orig	2011-11-09 14:05:09.000000000 -0800
+++ bin/named/client.c	2012-03-16 23:07:00.000000000 -0700
@@ -240,7 +240,7 @@
 	REQUIRE(client->state == NS_CLIENTSTATE_WORKING);
 
 	LOCK(&client->manager->reclock);
-	client->state = NS_CLIENTSTATE_RECURSING;
+	client->newstate = client->state = NS_CLIENTSTATE_RECURSING;
 	ISC_LIST_APPEND(client->manager->recursing, client, rlink);
 	UNLOCK(&client->manager->reclock);
 }
