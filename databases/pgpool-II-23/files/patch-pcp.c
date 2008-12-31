Index: pcp/pcp.c
===================================================================
RCS file: /cvsroot/pgpool/pgpool-II/pcp/pcp.c,v
retrieving revision 1.7
diff -u -r1.7 pcp.c
--- pcp/pcp.c	8 Feb 2008 08:10:43 -0000	1.7
+++ pcp/pcp.c	29 Dec 2008 05:15:44 -0000
@@ -42,6 +42,11 @@
 struct timeval pcp_timeout;
 
 static PCP_CONNECTION *pc;
+#ifdef DEBUG
+static int debug = 1;
+#else
+static int debug = 0;
+#endif
 static int pcp_authorize(char *username, char *password);
 
 /* --------------------------------
@@ -62,9 +67,7 @@
 
 	if (pc != NULL)
 	{
-#ifdef DEBUG
-		fprintf(stderr, "DEBUG: connection to backend \"%s\" already exists\n", hostname);
-#endif
+		if (debug) fprintf(stderr, "DEBUG: connection to backend \"%s\" already exists\n", hostname);
 		return 0;
 	}
 
@@ -76,9 +79,7 @@
 
 		if (fd < 0)
 		{
-#ifdef DEBUG
-			fprintf(stderr, "DEBUG: could not create socket\n");
-#endif
+			if (debug) fprintf(stderr, "DEBUG: could not create socket\n");
 			errorcode = SOCKERR;
 			return -1;
 		}
@@ -100,9 +101,7 @@
 
 		if (connect(fd, (struct sockaddr *) &unix_addr, sizeof(unix_addr)) < 0)
 		{
-#ifdef DEBUG
-			fprintf(stderr, "DEBUG: could not connect to \"%s\"\n", unix_addr.sun_path);
-#endif
+			if (debug) fprintf(stderr, "DEBUG: could not connect to \"%s\"\n", unix_addr.sun_path);
 			close(fd);
 			errorcode = CONNERR;
 			return -1;
@@ -113,9 +112,7 @@
 		fd = socket(AF_INET, SOCK_STREAM, 0);
 		if (fd < 0)
 		{
-#ifdef DEBUG
-			fprintf(stderr, "DEBUG: could not create socket\n");
-#endif
+		  	if (debug) fprintf(stderr, "DEBUG: could not create socket\n");
 			errorcode = SOCKERR;
 			return -1;
 		}
@@ -123,9 +120,7 @@
 		if (setsockopt(fd, IPPROTO_TCP, TCP_NODELAY,
 					   (char *) &on, sizeof(on)) < 0)
 		{
-#ifdef DEBUG
-			fprintf(stderr, "DEBUG: could not set socket option\n");
-#endif
+			if (debug) fprintf(stderr, "DEBUG: could not set socket option\n");
 			close(fd);
 			errorcode = SOCKERR;
 			return -1;
@@ -136,9 +131,7 @@
 		hp = gethostbyname(hostname);
 		if ((hp == NULL) || (hp->h_addrtype != AF_INET))
 		{
-#ifdef DEBUG
-			fprintf(stderr, "DEBUG: could not retrieve hostname\n");
-#endif
+			if (debug) fprintf(stderr, "DEBUG: could not retrieve hostname\n");
 			close(fd);
 			errorcode = HOSTERR;
 			return -1;
@@ -151,9 +144,7 @@
 		len = sizeof(struct sockaddr_in);
 		if (connect(fd, (struct sockaddr *) &addr, len) < 0)
 		{
-#ifdef DEBUG
-			fprintf(stderr, "DEBUG: could not connect to \"%s\"\n", hostname);
-#endif
+			if (debug) fprintf(stderr, "DEBUG: could not connect to \"%s\"\n", hostname);
 			close(fd);
 			errorcode = CONNERR;
 			return -1;
@@ -163,9 +154,7 @@
 	pc = pcp_open(fd);
 	if (pc == NULL)
 	{
-#ifdef DEBUG
-		fprintf(stderr, "DEBUG: could not allocate buffer space\n");
-#endif
+		if (debug) fprintf(stderr, "DEBUG: could not allocate buffer space\n");
 		close(fd);
 		return -1;
 	}
@@ -202,9 +191,7 @@
 	pcp_write(pc, &wsize, sizeof(int));
 	if (pcp_flush(pc) < 0)
 	{
-#ifdef DEBUG
-		fprintf(stderr, "DEBUG: could not send data to backend\n");
-#endif
+		if (debug) fprintf(stderr, "DEBUG: could not send data to backend\n");
 		return -1;
 	}
 
@@ -243,14 +230,10 @@
 	pcp_write(pc, encrypt_buf, strlen(encrypt_buf)+1);
 	if (pcp_flush(pc) < 0)
 	{
-#ifdef DEBUG
-		fprintf(stderr, "DEBUG: could not send data to backend\n");
-#endif
+		if  (debug) fprintf(stderr, "DEBUG: could not send data to backend\n");
 		return -1;
 	}
-#ifdef DEBUG
-	fprintf(stderr, "DEBUG: send: tos=\"R\", len=%d\n", ntohl(wsize));
-#endif
+	if (debug) fprintf(stderr, "DEBUG: send: tos=\"R\", len=%d\n", ntohl(wsize));
 
 	if (pcp_read(pc, &tos, 1))
 		return -1;
@@ -265,15 +248,11 @@
 	}
 	if (pcp_read(pc, buf, rsize - sizeof(int)))
 		return -1;
-#ifdef DEBUG
-	fprintf(stderr, "DEBUG: recv: tos=\"%c\", len=%d, data=%s\n", tos, rsize, buf);
-#endif
+	if (debug) fprintf(stderr, "DEBUG: recv: tos=\"%c\", len=%d, data=%s\n", tos, rsize, buf);
 
 	if (tos == 'e')
 	{
-#ifdef DEBUG
-		fprintf(stderr, "DEBUG: command failed. reason=%s\n", buf);
-#endif
+		if (debug) fprintf(stderr, "DEBUG: command failed. reason=%s\n", buf);
 		errorcode = BACKENDERR;
 	}
 	else if (tos == 'r')
@@ -284,9 +263,7 @@
 			return 0;
 		}
 
-#ifdef DEBUG
-		fprintf(stderr, "DEBUG: authentication failed. reason=%s\n", buf);
-#endif
+		if (debug) fprintf(stderr, "DEBUG: authentication failed. reason=%s\n", buf);
 		errorcode = AUTHERR;
 	}
 	free(buf);
@@ -305,9 +282,7 @@
 
 	if (pc == NULL)
 	{
-#ifdef DEBUG
-		fprintf(stderr, "DEBUG: connection does not exist\n");
-#endif
+		if (debug) fprintf(stderr, "DEBUG: connection does not exist\n");
 		return;
 	}
 
@@ -318,9 +293,7 @@
 	{
 		/* backend had closed connection already */
 	}
