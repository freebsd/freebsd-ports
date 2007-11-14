--- ircd/s_misc.c.orig	2007-11-14 03:09:05.000000000 +0600
+++ ircd/s_misc.c	2007-11-14 03:09:14.000000000 +0600
@@ -1032,7 +1032,7 @@
 	    {
 		last = motd->next;
 		MyFree(motd->line);
-		MyFree((char *)motd);
+		MyFree(motd);
 	    }
 	motd_tm = *localtime(&Sb.st_mtime);
 	(void)dgets(-1, line, 0, &head, &tail); /* initialize line */
