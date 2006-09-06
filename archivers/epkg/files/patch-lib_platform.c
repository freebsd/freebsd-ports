--- ./lib/platform.c.orig	Wed Apr 21 11:00:26 2004
+++ ./lib/platform.c	Wed Sep  6 08:32:24 2006
@@ -213,7 +213,7 @@
 	*/
 	if (strcmp(ut.sysname, "AIX") == 0)
 	{
-#ifdef __ia64
+#if defined __ia64 && defined _AIX
 		if (__ia64())
 			strlcpy(archbuf, "ia64", sizeof(archbuf));
 		else /* if (__power_pc() || __power_rs()) */
