--- tools/rleaddcom.c.orig	1992-04-30 23:11:00.000000000 +0900
+++ tools/rleaddcom.c	2012-10-16 01:10:13.000000000 +0900
@@ -26,6 +26,8 @@
  */
 
 #include <stdio.h>
+#include <string.h>
+#include <unistd.h>
 #include "rle.h"
 #include <sys/types.h>
 #include <sys/param.h>			/* for MAXPATHLEN */
@@ -60,7 +62,7 @@
  * Algorithm:
  *	[None]
  */
-void
+int
 main( argc, argv )
 int argc;
 char **argv;
@@ -118,7 +120,7 @@
 	}
 	else
 	    strcpy( buf, temp );
-	mktemp( buf );
+	mkstemp( buf );
 #ifndef NO_OPEN_PIPES
 	/* Compressed file special case. */
 	cp = i_fname + strlen( i_fname ) - 2;
