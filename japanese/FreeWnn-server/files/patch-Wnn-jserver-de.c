Index: Wnn/jserver/de.c
===================================================================
RCS file: /home/cvs/private/hrs/freewnn/Wnn/jserver/de.c,v
retrieving revision 1.1.1.1
retrieving revision 1.8
diff -u -p -r1.1.1.1 -r1.8
--- Wnn/jserver/de.c	20 Dec 2008 07:13:30 -0000	1.1.1.1
+++ Wnn/jserver/de.c	9 Sep 2014 16:18:01 -0000	1.8
@@ -1,7 +1,7 @@
 /*
  * FreeWnn is a network-extensible Kana-to-Kanji conversion system.
  * This file is part of FreeWnn.
- * 
+ *
  * Copyright Kyoto University Research Institute for Mathematical Sciences
  *                 1987, 1988, 1989, 1990, 1991, 1992
  * Copyright OMRON Corporation. 1987, 1988, 1989, 1990, 1991, 1992, 1999
@@ -102,54 +102,35 @@ static char rcs_id[] = "$Id: de.c,v 1.36
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
 
-#define PROTO_ALL	0x1
 #define PROTO_UN	0x2
 #define PROTO_INET	0x4
-#ifdef INET6
 #define PROTO_INET6	0x8
-#endif
-static int listen_proto = PROTO_ALL;
+#define PROTO_ALL	(PROTO_UN|PROTO_INET|PROTO_INET6)
+static int listen_proto;
 
 jmp_buf client_dead;
 
 static int port;
-static int serverNO = 0;
+static int serverNO;
 
-struct cmblk
-{
-  int sd;                       /** ソケットのfd        **/
+struct cmblk {
+	int domain;
+	int sd;		/* socket fd */
 };
-#define COMS_BLOCK      struct  cmblk
 
-static COMS_BLOCK *cblk;
-                /** クライアントごとのソケットを管理するテーブル **/
-
-static COMS_BLOCK accept_blk[MAX_ACCEPTS];      /*accept sock blocks */
-
-
-/*      Communication Buffers           */
-static char snd_buf[R_BUF_SIZ];         /** 送信バッファ **/
-static int sbp;                         /** 送信バッファポインタ **/
-
-static int rbc;                         /** 受信バッファcounter **/
-static char rcv_buf[S_BUF_SIZ];         /** 受信バッファ **/
+/** クライアントごとのソケットを管理するテーブル **/
+static struct cmblk *cblk;
+/*accept sock blocks */
+static struct cmblk accept_blk[MAX_ACCEPTS];
+static int bindex;
 
 #if defined(EAGAIN)
 # if defined(EWOULDBLOCK)
@@ -167,7 +148,6 @@ static char rcv_buf[S_BUF_SIZ];         
 
 /*      Client Table    */
 int clientp;            /** cblkの有効なデータの最後を差している **/
-
 int cur_clp;            /** 現在のクライアントの番号 **/
 
 static fd_set *all_socks;	/** ビットパターン
@@ -181,27 +161,24 @@ struct msg_cat *wnn_msg_cat;
 struct msg_cat *js_msg_cat;
 
 /* function prototypes */
-static void daemon_main (void);
-static void socket_disc_init (void);
-static void sel_all (void);
-static int  get_client (void);
-static void new_client (void);
-static void daemon_init (void);
-static void daemon_fin_un (int);
-static void daemon_fin_in (int);
-static int  rcv_1_client (int);
-static void snd_1_client (int, int);
-static void socket_init_un (void);
-static void socket_init_in (void);
-static int  socket_accept_un (void);
-static int  socket_accept_in (int);
-static void xerror (char*);
-static void get_options (int, char **);
-static void usage (void);
-static void print_version (void);
-#ifdef DEBUG
-static void dmp (char*, int);
-#endif
+static void daemon_main(void);
+static void socket_disc_init(void);
+static int sel_all(void);
+static int  get_client(void);
+static void new_client(void);
+static void daemon_init(void);
+static void daemon_fin_un(int);
+static void daemon_fin_in(int);
+static int  rcv_1_client(int);
+static void snd_1_client(int, int);
+static void socket_init_un(int *);
+static void socket_init_in(int *);
+static int  socket_accept(int);
+static void xerror(char*);
+static void get_options(int, char **);
+static void usage(void);
+static void print_version(void);
+static void dmp(char*, int);
 
 static char cmd_name[16];
 
@@ -214,154 +191,136 @@ int deny_severity;
 
 /* No arguments are used. Only options. */
 int
