--- webdbmenu.c.orig	2012-11-23 05:22:09 UTC
+++ webdbmenu.c
@@ -404,6 +404,10 @@ getURL (url)
 char *url;
 {
 	static char http[] = "http://";
+	static char https[] = "https://";
+	char *transport = http;
+	int ltransport = strlen (transport);
+	int ishttp = 0;
 	char buf[512], msg[1024];
 	char l0[512], l1[512], l2[512];
 	char *l0p = l0, *l1p = l1, *l2p = l2;
@@ -411,21 +415,31 @@ char *url;
 	char *slash, *dot;
 	char filename[256];
 	FILE *fp;
+	XE_SSL_FD ssl_fd;
 	int sockfd;
 	int nfound;
 
+	memset(&ssl_fd, 0, sizeof(ssl_fd));
+
 	/* start */
 	watch_cursor(1);
 	l0[0] = l1[0] = l2[0] = '\0';
 
 	/* find transport and host */
-	if (strncmp (url, http, 7)) {
-	    xe_msg (1, "URL must begin with %s", http);
+	if (!strncmp (url, transport, ltransport)) {
+	    ishttp = 1;
+	} else {
+	    transport = https;
+	    ltransport = strlen (transport);
+	}
+
+	if ((!ishttp) && (strncmp (url, transport, ltransport))) {
+	    xe_msg (1, "URL must begin with %s or %s", http, https);
 	    watch_cursor (0);
 	    return;
 	}
 
-	slash = strchr (url+7, '/');
+	slash = strchr (url+ltransport, '/');
 	dot = strrchr (url, '.');
 	if (!slash || !dot) {
 	    xe_msg (1, "Badly formed URL");
@@ -434,11 +448,16 @@ char *url;
 	}
 
 	/* connect to check url */
-	sprintf (host, "%.*s", (int)(slash-url-7), url+7);
+	sprintf (host, "%.*s", (int)(slash-url-ltransport), url+ltransport);
 	sprintf (buf, "GET %s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\nUser-Agent: xephem/%s\r\n\r\n",
 						url, host, PATCHLEVEL);
 	stopd_up();
-	sockfd = httpGET (host, buf, msg);
+	if (ishttp) {
+	    sockfd = httpGET (host, buf, msg);
+	    ssl_fd.fd = sockfd;
+	} else {
+	    sockfd = httpsGET (host, buf, msg, &ssl_fd);
+	}
 	if (sockfd < 0) {
 	    xe_msg (1, "http GET to %s failed: %s%s\n", host, buf, msg);
 	    stopd_down();
@@ -447,20 +466,22 @@ char *url;
 	}
 
 	/* create local file */
-	slash = strrchr (url+7, '/');
+	slash = strrchr (url+ltransport, '/');
 	sprintf (filename, "%s/%.*sedb", getPrivateDir(), (int)(dot-slash), slash+1);
 	fp = fopen (filename, "w");
 	if (!fp) {
 	    xe_msg (1, "%s:\n%s", filename, syserrstr());
 	    watch_cursor (0);
-	    close (sockfd);
+	    if (!ishttp)
+		SSL_free (ssl_fd.ssl);
+	    close (ssl_fd.fd);
 	    return;
 	}
 
 	/* copy to file, insuring only .edb lines.
 	 */
 	nfound = 0;
-	while (recvlineb (sockfd, l2p, sizeof(l2)) > 0) {
+	while (ssl_recvlineb (&ssl_fd, l2p, sizeof(l2)) > 0) {
 	    char *lrot;
 	    Obj o;
 
@@ -484,7 +505,9 @@ char *url;
 
 	/* tidy up and done */
 	fclose (fp);
-	close (sockfd);
+	if (!ishttp)
+	    SSL_free (ssl_fd.ssl);
+	close (ssl_fd.fd);
 	if (!nfound) {
 	    xe_msg (1, "No objects in file");
 	    remove (filename);
