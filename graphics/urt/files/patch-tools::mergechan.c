--- tools/mergechan.c.orig	Thu Mar 10 20:58:34 2005
+++ tools/mergechan.c	Thu Mar 10 21:00:31 2005
@@ -79,7 +79,7 @@
 	    {
 		fprintf( stderr,
 		 "%s: Images %d and %d are both from the standard input\n",
-			 stdin_used, i );
+			argv[0], stdin_used, i );
 		exit( -1 );
 	    }
     }
