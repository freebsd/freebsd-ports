Index: helper/egg-helper.c
diff -u -p helper/egg-helper.c.orig helper/egg-helper.c
--- helper/egg-helper.c.orig	Thu Feb 24 00:16:28 2005
+++ helper/egg-helper.c	Thu Feb 24 00:24:12 2005
@@ -25,7 +25,7 @@
 /*
  * connect unix domain cannaserver
  */
-int connect_canna_server(static char *sock_path)
+int connect_server(char *sock_path)
 {
   int sockfd;
   struct sockaddr_un sun;
@@ -88,7 +88,7 @@ int main(int argc, char *argv[])
 {
   int server;
   
-  server = connect_server();	/* connect IM server via unix domain socket */
+  server = connect_server(CANNA_PATH);	/* connect IM server via unix domain socket */
 
   /* transport request & response, until stdin or cannaserver is eof */
   while (1)
