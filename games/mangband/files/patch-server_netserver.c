--- server/netserver.c.orig	2016-05-31 18:04:59 UTC
+++ server/netserver.c
@@ -97,7 +97,7 @@ static int		(*playing_receive[256])(int 
 			(*drain_receive[256])(int ind);
 int			login_in_progress;
 static int		num_logins, num_logouts;
-static long		Id;
+long			Id;
 int			NumPlayers;
 
 int		MetaSocket = -1;
