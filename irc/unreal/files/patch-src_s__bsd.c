--- src/s_bsd.c.orig	2016-09-03 19:34:06 UTC
+++ src/s_bsd.c
@@ -455,7 +455,7 @@ int  inetport(aClient *cptr, char *name,
 	 */
 	if (cptr->fd == -1)
 	{
-		cptr->fd = socket(AFINET, SOCK_STREAM, 0);
+		cptr->fd = socket(AFINET, SOCK_STREAM, IPPROTO_TCP);
 	}
 	if (cptr->fd < 0)
 	{
