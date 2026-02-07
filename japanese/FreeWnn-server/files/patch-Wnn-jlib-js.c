Index: Wnn/jlib/js.c
===================================================================
RCS file: /home/cvs/private/hrs/freewnn/Wnn/jlib/js.c,v
retrieving revision 1.1.1.1
retrieving revision 1.3
diff -u -p -r1.1.1.1 -r1.3
--- Wnn/jlib/js.c	20 Dec 2008 07:13:30 -0000	1.1.1.1
+++ Wnn/jlib/js.c	2 Jan 2010 11:51:21 -0000	1.3
@@ -110,8 +110,7 @@ static WNN_JSERVER_ID *current_js = NULL
 
 /*      Packet Buffers          */
 static unsigned char snd_buf[S_BUF_SIZ];        /** 送信 **/
-static int sbp = 0;                     /** 送信バッファーポインター **/
-static int rbc = -1;                    /** 受信バッファーポインター **/
+static unsigned char *sbp = snd_buf;
 
 #if defined(EAGAIN)
 # if defined(EWOULDBLOCK)
@@ -130,11 +129,10 @@ static int rbc = -1;                    
 static void connect_timeout ();
 static int _get_server_name ();
 static int writen ();
+static int rcv_flush();
 static char *get_unixdomain_of_serv_defs (), *get_service_of_serv_defs ();
 static int get_port_num_of_serv_defs ();
-#if DEBUG
 void xerror ();
-#endif
 
 /*********      V4      *****************/
 /***
@@ -192,471 +190,506 @@ daemon_dead ()
                         (cdというのはコミュニケーションデバイスの名残)
 **/
 static int
-cd_open_un (lang)
-     register char *lang;
+cd_open_un(const char *lang)
 {
-#ifdef AF_UNIX
-  int sd;
-  struct sockaddr_un saddr;             /** ソケット **/
-  char *sock_name = NULL;
-  saddr.sun_family = AF_UNIX;
-
-  /* find socket name from table by lang */
-  if (lang && *lang)
-    {
-      if ((sock_name = get_unixdomain_of_serv_defs (lang)) == NULL)
-        {
-          sock_name = sockname;
-        }
-    }
-  else
-    {
-      sock_name = sockname;     /* Jserver */
-    }
-  strcpy (saddr.sun_path, sock_name);
+#if !defined(AF_UNIX)
+	return -1;
+#else
+	int sd;
+	struct sockaddr_un saddr;
+	char *sock_name = NULL;
+	saddr.sun_family = AF_UNIX;
+
+	/* find socket name from table by lang */
+	if (lang && *lang) {
+		if ((sock_name = get_unixdomain_of_serv_defs(lang)) == NULL)
+			sock_name = sockname;
+	} else
+		sock_name = sockname;	/* Jserver */
+	strcpy (saddr.sun_path, sock_name);
 
-  if ((sd = socket (AF_UNIX, SOCK_STREAM, 0)) == ERROR)
-    {
+	if ((sd = socket(AF_UNIX, SOCK_STREAM, 0)) == ERROR) {
 #if DEBUG
-      xerror ("jslib:Can't create unix domain socket.\n");
-#endif
-      return -1;
-    }
+		xerror ("jslib:Can't create unix domain socket.\n");
+#endif /* DEBUG */
+		return -1;
+	}
 
 #if !defined(SUN_LEN)
 # define SUN_LEN(su) (sizeof(*(su)) - sizeof((su)->sun_path) + strlen((su)->sun_path))
-#endif
-  if (connect (sd, (struct sockaddr *) &saddr, SUN_LEN (&saddr)) == ERROR)
-    {
-
+#endif /* !defined(SUN_LEN) */
+	if (connect(sd, (struct sockaddr *)&saddr, SUN_LEN(&saddr)) == ERROR) {
 #if DEBUG
-      xerror ("jslib:Can't connect unix domain socket.\n");
-#endif
-      close (sd);
-      return -1;
-    }
-  return sd;
-#else
-  return -1;
+		xerror ("jslib:Can't connect unix domain socket.\n");
+#endif /* DEBUG */
+		close (sd);
+		return -1;
+	}
+
+	return sd;
 #endif
 }
 
 static int
