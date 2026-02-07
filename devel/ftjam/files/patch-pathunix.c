--- pathunix.c.orig	2006-06-05 12:52:12.000000000 +0200
+++ pathunix.c	2014-08-07 15:41:24.000000000 +0200
@@ -110,7 +110,7 @@
 	p = 0;
 	q = file;
 
-	while( q = (char *)memchr( q, '.', end - q ) )
+	while( ( q = (char *)memchr( q, '.', end - q ) ) )
 	    p = q++;
 
 	if( p )
@@ -136,6 +136,7 @@
 	char	*file,
 	int	binding )
 {
+	(void)binding;
 	/* Start with the grist.  If the current grist isn't */
 	/* surrounded by <>'s, add them. */
 
