--- src/ip-lib.c.orig	2025-02-19 19:25:06 UTC
+++ src/ip-lib.c
@@ -52,7 +52,7 @@ int openip(char *host, unsigned int port, char *srcip,
 {
 	int	socketd;
 	struct sockaddr_in server;
-	struct hostent *hostp, *gethostbyname();
+	struct hostent *hostp;
 
 	socketd = socket(AF_INET, SOCK_STREAM, 0);
 	if (socketd < 0)