-cd_open_in (server, lang, timeout)
-     register char *server;
-     register char *lang;
-     register int timeout;
-{
-  int sd;
-#ifdef INET6
-  struct addrinfo hints, *res, *res0;
-  int error;
-  char sport[6];
-#else
-  struct sockaddr_in saddr_in;                  /** ソケット **/
-  register struct hostent *hp;
-#endif
-  struct servent *sp = NULL;
-  int serverNO, port_num;
-  int ret;
-  char pserver[64];
-  char sserver[64];
-  char *serv_name = NULL;
-
-  serverNO = _get_server_name (server, pserver);
+cd_open_in(const char *server,
+	   const char *lang,
+	   const int timeout)
+{
+	int sd;
+
+	struct addrinfo hints, *res, *res0;
+	struct sockaddr sa;
+	char sbuf[NI_MAXSERV];
+
+	int error;
+
+	struct servent *sp = NULL;
+	int serverNO, port_num;
+	int ret;
+	char pserver[NI_MAXHOST];
+	char sserver[NI_MAXHOST];
+	char *serv_name = NULL;
 
-  /* find service name from table by lang */
-  if (lang && *lang)
-    {
-      if ((serv_name = get_service_of_serv_defs (lang)) == NULL)
-        {
-          strcpy (sserver, SERVERNAME);
-        }
-      else
-        {
-          strcpy (sserver, serv_name);
-        }
-    }
-  else
-    {
-/*
-        serv_name = SERVERNAME;
-*/
-      strcpy (sserver, SERVERNAME);
-    }
-/*
-    if ((sp = getservbyname(serv_name,"tcp")) != NULL) {
-*/
-  if ((sp = getservbyname (sserver, "tcp")) != NULL)
-    {
-      serverNO += ntohs (sp->s_port);
-    }
-  else
-    {
-      if ((port_num = get_port_num_of_serv_defs (lang)) == -1)
-        {
-          serverNO += WNN_PORT_IN;
-        }
-      else
-        {
-          serverNO += port_num;
-        }
-    }
-#ifdef INET6
-  memset(&hints, 0, sizeof(hints));
-  hints.ai_family = PF_UNSPEC;
-  hints.ai_socktype = SOCK_STREAM;
-  sprintf(sport, "%d", serverNO);
-  error = getaddrinfo(pserver, sport, &hints, &res0);
-  if (error)
-    {
 #if DEBUG
-      xerror (gai_strerror(error));
+	fprintf(stderr, "cd_open_in: Enter: server=%s, lang=%s\n",
+		server, lang);
 #endif
-      return -1;
-    }
-  for (res = res0; res ; res = res->ai_next) {
-    if (res->ai_family == AF_INET || res->ai_family == AF_INET6){
-      if ((sd = socket(res->ai_family, res->ai_socktype, res->ai_protocol)) != ERROR){
-#else
-  if ((hp = gethostbyname (pserver)) == NULL)
-    {
-      return -1;
-    }
-  bzero ((char *) &saddr_in, sizeof (saddr_in));
-  bcopy (hp->h_addr, (char *) &saddr_in.sin_addr, hp->h_length);
-  saddr_in.sin_family = AF_INET;
-  saddr_in.sin_port = htons (serverNO);
-  if ((sd = socket (AF_INET, SOCK_STREAM, 0)) == ERROR)
-    {
+	serverNO = _get_server_name(server, pserver);
 #if DEBUG
-      xerror ("jslib:Can't create inet socket.\n");
+	fprintf(stderr, "cd_open_in: serverNO=%d\n", serverNO);
 #endif
-      return -1;
-    }
+	/* find service name from table by lang */
+	if (lang && *lang) {
+		if ((serv_name = get_service_of_serv_defs (lang)) == NULL) {
+			strncpy (sserver, SERVERNAME, sizeof(sserver) - 1);
+			sserver[sizeof(sserver) - 1] = '\0';
+		} else {
+			strncpy (sserver, serv_name, sizeof(sserver) - 1);
+			sserver[sizeof(sserver) - 1] = '\0';
+		}
+	} else {
+		strncpy (sserver, SERVERNAME, sizeof(sserver) - 1);
+		sserver[sizeof(sserver) - 1] = '\0';
+	}
+
+	memset(&sa, 0, sizeof(struct sockaddr));
+	error = getnameinfo(&sa, sa.sa_len,
+		    NULL, 0, sbuf, sizeof(sbuf), NI_NUMERICSERV);
+	if (!error) {
+		serverNO += atoi(sbuf);
+	} else {
+		if ((port_num = get_port_num_of_serv_defs (lang)) == -1)
+			serverNO += WNN_PORT_IN;
+		else
+			serverNO += port_num;
+        }
+#if DEBUG
+	fprintf(stderr, "cd_open_in: fixed serverNO=%d\n", serverNO);
 #endif
-
-  if (timeout != 0 && timeout > 0)
-    {
-      signal (SIGALRM, connect_timeout);
-      alarm (timeout);
-    }
+	memset(&hints, 0, sizeof(hints));
+	hints.ai_family = PF_UNSPEC;
+	hints.ai_socktype = SOCK_STREAM;
+	sprintf(sbuf, "%d", serverNO);
+
+	error = getaddrinfo(pserver, sbuf, &hints, &res0);
+	if (error) {
+		xerror(gai_strerror(error));
+		return -1;
+	}
+
+	for (res = res0; res ; res = res->ai_next) {
+		switch (res->ai_family) {
+		case AF_INET:
 #ifdef INET6
-  ret = connect (sd, res->ai_addr, res->ai_addrlen);
-#else
-  ret = connect (sd, (struct sockaddr *) &saddr_in, sizeof (saddr_in));
+		case AF_INET6:
 #endif
-  if (timeout != 0 && timeout > 0)
-    {
-      alarm (0);
-      signal (SIGALRM, SIG_IGN);
-    }
-  if (ret == ERROR)
-    {
-#if DEBUG
+			sd = socket(res->ai_family,
+				    res->ai_socktype,
+				    res->ai_protocol);
+
+			if (sd == ERROR) {
+				switch (res->ai_family) {
+				case AF_INET:
+					xerror ("jslib:Can't create inet socket.\n");
 #ifdef INET6
-      if (res->ai_family == AF_INET)
-	xerror ("jslib:Can't connect inet socket.\n");
-      else if (res->ai_family == AF_INET6)
-	xerror ("jslib:Can't connect inet6 socket.\n");
-#else
-      xerror ("jslib:Can't connect inet socket.\n");
-#endif
+				case AF_INET6:
+					xerror ("jslib:Can't create inet6 socket.\n");
 #endif
+				default:
+					xerror("jslib:Cannot create socket.  Unknown socket type.\n");
+				}
+				
+				break;
+			}
+			if (timeout) {
+				signal(SIGALRM, connect_timeout);
+				alarm(timeout);
+			}
+			ret = connect(sd,
+				      res->ai_addr,
+				      res->ai_addrlen);
+			if (timeout) {
+				alarm(0);
+				signal(SIGALRM, SIG_IGN);
+			}
+			if (ret == ERROR) {
+				switch (res->ai_family) {
+				case AF_INET:
+					fprintf(stderr, "jslib:Can't connect inet socket. (sd=%d)\n", sd);
+					break;
+#ifdef INET6
+				case AF_INET6:
+					fprintf(stderr, "jslib:Can't connect inet6 socket. (sd=%d)\n", sd);
+					break;
+#endif
+				default:
+					xerror("jslib:Cannot connect.  Unknown socket type.\n");
+					break;
+				}
 #ifdef HAVE_CLOSESOCKET
-      closesocket (sd);
+				closesocket(sd);
 #else
-      close (sd);
+				close(sd);
 #endif
-#ifdef INET6
-	  sd = ERROR;
-	} else
-	  break;
-      } else {
+				sd = ERROR;
+			}
 #if DEBUG
-      if (res->ai_family == AF_INET)
-	xerror ("jslib:Can't create inet socket.\n");
-      else if (res->ai_family == AF_INET6)
-	xerror ("jslib:Can't create inet6 socket.\n");
-#endif
-      }
-    }
-  }
-  freeaddrinfo(res0);
-  if (sd == ERROR) {
+			fprintf(stderr, "connect: sd=%d\n", sd);
 #endif
-      return -1;
-    }
-  return sd;
+			freeaddrinfo(res0);
+			return sd;
+		}
+	}
+	freeaddrinfo(res0);
+	return sd;
 }
 
 static void
-connect_timeout ()
+connect_timeout()
 {
 }
 
 /* get server name and return serverNo */
 static int
-_get_server_name (server, pserver)
-     char *server;
-     char *pserver;
+_get_server_name(char *server,
+		 char *pserver)
 {
-  register char *p;
+	char *p;
 #ifdef INET6
-  int len;
+	int len;
 
-  if (server[0] == '[') {
-    p = strchr(server++, ']');
-    if (p) {
-      len = p-server<64-1?p-server:64-1;
-      strncpy(pserver, server, len);
-      pserver[len] = '\0';
-    } else
-      pserver[0] = '\0';
-  } else {
+	if (server[0] == '[') {
+		p = strchr(server++, ']');
+		if (p) {
+			len = p-server < NI_MAXHOST - 1 ? p-server : NI_MAXHOST - 1;
+			strncpy(pserver, server, len);
+			pserver[len] = '\0';
+		} else
+			pserver[0] = '\0';
+	} else {
 #endif
   /* Workaround for pserver buffer overrun : Nov 11,1999 by T.Aono */
-  /* assumes pserver[64]. variable length string is not supported. */
-  strncpy(pserver, server, 64-1);
-  pserver[64-1] = '\0';
-  p = pserver;
+  /* assumes pserver[NI_MAXHOST]. variable length string is not supported. */
+		strncpy(pserver, server, NI_MAXHOST - 1);
+		pserver[NI_MAXHOST - 1] = '\0';
+		p = pserver;
 #ifdef INET6
-  }
+	}
 #endif
-  for (; *p && *p != ':'; p++);
-  if (!*p)
-    return (0);                 /* does not have a colon */
-  *p = 0;
-  return (atoi (++p));
+
+	for (; *p && *p != ':'; p++);
+	if (!*p) /* does not have a colon */	
+		return (0);
+	*p = 0;
+	return (atoi (++p));
 }
 
 /*      Packet SND/RCV subroutines      */
 static void put4com ();
 
-/**     パケットのヘッダーを送る        **/
+/* send packet header */
 static void
-snd_head (cmd)
-     int cmd;   /** cmd=コマンド **/
+snd_head(int cmd)
 {
-  sbp = 0;
-  put4com (cmd);
-  rbc = -1;
+	sbp = snd_buf;
+	put4com(cmd);
+	rcv_flush();
 }
 
-/**     パケットのヘッダーを送る        **/
+/* send environment header */
 static int
-snd_env_head (env, cmd)
-     register struct wnn_env *env;
-     int cmd;   /** cmd=コマンド **/
+snd_env_head (struct wnn_env *env,
+	      int cmd)
 {
-  snd_head (cmd);
-  put4com (env->env_id);
-  return 0;
+	snd_head(cmd);
+	put4com(env->env_id);
+	return 0;
 }
 
-/**     パケットのヘッダーを送る        **/
+/* send server header */
 static int
-snd_server_head (server, cmd)
-     register WNN_JSERVER_ID *server;
-     int cmd;   /** cmd=コマンド **/
+snd_server_head(WNN_JSERVER_ID *server,
+		int cmd)
 {
-  snd_head (cmd);
-  return 0;
+	snd_head(cmd);
+	return 0;
 }
 
-/**     送信バッファをフラッシュする    **/
+/* flush send buffer */
 static int
-snd_flush ()
+snd_flush()
 {
-  if (sbp == 0)
-    return (-1);
-  writen (sbp);
-  sbp = 0;
-  return (0);
+	/* empty buffer; no need to flush */
+	if (sbp == snd_buf)
+		return 0;
+
+	writen(sbp);
+	return 0;
 }
 
+/* send data */
 static int
-writen (n)
-     int n;
+writen(unsigned char *sp)
 {
-  int cc, x;
-  for (cc = 0; cc < n;)
-    {
-      errno = 0;
+	unsigned char *bp = snd_buf;
+	int n;
+	size_t total = sp - bp;
+
+	while (bp < sp && bp <= snd_buf + sizeof(snd_buf)) {
+#if DEBUG_IO
+		fprintf(stderr,
+			"writen: loop: sp - bp = %d\n", sp - bp);
+#endif
 #ifdef HAVE_SEND
-      x = send (current_sd, &snd_buf[cc], n - cc, 0);
+		n = send(current_sd, bp, sp - bp, 0);
 #else
-      x = write (current_sd, &snd_buf[cc], n - cc);
+		n = write(current_sd, bp, sp - bp);
 #endif
-      if (x < 0)
-        {
-          if (ERRNO_CHECK (errno) || errno == EINTR)
-            {
-              continue;
-            }
-          else
-            {
-              daemon_dead ();
-              return -1;
-            }
-        }
-      cc += x;
-    }
-#if DEBUG
-  fprintf (stderr, "jslib:writen=%d\n", x);
-/*      dmp(snd_buf,x); */
+		if (n < 0) {
+			if (ERRNO_CHECK (errno) || errno == EINTR) {
+				continue;
+			} else {
+#if DEBUG_IO
+				fprintf(stderr,
+					"writen: failed. errno=%d\n", errno);
+#endif
+				daemon_dead();
+				return -1;
+			}
+		}
+		bp += n;
+	}
+	sbp = snd_buf;
+#if DEBUG_IO
+	fprintf (stderr, "jslib:writen=%d\n", total);
 #endif
-  return (0);
+	return 0;
 }
 
-/**     サーバへ1バイト送る     **/
+/* send one byte to server */
 static void
-put1com (c)
-     int c;
+put1com(int c)
 {
-  snd_buf[sbp++] = c;
-  if (sbp >= S_BUF_SIZ)
-    {
-      writen (S_BUF_SIZ);
-      sbp = 0;
-    }
+	unsigned int data = c & 0xff;
+
+#if DEBUG_IO
+	fprintf(stderr, "put1com: [%02x]\n", data);
+#endif
+	
+	/* flush buffer if full */
+	if (sbp - snd_buf >= S_BUF_SIZ) {
+		writen(sbp);
+	}
+	*(sbp++) = data;
 }
 
-/**     サーバへ2バイト送る     **/
+/* send two bytes */
 static void
-put2com (c)
-     int c;
+put2com(int c)
 {
-  put1com (c >> (8 * 1));
-  put1com (c);
+	unsigned int data = c & 0xffff;
+#if DEBUG_IO
+	fprintf(stderr, "put2com: [%04x]\n", data);
+#endif
+	put1com(data >> (8 * 1));
+	put1com(data);
 }
 
-/**     サーバへ4バイト送る     **/
+/* send four bytes */
 static void
-put4com (c)
-     int c;
+put4com(int c)
 {
-  put1com (c >> (8 * 3));
-  put1com (c >> (8 * 2));
-  put1com (c >> (8 * 1));
-  put1com (c);
+	unsigned int data = c & 0xffffffff;
+#if DEBUG_IO
+	fprintf(stderr, "put4com: [%08x]\n", data);
+#endif
+	put1com(data >> (8 * 3));
+	put1com(data >> (8 * 2));
+	put1com(data >> (8 * 1));
+	put1com(data);
 }
 
-/**     サーバへ文字列を送る    **/
+/* send w_char string */
 static void
-putwscom (p)
-     register w_char *p;
+putwscom(w_char *p)
 {
-  if (p == NULL)
-    {
-      put2com (0);
-      return;
-    }
-  while (*p)
-    put2com (*p++);
-  put2com (0);
+	if (p == NULL) {
+		put2com(0x0000);
+		return;
+	}
+
+#if DEBUG_IO
+	fprintf(stderr, "putwscom: [%s]\n", p);
+#endif
+	while(*p)
+		put2com (*p++);
+	put2com(0x0000);
 }
 
-/**     サーバへ文字列を送る    **/
+/* send string */
 static void
-putscom (p)
-     register char *p;
+putscom(unsigned char *p)
 {
-  if (p == NULL)
-    {
-      put1com (0);
-      return;
-    }
-  while (*p)
-    put1com (*p++);
-  put1com (0);
-}
+	if (p == NULL) {
+		put1com(0x00);
+		return;
+	}
+#if DEBUG_IO
+	fprintf(stderr, "putscom: [%s]\n", p);
+#endif
+	while (*p)
+		put1com(*p++);
+	put1com(0);
+}
+
+static unsigned char rcv_buf[R_BUF_SIZ];
+static unsigned char *rbp = rcv_buf;
+static unsigned char *rp = rcv_buf;
 
