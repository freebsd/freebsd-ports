--- adventure/crc.c.bak	Sat Feb 23 01:59:45 2002
+++ adventure/crc.c	Wed Sep 29 03:29:37 2004
@@ -120,7 +120,7 @@
 
 /* Process nr bytes at a time; ptr points to them */
 u_long
-crc(const char *ptr, size_t nr)
+crc(const char *ptr, ssize_t nr)
 {
 	int 	i;
 	const char 	*p;
