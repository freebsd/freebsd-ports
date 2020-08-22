--- source/commands.c.orig	2014-11-04 10:54:23 UTC
+++ source/commands.c
@@ -118,7 +118,6 @@ extern	int	doing_notice;
 
 static	void	oper_password_received (char *, char *);
 
-int	no_hook_notify = 0;
 int	load_depth = -1;
 
 extern char	cx_function[];
