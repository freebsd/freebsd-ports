--- source/dcc.c.orig	Mon May  6 03:36:21 2002
+++ source/dcc.c	Mon May  6 03:36:44 2002
@@ -1366,7 +1366,7 @@
 		/*
 		 * Figure out something sane for the xfer speed.
 		 */
-		if (Client->bytes_sent)
+		if (act_sent)
 		{
 			strlcpy(speed, calc_speed(act_sent, 
 				Client->starttime.tv_sec, time(NULL)), 9);
