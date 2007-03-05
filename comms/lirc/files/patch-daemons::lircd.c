--- daemons/lircd.c.orig	Sun Jul 10 18:04:12 2005
+++ daemons/lircd.c	Fri Nov 24 14:21:10 2006
@@ -755,9 +755,12 @@
 	strcpy(serv_addr.sun_path,lircdfile);
 	if(bind(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr))==-1)
 	{
-		fprintf(stderr,"%s: could not assign address to socket\n",
-			progname);
-		perror(progname);
+		fprintf(stderr,
+                        "%s: could not assign address to socket %s: %s (%d)\n",
+			progname,
+                        lircdfile,
+                        strerror (errno),
+                        errno );
 		goto start_server_failed1;
 	}
 	
