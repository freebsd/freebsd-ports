--- src/backend/libpq/replicate.c	17 Apr 2004 14:41:22 -0000	1.1.1.11
+++ src/backend/libpq/replicate.c	17 Apr 2004 14:44:29 -0000	1.6
@@ -635,6 +635,7 @@
 		return NULL;
 	}
 	sock = get_replicate_server_socket( sp , socket_type);
+	elog(DEBUG1, "get_replicate_server_socket() returns %d", sock);
 	if (sock < 0)
 	{
 		if (Debug_pretty_print)
@@ -2067,6 +2068,30 @@
 		return 1;
 	}
 	return 0;
+}
+
+extern Datum pgr_current_replicator(PG_FUNCTION_ARGS);
+PG_FUNCTION_INFO_V1(pgr_current_replicator);
+
+Datum
+pgr_current_replicator(PG_FUNCTION_ARGS)
+{
+	int	len;
+	char	buf[HOSTNAME_MAX_LENGTH + 6];
+	text	*result;
+	ReplicateServerInfo	*sp;
+
+	sp = PGR_get_replicate_server_info();
+	if (sp == NULL) {
+		PG_RETURN_NULL();
+	}
+	len = snprintf(buf, sizeof(buf), "%s:%d",
+		       sp->hostName, sp->portNumber);
+	result = palloc(VARHDRSZ + len);
+	VARATT_SIZEP(result) = VARHDRSZ + len;
+	memcpy(VARDATA(result), buf, len);
+
+	PG_RETURN_TEXT_P(result);
 }
 
 #endif /* USE_REPLICATION */
