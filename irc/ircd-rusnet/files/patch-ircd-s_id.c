--- ircd/s_id.c.orig	2007-11-14 03:08:39.000000000 +0600
+++ ircd/s_id.c	2007-11-14 03:08:52.000000000 +0600
@@ -140,7 +140,7 @@
     if (chptr->history == 0 ||
 	(timeofday - chptr->history) >LDELAYCHASETIMELIMIT+DELAYCHASETIMELIMIT)
 	{
-	    MyFree((char *)chptr);
+	    MyFree(chptr);
 	    return;
 	}
 
@@ -182,7 +182,7 @@
 		    *chptr = del->nextch;
 		    istat.is_cchan--;
 		    istat.is_cchanmem -= sizeof(aChannel) +strlen(del->chname);
-		    MyFree((char *)del);
+		    MyFree(del);
 		}
 	    else
 		    chptr = &((*chptr)->nextch);
