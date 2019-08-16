--- src/cluster.c.orig	2017-10-08 08:53:35 UTC
+++ src/cluster.c
@@ -588,7 +588,11 @@ reload_sqlmed_user(ProxyFunction *func, 
 	 */
 	aclresult = pg_foreign_server_aclcheck(um->serverid, um->userid, ACL_USAGE);
 	if (aclresult != ACLCHECK_OK)
+#if PG_VERSION_NUM >= 110000
+		aclcheck_error(aclresult, OBJECT_FOREIGN_SERVER, cluster->name);
+#else
 		aclcheck_error(aclresult, ACL_KIND_FOREIGN_SERVER, cluster->name);
+#endif
 
 	/* Extract the common connect string elements from user mapping */
 	got_user = false;
@@ -657,7 +661,11 @@ reload_sqlmed_cluster(ProxyFunction *fun
 	 */
 	aclresult = pg_foreign_server_aclcheck(foreign_server->serverid, info->user_oid, ACL_USAGE);
 	if (aclresult != ACLCHECK_OK)
+#if PG_VERSION_NUM >= 110000
+		aclcheck_error(aclresult, OBJECT_FOREIGN_SERVER, foreign_server->servername);
+#else
 		aclcheck_error(aclresult, ACL_KIND_FOREIGN_SERVER, foreign_server->servername);
+#endif
 
 	/* drop old config values */
 	clear_config(&cluster->config);
