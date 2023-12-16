--- ircd/ircd_ext.h.orig	2023-12-06 19:35:50 UTC
+++ ircd/ircd_ext.h
@@ -37,7 +37,6 @@ extern char *debugmode;
 extern int debuglevel;
 extern int bootopt;
 extern char *debugmode;
-extern char *sbrk0;
 extern char *tunefile;
 #ifdef DELAY_CLOSE
 extern time_t nextdelayclose;
