--- util.c.orig	1997-05-31 17:20:40 UTC
+++ util.c
@@ -36,7 +36,7 @@ skipch (char *str, char ch)
 }
 
 char *
-getline (FILE *fp, Bool cont)
+get_line (FILE *fp, Bool cont)
 {
 	char	*buf;
 	int	size;