-main (int argc, char *argv[])
+main(int argc, char *argv[])
 {
-  int tmpttyfd;
-  char *cswidth_name;
-  extern char *get_cswidth_name ();
-  extern void set_cswidth ();
-
-  char nlspath[64];
-
-  strcpy (cmd_name, WNN_DAEMON_NAME);
-  strcpy (lang_dir, LANG_NAME);
-  strcpy (nlspath, LIBDIR);
-  strcat (nlspath, "/%L/%N");
-  js_msg_cat = msg_open (MESSAGE_FILE, nlspath, lang_dir);
-  wnn_msg_cat = msg_open ("libwnn.msg", nlspath, lang_dir);
-  if (wnn_msg_cat == NULL)
-    {
-      log_err ("cannot open message file libwnn.msg.");
-    }
-  if (cswidth_name = get_cswidth_name (LANG_NAME))
-    set_cswidth (create_cswidth (cswidth_name));
+	int tmpttyfd;
+	pid_t pid;
+	int fd;
+	char *cswidth_name;
+	extern char *get_cswidth_name ();
+	extern void set_cswidth ();
+
+	char nlspath[64];
+
+	strcpy(cmd_name, WNN_DAEMON_NAME);
+	strcpy(lang_dir, LANG_NAME);
+	strcpy(nlspath, LIBDIR);
+	strcat(nlspath, "/%L/%N");
+	js_msg_cat = msg_open (MESSAGE_FILE, nlspath, lang_dir);
+	wnn_msg_cat = msg_open ("libwnn.msg", nlspath, lang_dir);
 
-  port = -1;
-  /* option default */
-  option_flag = (OPT_FORK & ~OPT_VERBOSE);
-
-  setuid (geteuid ());
-  get_options (argc, argv);
-  print_version();
-  log_debug("invoked as %s.", argv[0]);
-  if (option_flag & OPT_FORK)
-    {
-      if (fork ())
-	{
-	  signal (SIGCHLD, _exit);
-	  signal (SIGHUP, SIG_IGN);
-	  signal (SIGINT, SIG_IGN);
-	  signal (SIGQUIT, SIG_IGN);
-#ifdef  SIGTSTP
-	  signal (SIGTSTP, SIG_IGN);
-#endif
-	  signal (SIGTERM, _exit);
-	  pause ();
+	if (wnn_msg_cat == NULL) {
+		log_err ("cannot open message file libwnn.msg.");
 	}
-    }
+	if (cswidth_name = get_cswidth_name (LANG_NAME))
+		set_cswidth (create_cswidth (cswidth_name));
 
+	port = -1;
+	/* option default */
+	option_flag = (OPT_FORK & ~OPT_VERBOSE);
+
+	setuid(geteuid());
+	get_options (argc, argv);
+	print_version();
+	log_debug("invoked as %s.", argv[0]);
 #if defined(HAVE_LIBWRAP)
-  allow_severity = LOG_INFO;
-  deny_severity = LOG_WARNING;
-  /*  hosts_access_verbose = 2; */
+	allow_severity = LOG_INFO;
+	deny_severity = LOG_WARNING;
+	/*  hosts_access_verbose = 2; */
 #endif /* HAVE_LIBWRAP */
 
-  signal (SIGHUP, signal_hand);
-  signal (SIGINT, signal_hand);
-  signal (SIGQUIT, signal_hand);
-  signal (SIGTERM, terminate_hand);
-  if (option_flag & OPT_FORK)
-    {
-#ifdef  SIGTSTP
-      signal (SIGTSTP, SIG_IGN);
+	signal(SIGHUP, signal_hand);
+	signal(SIGQUIT, signal_hand);
+	signal(SIGTERM, terminate_hand);
+	if (option_flag & OPT_FORK) {
+		/* when -D is not specified, accept SIGINT */
+		signal(SIGINT, signal_hand);
+#ifdef	SIGTSTP
+		signal(SIGTSTP, SIG_IGN);
 #endif /* SIGTSTP */
-    }
-  read_default ();
-  daemon_init ();
-
-  env_init ();
-  if (file_init () == NULL)
-    {
-      exit (1);
-    }
-  dic_init ();
-  if (NULL == get_kaiseki_area (LENGTHCONV + 1))    /* 変換可能文字数 */
-    {
-      log_err ("get_kaiseki_area failed.");
-      exit (1);
-    }
-  init_work_areas ();
-  init_jmt ();
-
-  read_default_files ();
-
-  if (option_flag & OPT_FORK)
-    {
-      /* End of initialization, kill parent */
-      kill (getppid (), SIGTERM);
-      fclose (stdin);
-      fclose (stdout);
-      if (!(option_flag & OPT_VERBOSE))
-	{
-#if !(defined(BSD) && (BSD >= 199306))  /* !4.4BSD-Lite by Taoka */
-	  fclose (stderr);
-#else /* 4.4BSD-Lite */
-	  int fd = open ("/dev/null", O_WRONLY);
-	  if (fd < 0)
-	    {
-	      xerror ("Cannot open /dev/null");
-	    }
-	  dup2 (fd, 2);
-	  close (fd);
-#endif /* 4.4BSD-Lite */
 	}
-
+	read_default();
+	daemon_init();
+	env_init();
+	if (file_init() == 0)
+		exit (1);
+	dic_init();
+	if (0 == get_kaiseki_area (LENGTHCONV + 1)) {
+		/* 変換可能文字数 */
+		log_err ("get_kaiseki_area failed.");
+		exit (1);
+	}
+	init_work_areas();
+	init_jmt();
+	read_default_files();
+	if (option_flag & OPT_FORK) {
+		pid = fork();
+		if (pid == -1) {
+			log_err ("cannot fork.");
+			exit(1);
+		}
+		if (pid > 0)
+			_exit(0);
+		setsid();
+		pid = fork();
+		if (pid == -1) {
+			log_err ("cannot fork.");
+			exit(1);
+		}
+		if (pid > 0)
+			_exit(0);
+		chdir("/");
+		umask(0);
+		close(STDIN_FILENO);
+		close(STDOUT_FILENO);
+		if (!(option_flag & OPT_VERBOSE)) {
+			close(STDERR_FILENO);
+			fd = open("/dev/null", O_WRONLY);
+			if (fd < 0) {
+				xerror ("Cannot open /dev/null");
+			}
+			dup2(fd, STDERR_FILENO);
+			close(fd);
+		}
 #ifdef SETPGRP_VOID
-      setpgrp ();
+		setpgrp();
 #else /* !SETPGRP_VOID */
 # if !defined(TIOCNOTTY) && defined(SVR4)
 #  define TIOCNOTTY     _IO('t', 113)
 # endif /* !defined(TIOCNOTTY) && defined(SVR4) */
 #ifndef HITACHI
-      if ((tmpttyfd = open ("/dev/tty", O_RDWR)) >= 0)
-	{
-	  ioctl (tmpttyfd, TIOCNOTTY, 0);
-	  close (tmpttyfd);
-	}
+		if ((tmpttyfd = open("/dev/tty", O_RDWR)) >= 0) {
+			ioctl(tmpttyfd, TIOCNOTTY, 0);
+			close(tmpttyfd);
+		}
 #endif /* HITACHI */
 #endif /* SETPGRP_VOID */
-    }
-
-  daemon_main ();
-
-  daemon_fin ();
-  return (0);	/* it is not reached. only for avoiding compiler warning. */
+	}
+	daemon_main();
+	daemon_fin();
+	return(0);	/* NOTREACHED */
 }
 
 static void
 daemon_main (void)
 {
-  for (;;)
-    {
-      c_c = NULL;	/* Added for logging: server section */
-      sel_all ();
-      new_client ();
-      for (;;)
-        {
-          if (get_client () == -1)
-            break;
-          c_c = &client[cur_clp];
-          rbc = 0;
-          sbp = 0;
+	for (;;) {
+		c_c = NULL;	/* Added for logging: server section */
+		sel_all();
+		new_client();
+
+		for (;;) {
+			if (get_client () == -1)
+				break;
+			c_c = &client[cur_clp];
 /*      if(rcv_1_client(cur_clp) == 0){ del_client(); continue; }       */
-          if (setjmp (client_dead))
-            {
-              del_client ();
-              continue;
-            }
-          do_command (c_c);
-        }
-    }
+			if (setjmp(client_dead)) {
+				del_client ();
+				continue;
+			}
+			do_command(c_c);
+		}
+	}
 }
 
 /*
@@ -370,39 +329,36 @@ daemon_main (void)
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
-  all_socks = (fd_set *) malloc (sizeof (fd_set));
-  FD_ZERO (all_socks);
-  ready_socks = (fd_set *) malloc (sizeof (fd_set));
-  dummy1_socks = (fd_set *) malloc (sizeof (fd_set));
-  dummy2_socks = (fd_set *) malloc (sizeof (fd_set));
+	nofile = MIN(WNN_NFD, FD_SETSIZE);
+
+	all_socks = (fd_set *)malloc(sizeof(fd_set));
+	ready_socks = (fd_set *)malloc(sizeof(fd_set));
+	dummy1_socks = (fd_set *)malloc(sizeof(fd_set));
+	dummy2_socks = (fd_set *)malloc(sizeof(fd_set));
+	FD_ZERO(all_socks);
+	FD_ZERO(ready_socks);
+	FD_ZERO(dummy1_socks);
+	FD_ZERO(dummy2_socks);
 }
 
 /**     全てのソケットについて待つ      **/
-static void
-sel_all (void)
+static int
+sel_all(void)
 {
-  memcpy (ready_socks, all_socks, sizeof (fd_set));
-  bzero (dummy1_socks, sizeof (fd_set));
-  bzero (dummy2_socks, sizeof (fd_set));
+	int ns = 0;
+	memcpy(ready_socks, all_socks, sizeof(fd_set));
+	FD_ZERO(dummy1_socks);
+	FD_ZERO(dummy2_socks);
 
 top:
-  errno = 0;
-  if ((no_of_ready_socks = select (nofile, ready_socks, dummy1_socks, dummy2_socks, NULL)) == -1)
-    {
-      if (errno == EINTR)
-        goto top;
-      xerror ("select error");
-    }
+	errno = 0;
+	if ((no_of_ready_socks = select(nofile, ready_socks, dummy1_socks, dummy2_socks, NULL)) == -1) {
+		if (errno == EINTR)
+			goto top;
+		xerror ("select error");
+	}
 #ifdef DEBUG
-  log_debug ("select OK, ready_socks[0]=%02X, n-r-s=%x\n", ready_socks[0], no_of_ready_socks);
+	log_debug ("select OK, ready_socks[0]=%02X, n-r-s=%x\n", ready_socks[0], no_of_ready_socks);
 #endif
 }
 
@@ -412,142 +368,136 @@ top:
 static int
 get_client (void)
 {
-  int i;
-
-  if (no_of_ready_socks == 0)
-    return -1;                  /* no client waits service */
-
-  for (i = cur_clp;;)
-    {
-      if (no_of_ready_socks == 0)
-        return -1;
-      i++;
-      if (i >= clientp)
-        i = 0;
-      if (FD_ISSET (cblk[i].sd, ready_socks))
-        {
-	  FD_CLR (cblk[i].sd, ready_socks);
-          no_of_ready_socks--;
-          return cur_clp = i;
-        }
-    }
+	int i;
+	
+	if (no_of_ready_socks == 0)
+		return -1;                  /* no client waits service */
+	
+	for (i = cur_clp;;)
+	{
+		if (no_of_ready_socks == 0)
+			return -1;
+		i++;
+		if (i >= clientp)
+			i = 0;
+		if (FD_ISSET(cblk[i].sd, ready_socks)) {
+			FD_CLR(cblk[i].sd, ready_socks);
+			no_of_ready_socks--;
+			return (cur_clp = i);
+		}
+	}
 }
 
 /**     新しいクライアントが居るか否かを調べる
         居た場合はcblkに登録する        **/
 static void
-new_client (void)               /* NewClient */
+new_client(void)
 {
-  int sd;
-  int full, i;
-  FILE *f[3];
-  char gomi[1024];
+	int sd = -1;
+	int full, i;
+	FILE *f[3];
+	char gomi[1024];
 #ifdef  HAVE_LIBWRAP
-  int is_internet_socket;
-  struct request_info tcpd_request;
+	int is_internet_socket;
+	struct request_info tcpd_request;
 #endif /* HAVE_LIBWRAP */
-#ifdef  AF_UNIX
-  if ((serverNO == 0) &&
-      (FD_ISSET (accept_blk[UNIX_ACPT].sd, ready_socks)))
-    {
-      FD_CLR (accept_blk[UNIX_ACPT].sd, ready_socks);
-      no_of_ready_socks--;
-      sd = socket_accept_un ();
+
+	log_debug("new client called");
+
+	for (i = 0; i < bindex && !FD_ISSET(accept_blk[i].sd, ready_socks); i++)
+		;
+
+	if (i == bindex)
+		return;
+
+	FD_CLR(accept_blk[i].sd, ready_socks);
+	no_of_ready_socks--;
+	log_debug("new client: FDISSET(%d/%d) true, domain=%d",
+		  i, bindex, accept_blk[i].domain);
+	
+	switch (accept_blk[i].domain) {
+#ifdef AF_UNIX
+	case AF_UNIX:
+		sd = socket_accept(i);
 #ifdef  HAVE_LIBWRAP
-      is_internet_socket = 0;
-#endif
-    }
-  else
+		is_internet_socket = 0;
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
-      is_internet_socket = 1;
-#endif
-    }
-  else
-    {
-      return;
-    }
-  log_debug ("new client: sd = %d", sd);
-  /* reserve 2 fd */
-  for (full = i = 0; i < 2; i++)
-    {
-      if (NULL == (f[i] = fopen ("/dev/null", "r")))
-        {
-          full = 1;
-        }
-    }
-  for (i = 0; i < 2; i++)
-    {
-      if (NULL != f[i])
-        fclose (f[i]);
-    }
-
-  if (full || sd >= nofile || clientp >= max_client)
-    {
-      log_err ("no more client.");
+		is_internet_socket = 1;
+#endif /* HAVE_LIBWRAP */
+		break;
+	default:
+		return;
+	}
+	
+	log_debug("new client: sd = %d (type=%d)",
+		  sd, accept_blk[i].domain);
+	
+	/* reserve 2 fd */
+	for (full = i = 0; i < 2; i++) {
+		if (NULL == (f[i] = fopen ("/dev/null", "r"))) {
+			full = 1;
+		}
+	}
+	
+	for (i = 0; i < 2; i++) {
+		if (NULL != f[i])
+			fclose (f[i]);
+	}
+	
+	if (full || sd >= nofile || clientp >= max_client) {
+		log_err("no more client.");
 #ifdef HAVE_RECV
-      recv (sd, gomi, 1024, 0);
+		recv(sd, gomi, 1024, 0);
 #else
-      read (sd, gomi, 1024);
+		read(sd, gomi, 1024);
 #endif
-      shutdown (sd, 2);
+		shutdown(sd, 2);
 #ifdef HAVE_CLOSESOCKET
-      closesocket (sd);
+		closesocket(sd);
 #else
-      close (sd);
+		close(sd);
 #endif
-      return;
-    }
-
+		return;
+	}
+	
 #ifdef HAVE_LIBWRAP
-  if (is_internet_socket) {
-    request_init (&tcpd_request,RQ_DAEMON, WNN_DAEMON_NAME,
-		  RQ_FILE, sd, NULL);
-    fromhost (&tcpd_request);
-    if (!hosts_access (&tcpd_request))
-      {
-	log_err ("reject client."); /* should be log_info? */
-				    /* should we log IP address / hostname? */
+	if (is_internet_socket) {
+		request_init (&tcpd_request,RQ_DAEMON, WNN_DAEMON_NAME,
+			      RQ_FILE, sd, NULL);
+		fromhost (&tcpd_request);
+		if (!hosts_access (&tcpd_request)) {
+			log_err ("reject client."); /* should be log_info? */
+			/* should we log IP address / hostname? */
 #ifdef HAVE_RECV
-	recv (sd, gomi, 1024, 0);
+			recv(sd, gomi, 1024, 0);
 #else
-	read (sd, gomi, 1024);
+			read(sd, gomi, 1024);
 #endif
-	shutdown (sd, 2);
+			shutdown(sd, 2);
 #ifdef HAVE_CLOSESOCKET
-	closesocket (sd);
+			closesocket(sd);
 #else
-	close (sd);
+			close(sd);
 #endif
-	return;
-      }
-  }
+			return;
+		}
+	}
 #endif /*  HAVE_LIBWRAP */
-
-  cblk[clientp].sd = sd;
-  FD_SET (sd, all_socks);
-  for (i = 0; i < WNN_MAX_ENV_OF_A_CLIENT; i++)
-    {
-      (client[clientp].env)[i] = -1;
-    }
-  clientp++;
+	
+	cblk[clientp].sd = sd;
+	FD_SET(sd, all_socks);
+	for (i = 0; i < WNN_MAX_ENV_OF_A_CLIENT; i++) {
+		(client[clientp].env)[i] = -1;
+	}
+	clientp++;
 }
 
 /**     クライアントをcblkから削除する  **/
@@ -555,746 +505,726 @@ new_client (void)               /* NewCl
 void
 del_client (void)
 {
-  disconnect_all_env_of_client ();
-  FD_CLR (cblk[cur_clp].sd, all_socks);
+	disconnect_all_env_of_client ();
+	FD_CLR(cblk[cur_clp].sd, all_socks);
 #ifdef HAVE_CLOSESOCKET
-  closesocket (cblk[cur_clp].sd);
+	closesocket(cblk[cur_clp].sd);
 #else
-  close (cblk[cur_clp].sd);
+	close(cblk[cur_clp].sd);
 #endif
   /* logging here because c_c (used in log_debug) will be broken after
      following section */
-  log_debug("Delete Client: cur_clp = %d\n", cur_clp);
-  cblk[cur_clp] = cblk[clientp - 1];
-  client[cur_clp] = client[clientp - 1];
-  /* Clear host/user name with zero - needed for logging */
-  client[clientp - 1].user_name[0] = '\0';	/* Should we use bzero()? */
-  client[clientp - 1].host_name[0] = '\0';
-  clientp--;
-}
+	log_debug("Delete Client: cur_clp = %d\n", cur_clp);
+	cblk[cur_clp] = cblk[clientp - 1];
+	client[cur_clp] = client[clientp - 1];
+	/* Clear host/user name with zero - needed for logging */
+
+	/* Should we use bzero()? */
+	client[clientp - 1].user_name[0] = '\0';
 