-/**     サーバから1バイト受ける **/
 static int
-get1com ()
+rcv_flush()
 {
-  static int rbp;
-  static unsigned char rcv_buf[R_BUF_SIZ];      /** 受信 **/
-  if (rbc <= 0)
-    {
-      while (1)
-        {
-          errno = 0;
-#ifdef HAVE_RECV
-          rbc = recv (current_sd, rcv_buf, R_BUF_SIZ, 0);
-#else
-          rbc = read (current_sd, rcv_buf, R_BUF_SIZ);
-#endif
-          if (rbc <= 0)
-            {
-              if (ERRNO_CHECK (errno))
-                {
-                  continue;
-                }
-              else if (rbc == 0)
-                {
-                  daemon_dead ();
-                  return -1;
-                }
-              else
-                {               /* cc == -1 */
-                  if (errno != EINTR)
-                    {
-                      daemon_dead ();
-                      return -1;
-                    }
-                  continue;
-                }
-            }
-          rbp = 0;
-#if DEBUG
-          fprintf (stderr, "jslib:read:rbc=%d\n", rbc);
-/*      dmp(rcv_buf,rbc); */
+#if DEBUG_IO
+	fprintf(stderr, "rcv_flush\n");
 #endif
-          break;
-        }
-    }
-  rbc--;
-  return rcv_buf[rbp++] & 0xFF;
+	rbp = rp = &rcv_buf[0];
+	return 0;
 }
 
