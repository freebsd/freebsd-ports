--- src/backend/libpq/replicate.c.orig.1	Fri Feb 20 11:38:39 2004
+++ src/backend/libpq/replicate.c	Wed Feb 25 09:28:07 2004
@@ -645,6 +645,7 @@
 		return NULL;
 	}
 	sock = get_replicate_server_socket( sp , socket_type);
+	elog(DEBUG1, "get_replicate_server_socket() returns %d", sock);
 	if (sock == -1)
 	{
 		if (Debug_pretty_print)
@@ -668,7 +669,7 @@
 	while (send_replicate_packet(sock,&header,query_string) != STATUS_OK)
 	{
 		if (Debug_pretty_print)
-			elog(DEBUG1,"replication server: %s may be down",sp->hostName);
+			elog(DEBUG1,"replication server: %s may be down (cnt=%d, sock=%d)", sp->hostName, cnt, sock);
 		close_replicate_server_socket ( sp , socket_type);
 		sp->useFlag =  DATA_ERR;
 		sock = search_new_replication_server( sp,socket_type,&header);
@@ -760,6 +761,11 @@
 	fd_set      wmask;
 	struct timeval timeout;
 
+	/* check parameter */
+	if ((sock <= 0) || (header == NULL) || (query_string == NULL))
+	{
+		return STATUS_ERROR;
+	}
 	/*header->query_size +=1;*/
 	header_size = sizeof(ReplicateHeader);
 	buf_size = header_size + header->query_size + 4;
@@ -776,6 +782,7 @@
 	/*
 	 * Wait for something to happen.
 	 */
+	elog(DEBUG1, "send_replicate_packet(%d, %p, %s)", sock, header, query_string);
 	FD_ZERO(&wmask);
 	FD_SET(sock,&wmask);
 	rtn = select(sock+1, (fd_set *)NULL, &wmask, (fd_set *)NULL, &timeout);
@@ -1767,4 +1774,29 @@
 		return false;
 	}
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
