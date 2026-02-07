--- sbr/ruserpass.c.orig
+++ sbr/ruserpass.c
@@ -66,7 +66,6 @@
 	char myname[MAXHOSTNAMELEN], *mydomain;
 	int t, i, c, usedefault = 0;
 	struct stat stb;
-	extern int errno;
 
 	hdir = getenv("HOME");
 	if (hdir == NULL)
