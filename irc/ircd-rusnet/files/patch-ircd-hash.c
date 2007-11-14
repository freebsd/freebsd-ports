--- ircd/hash.c.orig	2007-11-14 03:03:11.000000000 +0600
+++ ircd/hash.c	2007-11-14 03:04:18.000000000 +0600
@@ -139,7 +139,7 @@
 {
 	if (!collnum)
 	{
-		MyFree((char *)collmap);
+		MyFree(collmap);
 		collmap = NULL;
 		collsize = 0;
 		Debug((DEBUG_DEBUG, "Collision map is empty"));
@@ -526,7 +526,7 @@
 		channelTable = table;
 		for (chptr = channel; chptr; chptr = chptr->nextch)
 			(void)add_to_channel_hash_table(chptr->chname, chptr);
-		MyFree((void *)otab);
+		MyFree(otab);
 	    }
 	else if (otab == clientTable)
 	    {
@@ -551,7 +551,7 @@
 					cptr);
 			    }
 		    }
-		MyFree((void *)otab);
+		MyFree(otab);
 	    }
 	else if (otab == serverTable)
 	    {
@@ -563,7 +563,7 @@
 		serverTable = table;
 		for (sptr = svrtop; sptr; sptr = sptr->nexts)
 			(void)add_to_server_hash_table(sptr, sptr->bcptr);
-		MyFree((void *)otab);
+		MyFree(otab);
 	    }
 	return;
 }