-#ifdef DEBUG
-	fprintf(stderr, "DEBUG: send: tos=\"X\", len=%d\n", sizeof(int));
-#endif
+	if (debug) fprintf(stderr, "DEBUG: send: tos=\"X\", len=%d\n", sizeof(int));
 
 	pcp_close(pc);
 	pc = NULL;
@@ -339,9 +312,7 @@
 
 	if (pc == NULL)
 	{
-#ifdef DEBUG
-		fprintf(stderr, "DEBUG: connection does not exist\n");
-#endif
+		if (debug) fprintf(stderr, "DEBUG: connection does not exist\n");
 		errorcode = NOCONNERR;
 		return -1;
 	}
@@ -352,14 +323,10 @@
 	pcp_write(pc, &mode, sizeof(char));
 	if (pcp_flush(pc) < 0)
 	{
-#ifdef DEBUG
-		fprintf(stderr, "DEBUG: could not send data to backend\n");
-#endif
+		if (debug) fprintf(stderr, "DEBUG: could not send data to backend\n");
 		return -1;
 	}
-#ifdef DEBUG
-	fprintf(stderr, "DEBUG: send: tos=\"T\", len=%d\n", ntohl(wsize));
-#endif
+	if (debug) fprintf(stderr, "DEBUG: send: tos=\"T\", len=%d\n", ntohl(wsize));
 
 	return 0;
 }
