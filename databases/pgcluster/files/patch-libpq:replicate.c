--- src/backend/libpq/replicate.c	9 May 2004 11:21:32 -0000	1.1.1.12
+++ src/backend/libpq/replicate.c	9 May 2004 11:51:34 -0000	1.7
@@ -637,6 +637,7 @@
 		return NULL;
 	}
 	sock = get_replicate_server_socket( sp , socket_type);
+	elog(DEBUG1, "get_replicate_server_socket() returns %d", sock);
 	if (sock < 0)
 	{
 		if (Debug_pretty_print)
@@ -2183,4 +2184,29 @@
 	free(result);
 	return false;
 }
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
+}
+
 #endif /* USE_REPLICATION */
