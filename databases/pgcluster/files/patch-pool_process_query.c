--- src/pgcluster/pglb/pool_process_query.c.orig	Sat Jan 24 14:14:51 2004
+++ src/pgcluster/pglb/pool_process_query.c	Sat Jan 24 14:15:00 2004
@@ -728,10 +728,11 @@
 static POOL_STATUS EmptyQueryResponse(POOL_CONNECTION *frontend,
 									  POOL_CONNECTION *backend)
 {
+	char c;
+
 	/* set function name */
 	set_function("EmptyQueryResponse");
 
-	char c;
 	if (pool_read(backend, &c, sizeof(c)) < 0)
 		return POOL_END;
 
