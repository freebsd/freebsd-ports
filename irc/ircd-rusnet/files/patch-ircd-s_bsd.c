--- ircd/s_bsd.c.orig	2007-11-14 03:08:12.000000000 +0600
+++ ircd/s_bsd.c	2007-11-14 03:08:19.000000000 +0600
@@ -1540,7 +1540,7 @@
 		    {
 			blptr= *blscn;
 			*blscn=blptr->next;
-			MyFree((char *)blptr);
+			MyFree(blptr);
 		    }
 		else
 			blscn = &(*blscn)->next;
