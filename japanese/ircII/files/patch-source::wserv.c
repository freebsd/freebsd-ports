--- source/wserv.c.orig	Sat Jul  2 11:32:13 1994
+++ source/wserv.c	Tue Oct 15 07:52:08 2002
@@ -80,7 +80,7 @@
 	strcpy(addr->sun_path, argv[1]);
 	s = socket(AF_UNIX, SOCK_STREAM, 0);
 	if (0 > connect(s, (struct sockaddr *) addr, sizeof(addr->sun_family) +
-						strlen(addr->sun_path)))
+						strlen(addr->sun_path) + 1))
 		exit(0);
 
 	/*
@@ -88,10 +88,10 @@
 	 * can grab the size of the tty, and have it changed.
 	 */
 
-	tmp = ttyname(0);
+	if ((tmp = ttyname(0)) == NULL)
+		perror("ttyname(0)");
 	write(s, tmp, strlen(tmp));
 	write(s, "\n", 1);
-	perror(tmp);
 
 	term_init();
 