+	client[clientp - 1].host_name[0] = '\0';
+	clientp--;
+}
 
 /**     サーバをイニシャライズする      **/
 static void
-daemon_init (void)               /* initialize Daemon */
+daemon_init(void)               /* initialize Daemon */
 {
-  /*
-  signal (SIGHUP, SIG_IGN);
-  signal (SIGINT, SIG_IGN);
-  signal (SIGQUIT, SIG_IGN);
-  */
+	/*
+	  signal (SIGHUP, SIG_IGN);
+	  signal (SIGINT, SIG_IGN);
+	  signal (SIGQUIT, SIG_IGN);
+	*/
 
+	if ((cblk = (struct cmblk *)malloc(max_client * sizeof(struct cmblk))) == NULL) {
+		xerror ("daemon_init: ");
+	}
+
+	if ((client = (CLIENT *)malloc(max_client * sizeof (CLIENT))) == NULL) {
+		xerror ("daemon_init: ");
+	}
+
+	SDRAND(time(NULL));
+	clientp = 0;                  /* V3.0 */
+	cur_clp = 0;                  /* V3.0 */
+	socket_disc_init();
 
-  if ((cblk = (COMS_BLOCK *) malloc (max_client * sizeof (COMS_BLOCK))) == NULL)
-    {
-      xerror ("daemon_init: ");
-    }
-  if ((client = (CLIENT *) malloc (max_client * sizeof (CLIENT))) == NULL)
-    {
-      xerror ("daemon_init: ");
-    }
-  SDRAND (time (NULL));
-  clientp = 0;                  /* V3.0 */
-  cur_clp = 0;                  /* V3.0 */
-  socket_disc_init ();
-#ifdef INET6
-  if (listen_proto&(PROTO_ALL|PROTO_INET|PROTO_INET6))
-      socket_init_in ();
-#else
-  if (listen_proto&(PROTO_ALL|PROTO_INET))
-      socket_init_in ();
-#endif
 #ifdef  AF_UNIX
-  if (listen_proto&(PROTO_ALL|PROTO_UN))
-      socket_init_un ();
-#endif /* AF_UNIX */
+	if (listen_proto & PROTO_UN)
+		socket_init_un(&bindex);
+#endif
+	if (listen_proto & (PROTO_INET|PROTO_INET6))
+		socket_init_in(&bindex);
 }
 
 /**     サーバを終わる  **/