-/**     サーバから2バイト受ける **/
-static int
-get2com ()
+static unsigned int
+get1com()
 {
-  register int h;
-  h = get1com ();
-  return (h << 8) | get1com ();
-}
+	int n;
 
-/**     サーバから4バイト受ける **/
-static int
-get4com ()
-{
-  register int h1, h2, h3;
-  h1 = get1com () << 24;
-  h2 = get1com () << 16;
-  h3 = get1com () << 8;
-  return h1 | h2 | h3 | get1com ();
+#if DEBUG_IO
+	fprintf(stderr, "get1com: Enter\n");
+#endif
+	if (rp == rbp) {
+		/* rp == rbp case; no data in rcv_buf */
+
+		rbp = rp = rcv_buf;
+
+		while (rbp == rp) {
+			errno = 0;
+#ifdef HAVE_RECV
+			n = recv(current_sd, rcv_buf, sizeof(rcv_buf), 0);
+#else
+			n = read(current_sd, rcv_buf, sizeof(rcv_buf));
+#endif
+#if DEBUG_IO
+			fprintf(stderr, "recvloop: n=%d\n", n);
+#endif
+			if (n == 0) {
+				if (ERRNO_CHECK(errno)) {
+					continue;
+				} else {
+					daemon_dead();
+					return -1;
+				}
+			}
+			if (n < 0) {
+				if (ERRNO_CHECK(errno) || errno == EINTR) {
+					continue;
+				} else {
+					daemon_dead();
+					return -1;
+				}
+			}
+			rp += n;
+		}
+#if DEBUG_IO
+		fprintf (stderr, "jslib:read:rp - rbp =%d\n", rp - rbp);
+#endif
+	}
+
+#if DEBUG_IO
+	fprintf(stderr, "get1com: data [%02x]\n", *rbp & 0xff);
+	
+	fprintf(stderr, "rcv_buf: ");
+	{
+		int i;
+		for (i=0; i < rp - rbp; i++) {
+			fprintf(stderr, "[%02x]", *(rbp + i));
+		}
+		fprintf(stderr, "\n");
+	}
+#endif
+	return (*(rbp++) & 0xff);
+}
+
+/* get two bytes */
+static unsigned int
+get2com()
+{
+	unsigned int h;
+#if DEBUG_IO
+	fprintf(stderr, "get2com: Enter\n");
+#endif
+	h  = get1com() << 8;
+	h |= get1com();
+
+#if DEBUG_IO
+	fprintf(stderr, "get2com: [%04x]\n", h);
+#endif
+	return h;
+}
+
+/* get four bytes */
+static unsigned int
+get4com()
+{
+	unsigned int h;
+#if DEBUG_IO
+	fprintf(stderr, "get4com: Enter\n");
+#endif
+	h  = get1com() << 24;
+	h |= get1com() << 16;
+	h |= get1com() << 8;
+	h |= get1com();
+#if DEBUG_IO
+	fprintf(stderr, "get4com: [%08x]\n", h);
+#endif
+	return h;
 }
 
