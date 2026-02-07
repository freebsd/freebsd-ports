--- src/ftp.c.orig	2004-07-30 12:52:12 UTC
+++ src/ftp.c
@@ -115,7 +115,7 @@ ftpcmd_t cmdtab[] = {
 
 unsigned get_interface_info(int pfd, char *ip, int max)
 {
-	int	size;
+	socklen_t	size;
 	unsigned int port;
 	struct sockaddr_in saddr;
 
@@ -133,7 +133,7 @@ unsigned get_interface_info(int pfd, char *ip, int max
 
 int get_client_info(ftp_t *x, int pfd)
 {
-	int	size;
+	socklen_t	size;
 	struct sockaddr_in saddr;
 	struct in_addr *addr;
 	struct hostent *hostp = NULL;
@@ -274,7 +274,8 @@ int getc_fd(ftp_t *x, int fd)
 				}
 			else if (FD_ISSET(x->ch.active, &available)) {
 				if (x->ch.state == PORT_LISTEN) {
-					int	sock, adrlen;
+					int	sock;
+					socklen_t adrlen;
 					struct sockaddr_in adr;
 
 					earlyreported = 0;
@@ -1823,7 +1824,7 @@ int proxy_request(config_t *config)
 				syslog(LOG_NOTICE, "%s %s: %ld bytes", x->ch.command, x->ch.filename, x->ch.bytes);
 
 				if (x->xlfp != NULL) {
-					unsigned long now;
+					time_t now;
 					char	date[80];
 
 					/*
