--- ircd/channel.c.orig	2007-11-14 03:02:17.000000000 +0600
+++ ircd/channel.c	2007-11-14 03:02:27.000000000 +0600
@@ -2111,7 +2111,7 @@
 		if (*chptr->chname == '!' && close_chid(chptr->chname+1))
 			cache_chid(chptr);
 		else
-			MyFree((char *)chptr);
+			MyFree(chptr);
 	    }
 }
 
