--- src/common/text.c.orig	Sun Sep 21 12:36:15 2003
+++ src/common/text.c	Sat Oct 25 22:29:56 2003
@@ -446,7 +446,7 @@
 get_stamp_str (char *fmt, time_t tim, char **ret)
 {
 	char dest[128];
-	int len;
+	gsize len;
 
 	len = strftime (dest, sizeof (dest), fmt, localtime (&tim));
 	if (len)