-/**     サーバへ文字列を送る    **/
+/* get string */
 static void
-getscom (p)
-     register char *p;
+getscom(unsigned char *p)
 {
-  while (*p++ = get1com ())
-    ;
+	unsigned char *bp = p;
+	while (*p++ = get1com())
+		;
+#if DEBUG_IO
+	fprintf(stderr, "getscom: [%s]\n", bp);
+#endif
 }
 
-/**     サーバへ文字列を送る    **/
+/* get wstring */
 static void
-getwscom (p)
-     w_char register *p;
+getwscom(w_char *p)
 {
-  while (*p++ = get2com ())
-    ;
+	while (*p++ = get2com ())
+		;
 }
 
 #ifdef nodef
@@ -687,7 +720,6 @@ Strcpy (s1, s2)
 
 
 /*      Debug Subroutines       */
-#if DEBUG
 void
 xerror (s)
      char *s;
@@ -716,8 +748,6 @@ dmp (p, c)
     }
 }
 
-#endif
-
 /*      get login name form /etc/passwd file    */
 static char *
 getlogname ()
@@ -741,87 +771,104 @@ getlogname ()
 
 /**       jserver と接続する。jserver_id を返す。       **/
 WNN_JSERVER_ID *
-js_open_lang (server, lang, timeout)
-     register char *server, *lang;
-     register int timeout;
-{
-  char *new_js;
-  char host[WNN_HOSTLEN], user[WNN_ENVNAME_LEN];
-  int x;
+js_open_lang (char *server,
+	      char *lang,
+	      int timeout)
+{
+	char *new_js;
+	char host[WNN_HOSTLEN];
+	char user[WNN_ENVNAME_LEN];
+	int x;
+
+	if (wnn_msg_cat == NULL) {
+		char nlspath[MAXPATHLEN];
+		strcpy (nlspath, LIBDIR);
+		strcat (nlspath, "/%L/%N");
+		wnn_msg_cat = msg_open ("libwnn.msg", nlspath, lang);
+		if (wnn_msg_cat == NULL) {
+			fprintf (stderr,
+				 "libwnn: Cannot open message file for libwnn.a\n");
+		}
+	}
+
+	if (!(new_js = (char *) malloc (sizeof (WNN_JSERVER_ID)))) {
+		wnn_errorno = WNN_ALLOC_FAIL;
+		return NULL;
+	}
+
+	current_js = (WNN_JSERVER_ID *) new_js;
+	if (server == NULL) {
+		current_js->js_name[0] = '\0';
+	} else {
+		strncpy(current_js->js_name, server, sizeof (current_js->js_name) - 1);
+		current_js->js_name[sizeof (current_js->js_name) - 1] = '\0';
+	}
 
-  if (wnn_msg_cat == NULL)
-    {
-      char nlspath[MAXPATHLEN];
-      strcpy (nlspath, LIBDIR);
-      strcat (nlspath, "/%L/%N");
-      wnn_msg_cat = msg_open ("libwnn.msg", nlspath, lang);
-      if (wnn_msg_cat == NULL)
-        {
-          fprintf (stderr, "libwnn: Cannot open message file for libwnn.a\n");
-        }
-    }
-  sbp = 0;                      /* init sndBufPointer */
-  if (!(new_js = (char *) malloc (sizeof (WNN_JSERVER_ID))))
-    {
-      wnn_errorno = WNN_ALLOC_FAIL;
-      return NULL;
-    }
-  current_js = (WNN_JSERVER_ID *) new_js;
-  if (server == NULL)
-    {
-      current_js->js_name[0] = '\0';
-    }
-  else
-    {
-      strncpy (current_js->js_name, server, sizeof (current_js->js_name) - 1);
-      current_js->js_name[sizeof (current_js->js_name) - 1] = '\0';
-    }
-  current_js->js_dead = 0;
-  current_js->js_dead_env_flg = 0;
+	current_js->js_dead = 0;
+	current_js->js_dead_env_flg = 0;
 /*
  if(user == NULL || 0==strcmp(user,""))
 */
-  strncpy (user, getlogname (), WNN_ENVNAME_LEN);
-  user[WNN_ENVNAME_LEN - 1] = '\0';     /* truncate by WNN_ENVNAME_LEN */
-  if (server == NULL || 0 == strcmp (server, "") || 0 == strcmp (server, "unix"))
-    {
-      strcpy (host, "unix");
-      if ((current_sd = cd_open_un (lang)) == -1)
-        {
-          wnn_errorno = WNN_SOCK_OPEN_FAIL;
-          free ((char *) current_js);
-          current_js = NULL;
-          return NULL;
-        }
-    }
-  else
-    {
-      gethostname (host, WNN_HOSTLEN);
-      host[WNN_HOSTLEN - 1] = '\0';     /* truncate by WNN_HOSTLEN */
-      if ((current_sd = cd_open_in (server, lang, timeout)) == -1)
-        {
-          wnn_errorno = WNN_SOCK_OPEN_FAIL;
-          free ((char *) current_js);
-          current_js = NULL;
-          return NULL;
-        }
-    }
-  current_js->sd = current_sd;
-  handler_of_jserver_dead (NULL);
-  snd_head (JS_OPEN);
-  put4com (JLIB_VERSION);       /* H.T. */
-  putscom (host);
-  putscom (user);
-  snd_flush ();
-  if (get4com () == -1)
-    {
-      x = wnn_errorno = get4com ();
-      js_close (current_js);    /* H.T. */
-      current_js = NULL;
-      wnn_errorno = x;
-      return NULL;
-    }
-  return current_js;
+	strncpy(user, getlogname (), WNN_ENVNAME_LEN);
+	user[WNN_ENVNAME_LEN - 1] = '\0';     /* truncate by WNN_ENVNAME_LEN */
+
+#if DEBUG
+	fprintf(stderr, "js_open_lang: server: %s\n", server);
+#endif
+	if (server == NULL
+	    || 0 == strcmp(server, "")
+	    || 0 == strcmp(server, "unix")) {
+		strcpy(host, "unix");
+		if ((current_sd = cd_open_un(lang)) == -1) {
+			wnn_errorno = WNN_SOCK_OPEN_FAIL;
+			free ((char *) current_js);
+			current_js = NULL;
+			return NULL;
+		}
+	} else {
+		gethostname (host, WNN_HOSTLEN);
+		host[WNN_HOSTLEN - 1] = '\0';     /* truncate by WNN_HOSTLEN */
+#if DEBUG
+		fprintf(stderr, "js_open_lang: before cd_open_in\n");
+#endif
+		if ((current_sd = cd_open_in(server, lang, timeout)) == -1) {
+			wnn_errorno = WNN_SOCK_OPEN_FAIL;
+			free((char *)current_js);
+			current_js = NULL;
+#if DEBUG
+			fprintf(stderr, "js_open_lang: cd_open_in failed\n");
+#endif
+			return NULL;
+		}
+#if DEBUG
+		fprintf(stderr, "js_open_lang: after cd_open_in\n");
+#endif
+	}
+
+#if DEBUG
+	fprintf(stderr, "current_sd=%d\n", current_sd);
+#endif
+	current_js->sd = current_sd;
+	handler_of_jserver_dead (NULL);
+	snd_head(JS_OPEN);
+	put4com(JLIB_VERSION);       /* H.T. */
+	putscom(host);
+	putscom(user);
+	snd_flush();
+
+#if DEBUG
+	fprintf(stderr, "cd_open_in: before get4com\n");
+#endif
+
+	if (get4com() == -1) {
+		x = wnn_errorno = get4com ();
+		js_close(current_js);    /* H.T. */
+		current_js = NULL;
+		wnn_errorno = x;
+		return NULL;
+	}
+
+	return current_js;
 }
 
 
@@ -2988,29 +3035,25 @@ get_serv_defs (lang, cnt)
 }
 
 char *
-_wnn_get_machine_of_serv_defs (lang)
-     char *lang;
+_wnn_get_machine_of_serv_defs(char *lang)
 {
   return (get_serv_defs (lang, MACHINE_NAME));
 }
 
 static char *
-get_unixdomain_of_serv_defs (lang)
-     char *lang;
+get_unixdomain_of_serv_defs(char *lang)
 {
   return (get_serv_defs (lang, UNIXDOMAIN_NAME));
 }
 
 static char *
-get_service_of_serv_defs (lang)
-     char *lang;
+get_service_of_serv_defs(char *lang)
 {
   return (get_serv_defs (lang, SERVICE_NAME));
 }
 
 static int
-get_port_num_of_serv_defs (lang)
-     char *lang;
+get_port_num_of_serv_defs(char *lang)
 {
   char *port_char;
 
