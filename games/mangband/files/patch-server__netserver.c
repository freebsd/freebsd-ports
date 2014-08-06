--- ./server/netserver.c.orig	2014-08-05 15:15:31.916658572 +0200
+++ ./server/netserver.c	2014-08-05 15:15:32.006682679 +0200
@@ -97,7 +97,7 @@
 			(*drain_receive[256])(int ind);
 int			login_in_progress;
 static int		num_logins, num_logouts;
-static long		Id;
+long			Id;
 int			NumPlayers;
 
 int		MetaSocket = -1;
