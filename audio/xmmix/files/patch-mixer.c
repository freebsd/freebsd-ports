--- mixer.c.orig	1996-11-07 16:00:26 UTC
+++ mixer.c
@@ -124,7 +124,7 @@ STATIC ctlinfo_t	ctlsav;		/* Saved state
  *	Nothing
  */
 STATIC void
-do_ioctl(int cmd, int *arg, char *name, int dir)
+do_ioctl(long cmd, int *arg, char *name, int dir)
 {
 	int	ret;
 	char	errmsg[STR_BUF_SZ];
