--- tools/rlecat.c.orig	Thu Nov 29 16:39:51 2007
+++ tools/rlecat.c	Thu Nov 29 16:40:44 2007
@@ -62,7 +62,7 @@
  *  	repeat count.  If the collation flag (-c) is specified, then
  *  	all images will be read before starting to repeat.
  */
-void
+int
 main( argc, argv )
 int argc;
 char **argv;
@@ -110,7 +110,7 @@
 	    nflag = 0;		/* Not really repeating! */
 	else
 	{
-	    mktemp( temp );	/* Make a temporary file name */
+	    mkstemp( temp );	/* Make a temporary file name */
 	    tmpfile = rle_open_f( cmd_name( argv ), temp, "w+" );
 	}
     }
