--- bin/named/query.c.orig	2011-04-27 10:06:27.000000000 -0700
+++ bin/named/query.c	2011-05-27 15:00:15.000000000 -0700
@@ -637,6 +637,7 @@
 		dns_db_attach(db, &dbversion->db);
 		dns_db_currentversion(db, &dbversion->version);
 		dbversion->acl_checked = ISC_FALSE;
+		dbversion->queryok = ISC_FALSE;
 		ISC_LIST_APPEND(client->query.activeversions,
 				dbversion, link);
 	}
@@ -768,6 +769,7 @@
 		dbversion->queryok = ISC_FALSE;
 		return (DNS_R_REFUSED);
 	}
+	dbversion->queryok = ISC_TRUE;
 
  approved:
 	/* Transfer ownership, if necessary. */
