--- sapi/apache/mod_php5.c.orig	Thu Jul 15 09:29:05 2004
+++ sapi/apache/mod_php5.c	Thu Jul 15 09:30:01 2004
@@ -485,7 +485,7 @@
 		tmp = uudecode(r->pool, authorization);
 		SG(request_info).auth_user = NULL;
 		tmp_user = getword_nulls_nc(r->pool, &tmp, ':');
-		if (SG(request_info).auth_user) {
+		if (tmp_user) {
 			r->connection->user = pstrdup(r->connection->pool, tmp_user);
 			r->connection->ap_auth_type = "Basic";
 			SG(request_info).auth_user = estrdup(tmp_user);
