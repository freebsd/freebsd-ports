--- src/host.c.orig	Thu Aug  9 10:11:56 2001
+++ src/host.c	Thu Aug  9 10:12:27 2001
@@ -106,7 +106,7 @@
 
     hp = gethostbyname2(name, af);
     if (!hp) {
-	if (inet_pton(af, name, addr) != -1) {
+	if (inet_pton(af, name, addr) == 1) {
 	    switch (af) {
 	    case AF_INET:
 		socksize = sizeof (struct sockaddr_in);
