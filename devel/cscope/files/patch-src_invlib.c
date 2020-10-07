--- src/invlib.c.orig	2020-10-05 13:04:06 UTC
+++ src/invlib.c
@@ -103,7 +103,7 @@ static	int	zipf[ZIPFSIZE + 1];
 long
 invmake(char *invname, char *invpost, FILE *infile)
 {
-	unsigned char	*s;
+	char	*s;
 	long	num;
 	int	i;
 	long	fileindex = 0;	/* initialze, to avoid warning */
