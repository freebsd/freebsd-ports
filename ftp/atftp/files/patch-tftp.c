--- tftp.c.orig	2010-10-05 09:35:38.000000000 +0800
+++ tftp.c	2010-10-05 09:42:03.000000000 +0800
@@ -354,7 +354,7 @@
 void make_arg(char *string, int *argc, char ***argv)
 {
      static char *tmp = NULL;
-     int argz_len;
+     size_t argz_len;
 
      /* split the string to an argz vector */
      if (argz_create_sep(string, ' ', &tmp, &argz_len) != 0)
@@ -608,9 +608,16 @@
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
@@ -621,7 +628,7 @@
      fsync(data.sockfd);
      close(data.sockfd);
 
-     return OK;
+     return tftp_result;
 }
 
 /*
@@ -712,9 +719,16 @@
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
@@ -731,7 +745,7 @@
      fsync(data.sockfd);
      close(data.sockfd);
 
-     return OK;
+     return tftp_result;
 }
 
 #ifdef HAVE_MTFTP