@@ -381,9 +348,7 @@
 
 	if (pc == NULL)
 	{
-#ifdef DEBUG
-		fprintf(stderr, "DEBUG: connection does not exist\n");
-#endif
+		if (debug) fprintf(stderr, "DEBUG: connection does not exist\n");
 		errorcode = NOCONNERR;
 		return -1;
 	}
@@ -393,14 +358,10 @@
 	pcp_write(pc, &wsize, sizeof(int));
 	if (pcp_flush(pc) < 0)
 	{
-#ifdef DEBUG
-		fprintf(stderr, "DEBUG: could not send data to backend\n");
-#endif
+		if (debug) fprintf(stderr, "DEBUG: could not send data to backend\n");
 		return -1;
 	}
-#ifdef DEBUG
-	fprintf(stderr, "DEBUG: send: tos=\"L\", len=%d\n", ntohl(wsize));
-#endif
+	if (debug) fprintf(stderr, "DEBUG: send: tos=\"L\", len=%d\n", ntohl(wsize));
 
 	if (pcp_read(pc, &tos, 1))
 		return -1;
@@ -419,15 +380,11 @@
 		return -1;
 	}
 
-#ifdef DEBUG
-	fprintf(stderr, "DEBUG: recv: tos=\"%c\", len=%d, data=%s\n", tos, rsize, buf);
-#endif
+	if (debug) fprintf(stderr, "DEBUG: recv: tos=\"%c\", len=%d, data=%s\n", tos, rsize, buf);
 
 	if (tos == 'e')
 	{
-#ifdef DEBUG
-		fprintf(stderr, "DEBUG: command failed. reason=%s\n", buf);
-#endif
+		if (debug) fprintf(stderr, "DEBUG: command failed. reason=%s\n", buf);
 		errorcode = BACKENDERR;
 	}
 	else if (tos == 'l')
@@ -466,9 +423,7 @@
 
 	if (pc == NULL)
 	{
-#ifdef DEBUG
-		fprintf(stderr, "DEBUG: connection does not exist\n");
-#endif
+		if (debug) fprintf(stderr, "DEBUG: connection does not exist\n");
 		errorcode = NOCONNERR;
 		return NULL;
 	}
@@ -481,14 +436,10 @@
 	pcp_write(pc, node_id, strlen(node_id)+1);
 	if (pcp_flush(pc) < 0)
 	{
-#ifdef DEBUG
-		fprintf(stderr, "DEBUG: could not send data to backend\n");
-#endif
+		if (debug) fprintf(stderr, "DEBUG: could not send data to backend\n");
 		return NULL;
 	}
-#ifdef DEBUG
-	fprintf(stderr, "DEBUG: send: tos=\"I\", len=%d\n", ntohl(wsize));
-#endif
+	if (debug) fprintf(stderr, "DEBUG: send: tos=\"I\", len=%d\n", ntohl(wsize));
 
 	if (pcp_read(pc, &tos, 1))
 		return NULL;	
@@ -507,15 +458,11 @@
 		return NULL;
 	}
 
