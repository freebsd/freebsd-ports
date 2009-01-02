Index: Wnn/jserver/de.c
===================================================================
RCS file: /home/cvs/private/hrs/freewnn/Wnn/jserver/de.c,v
retrieving revision 1.1.1.1
diff -d -u -I\$FreeBSD: /tmp/pcvs/ports/japanese/FreeWnn-server/files/patch-Wnn-jserver-de.c,v 1.3 2009-01-02 23:08:15 hrs Exp $ -I\$NetBSD:.*\$ -I\$OpenBSD:.*\$ -I\$DragonFly:.*\$ -I\$Id:.*\$ -I\$Translation:.*\$ -I\$hrs:.*\$ -w -r1.1.1.1 de.c
--- Wnn/jserver/de.c	20 Dec 2008 07:13:30 -0000	1.1.1.1
+++ Wnn/jserver/de.c	2 Jan 2009 22:27:53 -0000
@@ -102,29 +102,18 @@
 #endif
 
 #ifndef INET6
-#  define OPTIONARGS  "Df:s:h:N:p:vu4"
+#  define OPTIONARGS  "a:Df:s:h:N:p:vu4"
 #else
-#  define OPTIONARGS  "Df:s:h:N:p:vu46"
+#  define OPTIONARGS  "a:Df:s:h:N:p:vu46"
 #endif /* INET6 */
 
 /*      Accept Socket   */
-#ifdef INET6
-#define MAX_ACCEPTS     3
-#else
-#define MAX_ACCEPTS     2
-#endif
-#define UNIX_ACPT       0
-#define INET_ACPT       1
-#ifdef INET6
-#define INET6_ACPT      2
-#endif
+#define MAX_ACCEPTS     256
 
 #define PROTO_ALL	0x1
 #define PROTO_UN	0x2
 #define PROTO_INET	0x4
-#ifdef INET6
 #define PROTO_INET6	0x8
-#endif
 static int listen_proto = PROTO_ALL;
 
 jmp_buf client_dead;
@@ -132,17 +121,15 @@
 static int port;
 static int serverNO = 0;
 
-struct cmblk
-{
+struct cmblk {
+	int domain;
   int sd;                       /** ソケットのfd        **/
 };
-#define COMS_BLOCK      struct  cmblk
 
-static COMS_BLOCK *cblk;
+static struct cmblk *cblk;
                 /** クライアントごとのソケットを管理するテーブル **/
-
-static COMS_BLOCK accept_blk[MAX_ACCEPTS];      /*accept sock blocks */
-
+static struct cmblk accept_blk[MAX_ACCEPTS];      /*accept sock blocks */
+static int bindex;
 
 /*      Communication Buffers           */
 static char snd_buf[R_BUF_SIZ];         /** 送信バッファ **/
@@ -191,17 +178,14 @@
 static void daemon_fin_in (int);
 static int  rcv_1_client (int);
 static void snd_1_client (int, int);
-static void socket_init_un (void);
-static void socket_init_in (void);
-static int  socket_accept_un (void);
-static int  socket_accept_in (int);
+static void socket_init_un(int *);
+static void socket_init_in(int *);
+static int  socket_accept(int);
 static void xerror (char*);
 static void get_options (int, char **);
 static void usage (void);
 static void print_version (void);
-#ifdef DEBUG
 static void dmp (char*, int);
-#endif
 
 static char cmd_name[16];
 
@@ -266,8 +250,11 @@
   /*  hosts_access_verbose = 2; */
 #endif /* HAVE_LIBWRAP */
 
-  signal (SIGHUP, signal_hand);
+  if (option_flag & OPT_FORK)
+	  /* when -D is not specified, accept SIGINT */
   signal (SIGINT, signal_hand);
+
+  signal (SIGHUP, signal_hand);
   signal (SIGQUIT, signal_hand);
   signal (SIGTERM, terminate_hand);
   if (option_flag & OPT_FORK)
@@ -276,16 +263,17 @@
       signal (SIGTSTP, SIG_IGN);
 #endif /* SIGTSTP */
     }
