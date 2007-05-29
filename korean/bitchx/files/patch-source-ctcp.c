--- source/ctcp.c.orig	Mon Dec 18 22:26:09 2006
+++ source/ctcp.c	Mon Dec 18 22:26:24 2006
@@ -176,7 +176,7 @@
 
 /* CDE do ops and unban logging */
 
-static char	*ctcp_type[] =
+char	*ctcp_type[] =
 {
 	"PRIVMSG",
 	"NOTICE"
