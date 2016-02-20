--- soundcard/winlog.c.orig	2002-12-31 11:30:52 UTC
+++ soundcard/winlog.c
@@ -44,7 +44,7 @@
 
 /* ---------------------------------------------------------------------- */
 
-unsigned int log_verblevel = 0;
+extern unsigned int log_verblevel = 0;
 static HANDLE logh = NULL;
 
 /* ---------------------------------------------------------------------- */
