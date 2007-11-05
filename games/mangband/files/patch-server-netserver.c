--- server/netserver.c.orig	2001-01-02 04:02:10.000000000 +0000
+++ server/netserver.c	2007-11-01 04:27:06.000000000 +0000
@@ -98,7 +98,7 @@
 			(*drain_receive[256])(int ind);
 int			login_in_progress;
 static int		num_logins, num_logouts;
-static long		Id;
+long			Id;
 int			NumPlayers;
 
 int		MetaSocket = -1;