-#ifdef  AF_UNIX
+#ifdef AF_UNIX
 static void
-daemon_fin_un (int sock_d_un)
+daemon_fin_un(int sock_d_un)
 {
-  int trueFlag = 1;
-  struct sockaddr_un addr_un;
-  socklen_t addrlen;
+	int trueFlag = 1;
+	struct sockaddr_un addr_un;
+	socklen_t addrlen;
 
-  if (serverNO == 0)
-    {
 #ifndef SOLARIS
 #if defined(FIONBIO)
-      ioctl (sock_d_un, FIONBIO, &trueFlag);
+	ioctl (sock_d_un, FIONBIO, &trueFlag);
 #endif
 #else /* !SOLARIS */
-      fcntl (sock_d_un, F_SETFL, F_UNLCK);
+	fcntl (sock_d_un, F_SETFL, F_UNLCK);
 #endif /* !SOLARIS */
-      for (;;)
-        {
-          addrlen = sizeof (addr_un);
-          if (accept (sock_d_un, (struct sockaddr *) &addr_un, &addrlen) < 0)
-            break;
-          /* EWOULDBLOCK EXPECTED, but we don't check */
+	for (;;) {
+		addrlen = sizeof (addr_un);
+		if (accept(sock_d_un,
+			   (struct sockaddr *)&addr_un,
+			   &addrlen) < 0)
+			break;
+		/* EWOULDBLOCK EXPECTED, but we don't check */
         }
-      shutdown (sock_d_un, 2);
-      close (sock_d_un);
-    }
+	shutdown (sock_d_un, 2);
+	close (sock_d_un);
 }
 #endif /* AF_UNIX */
 
 static void
-daemon_fin_in (int sock_d_in)
+daemon_fin_in(int sock_d_in)
 {
-  int trueFlag = 1;
-  struct sockaddr_in addr_in;
-  socklen_t addrlen;
+	int trueFlag = 1;
+	struct sockaddr_in addr_in;
+	socklen_t addrlen;
 #ifdef USE_SETSOCKOPT
-  int on = ~0;
+	int on = ~0;
 #endif
 
 #ifndef SOLARIS
 #ifdef USE_SETSOCKOPT
-  setsockopt (sock_d_in, SOL_SOCKET, SO_NONBLOCK, &on, sizeof (int));
+	setsockopt(sock_d_in, SOL_SOCKET, SO_NONBLOCK, &on, sizeof(int));
 #else
 #if defined(FIONBIO)
-  ioctl (sock_d_in, FIONBIO, &trueFlag);
+	ioctl(sock_d_in, FIONBIO, &trueFlag);
 #endif
 #endif /* USE_SETSOCKOPT */
 #else /* !SOLARIS */
-  fcntl (sock_d_in, F_SETFL, F_UNLCK);
+	fcntl(sock_d_in, F_SETFL, F_UNLCK);
 #endif /* !SOLARIS */
-  for (;;)
-    {
-      addrlen = sizeof (addr_in);
-      if (accept (sock_d_in, (struct sockaddr *) &addr_in, &addrlen) < 0)
-        break;
-      /* EWOULDBLOCK EXPECTED, but we don't check */
-    }
-  shutdown (sock_d_in, 2);
+	for (;;) {
+		addrlen = sizeof(addr_in);
+		if (accept(sock_d_in,
+			   (struct sockaddr *)&addr_in,
+			   &addrlen) < 0)
+			break;
+		/* EWOULDBLOCK EXPECTED, but we don't check */
+	}
+	shutdown (sock_d_in, 2);
 #ifdef HAVE_CLOSESOCKET
-  closesocket (sock_d_in);
+	closesocket (sock_d_in);
 #else
-  close (sock_d_in);
+	close (sock_d_in);
 #endif
 }
 
 void
 daemon_fin (void)
 {
-  int fd;
-#ifdef  AF_UNIX
-  int sock_d_un = accept_blk[UNIX_ACPT].sd;
-#endif /* AF_UNIX */
-  int sock_d_in = accept_blk[INET_ACPT].sd;
-#ifdef INET6
-  int sock_d_in6 = accept_blk[INET6_ACPT].sd;
-#endif
+	int i;
+	int fd;
 
-  /*
-     accept all pending connection from new clients,
-     avoiding kernel hangup.
-   */
+	for (i = 0; i < bindex; i++) {
+		if (FD_ISSET(accept_blk[i].sd, all_socks)) {
+			switch (accept_blk[i].domain) {
 #ifdef  AF_UNIX
-  daemon_fin_un (sock_d_un);
-#endif
-  daemon_fin_in (sock_d_in);
+			case AF_UNIX:
+				if (listen_proto & PROTO_UN)
+					daemon_fin_un(accept_blk[i].sd);
+				break;
+#endif
+			case AF_INET:
+				if (listen_proto & PROTO_INET)
+					daemon_fin_in(accept_blk[i].sd);
+				break;
 #ifdef INET6
-  daemon_fin_in (sock_d_in6);
-#endif
+			case AF_INET6:
+				if (listen_proto & PROTO_INET6)
+					daemon_fin_in(accept_blk[i].sd);
+				break;
+#endif
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
-          shutdown (fd, 2);
+	for (fd = nofile - 1; fd >= 0; fd--) {
+		if (FD_ISSET(fd, all_socks)) {
+			shutdown (fd, 2);
 #ifdef HAVE_CLOSESOCKET
-          closesocket (fd);
+			closesocket (fd);
 #else
-          close (fd);
+			close (fd);
 #endif
-        }
-    }
+		}
+	}
 }
 
-/*------*/
+static unsigned char snd_buf[S_BUF_SIZ];         /** 送信バッファ **/
+static unsigned char *sp = snd_buf;
+
+static unsigned char rcv_buf[R_BUF_SIZ];         /** 受信バッファ **/
+static unsigned char *rbp = rcv_buf;
+static unsigned char *rp = rcv_buf;
 
-/**     **/
 char *
-gets_cur (char *buffer, size_t buffer_size)
+gets_cur(char *buffer, size_t buffer_size)
 {
-  char *b;
+	char *b;
 
-  if (!buffer || !buffer_size)
-    return NULL;
+	if (!buffer || !buffer_size)
+		return NULL;
 
-  b = buffer;
+	b = buffer;
 
-  while (--buffer_size && (*b = getc_cur ()) != '\0')
-    b++;
+	while (--buffer_size && (*b = getc_cur()) != '\0')
+		b++;
 
-  if (!buffer_size)
-    {
-      *b = '\0';
-      while (getc_cur () != '\0')
-        ;
-    }
+	if (!buffer_size) {
+		*b = '\0';
+		while (getc_cur() != '\0')
+			;
+	}
 
-  return buffer;
+	return buffer;
 }
 
 /**     **/
 w_char *
-getws_cur (w_char *buffer, size_t buffer_size)
+getws_cur(w_char *buffer, size_t buffer_size)
 {
-  w_char *b;
+	w_char *b;
 
-  if (!buffer || !buffer_size)
-    return NULL;
+	if (!buffer || !buffer_size)
+		return NULL;
 
-  b = buffer;
+	b = buffer;
 
-  while (--buffer_size && (*b = get2_cur ()) != 0)
-    b++;
+	while (--buffer_size && (*b = get2_cur ()) != 0)
+		b++;
 
-  if (!buffer_size)
-    {
-      *b = 0;
-      while (getc_cur () != 0)
-        ;
-    }
-
-  return buffer;
+	if (!buffer_size) {
+		*b = 0;
+		while (getc_cur () != 0)
+			;
+	}
+	return buffer;
 }
 
 /**     カレント・クライアントから2バイト取る   **/
 int
 get2_cur (void)
 {
-  int x;
-  x = getc_cur ();
-  return (x << 8) | getc_cur ();
+	int h;
+	h  = getc_cur () << 8;
+	h |= getc_cur ();
+	return h;
 }
 
 /**     カレント・クライアントから4バイト取る   **/
 int
 get4_cur (void)
 {
-  int x1, x2, x3;
-  x1 = getc_cur ();
-  x2 = getc_cur ();
-  x3 = getc_cur ();
-  return (x1 << (8 * 3)) | (x2 << (8 * 2)) | (x3 << (8 * 1)) | getc_cur ();
+	int h;
+	h  = getc_cur() << (8*3);
+	h |= getc_cur() << (8*2);
+	h |= getc_cur() << (8*1);
+	h |= getc_cur() << (8*0);
+	return h;
 }
 
 /**     カレント・クライアントから1バイト取る   **/
 int
-getc_cur (void)
+getc_cur(void)
 {
-  static int rbp;
-  if (rbc <= 0)
-    {
-      rbc = rcv_1_client (cur_clp);
-      rbp = 0;
-    }
-  rbc--;
-  return rcv_buf[rbp++] & 0xFF;
+#if DEBUG_IO
+	fprintf(stderr, "getc_cur: Enter\n");
+#endif
+	if (rp == rbp) {
+		rcv_1_client(cur_clp);
+	}
+#if DEBUG_IO
+	fprintf(stderr, "getc_cur: [%02x]\n", *rbp & 0xff);
+#endif
+	return *(rbp++) & 0xff;
 }
 
 /**     クライアントから1パケット取る   **/
 static int
-rcv_1_client (int clp)		/* clp=クライアント番号 */
+rcv_1_client(int clp)		/* clp=クライアント番号 */
 {
-  int cc = 0;
-  while (cc <= 0)
-    {
-      errno = 0;
+	int n = 0;
+
+	if (rbp == rp) {
+		rbp = rp = &rcv_buf[0];
+	}
+
+	while (rbp == rp) {
+		errno = 0;
 #ifdef HAVE_RECV
-      cc = recv (cblk[clp].sd, rcv_buf, S_BUF_SIZ, 0);
+		n = recv(cblk[clp].sd, rcv_buf, sizeof(rcv_buf), 0);
 #else
-      cc = read (cblk[clp].sd, rcv_buf, S_BUF_SIZ);
+		n = read(cblk[clp].sd, rcv_buf, sizeof(rcv_buf));
 #endif
-      if (cc <= 0)
-        {
-          if (ERRNO_CHECK (errno))
-            {
-              continue;
-            }
-          else if (cc == 0)
-            {                   /* client dead */
-              longjmp (client_dead, 666);
-            }
-          else
-            {                   /* cc == -1 */
-              if (errno != EINTR)
-                longjmp (client_dead, 666);
-              continue;
-            }
-        }
-    }
-#ifdef DEBUG
-  log_debug ("rcv: clp = %d, sd = %d, cc = %d", clp, cblk[clp].sd, cc);
-  dmp (rcv_buf, cc);
+		if (n <= 0) {
+			if (ERRNO_CHECK (errno)) {
+				continue;
+			} else if (n == 0) {
+				/* client dead */
+				longjmp(client_dead, 666);
+			} else  {
+				/* n == -1 */
+				if (errno != EINTR)
+					longjmp (client_dead, 666);
+				continue;
+			}
+		}
+		rp += n;
+		log_debug ("rcv: clp=%d, sd=%d, n=%d\n", clp, cblk[clp].sd, n);
+#if DEBUG_IO
+		dmp(rbp, rp - rbp);
 #endif
-  return cc;
+	}
+
+	return n;
 }
 
 /**     クライアントへ1パケット送る     **/
 static void
-snd_1_client (int clp,	/* clp: クライアント番号 */
-	      int n	/* n : number of bytes to send */ )
+snd_1_client(int clp, int dummy)
 {
-  int cc, x;
-#ifdef  DEBUG
-  log_debug ("snd: clp = %d, sd = %d", clp, cblk[clp].sd);
-  dmp (snd_buf, n);
+	unsigned char *bp = snd_buf;
+	int n;
+	size_t total = sp - bp;
+
+#if DEBUG_IO
+	fprintf(stderr, "snd: clp=%d, sd=%d\n", clp, cblk[clp].sd);
+	dmp(snd_buf, sp - bp);
 #endif
-  for (cc = 0; cc < n;)
-    {
-      errno = 0;
+
+	while (0 < sp - bp && sp <= snd_buf + sizeof(snd_buf)) {
+		errno =0;
 #ifdef HAVE_SEND
-      x = send (cblk[clp].sd, &snd_buf[cc], n - cc, 0);
+		n = send(cblk[clp].sd, bp, sp - bp, 0);
 #else
-      x = write (cblk[clp].sd, &snd_buf[cc], n - cc);
+		n = write(cblk[clp].sd, bp, sp - bp);
 #endif
-      if (x < 0)
-        {
-          if (ERRNO_CHECK (errno) || errno == EINTR)
-            {
-              errno = 0;
-              continue;
-            }
-          else
-            {                   /* client dead */
-              longjmp (client_dead, 666);
-            }
-        }
-      cc += x;
-    }
+		if (n < 0) {
+			if (ERRNO_CHECK (errno) || errno == EINTR) {
+				continue;
+			} else {
+				/* client dead */
+				longjmp (client_dead, 666);
+			}
+		}
+		bp += n;
+	}
+	sp = snd_buf;
 }
 
-/**     **/
 void
-puts_cur (char *p)
+puts_cur(char *p)
 {
-  int c;
-  while (c = *p++)
-    putc_cur (c);
-  putc_cur (0);
+	int c;
+	while(c = *p++)
+		putc_cur(c);
+	putc_cur(0x00);
 }
 
-/**     **/
 void
-puts_n_cur (char *p, int n)
+puts_n_cur(char *p, int n)
 {
-  int c;
-  while ((c = *p++) && --n >= 0)
-    putc_cur (c);
-  putc_cur (0);
+	int c;
+	while ((c = *p++) && --n >= 0)
+		putc_cur(c);
+	putc_cur(0x00);
 }
 
-/**     **/
 void
-putws_cur (w_char *p)
+putws_cur(w_char *p)
 {
-  int c;
-  while (c = *p++)
-    put2_cur (c);
-  put2_cur (0);
+	int c;
+	while (c = *p++)
+		put2_cur(c);
+	put2_cur(0x0000);
 }
 
-/**     **/
 void
-putnws_cur (w_char *p, int n)
+putnws_cur(w_char *p, int n)
 {
-  int c;
-  for (; n > 0; n--)
-    {
-      if ((c = *p++) == 0)
-        break;
-      put2_cur (c);
-    }
-  put2_cur (0);
+	unsigned int c;
+	for (; n > 0; n--) {
+		if ((c = *p++) == 0)
+			break;
+		put2_cur(c);
+	}
+	put2_cur(0x0000);
 }
 
-/**     カレント・クライアントへ2バイト送る     **/
 void
-put2_cur (int c)
+put2_cur(int c)
 {
-  putc_cur (c >> (8 * 1));
-  putc_cur (c);
+	putc_cur(c >> (8 * 1));
+	putc_cur(c);
 }
 
-/**     カレント・クライアントへ4バイト送る     **/
 void
-put4_cur (int c)
+put4_cur(int c)
 {
-  putc_cur (c >> (8 * 3));
-  putc_cur (c >> (8 * 2));
-  putc_cur (c >> (8 * 1));
-  putc_cur (c);
+	putc_cur(c >> (8 * 3));
+	putc_cur(c >> (8 * 2));
+	putc_cur(c >> (8 * 1));
+	putc_cur(c);
 }
 
-/**     カレント・クライアントへ1バイト送る     **/
 void
-putc_cur (int c)
+putc_cur(int c)
 {
-  snd_buf[sbp++] = c;
-  if (sbp >= R_BUF_SIZ)
-    {
-      snd_1_client (cur_clp, R_BUF_SIZ);
-      sbp = 0;
-    }
+#if DEBUG_IO
+	fprintf(stderr, "putc_cur: Enter\n");
+#endif
+	if (snd_buf + sizeof(snd_buf) <= sp)
+		putc_purge();
+
+#if DEBUG_IO
+	fprintf(stderr, "putc_cur: [%02x]\n", c & 0xff);
+#endif
+	*(sp++) = c & 0xff;
 }
 
-/**     カレント・クライアントの送信バッファをフラッシュする    **/
+/* flush send buffer */
 void
-putc_purge (void)
+putc_purge(void)
 {
-  if (sbp != 0)
-    {
-      snd_1_client (cur_clp, sbp);
-      sbp = 0;
-    }
+	if (snd_buf < sp) {
+		snd_1_client(cur_clp, 0);
+	}
 }
 
-/*-----*/
-
-/**     ソケットのイニシャライズ        **/
+/* initialize sockets */
 #ifdef  AF_UNIX
+#if !defined(SUN_LEN)
+# define SUN_LEN(su) (sizeof(*(su)) - sizeof((su)->sun_path) + strlen((su)->sun_path))
+#endif
+
 static void
-socket_init_un (void)
+socket_init_un(int *index)
 {
-  struct sockaddr_un saddr_un;
-  int sock_d_un;
-  if (serverNO == 0)
-    {
-      saddr_un.sun_family = AF_UNIX;
-      unlink (sockname);
-      strcpy (saddr_un.sun_path, sockname);
-      if ((sock_d_un = socket (AF_UNIX, SOCK_STREAM, 0)) == ERROR)
-        {
-          xerror ("could not create unix domain socket");
-        }
-      if (bind (sock_d_un, (struct sockaddr *) &saddr_un, strlen (saddr_un.sun_path) + 2) == ERROR)
-        {
-          shutdown (sock_d_un, 2);
-          xerror ("could not bind unix domain socket");
+	struct sockaddr_un saddr_un;
+	int sock_d_un;
+
+	saddr_un.sun_family = AF_UNIX;
+	strncpy(saddr_un.sun_path, sockname, sizeof(saddr_un.sun_path) - 1);
+	saddr_un.sun_path[sizeof(saddr_un.sun_path) - 1] = '\0';
+
+	unlink(saddr_un.sun_path);
+
+	if ((sock_d_un = socket(saddr_un.sun_family, SOCK_STREAM, 0)) == ERROR)
+		xerror("could not create unix domain socket");
+
+	if (bind(sock_d_un,
+		 (struct sockaddr *)&saddr_un,
+		 SUN_LEN(&saddr_un)) == ERROR) {
+		shutdown (sock_d_un, 2);
+		xerror("could not bind unix domain socket");
         }
-      if (listen (sock_d_un, 5) == ERROR)
-        {
-          shutdown (sock_d_un, 2);
-          xerror ("could not listen unix domain socket");
+
+	if (listen(sock_d_un, 5) == ERROR) {
+		shutdown (sock_d_un, 2);
+		xerror("could not listen unix domain socket");
         }
-      chmod (sockname, 0777);
-      signal (SIGPIPE, SIG_IGN);
-#ifdef DEBUG
-      log_debug ("sock_d_un = %d", sock_d_un);
-#endif
-      accept_blk[UNIX_ACPT].sd = sock_d_un;
-      FD_SET (sock_d_un, all_socks);
-    }
+
+	chmod(sockname, 0777);
+	signal(SIGPIPE, SIG_IGN);
+	log_debug("sock_d_un = %d (bindex=%d)", sock_d_un, *index);
+	accept_blk[(*index)].sd = sock_d_un;
+	accept_blk[(*index)].domain = saddr_un.sun_family;
+	(*index)++;
+	FD_SET (sock_d_un, all_socks);
 }
 #endif /* AF_UNIX */
 
 /*      Inet V3.0 */
 static void
-socket_init_in (void)
+socket_init_in(int *index)
 {
+	int i;
 #ifndef SOLARIS
-  int on = 1;
+	int on = 1;
 #else /* SOLARIS */
-  int on = 0;
+	int on = 0;
 #endif /* SOLARIS */
-  struct servent *sp;
+
+	struct servent *sp;
 #if !defined(SO_DONTLINGER) && defined(SO_LINGER)
-  struct linger linger;
+	struct linger linger;
 #endif
-#ifdef INET6
-  struct addrinfo hints, *res, *res0;
-  int error;
-  char sport[6];
-#else
-  struct sockaddr_in saddr_in;
-#endif
-  int sock_d_in;
-
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
-    }
+	struct addrinfo hints, *res, *res0;
+	struct sockaddr sa;
+	int error;
+	char hbuf[NI_MAXHOST];
+	char sbuf[NI_MAXSERV];
+	int sock_d_in;
+
+	memset(&sa, 0, sizeof(struct sockaddr));
+	if (port < 0) {
+		strncpy(sbuf, SERVERNAME, sizeof(sbuf) - 1);
+		sbuf[sizeof(sbuf) - 1] = '\0';
+		error = getnameinfo(&sa,
+				    sa.sa_len,
+				    NULL,
+				    0,
+				    sbuf,
+				    sizeof(sbuf),
+				    NI_NUMERICSERV);
+		if (error)
+			sprintf(sbuf, "%d", WNN_PORT_IN);
+	} else {
+		sprintf(sbuf, "%d", port);
+	}
 
-  port += serverNO;
+	port += serverNO;
 
-#if DEBUG
-  log_debug ("port=%x", port);
-#endif
-#ifdef INET6
-  memset(&hints, 0, sizeof(hints));
-  if (listen_proto&PROTO_INET && !(listen_proto&PROTO_INET6))
-      hints.ai_family = PF_INET;
-  else if (listen_proto&PROTO_INET6 && !(listen_proto&PROTO_INET))
-      hints.ai_family = PF_INET6;
-  else
-      hints.ai_family = PF_UNSPEC;
-  hints.ai_socktype = SOCK_STREAM;
-  hints.ai_flags = AI_PASSIVE;
-  sprintf(sport, "%d", port);
-  error = getaddrinfo(NULL, sport, &hints, &res0);
-  if (error)
-    {
-      xerror (gai_strerror(error));
-    }
-  for (res = res0; res; res = res->ai_next) {
-    if (res->ai_family == AF_INET || res->ai_family == AF_INET6){
-      if ((sock_d_in = socket (res->ai_family, res->ai_socktype, res->ai_protocol)) == ERROR)
-#else
-  saddr_in.sin_family = AF_INET;
-  saddr_in.sin_port = htons (port);
-  saddr_in.sin_addr.s_addr = htonl (INADDR_ANY);
-  if ((sock_d_in = socket (AF_INET, SOCK_STREAM, 0)) == ERROR)
-#endif
-    {
+	memset(&hints, 0, sizeof(hints));
+	if (listen_proto & PROTO_INET
+	    || listen_proto & PROTO_INET6)
+		hints.ai_family = PF_UNSPEC;
+	hints.ai_socktype = SOCK_STREAM;
+	hints.ai_flags = AI_PASSIVE;
+
+	for (i = 0; i < MAXLISTENADDR && listenaddr[i][0] != '\0'; i++) {
+		log_debug("getaddrinfo: try %s",listenaddr[i]);
+
+		if (error = getaddrinfo(listenaddr[i], sbuf, &hints, &res0))
+			xerror((char *)gai_strerror(error));
+
+		for (res = res0; res; res = res->ai_next) {
+			log_debug("socket: try %s : %s (type=%d)",
+				  listenaddr[i], sbuf, res->ai_family);
+
+			switch (res->ai_family) {
+			case AF_INET:
+				if (!(listen_proto & PROTO_INET)) {
+					log_debug("socket: ignore %s\n", listenaddr[i]);
+					continue;
+				}
+				sock_d_in = socket(res->ai_family,
+						   res->ai_socktype,
+						   res->ai_protocol);
+				if (sock_d_in == -1)
+					xerror("could not create inet socket");
+				break;
 #ifdef INET6
-      if (res->ai_family == AF_INET6)
-        xerror ("could not create inet6 socket");
-      else if (res->ai_family == AF_INET)
+			case AF_INET6:
+				if (!(listen_proto & PROTO_INET6)) {
+					log_debug("socket: ignore %s\n", listenaddr[i]);
+					continue;
+				}
+				sock_d_in = socket(res->ai_family,
+						   res->ai_socktype,
+						   res->ai_protocol);
+				if (sock_d_in == -1)
+					xerror("could not create inet6 socket");
+#ifdef IPV6_V6ONLY
+				setsockopt(sock_d_in, IPPROTO_IPV6, IPV6_V6ONLY, NULL, 0);
 #endif
-      xerror ("could not create inet socket");
-    }
-  setsockopt (sock_d_in, SOL_SOCKET, SO_REUSEADDR, (char *) &on, sizeof (int));
+#endif /* INET6 */
+			default:
+				continue;
+			}
+			setsockopt (sock_d_in, SOL_SOCKET, SO_REUSEADDR, (char *) &on, sizeof (int));
 #ifdef SO_DONTLINGER
-  setsockopt (sock_d_in, SOL_SOCKET, SO_DONTLINGER, (char *) 0, 0);
+			setsockopt (sock_d_in, SOL_SOCKET, SO_DONTLINGER, (char *) 0, 0);
 #else
 # ifdef SO_LINGER
-  linger.l_onoff = 0;
-  linger.l_linger = 0;
-  setsockopt (sock_d_in, SOL_SOCKET, SO_LINGER, (char *) &linger, sizeof linger);
+			linger.l_onoff = 0;
+			linger.l_linger = 0;
+			setsockopt(sock_d_in, SOL_SOCKET, SO_LINGER, (char *) &linger, sizeof linger);
 # endif /* SO_LINGER */
 #endif /* SO_DONTLINGER */
 
-#ifdef INET6
-  if (bind (sock_d_in, res->ai_addr, res->ai_addrlen) == ERROR)
-#else
-  if (bind (sock_d_in, (struct sockaddr *) &saddr_in, sizeof (saddr_in)) == ERROR)
-#endif
-    {
-      shutdown (sock_d_in, 2);
-#ifdef INET6
-      if (res->ai_family == AF_INET6)
-        xerror ("can't bind inet6 socket");
-      else if (res->ai_family == AF_INET)
-#endif
-      xerror ("can't bind inet socket");
-    }
-  if (listen (sock_d_in, 5) == ERROR)
-    {
-      shutdown (sock_d_in, 2);
-#ifdef INET6
-      if (res->ai_family == AF_INET6)
-        xerror ("can't listen inet6 socket");
-      else if (res->ai_family == AF_INET)
-#endif
-      xerror ("can't listen inet socket");
-    }
-#if DEBUG
-  log_debug ("sock_d_in = %d", sock_d_in);
-#endif
-  FD_SET (sock_d_in, all_socks);
-#ifdef INET6
-      if (res->ai_family == AF_INET)
-	accept_blk[INET_ACPT].sd = sock_d_in;
-      else if (res->ai_family == AF_INET6)
-	accept_blk[INET6_ACPT].sd = sock_d_in;
-    }
-  }
-  freeaddrinfo(res0);
-#else
-  accept_blk[INET_ACPT].sd = sock_d_in;
-#endif
+			if (bind(sock_d_in, res->ai_addr, res->ai_addrlen) == ERROR) {
+				shutdown (sock_d_in, 2);
+				xerror("could not bind inet/inet6 socket");
+			}
+
+			if (listen(sock_d_in, 5) == ERROR) {
+				shutdown (sock_d_in, 2);
+				xerror("could not listen inet/inet6 socket");
+			}
+
+			log_debug("sock_d_in = %d (bindex=%d)",
+				  sock_d_in, *index);
+			FD_SET(sock_d_in, all_socks);
+			accept_blk[(*index)].sd = sock_d_in;
+			accept_blk[(*index)].domain = res->ai_family;
+			(*index)++;
+		}
+	}
+	freeaddrinfo(res0);
 }
 
-
 /**     accept new client socket        **/
-#ifdef  AF_UNIX
 static int
-socket_accept_un (void)
+socket_accept(int index)
 {
-  struct sockaddr_un addr;
-  socklen_t addrlen;
-
-  addrlen = sizeof (addr);
-  return accept (accept_blk[UNIX_ACPT].sd, (struct sockaddr *) &addr, &addrlen);
-}
-#endif /* AF_UNIX */
-
-static int
-socket_accept_in (int fd)
-{
-  struct sockaddr_in addr;
-  socklen_t addrlen;
-
-  addrlen = sizeof (addr);
-  return accept (fd, (struct sockaddr *) &addr, &addrlen);
+	return accept(accept_blk[index].sd, NULL, NULL);
 }
 
 static void
-xerror (char *s)
+xerror(char *s)
 {
-  log_err ("%s (%s).", s, strerror(errno));
-  exit (1);
+	log_err ("%s (%s).", s, strerror(errno));
+	exit (1);
 }
 
-#if DEBUG
 static void
-dmp (char *p, int n)
+dmp(char *p, int n)
 {
-  int i, j;
+	int i, j;
 
-  for (i = 0; i < n; i += 16)
-    {
-      for (j = 0; j < 16; j++)
-        {
-          fprintf (stderr, "%02x ", p[i + j] & 0xFF);
-        }
-      fprintf (stderr, "n=%d\n", n);
-    }
+	for (i = 0; i < n; i += 16) {
+		for (j = 0; j < 16; j++) {
+			fprintf (stderr, "%02x ", p[i + j] & 0xFF);
+		}
+		fprintf (stderr, "n=%d\n", n);
+	}
 }
-#endif
 
 static void
-get_options (int argc, char **argv)
+get_options(int argc, char **argv)
 {
-  int c;
-  int digit_optind = 0;
-
-  strcpy (jserverrcfile, LIBDIR);       /* usr/local/lib/wnn */
-  strcat (jserverrcfile, SERVER_INIT_FILE);     /* ja_JP/jserverrc */
+	int c;
+	int digit_optind = 0;
+	int lindex = 0;
 
-  while (1)
-    {
-      int this_option_optind = optind ? optind : 1;
-      int option_index = 0;
-      static struct option long_options[] =
-      {
-	{"baseport",	1, NULL, 'p'},
-	{"inet",	0, NULL, '4'},
-	{"inet6",	0, NULL, '6'},
-	{"jserverrc",	1, NULL, 'f'},
-	{"version",	0, NULL, 'v'},
-	{0, 0, 0, 0}
-      };
-
-      c = getopt_long (argc, argv, OPTIONARGS,
-		       long_options, &option_index);
-      if (c == -1)
-        break;
+	strcpy (jserverrcfile, LIBDIR);       /* usr/local/lib/wnn */
+	strcat (jserverrcfile, SERVER_INIT_FILE);     /* ja_JP/jserverrc */
 
-      switch (c)
+	while (1)
 	{
-	case 'D': /* do not detach, not a daemon */
-	  option_flag &= ~OPT_FORK;
-	  break;
-
-        case 'f': /* --jserverrc FILENAME */
-          strcpy (jserverrcfile, optarg);
-          break;
-
-        case 's':
-	  /* should nuke noisy someday */
-          noisy = 1; option_flag |= OPT_VERBOSE;
-          if (strcmp ("-", optarg) != 0)
-            {
-	      /** maybe FILE wnnerr = stderr; or wnnerr = open(optarg...) is better? or freopen is normal method? */
-	      /** take a look at daemon(3) */
-              if (freopen (optarg, "a", stderr) == NULL)
-                {
-		  /** fprintf to stderr? */
-                  printf ("Error in opening scriptfile %s.\n", optarg);
-                  exit (1);
-                }
-            }
-          log_debug ("script started");
-          break;
-
-        case 'h':
-	  /* var hinsi_file_name polluted */
-          hinsi_file_name = optarg; 
-          break;
-
-        case 'N':
-          serverNO = atoi (optarg);
-	  /* error handling needed */
-          break;
-
-        case 'p':
-          port = atoi (optarg);
-	  /* error handling needed */
-          break;
-
-        case 'v':
-          print_version();
-          usage();
-	  break;
-
-        case 'u':
-	  listen_proto &= ~PROTO_ALL;
-	  listen_proto |= PROTO_UN;
-	  break;
-
-        case '4':
-	  listen_proto &= ~PROTO_ALL;
-	  listen_proto |= PROTO_INET;
-	  break;
+		int this_option_optind = optind ? optind : 1;
+		int option_index = 0;
+		static struct option long_options[] =
+			{
+				{"baseport",	1, NULL, 'p'},
+				{"inet",	0, NULL, '4'},
+				{"inet6",	0, NULL, '6'},
+				{"jserverrc",	1, NULL, 'f'},
+				{"listenaddr",	1, NULL, 'a'},
+				{"unix",	0, NULL, 'u'},
+				{"version",	0, NULL, 'v'},
+				{0, 0, 0, 0}
+			};
+
+		c = getopt_long (argc, argv, OPTIONARGS,
+				 long_options, &option_index);
+		if (c == -1)
+			break;
+
+		switch (c)
+		{
+		case 'D': /* do not detach, not a daemon */
+			option_flag &= ~OPT_FORK;
+			break;
+
+		case 'f': /* --jserverrc FILENAME */
+			strncpy(jserverrcfile, optarg, sizeof(jserverrcfile) - 1);
+			jserverrcfile[sizeof(jserverrcfile) - 1] = '\0';
+			break;
+
+		case 'a': /* --listenaddr ADDR */
+			strncpy(listenaddr[lindex], optarg, NI_MAXHOST - 1);
+			listenaddr[lindex][NI_MAXHOST - 1] = '\0';
+			lindex++;
+			break;
+
+		case 's':
+			/* should nuke noisy someday */
+			noisy = 1; option_flag |= OPT_VERBOSE;
+			if (strcmp ("-", optarg) != 0)
+			{
+				/** maybe FILE wnnerr = stderr; or wnnerr = open(optarg...) is better? or freopen is normal method? */
+				/** take a look at daemon(3) */
+				if (freopen (optarg, "a", stderr) == NULL)
+				{
+					/** fprintf to stderr? */
+					printf ("Error in opening scriptfile %s.\n", optarg);
+					exit (1);
+				}
+			}
+			log_debug ("script started");
+			break;
+
+		case 'h':
+			/* var hinsi_file_name polluted */
+			hinsi_file_name = optarg;
+			break;
+
+		case 'N':
+			serverNO = atoi (optarg);
+			/* error handling needed */
+			break;
+
+		case 'p':
+			port = atoi (optarg);
+			/* error handling needed */
+			break;
+
+		case 'v':
+			print_version();
+			usage();
+			break;
+
+		case 'u':
+			listen_proto |= PROTO_UN;
+			break;
+
+		case '4':
+			listen_proto |= PROTO_INET;
+			break;
 
 #ifdef INET6
-        case '6':
-	  listen_proto &= ~PROTO_ALL;
-	  listen_proto |= PROTO_INET6;
-          break;
+		case '6':
+			listen_proto |= PROTO_INET6;
+			break;
 #endif /* INET6 */
-
-        default:
-          print_version();
-	  usage();
-	  break;
+		default:
+			print_version();
+			usage();
+			break;
+		}
+	}
+	if (!listen_proto) {
+		listen_proto = PROTO_ALL;
 	}
-    }
 }
 
 
-/*
-*/
 void
 js_who (void)
 {
-  int i, j;
+	int i, j;
 
-  put4_cur (clientp);
-  for (i = 0; i < clientp; i++)
-    {
-      put4_cur (cblk[i].sd);
-      puts_cur (client[i].user_name);
-      puts_cur (client[i].host_name);
-      for (j = 0; j < WNN_MAX_ENV_OF_A_CLIENT; j++)
-        {
-          put4_cur ((client[i].env)[j]);
-        }
+	put4_cur (clientp);
+	for (i = 0; i < clientp; i++)
+	{
+		put4_cur (cblk[i].sd);
+		puts_cur (client[i].user_name);
+		puts_cur (client[i].host_name);
+		for (j = 0; j < WNN_MAX_ENV_OF_A_CLIENT; j++)
+		{
+			put4_cur ((client[i].env)[j]);
+		}
 
-    }
-  putc_purge ();
+	}
+	putc_purge();
 }
 
 void
@@ -1302,25 +1232,25 @@ js_kill (void)
 {
   if (clientp == 1)
     {
-      put4_cur (0);
-      putc_purge ();
+	    put4_cur(0x00000000);
+      putc_purge();
       terminate_hand ();
     }
   else
     {
       put4_cur (clientp - 1);
-      putc_purge ();
+      putc_purge();
     }
 }
 
 void
 usage (void)
 {
-  fprintf(stderr, 
+  fprintf(stderr,
 #ifdef INET6
-	  "usage: %s [-Du46][-f <init_file> -s <log_file(\"-\" for stderr)> -h <pos_file> -N <serverNO> -p <port_base>]\n",
+	  "usage: %s [-Du46][-f <init_file> -a <listenaddr> -s <log_file(\"-\" for stderr)> -h <pos_file> -N <serverNO> -p <port_base>]\n",
 #else
-	  "usage: %s [-Du4][-f <init_file> -s <log_file(\"-\" for stderr)> -h <pos_file> -N <serverNO> -p <port_base>]\n",
+	  "usage: %s [-Du4][-f <init_file> -a <listenaddr> -s <log_file(\"-\" for stderr)> -h <pos_file> -N <serverNO> -p <port_base>]\n",
 #endif
 	  cmd_name);
   fprintf(stderr,
