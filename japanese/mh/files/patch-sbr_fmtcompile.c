--- sbr/fmtcompile.c.orig	2001-04-02 16:06:09 UTC
+++ sbr/fmtcompile.c
@@ -24,6 +24,8 @@ static int infunction;			/* function nesting cnt */
 extern char *getusr();
 extern struct mailname fmt_mnull;
 
+struct comp *wantcomp[128];
+
 struct ftable {
     char	*name;		/* function name */
     char	type;		/* argument type */
