--- sunmenu.c.orig	2012-04-01 22:38:50 UTC
+++ sunmenu.c
@@ -884,9 +884,11 @@ readSOHOImage()
 	int isjpeg, jpegl;
 	int njpeg;
 	unsigned char *jpeg;
+	XE_SSL_FD ssl_fd;
 	int fd, nr;
 	struct tm tm;
 
+	memset(&ssl_fd, 0, sizeof(ssl_fd));
 	memset(&tm, 0, sizeof(struct tm));
 
 	/* get desired type and size */
@@ -899,18 +901,18 @@ readSOHOImage()
 
 	/* build GET command */
 	sprintf (get, "GET http://%s%s HTTP/1.0\r\nUser-Agent: xephem/%s\r\n\r\n", sohohost, fn, PATCHLEVEL);
-
+	
 	/* query server */
-	fd = httpGET (sohohost, get, buf);
+	fd = httpsGET (sohohost, get, buf, &ssl_fd);
 	if (fd < 0) {
-	    xe_msg (1, "http get: %s", buf);
+	    xe_msg (1, "https get: %s", buf);
 	    return (-1);
 	}
 
 	/* read header (everything to first blank line), looking for jpeg */
 	isjpeg = 0;
 	jpegl = 0;
-	while (recvline (fd, buf, sizeof(buf)) > 1) {
+	while (ssl_recvline (&ssl_fd, buf, sizeof(buf)) > 1) {
 	    xe_msg (0, "Rcv: %s", buf);
 	    if (strstr (buf, "Content-Type:") && strstr (buf, "image/jpeg"))
 		isjpeg = 1;
@@ -923,15 +925,17 @@ readSOHOImage()
 	    }
 	}
 	if (!isjpeg) {
-	    while (recvline (fd, buf, sizeof(buf)) > 0)
+	    while (ssl_recvline (&ssl_fd, buf, sizeof(buf)) > 0)
 		xe_msg (0, "Rcv: %s", buf);
 	    xe_msg (1, "Error talking to SOHO .. see File->System log\n");
-	    close (fd);
+	    SSL_free (ssl_fd.ssl);
+	    close (ssl_fd.fd);
 	    return (-1);
 	}
 	if (jpegl == 0) {
 	    xe_msg (1, "No Content-Length in header");
-	    close (fd);
+	    SSL_free (ssl_fd.ssl);
+	    close (ssl_fd.fd);
 	    return (-1);
 	}
 
@@ -941,20 +945,22 @@ readSOHOImage()
 	for (njpeg = 0; njpeg < jpegl; njpeg += nr) {
 	    pm_set (100*njpeg/jpegl);
 	    jpeg = (unsigned char *) XtRealloc ((char*)jpeg, njpeg+NSREAD);
-	    nr = readbytes (fd, jpeg+njpeg, NSREAD);
-	    if (nr < 0) {
-		xe_msg (1, "%s:\n%s", sohohost, syserrstr());
+	    nr = SSL_read (ssl_fd.ssl, jpeg+njpeg, NSREAD);
+	    if (nr <= 0) {
+		xe_msg (1, "%s: ssl read error code: %d", sohohost, SSL_get_error(ssl_fd.ssl, nr));
 		pm_down();
-		close (fd);
+		SSL_free (ssl_fd.ssl);
+		close (ssl_fd.fd);
 		return (-1);
 	    }
 	    if (nr == 0)
 		break;
 	}
 	pm_down();
-	close (fd);
+	SSL_free (ssl_fd.ssl);
+	close (ssl_fd.fd);
 
-        sprintf (fn, "/%s_%s.jpg", filetime, filetype);
+	sprintf (fn, "/%s_%s.jpg", filetime, filetype);
 	/* display jpeg */
 	if (displayPic (fn, jpeg, njpeg) < 0)
 	    return (-1);
