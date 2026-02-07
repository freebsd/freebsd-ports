--- phoon.c.orig	2014-06-29 23:07:16 UTC
+++ phoon.c
@@ -534,7 +534,7 @@ main( int argc, char** argv )
     if ( argc - argn == 0 )
 	{
 	/* No arguments present - use the current date and time. */
-	t = time( (time_t) 0 );
+	t = time( NULL );
 	}
     else if ( argc - argn == 1 || argc - argn == 2 || argc - argn == 3 )
 	{
