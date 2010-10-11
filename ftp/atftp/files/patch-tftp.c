--- tftp.c.orig	2010-10-11 11:19:25.000000000 +0800
+++ tftp.c	2010-10-11 11:19:12.000000000 +0800
@@ -354,7 +354,7 @@
 void make_arg(char *string, int *argc, char ***argv)
 {
      static char *tmp = NULL;
-     int argz_len;
+     size_t argz_len;
 
      /* split the string to an argz vector */
      if (argz_create_sep(string, ' ', &tmp, &argz_len) != 0)
@@ -408,8 +408,7 @@
  */
 int set_peer(int argc, char **argv)
 {
-     struct hostent *host;      /* for host name lookup */
-     struct servent *sp;        /* server entry for tftp service */
+     int port = -1;
 
      /* sanity check */
      if ((argc < 2) || (argc > 3))
@@ -418,13 +417,34 @@
           return ERR;
      }
 
-     /* get the server entry */
-     sp = getservbyname("tftp", "udp");
-     if (sp == 0) {
-          fprintf(stderr, "tftp: udp/tftp, unknown service.\n");
-          return ERR;
+     /* get the server port */ 
+     if (argc == 3)
+     {
+	  port = htons(atoi(argv[2]));
+	  if (port < 0)
+	  {
+	       fprintf(stderr, "%s: bad port number.\n", argv[2]);
+	       data.connected = 0;
+	       return ERR;
+          }
+	  data.sa_peer.sin_port = port;
+     }
+     else
+     {
+	  /* get the server entry */ 
+	  struct servent *sp;
+	  sp = getservbyname("tftp", "udp");
+          if (sp == 0) {
+	       fprintf(stderr, "tftp: udp/tftp, unknown service.\n");
+	       return ERR;
+          } 
+	  else
+	  {
+	       port = sp->s_port;
+          }
      }
 
+     struct hostent *host;	/* for host name lookup */ 
      /* look up the host */
      host = gethostbyname(argv[1]);
      /* if valid, update s_inn structure */
@@ -437,7 +457,7 @@
           Strncpy(data.hostname, host->h_name,
                   sizeof(data.hostname));
           data.hostname[sizeof(data.hostname)-1] = 0;
-          data.sa_peer.sin_port = sp->s_port;
+          data.sa_peer.sin_port = port;
      } 
      else
      {
@@ -445,20 +465,8 @@
           data.connected = 0;
           return ERR;
      }
-     /* get the server port */
-     if (argc == 3)
-     {
-          sp->s_port = htons(atoi(argv[2]));
-          if (sp->s_port < 0)
-          {
-               fprintf(stderr, "%s: bad port number.\n", argv[2]);
-               data.connected = 0;
-               return ERR;
-          }
-          data.sa_peer.sin_port = sp->s_port;
-     }
      /* copy port number to data structure */
-     data.port = ntohs(sp->s_port);
+     data.port = ntohs(port);
 
      data.connected = 1;
      return OK;
@@ -608,9 +616,16 @@
           exit(ERR);
      }
      memset(&data.sa_local, 0, sizeof(data.sa_local));
-     bind(data.sockfd, (struct sockaddr *)&data.sa_local,
-          sizeof(data.sa_local));
-     getsockname(data.sockfd, (struct sockaddr *)&data.sa_local, &len);
+     if (bind(data.sockfd, (struct sockaddr *)&data.sa_local,
+          sizeof(data.sa_local)) < 0) {
+          perror("bind");
+	  exit(ERR);
+     }
+     if (getsockname(data.sockfd, (struct sockaddr *)&data.sa_local, &len) < 0)
+     {
+	  perror("getsockname");
+	  exit(ERR);
+     }
 
      /* do the transfer */
      gettimeofday(&data.start_time, NULL);
@@ -621,7 +636,7 @@
      fsync(data.sockfd);
      close(data.sockfd);
 
-     return OK;
+     return tftp_result;
 }
 
 /*
@@ -712,9 +727,16 @@
           exit(ERR);
      }
      memset(&data.sa_local, 0, sizeof(data.sa_local));
-     bind(data.sockfd, (struct sockaddr *)&data.sa_local,
-          sizeof(data.sa_local));
-     getsockname(data.sockfd, (struct sockaddr *)&data.sa_local, &len);
+     if (bind(data.sockfd, (struct sockaddr *)&data.sa_local,
+          sizeof(data.sa_local)) < 0) {
+          perror("bind");
+	  exit(ERR);
+     }
+     if (getsockname(data.sockfd, (struct sockaddr *)&data.sa_local, &len) < 0)
+     {
+	  perror("getsockname");
+	  exit(ERR);
+     }
 
      /* do the transfer */
      gettimeofday(&data.start_time, NULL);
@@ -731,7 +753,7 @@
      fsync(data.sockfd);
      close(data.sockfd);
 
-     return OK;
+     return tftp_result;
 }
 
 #ifdef HAVE_MTFTP
