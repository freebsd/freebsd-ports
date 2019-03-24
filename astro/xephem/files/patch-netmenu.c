--- netmenu.c.orig	2010-10-06 21:12:40 UTC
+++ netmenu.c
@@ -9,6 +9,8 @@
 #include <string.h>
 #include <unistd.h>
 
+#include <openssl/ssl.h>
+
 #include <Xm/Form.h>
 #include <Xm/Label.h>
 #include <Xm/PushB.h>
@@ -70,12 +72,24 @@ static int rb_unk;		/* index of first unknown char */
 
 static char netcategory[] = "Network";	/* Save category */
 
+static SSL_METHOD *ssl_method;	/* global ssl dispatch structure for creating a ssl context */
+static SSL_CTX *ssl_ctx;	/* global ssl context structure for creating ssl connections */
+
 /* call to set up without actually bringing up the menus.
  */
 void
 net_create()
 {
 	if (!netshell_w) {
+	    if (SSL_library_init() < 0) {
+		fprintf (stderr, "Could not initialize the OpenSSL library !\n");
+	    } else {
+		ssl_method = SSLv23_client_method();	/* deprecated since openssl 1.1.x */
+//		ssl_method = TLS_client_method();	/* since openssl 1.1.x */
+		ssl_ctx = SSL_CTX_new (ssl_method);
+		SSL_CTX_set_options (ssl_ctx, SSL_OP_NO_SSLv2);
+	    };
+
 	    net_create_form();
 	    (void) net_save();	/* confirming here is just annoying */
 	}
@@ -251,8 +265,8 @@ char msg[])	/* return diagnostic message here, if retu
             struct {
 		unsigned char  VN;	/* version number */
 		unsigned char  CD;	/* command code */
-		unsigned short DSTPORT;	/* destination port */
-		unsigned long  DSTIP;	/* destination IP addres */
+		uint16_t       DSTPORT;	/* destination port */
+		uint32_t       DSTIP;	/* destination IP address */
 	    } SocksPacket;
 
 	    struct hostent *hs = gethostbyname (socks_host);
@@ -390,7 +404,7 @@ readbytes (int fd, unsigned char buf[], int n)
 
 /* read up to and including the next '\n' from socket fd into buf[max].
  * we silently ignore all '\r'. we add a trailing '\0'.
- * return line lenth (not counting \0) if all ok, else -1.
+ * return line length (not counting \0) if all ok, else -1.
  * N.B. this never reads ahead -- if that's ok, recvlineb() is better
  */
 int
@@ -442,6 +456,216 @@ recvlineb (int sock, char *buf, int size)
 		    break;
 		}
 		nr = read (sock, rb_linebuf, sizeof(rb_linebuf));
