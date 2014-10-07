--- lists.c.orig	2014-08-07 15:25:31.000000000 +0200
+++ lists.c	2014-08-07 15:26:01.000000000 +0200
@@ -190,7 +190,7 @@
 
 	    /* Any embedded "'s?  Escape them */
 
-	    while( p = (char *)memchr( op, '"',  ep - op ) )
+	    while( ( p = (char *)memchr( op, '"',  ep - op ) ) )
 	    {
 		fwrite( op, p - op, 1, out );
 		fputc( '\\', out );
