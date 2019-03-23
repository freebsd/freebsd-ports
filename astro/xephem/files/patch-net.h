--- net.h.orig	2005-03-20 11:04:50 UTC
+++ net.h
@@ -20,6 +20,13 @@
 #include <sys/select.h>
 #endif
 
+#include <openssl/ssl.h>
+
+typedef struct {
+	int fd;		//file desciptor for the underlying connection socket
+	SSL *ssl;	//ssl connection for use with SSL_read( )and SSL_write()
+} XE_SSL_FD;
+
 /* support functions */
 
 extern int httpGET (char *host, char *GETcmd, char msg[]);
@@ -29,8 +36,11 @@ extern int readbytes (int fd, unsigned char buf[], int
 extern int recvline (int fd, char buf[], int max);
 extern int recvlineb (int sock, char *buf, int size);
 extern int sendbytes (int fd, unsigned char buf[], int n);
-
-
+extern int httpsGET (char *host, char *GETcmd, char msg[], XE_SSL_FD *ssl_fd);
+extern int ssl_recvbytes (XE_SSL_FD *ssl_fd, unsigned char buf[], int n);
+extern int ssl_readbytes (XE_SSL_FD *ssl_fd, unsigned char buf[], int n);
+extern int ssl_recvline (XE_SSL_FD *ssl_fd, char buf[], int max);
+extern int ssl_recvlineb (XE_SSL_FD *ssl_fd, char *buf, int size);
 
 /* For RCS Only -- Do Not Edit
  * @(#) $RCSfile: net.h,v $ $Date: 2003/03/17 07:26:21 $ $Revision: 1.3 $ $Name:  $