+		if (nr <= 0) {
+		    ok = nr;
+		    rb_next = 0;
+		    rb_unk = 0;
+		    break;
+		}
+		rb_next = 0;
+		rb_unk = nr;
+	    }
+
+	    if ((c = rb_linebuf[rb_next++]) != '\r')
+		*buf++ = c;
+
+	} while (buf-origbuf < size && c != '\n');
+
+	/* always give back a real line regardless, else status */
+	if (ok > 0) {
+	    *buf = '\0';
+	    ok = buf - origbuf;
+	}
+
+	return (ok);
+}
+
+/* open the host, do the given GET cmd, and return a socket fd for the result.
+ * on success it fills the XE_SSL_FD structure for later use by SSL_read() and necessary cleanup.
+ * return -1 and with excuse in msg[], else 0 if ok.
+ * N.B. can be called before we are created if net set in app defaults.
+ */
+int
+httpsGET (char *host, char *GETcmd, char msg[], XE_SSL_FD *ssl_fd)
+{
+	char buf[2048];
+	int fd;
+	int connected;
+	SSL *ssl;
+	int n;
+	int ret;
+	int httpsport = 443;
+
+	/* open connection */
+	if (proxy_on) {
+	    fd = mkconnection (proxy_host, proxy_port, msg);
+	    if (fd < 0)
+		return (-1);
+
+	    /* fill buf with CONNECT */
+	    (void) sprintf (buf, "CONNECT %1$s:%2$d HTTP/1.0\r\nUser-Agent: xephem/%3$s\r\nHost: %1$s:%2$d\r\n\r\n", host, httpsport, PATCHLEVEL);
+
+	    /* add proxy auth if enabled */
+	    if (!auth_w)
+		net_create_form();
+	    if (XmToggleButtonGetState (auth_w))
+		addAuth(buf);
+
+	    /* log it */
+	    xe_msg (0, "https proxy connect: %s", buf);
+
+	    /* send it */
+	    n = strlen (buf);
+	    if (sendbytes(fd, (unsigned char *)buf, n) < 0) {
+		(void) sprintf (msg, "%s: send error: %s", proxy_host, syserrstr());
+		(void) close (fd);
+		return (-1);
+	    }
+
+	    connected = 0;
+	    while (recvline (fd, buf, sizeof(buf)) > 1) {
+		xe_msg (0, "Rcv: %s", buf);
+		if (strstr (buf, "200 "))
+		    connected = 1;
+	    }
+	    if (!connected) {
+		(void) sprintf (msg, "%s: connect error: %s", proxy_host, syserrstr());
+		(void) close (fd);
+		return (-1);
+	    }
+	} else {
+	    /* SOCKS or direct are both handled by mkconnection() */
+	    fd = mkconnection (host, httpsport, msg);
+	    if (fd < 0)
+		return (-1);
+	}
+
+	/* fill buf with GETcmd */
+	(void) sprintf (buf, "%s", GETcmd);
+
+	/* start ssl connection */
+	ssl = SSL_new (ssl_ctx);
+	SSL_set_fd (ssl, fd);
+	SSL_connect (ssl);
+
+	/* log it */
+	xe_msg (0, "https: %s", buf);
+
+	/* send it */
+	n = strlen (buf);
+	ret = SSL_write (ssl, (unsigned char *)buf, n);
+	if (ret <= 0) {
+	    (void) sprintf (msg, "%s: ssl send error code: %d", host, SSL_get_error (ssl, ret));
+	    (void) SSL_free (ssl);
+	    (void) close (fd);
+	    return (-1);
+	}
+
+	/* caller can read response */
+	ssl_fd->fd = fd;
+	ssl_fd->ssl = ssl;
+	return (fd);
+}
+
+/* receive exactly n bytes from ssl connection ssl_fd into buf.
+ * return -1, 0 or n.
+ * N.B. with fallback to ordinary read from socket if ssl_fd->ssl is NULL
+ */
+int
+ssl_recvbytes (XE_SSL_FD *ssl_fd, unsigned char buf[], int n)
+{
+	int ns, tot;
+
+	for (tot = 0; tot < n; tot += ns) {
+	    if (tout (TOUT, ssl_fd->fd, 0) < 0)
+		return (-1);
+	    if (ssl_fd->ssl)
+		ns = SSL_read (ssl_fd->ssl, (void *)(buf+tot), n-tot);
+	    else
+		ns = read (ssl_fd->fd, (void *)(buf+tot), n-tot);
+	    if (ns <= 0)
+		return (ns);
+	}
+	return (n);
+}
+
+/* like read(2) except we time out and allow user to cancel.
+ * receive up to n bytes from ssl connection ssl_fd into buf.
+ * return count, or 0 on eof or -1 on error.
+ * N.B. with fallback to ordinary read from socket if ssl_fd->ssl is NULL
+ */
+int
+ssl_readbytes (XE_SSL_FD *ssl_fd, unsigned char buf[], int n)
+{
+	int ns;
+
+	if (tout (TOUT, ssl_fd->fd, 0) < 0)
+	    return (-1);
+	if (ssl_fd->ssl)
+	    ns = SSL_read (ssl_fd->ssl, (void *)buf, n);
+	else
+	    ns = read (ssl_fd->fd, (void *)buf, n);
+	return (ns);
+}
+
+/* read up to and including the next '\n' from ssl into buf[max].
+ * we silently ignore all '\r'. we add a trailing '\0'.
+ * return line length (not counting \0) if all ok, else -1.
+ * N.B. with fallback to ordinary read from socket if ssl_fd->ssl is NULL
+ */
+int
+ssl_recvline (XE_SSL_FD *ssl_fd, char buf[], int max)
+{
+	unsigned char c;
+	int n;
+
+	max--;	/* leave room for trailing \0 */
+
+	for (n = 0; n < max && ssl_recvbytes (ssl_fd, &c, 1) == 1; ) {
+	    if (c != '\r') {
+		buf[n++] = c;
+		if (c == '\n') {
+		    buf[n] = '\0';
+		    return (n);
+		}
+	    }
+	}
+
+	return (-1);
+}
+
+/* rather like ssl_recvline but reads ahead in big chunk for efficiency.
+ * return length if read a line ok, 0 if hit eof, -1 if error.
+ * N.B. we silently swallow all '\r'.
+ * N.B. we read ahead and can hide bytes after each call.
+ * N.B. with fallback to ordinary read from socket if ssl_fd->ssl is NULL
+ */
+int
+ssl_recvlineb (XE_SSL_FD *ssl_fd, char *buf, int size)
+{
+	char *origbuf = buf;		/* save to prevent overfilling buf */
+	char c = '\0';
+	int ok = 1;
+
+	/* always leave room for trailing \n */
+	size -= 1;
+
+	/* read and copy linebuf[next] to buf until buf fills or copied a \n */
+	do {
+
+	    if (rb_next >= rb_unk) {
+		/* linebuf is empty -- refill */
+
+		int nr;
+
+		if (tout (TOUT, ssl_fd->fd, 0) < 0) {
+		    nr = -1;
+		    break;
+		}
+		if (ssl_fd->ssl)
+		    nr = SSL_read (ssl_fd->ssl, rb_linebuf, sizeof(rb_linebuf));
+		else
+		    nr = read (ssl_fd->fd, rb_linebuf, sizeof(rb_linebuf));
 		if (nr <= 0) {
 		    ok = nr;
 		    rb_next = 0;