-#ifdef DEBUG
-	fprintf(stderr, "DEBUG: recv: tos=\"%c\", len=%d, data=%s\n", tos, rsize, buf);
-#endif
+	if (debug) fprintf(stderr, "DEBUG: recv: tos=\"%c\", len=%d, data=%s\n", tos, rsize, buf);
 
 	if (tos == 'e')
 	{
-#ifdef DEBUG
-		fprintf(stderr, "DEBUG: command failed. reason=%s\n", buf);
-#endif
+		if (debug) fprintf(stderr, "DEBUG: command failed. reason=%s\n", buf);
 		errorcode = BACKENDERR;
 		free(buf);
 		return NULL;
@@ -578,9 +525,7 @@
 	
 	if (pc == NULL)
 	{
-#ifdef DEBUG
-		fprintf(stderr, "DEBUG: connection does not exist\n");
-#endif
+		if (debug) fprintf(stderr, "DEBUG: connection does not exist\n");
 		errorcode = NOCONNERR;
 		return NULL;
 	}
@@ -590,14 +535,10 @@
 	pcp_write(pc, &wsize, sizeof(int));
 	if (pcp_flush(pc) < 0)
 	{
-#ifdef DEBUG
-		fprintf(stderr, "DEBUG: could not send data to backend\n");
-#endif
+		if (debug) fprintf(stderr, "DEBUG: could not send data to backend\n");
 		return NULL;
 	}
-#ifdef DEBUG
-	fprintf(stderr, "DEBUG: send: tos=\"N\", len=%d\n", ntohl(wsize));
-#endif
+	if (debug) fprintf(stderr, "DEBUG: send: tos=\"N\", len=%d\n", ntohl(wsize));
 
 	if (pcp_read(pc, &tos, 1))
 		return NULL;			
@@ -615,15 +556,11 @@
 		free(buf);
 		return NULL;		
 	}
