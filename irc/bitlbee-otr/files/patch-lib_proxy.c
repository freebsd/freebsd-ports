
$FreeBSD$

--- lib/proxy.c.orig
+++ lib/proxy.c
@@ -57,27 +57,6 @@
 	gint inpa;
 };
 
-
-
-static struct sockaddr_in *gaim_gethostbyname(const char *host, int port)
-{
-	static struct sockaddr_in sin;
-
-	if (!inet_aton(host, &sin.sin_addr)) {
-		struct hostent *hp;
-		if (!(hp = gethostbyname(host))) {
-			return NULL;
-		}
-		memset(&sin, 0, sizeof(struct sockaddr_in));
-		memcpy(&sin.sin_addr.s_addr, hp->h_addr, hp->h_length);
-		sin.sin_family = hp->h_addrtype;
-	} else
-		sin.sin_family = AF_INET;
-	sin.sin_port = htons(port);
-
-	return &sin;
-}
-
 static gboolean gaim_io_connected(gpointer data, gint source, b_input_condition cond)
 {
 	struct PHB *phb = data;
@@ -110,47 +89,71 @@
 	return FALSE;
 }
 
-static int proxy_connect_none(const char *host, unsigned short port, struct PHB *phb)
+static int proxy_connect_none(const char *host, unsigned short port_, struct PHB *phb)
 {
-	struct sockaddr_in *sin;
 	struct sockaddr_in me;
 	int fd = -1;
+	int ret;
+	char port[6];
+	struct addrinfo hints;
+	struct addrinfo* result;
 
-	if (!(sin = gaim_gethostbyname(host, port))) {
-		g_free(phb);
-		return -1;
-	}
+	g_snprintf(port, sizeof(port), "%d", port_);
 
-	if ((fd = socket(sin->sin_family, SOCK_STREAM, 0)) < 0) {
-		g_free(phb);
-		return -1;
-	}
+	memset(&hints, 0, sizeof(struct addrinfo));
+	hints.ai_family = AF_UNSPEC;
+	hints.ai_socktype = SOCK_STREAM;
+	hints.ai_flags = AI_ADDRCONFIG | AI_NUMERICSERV;
 
-	sock_make_nonblocking(fd);
+	if (!(ret = getaddrinfo(host, port, &hints, &result)))
+ 	{
+		struct addrinfo* rp;
+
+		for (rp = result; rp; rp = rp->ai_next)
+		{
+			if ((fd = socket(rp->ai_family, rp->ai_socktype, rp->ai_protocol)) < 0) {
+				event_debug( "socket failed: %d\n", errno);
+				continue;
+			}
+
+			sock_make_nonblocking(fd);
+
+			if (global.conf->iface_out)
+			{
+				me.sin_family = AF_INET;
+				me.sin_port = 0;
+				me.sin_addr.s_addr = inet_addr( global.conf->iface_out );
+				
+				if (bind(fd, (struct sockaddr *) &me, sizeof(me)) != 0)
+					event_debug("bind( %d, \"%s\" ) failure\n", fd, global.conf->iface_out);
+			}
+
+			event_debug("proxy_connect_none( \"%s\", %d ) = %d\n", host, port, fd);
 	
-	if( global.conf->iface_out )
+			if (connect(fd, rp->ai_addr, rp->ai_addrlen) < 0 && !sockerr_again()) {
+				event_debug( "connect failed: %s\n", strerror(errno));
+				closesocket(fd);
+				fd = -1;
+				continue;
+			} else {
+				phb->inpa = b_input_add(fd, GAIM_INPUT_WRITE, gaim_io_connected, phb);
+				phb->fd = fd;
+				
+				break;
+			}
+		}
+
+		freeaddrinfo(result);
+	}
+	else
 	{
-		me.sin_family = AF_INET;
-		me.sin_port = 0;
-		me.sin_addr.s_addr = inet_addr( global.conf->iface_out );
-		
-		if( bind( fd, (struct sockaddr *) &me, sizeof( me ) ) != 0 )
-			event_debug( "bind( %d, \"%s\" ) failure\n", fd, global.conf->iface_out );
+		event_debug("gai(): %s\n", gai_strerror(ret));
 	}
 	
-	event_debug("proxy_connect_none( \"%s\", %d ) = %d\n", host, port, fd);
-	
-	if (connect(fd, (struct sockaddr *)sin, sizeof(*sin)) < 0 && !sockerr_again()) {
-		closesocket(fd);
+	if(fd < 0)
 		g_free(phb);
-		
-		return -1;
-	} else {
-		phb->inpa = b_input_add(fd, GAIM_INPUT_WRITE, gaim_io_connected, phb);
-		phb->fd = fd;
-		
-		return fd;
-	}
+
+	return fd;
 }
 
 
