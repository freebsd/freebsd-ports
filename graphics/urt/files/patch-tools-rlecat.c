--- tools/rlecat.c.orig	1992-04-30 23:11:44.000000000 +0900
+++ tools/rlecat.c	2012-10-16 00:43:29.000000000 +0900
@@ -15,6 +15,7 @@
 */
 
 #include <stdio.h>
+#include <unistd.h>
 #include "rle.h"
 #include "rle_raw.h"
 
@@ -62,7 +63,7 @@
  *  	repeat count.  If the collation flag (-c) is specified, then
  *  	all images will be read before starting to repeat.
  */
-void
+int
 main( argc, argv )
 int argc;
 char **argv;
@@ -110,7 +111,7 @@
 	    nflag = 0;		/* Not really repeating! */
 	else
 	{
-	    mktemp( temp );	/* Make a temporary file name */
+	    mkstemp( temp );	/* Make a temporary file name */
 	    tmpfile = rle_open_f( cmd_name( argv ), temp, "w+" );
 	}
     }
