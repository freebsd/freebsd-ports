--- clients/earthtrack/earthtrack.c.orig	2023-06-10 19:16:02 UTC
+++ clients/earthtrack/earthtrack.c
@@ -53,13 +53,6 @@ FILE	*markerfd=NULL, *greatarcfd=NULL;
 	HALFPI=1.570796326794896, deg2rad=1.74532925199e-02;
 FILE	*markerfd=NULL, *greatarcfd=NULL;
 
-void handler(void)
-{
-	/* This is a function that is called when the response function
-	   times out.  This is in case the server fails to respond. */
-
-	signal(SIGALRM,handler);
-}
 
 int connectsock(char *host, char *service, char *protocol)
 {
