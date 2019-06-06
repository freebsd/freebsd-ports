--- source/alias.c.orig	2019-01-18 10:29:41 UTC
+++ source/alias.c
@@ -2528,7 +2528,7 @@ function_userhost(u_char *input)
 static u_char	*
 function_strip(u_char *input)
 {
-	u_char	tmpbuf[128], *result;
+	u_char	tmpbuf[128], *result = NULL;
 	u_char	*retval = NULL;
 	u_char	*chars;
 	u_char	*cp, *dp;
