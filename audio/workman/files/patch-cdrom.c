--- cdrom.c.orig	1997-06-15 10:05:03.000000000 +0200
+++ cdrom.c	2013-10-16 13:14:49.440566031 +0200
@@ -531,7 +531,7 @@
 	int	top = 0, bottom, current, interval, ret = 0, i;
 
 	if (cur_cdmode == EJECTED || cd == NULL)
-		return;
+		return (0);
 
 	for (i = 0; i < cur_ntracks; i++)
 		if (cd->trk[i].track == track)