-#ifdef DEBUG
-	fprintf(stderr, "DEBUG: recv: tos=\"%c\", len=%d, data=%s\n", tos, rsize, buf);
-#endif
+	if (debug) fprintf(stderr, "DEBUG: recv: tos=\"%c\", len=%d, data=%s\n", tos, rsize, buf);
 
 	if (tos == 'e')
 	{
-#ifdef DEBUG
-		fprintf(stderr, "DEBUG: command failed. reason=%s\n", buf);
-#endif
+		if (debug) fprintf(stderr, "DEBUG: command failed. reason=%s\n", buf);
 		free(buf);
 		errorcode = BACKENDERR;
 		return NULL;
@@ -685,9 +622,7 @@
 
 	if (pc == NULL)
 	{
-#ifdef DEBUG
-		fprintf(stderr, "DEBUG: connection does not exist\n");
-#endif
+		if (debug) fprintf(stderr, "DEBUG: connection does not exist\n");
 		errorcode = NOCONNERR;
 		return NULL;
 	}
@@ -700,14 +635,10 @@
 	pcp_write(pc, process_id, strlen(process_id)+1);
 	if (pcp_flush(pc) < 0)
 	{
-#ifdef DEBUG
-		fprintf(stderr, "DEBUG: could not send data to backend\n");
-#endif
+		if (debug) fprintf(stderr, "DEBUG: could not send data to backend\n");
 		return NULL;
 	}
-#ifdef DEBUG
-	fprintf(stderr, "DEBUG: send: tos=\"P\", len=%d\n", ntohl(wsize));
-#endif
+	if (debug) fprintf(stderr, "DEBUG: send: tos=\"P\", len=%d\n", ntohl(wsize));
 
 	while (1)
 	{
@@ -727,15 +658,11 @@
 			free(buf);
 			return NULL;
 		}
-#ifdef DEBUG
-		fprintf(stderr, "DEBUG: recv: tos=\"%c\", len=%d, data=%s\n", tos, rsize, buf);
-#endif
+		if (debug) fprintf(stderr, "DEBUG: recv: tos=\"%c\", len=%d, data=%s\n", tos, rsize, buf);
 
 		if (tos == 'e')
 		{
-#ifdef DEBUG
-			fprintf(stderr, "DEBUG: command failed. reason=%s\n", buf);
-#endif
+			if (debug) fprintf(stderr, "DEBUG: command failed. reason=%s\n", buf);
 			free(buf);
 			errorcode = BACKENDERR;
 			return NULL;
@@ -836,9 +763,7 @@
 
 	if (pc == NULL)
 	{
-#ifdef DEBUG
-		fprintf(stderr, "DEBUG: connection does not exist\n");
-#endif
+		if (debug) fprintf(stderr, "DEBUG: connection does not exist\n");
 		errorcode = NOCONNERR;
 		return NULL;
 	}
@@ -848,14 +773,10 @@
 	pcp_write(pc, &wsize, sizeof(int));
 	if (pcp_flush(pc) < 0)
 	{
-#ifdef DEBUG
-		fprintf(stderr, "DEBUG: could not send data to backend\n");
-#endif
+		if (debug) fprintf(stderr, "DEBUG: could not send data to backend\n");
 		return NULL;
 	}
-#ifdef DEBUG
-	fprintf(stderr, "DEBUG: send: tos=\"S\", len=%d\n", ntohl(wsize));
-#endif
+	if (debug) fprintf(stderr, "DEBUG: send: tos=\"S\", len=%d\n", ntohl(wsize));
 
 	while (1) {
 		if (pcp_read(pc, &tos, 1))
@@ -874,15 +795,11 @@
 			free(buf);
 			return NULL;
 		}
-#ifdef DEBUG
-		fprintf(stderr, "DEBUG: recv: tos=\"%c\", len=%d, data=%s\n", tos, rsize, buf);
-#endif
+		if (debug) fprintf(stderr, "DEBUG: recv: tos=\"%c\", len=%d, data=%s\n", tos, rsize, buf);
 
 		if (tos == 'e')
 		{
-#ifdef DEBUG
-			fprintf(stderr, "DEBUG: command failed. reason=%s\n", buf);
-#endif
+			if (debug) fprintf(stderr, "DEBUG: command failed. reason=%s\n", buf);
 			free(buf);
 			errorcode = BACKENDERR;
 			return NULL;
@@ -1166,9 +1083,7 @@
 
 	if (pc == NULL)
 	{
-#ifdef DEBUG
-		fprintf(stderr, "DEBUG: connection does not exist\n");
-#endif
+		if (debug) fprintf(stderr, "DEBUG: connection does not exist\n");
 		errorcode = NOCONNERR;
 		return -1;
 	}
@@ -1181,14 +1096,10 @@
 	pcp_write(pc, node_id, strlen(node_id)+1);
 	if (pcp_flush(pc) < 0)
 	{
-#ifdef DEBUG
-		fprintf(stderr, "DEBUG: could not send data to backend\n");
-#endif
+		if (debug) fprintf(stderr, "DEBUG: could not send data to backend\n");
 		return -1;
 	}
-#ifdef DEBUG
-	fprintf(stderr, "DEBUG: send: tos=\"D\", len=%d\n", ntohl(wsize));
-#endif
+	if (debug) fprintf(stderr, "DEBUG: send: tos=\"D\", len=%d\n", ntohl(wsize));
 
 	if (pcp_read(pc, &tos, 1))
 		return -1;
@@ -1206,15 +1117,11 @@
 		free(buf);
 		return -1;
 	}
-#ifdef DEBUG
-	fprintf(stderr, "DEBUG: recv: tos=\"%c\", len=%d, data=%s\n", tos, rsize, buf);
-#endif
+	if (debug) fprintf(stderr, "DEBUG: recv: tos=\"%c\", len=%d, data=%s\n", tos, rsize, buf);
 
 	if (tos == 'e')
 	{
-#ifdef DEBUG
-		fprintf(stderr, "DEBUG: command failed. reason=%s\n", buf);
-#endif
+		if (debug) fprintf(stderr, "DEBUG: command failed. reason=%s\n", buf);
 		errorcode = BACKENDERR;
 	}
 	else if (tos == 'd')
@@ -1249,9 +1156,7 @@
 
 	if (pc == NULL)
 	{
-#ifdef DEBUG
-		fprintf(stderr, "DEBUG: connection does not exist\n");
-#endif
+		if (debug) fprintf(stderr, "DEBUG: connection does not exist\n");
 		errorcode = NOCONNERR;
 		return -1;
 	}
@@ -1264,14 +1169,10 @@
 	pcp_write(pc, node_id, strlen(node_id)+1);
 	if (pcp_flush(pc) < 0)
 	{
-#ifdef DEBUG
-		fprintf(stderr, "DEBUG: could not send data to backend\n");
-#endif
+		if (debug) fprintf(stderr, "DEBUG: could not send data to backend\n");
 		return -1;
 	}
-#ifdef DEBUG
-	fprintf(stderr, "DEBUG: send: tos=\"D\", len=%d\n", ntohl(wsize));
-#endif
+	if (debug) fprintf(stderr, "DEBUG: send: tos=\"D\", len=%d\n", ntohl(wsize));
 
 	if (pcp_read(pc, &tos, 1))
 		return -1;
@@ -1289,15 +1190,11 @@
 		free(buf);
 		return -1;
 	}
-#ifdef DEBUG
-	fprintf(stderr, "DEBUG: recv: tos=\"%c\", len=%d, data=%s\n", tos, rsize, buf);
-#endif
+	if (debug) fprintf(stderr, "DEBUG: recv: tos=\"%c\", len=%d, data=%s\n", tos, rsize, buf);
 
 	if (tos == 'e')
 	{
-#ifdef DEBUG
-		fprintf(stderr, "DEBUG: command failed. reason=%s\n", buf);
-#endif
+		if (debug) fprintf(stderr, "DEBUG: command failed. reason=%s\n", buf);
 		errorcode = BACKENDERR;
 	}
 	else if (tos == 'c')
@@ -1334,9 +1231,7 @@
 
 	if (pc == NULL)
 	{
-#ifdef DEBUG
-		fprintf(stderr, "DEBUG: connection does not exist\n");
-#endif
+		if (debug) fprintf(stderr, "DEBUG: connection does not exist\n");
 		errorcode = NOCONNERR;
 		return -1;
 	}
@@ -1349,14 +1244,10 @@
 	pcp_write(pc, node_id, strlen(node_id)+1);
 	if (pcp_flush(pc) < 0)
 	{
-#ifdef DEBUG
-		fprintf(stderr, "DEBUG: could not send data to backend\n");
-#endif
+		if (debug) fprintf(stderr, "DEBUG: could not send data to backend\n");
 		return -1;
 	}
-#ifdef DEBUG
-	fprintf(stderr, "DEBUG: send: tos=\"D\", len=%d\n", ntohl(wsize));
-#endif
+	if (debug) fprintf(stderr, "DEBUG: send: tos=\"D\", len=%d\n", ntohl(wsize));
 
 	if (pcp_read(pc, &tos, 1))
 		return -1;
@@ -1374,15 +1265,11 @@
 		free(buf);
 		return -1;
 	}
-#ifdef DEBUG
-	fprintf(stderr, "DEBUG: recv: tos=\"%c\", len=%d, data=%s\n", tos, rsize, buf);
-#endif
+	if (debug) fprintf(stderr, "DEBUG: recv: tos=\"%c\", len=%d, data=%s\n", tos, rsize, buf);
 
 	if (tos == 'e')
 	{
-#ifdef DEBUG
-		fprintf(stderr, "DEBUG: command failed. reason=%s\n", buf);
-#endif
+		if (debug) fprintf(stderr, "DEBUG: command failed. reason=%s\n", buf);
 		errorcode = BACKENDERR;
 	}
 	else if (tos == 'c')
@@ -1398,3 +1285,15 @@
 	free(buf);
 	return -1;
 }
+
+void
+pcp_enable_debug(void)
+{
+	debug = 1;
+}
+
+void
+pcp_disable_debug(void)
+{
+	debug = 0;
+}
