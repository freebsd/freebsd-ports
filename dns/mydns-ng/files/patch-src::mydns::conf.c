--- src/mydns/conf.c.orig	Fri Nov 28 12:04:45 2003
+++ src/mydns/conf.c	Fri Nov 28 12:04:58 2003
@@ -351,7 +351,7 @@
 
 	/* Set additional where clauses if provided */
 	mydns_set_soa_where_clause(conf_get(&Conf, "soa-where", NULL));
-	mydns_set_rr_where_clause(conf_get(&Conf, "soa-where", NULL));
+	mydns_set_rr_where_clause(conf_get(&Conf, "rr-where", NULL));
 }
 /*--- load_config() -----------------------------------------------------------------------------*/
 
