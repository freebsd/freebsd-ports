--- src/mydns/conf.c.orig	Fri Dec 12 06:02:22 2003
+++ src/mydns/conf.c	Tue Dec 16 08:16:03 2003
@@ -429,7 +429,7 @@
 
 	/* Set additional where clauses if provided */
 	mydns_set_soa_where_clause(conf_get(&Conf, "soa-where", NULL));
-	mydns_set_rr_where_clause(conf_get(&Conf, "soa-where", NULL));
+	mydns_set_rr_where_clause(conf_get(&Conf, "rr-where", NULL));
 
 	/* Set recursive server if specified */
 	conf_set_recursive();