+
   read_default ();
   daemon_init ();
 
   env_init ();
-  if (file_init () == NULL)
+  if (file_init () == 0)
     {
       exit (1);
     }
   dic_init ();
-  if (NULL == get_kaiseki_area (LENGTHCONV + 1))    /* 変換可能文字数 */
+  if (0 == get_kaiseki_area (LENGTHCONV + 1))    /* 変換可能文字数 */
     {
       log_err ("get_kaiseki_area failed.");
       exit (1);
@@ -370,19 +358,16 @@
 static void
 socket_disc_init (void)
 {
-  if (WNN_NFD <= FD_SETSIZE)
-    {
-      nofile = WNN_NFD;
-    }
-  else
-    {
-      nofile = FD_SETSIZE;
-    }
+	nofile = MIN(WNN_NFD, FD_SETSIZE);
+
   all_socks = (fd_set *) malloc (sizeof (fd_set));
-  FD_ZERO (all_socks);
   ready_socks = (fd_set *) malloc (sizeof (fd_set));
   dummy1_socks = (fd_set *) malloc (sizeof (fd_set));
   dummy2_socks = (fd_set *) malloc (sizeof (fd_set));
+	FD_ZERO(all_socks);
+	FD_ZERO(ready_socks);
+	FD_ZERO(dummy1_socks);
+	FD_ZERO(dummy2_socks);
 }
 
 /**     全てのソケットについて待つ      **/
@@ -390,20 +375,17 @@
 sel_all (void)
 {
   memcpy (ready_socks, all_socks, sizeof (fd_set));
-  bzero (dummy1_socks, sizeof (fd_set));
-  bzero (dummy2_socks, sizeof (fd_set));
+	FD_ZERO(dummy1_socks);
+	FD_ZERO(dummy2_socks);
 
 top:
   errno = 0;
-  if ((no_of_ready_socks = select (nofile, ready_socks, dummy1_socks, dummy2_socks, NULL)) == -1)
-    {
+	if ((no_of_ready_socks = select(nofile, ready_socks, dummy1_socks, dummy2_socks, NULL)) == -1) {
       if (errno == EINTR)
         goto top;
       xerror ("select error");
     }
-#ifdef DEBUG
   log_debug ("select OK, ready_socks[0]=%02X, n-r-s=%x\n", ready_socks[0], no_of_ready_socks);
-#endif
 }
 
 /**     ready_socksから今やる一人を取り出して返す(cur_clpにもセットする)
@@ -438,7 +420,7 @@
 static void
 new_client (void)               /* NewClient */
 {
-  int sd;
+	int sd = -1;
   int full, i;
   FILE *f[3];
   char gomi[1024];
@@ -446,61 +428,54 @@
   int is_internet_socket;
   struct request_info tcpd_request;
 #endif /* HAVE_LIBWRAP */
-#ifdef  AF_UNIX
-  if ((serverNO == 0) &&
-      (FD_ISSET (accept_blk[UNIX_ACPT].sd, ready_socks)))
-    {
-      FD_CLR (accept_blk[UNIX_ACPT].sd, ready_socks);
+
+	log_debug("new client called");
+	for (i = 0; i < bindex && !FD_ISSET(accept_blk[i].sd, ready_socks); i++)
+		;
+
+	if (i == bindex)
+		return;
+
+	log_debug("new client: FDISSET(%d/%d) true, domain=%d", i, bindex, accept_blk[i].domain);
+	FD_CLR(accept_blk[i].sd, ready_socks);
       no_of_ready_socks--;
-      sd = socket_accept_un ();
+
+	switch (accept_blk[i].domain) {
+#ifdef AF_UNIX
+	case AF_UNIX:
+		sd = socket_accept(i);
 #ifdef  HAVE_LIBWRAP
       is_internet_socket = 0;
-#endif
-    }
-  else
+#endif /* HAVE_LIBWRAP */
+		break;
 #endif
 #ifdef INET6
-  if (FD_ISSET (accept_blk[INET6_ACPT].sd, ready_socks))
-    {
-      FD_CLR (accept_blk[INET6_ACPT].sd, ready_socks);
-      no_of_ready_socks--;
-      sd = socket_accept_in (accept_blk[INET6_ACPT].sd);
-#ifdef  HAVE_LIBWRAP
-      is_internet_socket = 1;
-#endif
-    }
-  else
+	case AF_INET6:
 #endif
-  if (FD_ISSET (accept_blk[INET_ACPT].sd, ready_socks))
-    {
-      FD_CLR (accept_blk[INET_ACPT].sd, ready_socks);
-      no_of_ready_socks--;
-      sd = socket_accept_in (accept_blk[INET_ACPT].sd);
+	case AF_INET:
+		sd = socket_accept(i);
 #ifdef  HAVE_LIBWRAP
       is_internet_socket = 1;
-#endif
-    }
-  else
-    {
+#endif /* HAVE_LIBWRAP */
+		break;
+	default:
       return;
     }
-  log_debug ("new client: sd = %d", sd);
+
+	log_debug("new client: sd = %d (type=%d)", sd, accept_blk[i].domain);
+
   /* reserve 2 fd */
-  for (full = i = 0; i < 2; i++)
-    {
-      if (NULL == (f[i] = fopen ("/dev/null", "r")))
-        {
+	for (full = i = 0; i < 2; i++) {
+		if (NULL == (f[i] = fopen ("/dev/null", "r"))) {
           full = 1;
         }
     }
-  for (i = 0; i < 2; i++)
-    {
+	for (i = 0; i < 2; i++) {
       if (NULL != f[i])
         fclose (f[i]);
     }
 
-  if (full || sd >= nofile || clientp >= max_client)
-    {
+	if (full || sd >= nofile || clientp >= max_client) {
       log_err ("no more client.");
 #ifdef HAVE_RECV
       recv (sd, gomi, 1024, 0);
@@ -521,8 +496,7 @@
     request_init (&tcpd_request,RQ_DAEMON, WNN_DAEMON_NAME,
 		  RQ_FILE, sd, NULL);
     fromhost (&tcpd_request);
-    if (!hosts_access (&tcpd_request))
-      {
+		if (!hosts_access (&tcpd_request)) {
 	log_err ("reject client."); /* should be log_info? */
 				    /* should we log IP address / hostname? */
 #ifdef HAVE_RECV
@@ -543,8 +517,7 @@
 
   cblk[clientp].sd = sd;
   FD_SET (sd, all_socks);
-  for (i = 0; i < WNN_MAX_ENV_OF_A_CLIENT; i++)
-    {
+	for (i = 0; i < WNN_MAX_ENV_OF_A_CLIENT; i++) {
       (client[clientp].env)[i] = -1;
     }
   clientp++;
@@ -584,8 +557,7 @@
   signal (SIGQUIT, SIG_IGN);
   */
 
-
-  if ((cblk = (COMS_BLOCK *) malloc (max_client * sizeof (COMS_BLOCK))) == NULL)
+  if ((cblk = (struct cmblk *) malloc (max_client * sizeof(struct cmblk))) == NULL)
     {
       xerror ("daemon_init: ");
     }
@@ -597,17 +569,14 @@
   clientp = 0;                  /* V3.0 */
   cur_clp = 0;                  /* V3.0 */
   socket_disc_init ();
-#ifdef INET6
-  if (listen_proto&(PROTO_ALL|PROTO_INET|PROTO_INET6))
-      socket_init_in ();
-#else
-  if (listen_proto&(PROTO_ALL|PROTO_INET))
-      socket_init_in ();
-#endif
+
 #ifdef  AF_UNIX
   if (listen_proto&(PROTO_ALL|PROTO_UN))
-      socket_init_un ();
-#endif /* AF_UNIX */
+	  socket_init_un(&bindex);
+#endif
+
+  if (listen_proto & (PROTO_ALL|PROTO_INET|PROTO_INET6))
+	  socket_init_in(&bindex);
 }
 
 /**     サーバを終わる  **/
@@ -619,8 +588,6 @@
   struct sockaddr_un addr_un;
   socklen_t addrlen;
 
-  if (serverNO == 0)
-    {
 #ifndef SOLARIS
 #if defined(FIONBIO)
       ioctl (sock_d_un, FIONBIO, &trueFlag);
@@ -628,8 +595,7 @@
 #else /* !SOLARIS */
       fcntl (sock_d_un, F_SETFL, F_UNLCK);
 #endif /* !SOLARIS */
-      for (;;)
-        {
+	for (;;) {
           addrlen = sizeof (addr_un);
           if (accept (sock_d_un, (struct sockaddr *) &addr_un, &addrlen) < 0)
             break;
@@ -638,7 +604,6 @@
       shutdown (sock_d_un, 2);
       close (sock_d_un);
     }
-}
 #endif /* AF_UNIX */
 
 static void
@@ -662,8 +627,7 @@
 #else /* !SOLARIS */
   fcntl (sock_d_in, F_SETFL, F_UNLCK);
 #endif /* !SOLARIS */
-  for (;;)
-    {
+	for (;;) {
       addrlen = sizeof (addr_in);
       if (accept (sock_d_in, (struct sockaddr *) &addr_in, &addrlen) < 0)
         break;
@@ -680,38 +644,36 @@
 void
 daemon_fin (void)
 {
+	int i;
   int fd;
-#ifdef  AF_UNIX
-  int sock_d_un = accept_blk[UNIX_ACPT].sd;
-#endif /* AF_UNIX */
-  int sock_d_in = accept_blk[INET_ACPT].sd;
-#ifdef INET6
-  int sock_d_in6 = accept_blk[INET6_ACPT].sd;
-#endif
 
-  /*
-     accept all pending connection from new clients,
-     avoiding kernel hangup.
-   */
+	for (i = 0; i < bindex; i++) {
+		if (FD_ISSET(accept_blk[i].sd, all_socks)) {
+			switch (accept_blk[i].domain) {
 #ifdef  AF_UNIX
-  daemon_fin_un (sock_d_un);
+			case AF_UNIX:
+				if (listen_proto & (PROTO_ALL|PROTO_UN))
+					daemon_fin_un(accept_blk[i].sd);
+				break;
 #endif
-  daemon_fin_in (sock_d_in);
+			case AF_INET:
+				if (listen_proto & (PROTO_ALL|PROTO_INET))
+					daemon_fin_in(accept_blk[i].sd);
+				break;
 #ifdef INET6
-  daemon_fin_in (sock_d_in6);
+			case AF_INET6:
+				if (listen_proto & (PROTO_ALL|PROTO_INET6))
+					daemon_fin_in(accept_blk[i].sd);
+				break;
 #endif
+			default:
+				break;
+			}
+		}
+	}
 
-  for (fd = nofile - 1; fd >= 0; fd--)
-    {
-      if ((fd != sock_d_in) &&
-#ifdef INET6
-          (fd != sock_d_in6) &&
-#endif
-#ifdef AF_UNIX
-          (fd != sock_d_un) &&
-#endif /* AF_UNIX */
-          FD_ISSET (fd, all_socks))
-        {
+	for (fd = nofile - 1; fd >= 0; fd--) {
+		if (FD_ISSET(fd, all_socks)) {
           shutdown (fd, 2);
 #ifdef HAVE_CLOSESOCKET
           closesocket (fd);
@@ -837,10 +799,8 @@
             }
         }
     }
-#ifdef DEBUG
   log_debug ("rcv: clp = %d, sd = %d, cc = %d", clp, cblk[clp].sd, cc);
   dmp (rcv_buf, cc);
-#endif
   return cc;
 }
 
@@ -850,10 +810,9 @@
 	      int n	/* n : number of bytes to send */ )
 {
   int cc, x;
-#ifdef  DEBUG
   log_debug ("snd: clp = %d, sd = %d", clp, cblk[clp].sd);
   dmp (snd_buf, n);
-#endif
+
   for (cc = 0; cc < n;)
     {
       errno = 0;
@@ -967,112 +926,111 @@
 
 /**     ソケットのイニシャライズ        **/
 #ifdef  AF_UNIX
+#if !defined(SUN_LEN)
+# define SUN_LEN(su) (sizeof(*(su)) - sizeof((su)->sun_path) + strlen((su)->sun_path))
+#endif
+
 static void
-socket_init_un (void)
+socket_init_un(int *index)
 {
   struct sockaddr_un saddr_un;
   int sock_d_un;
-  if (serverNO == 0)
-    {
+
       saddr_un.sun_family = AF_UNIX;
-      unlink (sockname);
-      strcpy (saddr_un.sun_path, sockname);
-      if ((sock_d_un = socket (AF_UNIX, SOCK_STREAM, 0)) == ERROR)
-        {
+	strncpy(saddr_un.sun_path, sockname, sizeof(saddr_un.sun_path) - 1);
+	saddr_un.sun_path[sizeof(saddr_un.sun_path) - 1] = '\0';
+
+	unlink(saddr_un.sun_path);
+
+	if ((sock_d_un = socket(saddr_un.sun_family, SOCK_STREAM, 0)) == ERROR)
           xerror ("could not create unix domain socket");
-        }
-      if (bind (sock_d_un, (struct sockaddr *) &saddr_un, strlen (saddr_un.sun_path) + 2) == ERROR)
-        {
+
+	if (bind(sock_d_un, (struct sockaddr *)&saddr_un, SUN_LEN(&saddr_un)) == ERROR) {
           shutdown (sock_d_un, 2);
           xerror ("could not bind unix domain socket");
         }
-      if (listen (sock_d_un, 5) == ERROR)
-        {
+
+	if (listen(sock_d_un, 5) == ERROR) {
           shutdown (sock_d_un, 2);
           xerror ("could not listen unix domain socket");
         }
+
       chmod (sockname, 0777);
       signal (SIGPIPE, SIG_IGN);
-#ifdef DEBUG
-      log_debug ("sock_d_un = %d", sock_d_un);
-#endif
-      accept_blk[UNIX_ACPT].sd = sock_d_un;
+	log_debug ("sock_d_un = %d (bindex=%d)", sock_d_un, *index);
+	accept_blk[(*index)].sd = sock_d_un;
+	accept_blk[(*index)].domain = saddr_un.sun_family;
+	(*index)++;
       FD_SET (sock_d_un, all_socks);
     }
-}
 #endif /* AF_UNIX */
 
 /*      Inet V3.0 */
 static void
-socket_init_in (void)
+socket_init_in(int *index)
 {
+	int i;
 #ifndef SOLARIS
   int on = 1;
 #else /* SOLARIS */
   int on = 0;
 #endif /* SOLARIS */
+
   struct servent *sp;
 #if !defined(SO_DONTLINGER) && defined(SO_LINGER)
   struct linger linger;
 #endif
-#ifdef INET6
   struct addrinfo hints, *res, *res0;
+	struct sockaddr sa;
   int error;
-  char sport[6];
-#else
-  struct sockaddr_in saddr_in;
-#endif
+	char hbuf[NI_MAXHOST];
+	char sbuf[NI_MAXSERV];
   int sock_d_in;
 
-  if (port < 0)
-    {
-      if ((sp = getservbyname (SERVERNAME, "tcp")) == NULL)
-        {
-          port = WNN_PORT_IN;
-        }
-      else
-        {
-          port = ntohs (sp->s_port);
-        }
+	memset(&sa, 0, sizeof(struct sockaddr));
+	if (port < 0) {
+		strncpy(sbuf, SERVERNAME, sizeof(sbuf) - 1);
+		sbuf[sizeof(sbuf) - 1] = '\0';
+		error = getnameinfo(&sa, sa.sa_len, NULL, 0, sbuf, sizeof(sbuf), NI_NUMERICSERV);
+		if (error)
+			sprintf(sbuf, "%d", WNN_PORT_IN);
+	} else {
+		sprintf(sbuf, "%d", port);
     }
 
   port += serverNO;
 
-#if DEBUG
-  log_debug ("port=%x", port);
-#endif
-#ifdef INET6
   memset(&hints, 0, sizeof(hints));
-  if (listen_proto&PROTO_INET && !(listen_proto&PROTO_INET6))
+	if (listen_proto & PROTO_ALL || listen_proto & (PROTO_INET|PROTO_INET6))
+		hints.ai_family = PF_UNSPEC;
+	else if (listen_proto & PROTO_INET)
       hints.ai_family = PF_INET;
-  else if (listen_proto&PROTO_INET6 && !(listen_proto&PROTO_INET))
+	else if (listen_proto & PROTO_INET6)
       hints.ai_family = PF_INET6;
-  else
-      hints.ai_family = PF_UNSPEC;
+
   hints.ai_socktype = SOCK_STREAM;
   hints.ai_flags = AI_PASSIVE;
-  sprintf(sport, "%d", port);
-  error = getaddrinfo(NULL, sport, &hints, &res0);
-  if (error)
-    {
-      xerror (gai_strerror(error));
-    }
+
+	for (i = 0; i < MAXLISTENADDR && listenaddr[i][0] != '\0'; i++) {
+		if (error = getaddrinfo(listenaddr[i], sbuf, &hints, &res0))
+			xerror((char *)gai_strerror(error));
+
   for (res = res0; res; res = res->ai_next) {
-    if (res->ai_family == AF_INET || res->ai_family == AF_INET6){
-      if ((sock_d_in = socket (res->ai_family, res->ai_socktype, res->ai_protocol)) == ERROR)
-#else
-  saddr_in.sin_family = AF_INET;
-  saddr_in.sin_port = htons (port);
-  saddr_in.sin_addr.s_addr = htonl (INADDR_ANY);
-  if ((sock_d_in = socket (AF_INET, SOCK_STREAM, 0)) == ERROR)
-#endif
-    {
-#ifdef INET6
-      if (res->ai_family == AF_INET6)
-        xerror ("could not create inet6 socket");
-      else if (res->ai_family == AF_INET)
+			log_debug("socket: try %s : %s (type=%d)", listenaddr[i], sbuf, res->ai_family);
+
+			switch (res->ai_family) {
+			case AF_INET:
+				sock_d_in = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
+				if (sock_d_in == -1)
+					xerror("could not create inet/inet6 socket");
+				break;
+			case AF_INET6:
+				sock_d_in = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
+				if (sock_d_in == -1)
+					xerror("could not create inet/inet6 socket");
+#ifdef IPV6_V6ONLY
+				setsockopt(sock_d_in, IPPROTO_IPV6, IPV6_V6ONLY, NULL, 0);
 #endif
-      xerror ("could not create inet socket");
     }
   setsockopt (sock_d_in, SOL_SOCKET, SO_REUSEADDR, (char *) &on, sizeof (int));
 #ifdef SO_DONTLINGER
@@ -1085,69 +1043,31 @@
 # endif /* SO_LINGER */
 #endif /* SO_DONTLINGER */
 
-#ifdef INET6
-  if (bind (sock_d_in, res->ai_addr, res->ai_addrlen) == ERROR)
-#else
-  if (bind (sock_d_in, (struct sockaddr *) &saddr_in, sizeof (saddr_in)) == ERROR)
-#endif
-    {
+			if (bind(sock_d_in, res->ai_addr, res->ai_addrlen) == ERROR) {
       shutdown (sock_d_in, 2);
-#ifdef INET6
-      if (res->ai_family == AF_INET6)
-        xerror ("can't bind inet6 socket");
-      else if (res->ai_family == AF_INET)
-#endif
-      xerror ("can't bind inet socket");
+				xerror("could not bind inet/inet6 socket");
     }
-  if (listen (sock_d_in, 5) == ERROR)
-    {
+
+			if (listen(sock_d_in, 5) == ERROR) {
       shutdown (sock_d_in, 2);
-#ifdef INET6
-      if (res->ai_family == AF_INET6)
-        xerror ("can't listen inet6 socket");
-      else if (res->ai_family == AF_INET)
-#endif
-      xerror ("can't listen inet socket");
+				xerror("could not listen inet/inet6 socket");
     }
-#if DEBUG
-  log_debug ("sock_d_in = %d", sock_d_in);
-#endif
+			log_debug("sock_d_in = %d (bindex=%d)", sock_d_in, *index);
   FD_SET (sock_d_in, all_socks);
-#ifdef INET6
-      if (res->ai_family == AF_INET)
-	accept_blk[INET_ACPT].sd = sock_d_in;
-      else if (res->ai_family == AF_INET6)
-	accept_blk[INET6_ACPT].sd = sock_d_in;
+			accept_blk[(*index)].sd = sock_d_in;
+			accept_blk[(*index)].domain = res->ai_family;
+			(*index)++;
     }
   }
   freeaddrinfo(res0);
-#else
-  accept_blk[INET_ACPT].sd = sock_d_in;
-#endif
 }
 
 
 /**     accept new client socket        **/
-#ifdef  AF_UNIX
-static int
-socket_accept_un (void)
-{
-  struct sockaddr_un addr;
-  socklen_t addrlen;
-
-  addrlen = sizeof (addr);
-  return accept (accept_blk[UNIX_ACPT].sd, (struct sockaddr *) &addr, &addrlen);
-}
-#endif /* AF_UNIX */
-
 static int
-socket_accept_in (int fd)
+socket_accept(int index)
 {
-  struct sockaddr_in addr;
-  socklen_t addrlen;
-
-  addrlen = sizeof (addr);
-  return accept (fd, (struct sockaddr *) &addr, &addrlen);
+	return accept(accept_blk[index].sd, NULL, NULL);
 }
 
 static void
@@ -1157,7 +1077,6 @@
   exit (1);
 }
 
-#if DEBUG
 static void
 dmp (char *p, int n)
 {
@@ -1172,13 +1091,13 @@
       fprintf (stderr, "n=%d\n", n);
     }
 }
-#endif
 
 static void
 get_options (int argc, char **argv)
 {
   int c;
   int digit_optind = 0;
+  int lindex = 0;
 
   strcpy (jserverrcfile, LIBDIR);       /* usr/local/lib/wnn */
   strcat (jserverrcfile, SERVER_INIT_FILE);     /* ja_JP/jserverrc */
@@ -1193,6 +1112,8 @@
 	{"inet",	0, NULL, '4'},
 	{"inet6",	0, NULL, '6'},
 	{"jserverrc",	1, NULL, 'f'},
+	{"listenaddr",	1, NULL, 'a'},
+	{"unix",	0, NULL, 'u'},
 	{"version",	0, NULL, 'v'},
 	{0, 0, 0, 0}
       };
@@ -1209,7 +1130,14 @@
 	  break;
 
         case 'f': /* --jserverrc FILENAME */
-          strcpy (jserverrcfile, optarg);
+          strncpy(jserverrcfile, optarg, sizeof(jserverrcfile) - 1);
+	  jserverrcfile[sizeof(jserverrcfile) - 1] = '\0';
+          break;
+
+        case 'a': /* --listenaddr ADDR */
+		strncpy(listenaddr[lindex], optarg, NI_MAXHOST - 1);
+		listenaddr[lindex][NI_MAXHOST - 1] = '\0';
+		lindex++;
           break;
 
         case 's':
@@ -1318,9 +1246,9 @@
 {
   fprintf(stderr, 
 #ifdef INET6
-	  "usage: %s [-Du46][-f <init_file> -s <log_file(\"-\" for stderr)> -h <pos_file> -N <serverNO> -p <port_base>]\n",
+	  "usage: %s [-Du46][-f <init_file> -a <listenaddr> -s <log_file(\"-\" for stderr)> -h <pos_file> -N <serverNO> -p <port_base>]\n",
 #else
-	  "usage: %s [-Du4][-f <init_file> -s <log_file(\"-\" for stderr)> -h <pos_file> -N <serverNO> -p <port_base>]\n",
+	  "usage: %s [-Du4][-f <init_file> -a <listenaddr> -s <log_file(\"-\" for stderr)> -h <pos_file> -N <serverNO> -p <port_base>]\n",
 #endif
 	  cmd_name);
   fprintf(stderr,
