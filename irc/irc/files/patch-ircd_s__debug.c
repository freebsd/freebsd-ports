--- ircd/s_debug.c.orig	2023-12-06 19:34:45 UTC
+++ ircd/s_debug.c
@@ -687,9 +687,8 @@ void	count_memory(aClient *cptr, char *nick, int debug
 		sendto_one(cptr, ":%s %d %s :TOTAL: %lu [REAL]",
 			me.name, RPL_STATSDEBUG, nick, d_tot);
 	}
-	sendto_one(cptr, ":%s %d %s :TOTAL: %d sbrk(0)-etext: %u",
-		   me.name, RPL_STATSDEBUG, nick, tot,
-		   (u_long)sbrk((size_t)0)-(u_long)sbrk0);
+	sendto_one(cptr, ":%s %d %s :TOTAL: %d",
+		   me.name, RPL_STATSDEBUG, nick, tot);
 	return;
 }
 
