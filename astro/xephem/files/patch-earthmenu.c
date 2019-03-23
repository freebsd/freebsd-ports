--- earthmenu.c.orig	2012-11-23 04:15:39 UTC
+++ earthmenu.c
@@ -4886,8 +4886,11 @@ e_getwxgif()
 	int nrawgif;
 	char buf[1024];
 	int w, h;
+	XE_SSL_FD ssl_fd;
 	int fd;
 
+	memset(&ssl_fd, 0, sizeof(ssl_fd));
+
 	/* open test case, else real network */
 	fd = openh ("/tmp/latest_cmoll.gif", O_RDONLY);
 	if (fd >= 0) {
@@ -4902,12 +4905,12 @@ e_getwxgif()
 	    stopd_up();
 
 	    /* make connection to server for the file */
-	    xe_msg (0, "Getting\nhttp://%s%s", wxhost, wxfile);
-	    (void) sprintf (buf, "GET http://%s%s HTTP/1.0\r\nUser-Agent: xephem/%s\r\n\r\n",
-						wxhost, wxfile, PATCHLEVEL);
-	    fd = httpGET (wxhost, buf, buf);
+	    xe_msg (0, "Getting\nhttps://%s%s", wxhost, wxfile);
+	    (void) sprintf (buf, "GET %s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\nUser-Agent: xephem/%s\r\n\r\n",
+						wxfile, wxhost, PATCHLEVEL);
+	    fd = httpsGET (wxhost, buf, buf, &ssl_fd);
 	    if (fd < 0) {
-		xe_msg (1, "http get:\n%s", buf);
+		xe_msg (1, "https get:\n%s", buf);
 		stopd_down();
 		return (-1);
 	    }
@@ -4915,7 +4918,7 @@ e_getwxgif()
 	    /* read header, looking for some header info */
 	    isgif = 0;
 	    length = 0;
-	    while (recvline (fd, buf, sizeof(buf)) > 1) {
+	    while (ssl_recvline (&ssl_fd, buf, sizeof(buf)) > 1) {
 		xe_msg (0, "Rcv: %s", buf);
 		if (strstr (buf, "image/gif"))
 		    isgif = 1;
@@ -4923,9 +4926,10 @@ e_getwxgif()
 		    length = atoi (buf+15);
 	    }
 	    if (!isgif) {
-		while (recvline (fd, buf, sizeof(buf)) > 1)
+		while (ssl_recvline (&ssl_fd, buf, sizeof(buf)) > 1)
 		    xe_msg (0, "Rcv: %s", buf);
-		close (fd);
+		SSL_free (ssl_fd.ssl);
+		close (ssl_fd.fd);
 		stopd_down();
 		return (-1);
 	    }
@@ -4936,12 +4940,13 @@ e_getwxgif()
 	    pm_up();
 	    for (nrawgif = 0; nrawgif < sizeof(rawgif); nrawgif += nr) {
 		pm_set (100*nrawgif/length);
-		nr = readbytes (fd, rawgif+nrawgif, 4096);
+		nr = SSL_read (ssl_fd.ssl, rawgif+nrawgif, 4096);
 		if (nr < 0) {
-		    xe_msg (1, "%s:\n%s", wxhost, syserrstr());
+		    xe_msg (1, "%s: ssl read error code: %d", wxhost, SSL_get_error(ssl_fd.ssl, nr));
 		    stopd_down();
 		    pm_down();
-		    close (fd);
+		    SSL_free (ssl_fd.ssl);
+		    close (ssl_fd.fd);
 		    return (-1);
 		}
 		if (nr == 0)
@@ -4949,7 +4954,8 @@ e_getwxgif()
 	    }
 	    stopd_down();
 	    pm_down();
-	    close (fd);
+	    SSL_free (ssl_fd.ssl);
+	    close (ssl_fd.fd);
 	    if (nr > 0) {
 		xe_msg (1, "File too large");
 		return (-1);
