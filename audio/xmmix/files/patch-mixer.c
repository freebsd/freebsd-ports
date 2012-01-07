--- ./mixer.c.orig	1996-11-07 11:00:26.000000000 -0500
+++ ./mixer.c	2012-01-07 00:24:32.000000000 -0500
@@ -124,7 +124,7 @@
  *	Nothing
  */
 STATIC void
-do_ioctl(int cmd, int *arg, char *name, int dir)
+do_ioctl(long cmd, int *arg, char *name, int dir)
 {
 	int	ret;
 	char	errmsg[STR_BUF_SZ];
