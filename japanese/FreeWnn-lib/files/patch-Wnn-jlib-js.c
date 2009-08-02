Index: Wnn/jlib/js.c
===================================================================
RCS file: /home/cvs/private/hrs/freewnn/Wnn/jlib/js.c,v
retrieving revision 1.1.1.1
retrieving revision 1.2
diff -d -u -I\$FreeBSD$ -w -r1.1.1.1 -r1.2
--- Wnn/jlib/js.c	20 Dec 2008 07:13:30 -0000	1.1.1.1
+++ Wnn/jlib/js.c	2 Jan 2009 21:55:55 -0000	1.2
@@ -132,9 +132,7 @@
 static int writen ();
 static char *get_unixdomain_of_serv_defs (), *get_service_of_serv_defs ();
 static int get_port_num_of_serv_defs ();
-#if DEBUG
 void xerror ();
-#endif
 
 /*********      V4      *****************/
 /***
@@ -248,145 +246,107 @@
      register int timeout;
 {
   int sd;
-#ifdef INET6
+
   struct addrinfo hints, *res, *res0;
+	struct sockaddr sa;
+	char sbuf[NI_MAXSERV];
+
   int error;
-  char sport[6];
-#else
-  struct sockaddr_in saddr_in;                  /** ソケット **/
-  register struct hostent *hp;
-#endif
+
   struct servent *sp = NULL;
   int serverNO, port_num;
   int ret;
-  char pserver[64];
-  char sserver[64];
+	char pserver[NI_MAXHOST];
+	char sserver[NI_MAXHOST];
   char *serv_name = NULL;
 
   serverNO = _get_server_name (server, pserver);
 
   /* find service name from table by lang */
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
+	if (lang && *lang) {
+		if ((serv_name = get_service_of_serv_defs (lang)) == NULL) {
+			strncpy (sserver, SERVERNAME, sizeof(sserver) - 1);
+			sserver[sizeof(sserver) - 1] = '\0';
+		} else {
+			strncpy (sserver, serv_name, sizeof(sserver) - 1);
+			sserver[sizeof(sserver) - 1] = '\0';
     }
-/*
-    if ((sp = getservbyname(serv_name,"tcp")) != NULL) {
-*/
-  if ((sp = getservbyname (sserver, "tcp")) != NULL)
-    {
-      serverNO += ntohs (sp->s_port);
+	} else {
+		strncpy (sserver, SERVERNAME, sizeof(sserver) - 1);
+		sserver[sizeof(sserver) - 1] = '\0';
     }
-  else
-    {
+
+	memset(&sa, 0, sizeof(struct sockaddr));
+	error = getnameinfo(&sa, sa.sa_len, NULL, 0, sbuf, sizeof(sbuf), NI_NUMERICSERV);
+	if (!error) {
+		serverNO += atoi(sbuf);
+	} else {
       if ((port_num = get_port_num_of_serv_defs (lang)) == -1)
-        {
           serverNO += WNN_PORT_IN;
-        }
       else
-        {
           serverNO += port_num;
         }
-    }
-#ifdef INET6
+
   memset(&hints, 0, sizeof(hints));
   hints.ai_family = PF_UNSPEC;
   hints.ai_socktype = SOCK_STREAM;
-  sprintf(sport, "%d", serverNO);
-  error = getaddrinfo(pserver, sport, &hints, &res0);
-  if (error)
-    {
-#if DEBUG
+	sprintf(sbuf, "%d", serverNO);
+
+	error = getaddrinfo(pserver, sbuf, &hints, &res0);
+	if (error) {
       xerror (gai_strerror(error));
-#endif
       return -1;
     }
+
   for (res = res0; res ; res = res->ai_next) {
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
-#if DEBUG
-      xerror ("jslib:Can't create inet socket.\n");
-#endif
-      return -1;
-    }
+		switch (res->ai_family) {
+		case AF_INET:
+#ifdef INET6
+		case AF_INET6:
 #endif
-
-  if (timeout != 0 && timeout > 0)
-    {
+			if ((sd = socket(res->ai_family, res->ai_socktype, res->ai_protocol)) != ERROR){
+				if (timeout != 0 && timeout > 0) {
       signal (SIGALRM, connect_timeout);
       alarm (timeout);
     }
-#ifdef INET6
+
   ret = connect (sd, res->ai_addr, res->ai_addrlen);
-#else
-  ret = connect (sd, (struct sockaddr *) &saddr_in, sizeof (saddr_in));
-#endif
-  if (timeout != 0 && timeout > 0)
-    {
+
+				if (timeout != 0 && timeout > 0) {
       alarm (0);
       signal (SIGALRM, SIG_IGN);
     }
-  if (ret == ERROR)
-    {
-#if DEBUG
-#ifdef INET6
+
+				if (ret == ERROR) {
       if (res->ai_family == AF_INET)
 	xerror ("jslib:Can't connect inet socket.\n");
+#ifdef INET6
       else if (res->ai_family == AF_INET6)
 	xerror ("jslib:Can't connect inet6 socket.\n");
-#else
-      xerror ("jslib:Can't connect inet socket.\n");
-#endif
 #endif
 #ifdef HAVE_CLOSESOCKET
       closesocket (sd);
 #else
       close (sd);
 #endif
-#ifdef INET6
-	  sd = ERROR;
-	} else
-	  break;
+					freeaddrinfo(res0);
+					return(-1);
+				}
       } else {
-#if DEBUG
       if (res->ai_family == AF_INET)
 	xerror ("jslib:Can't create inet socket.\n");
+#ifdef INET6
       else if (res->ai_family == AF_INET6)
 	xerror ("jslib:Can't create inet6 socket.\n");
 #endif
       }
+			break;
+		default:
+			break;
     }
   }
+
   freeaddrinfo(res0);
-  if (sd == ERROR) {
-#endif
-      return -1;
-    }
   return sd;
 }
 
@@ -408,7 +368,7 @@
   if (server[0] == '[') {
     p = strchr(server++, ']');
     if (p) {
-      len = p-server<64-1?p-server:64-1;
+      len = p-server < NI_MAXHOST - 1 ? p-server : NI_MAXHOST - 1;
       strncpy(pserver, server, len);
       pserver[len] = '\0';
     } else
@@ -416,9 +376,9 @@
   } else {
 #endif
   /* Workaround for pserver buffer overrun : Nov 11,1999 by T.Aono */
-  /* assumes pserver[64]. variable length string is not supported. */
-  strncpy(pserver, server, 64-1);
-  pserver[64-1] = '\0';
+  /* assumes pserver[NI_MAXHOST]. variable length string is not supported. */
+  strncpy(pserver, server, NI_MAXHOST - 1);
+  pserver[NI_MAXHOST - 1] = '\0';
   p = pserver;
 #ifdef INET6
   }
@@ -687,7 +647,6 @@
 
 
 /*      Debug Subroutines       */
-#if DEBUG
 void
 xerror (s)
      char *s;
@@ -716,8 +675,6 @@
     }
 }
 
-#endif
-
 /*      get login name form /etc/passwd file    */
 static char *
 getlogname ()
