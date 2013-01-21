--- tools/mergechan.c.orig	1992-01-24 01:25:19.000000000 +0900
+++ tools/mergechan.c	2012-10-15 23:22:24.000000000 +0900
@@ -19,7 +19,7 @@
 
 #define RLE_END 32768		/* This should be in rle.h */
 
-void
+int
 main( argc, argv )
 int argc;
 char ** argv;
@@ -79,7 +79,7 @@
 	    {
 		fprintf( stderr,
 		 "%s: Images %d and %d are both from the standard input\n",
-			 stdin_used, i );
+			argv[0], stdin_used, i );
 		exit( -1 );
 	    }
     }
