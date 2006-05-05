--- ./sv_user.c.orig	Thu May 19 17:56:13 2005
+++ ./sv_user.c	Sun Feb 26 11:23:56 2006
@@ -1183,7 +1183,7 @@
 	sv_client->downloadsize = FS_LoadFile (name, NULL);
 
 	//adjust case and re-try
-#ifdef LINUX
+#if defined(__linux__) || defined(__FreeBSD__)
 	if (sv_client->downloadsize == -1)
 	{
 		Q_strlwr (name);
