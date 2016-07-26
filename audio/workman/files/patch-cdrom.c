--- cdrom.c.orig	1997-06-15 08:05:03 UTC
+++ cdrom.c
@@ -531,7 +531,7 @@ find_trkind(track, index, start)
 	int	top = 0, bottom, current, interval, ret = 0, i;
 
 	if (cur_cdmode == EJECTED || cd == NULL)
-		return;
+		return (0);
 
 	for (i = 0; i < cur_ntracks; i++)
 		if (cd->trk[i].track == track)
