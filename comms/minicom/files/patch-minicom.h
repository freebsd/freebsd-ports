--- src/minicom.h.orig	2020-08-20 23:32:58.277841000 +0700
+++ src/minicom.h	2020-08-20 23:49:18.458829000 +0700
@@ -110,13 +110,13 @@
 
 EXTERN char *dial_name;	    /* System we're conneced to */
 EXTERN char *dial_number;   /* Number we've dialed. */
-EXTERN char *dial_user;     /* Our username there */
-EXTERN char *dial_pass;     /* Our password */
+extern char *dial_user;     /* Our username there */
+extern char *dial_pass;     /* Our password */
 
 #ifdef USE_SOCKET
-EXTERN int portfd_is_socket;	/* File descriptor is a unix socket */
-EXTERN int portfd_is_connected;	/* 1 if the socket is connected */
-EXTERN struct sockaddr_un portfd_sock_addr;	/* the unix socket address */
+extern int portfd_is_socket;	/* File descriptor is a unix socket */
+extern int portfd_is_connected;	/* 1 if the socket is connected */
+extern struct sockaddr_un portfd_sock_addr;	/* the unix socket address */
 #define portfd_connected ((portfd_is_socket && !portfd_is_connected) \
                            ? -1 : portfd)
 #else
@@ -142,7 +142,7 @@
 EXTERN int st_attr;	/* Status Bar attributes. */
 
 /* jl 04.09.97 conversion tables */
-EXTERN unsigned char vt_outmap[256], vt_inmap[256];
+extern unsigned char vt_outmap[256], vt_inmap[256];
 
 /* MARK updated 02/17/95 - history buffer */
 EXTERN int num_hist_lines;  /* History buffer size */
