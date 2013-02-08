--- tools/rlehdr.c.orig	1992-04-30 23:12:10.000000000 +0900
+++ tools/rlehdr.c	2012-10-16 01:10:34.000000000 +0900
@@ -32,6 +32,7 @@
 */
 
 #include <stdio.h>
+#include <string.h>
 #include "rle.h"
 #include "../patchlevel.h"
 
@@ -65,7 +66,7 @@
  *	[None]
  */
 
-void
+int
 main( argc, argv )
 int argc;
 char **argv;
@@ -289,7 +290,7 @@
 		{
 		    if ( (cp = index( the_comment, '\n' )) )
 			printf( ", %s=%.*s", *comment_names,
-				cp - the_comment - 1, the_comment );
+				*comment_names,cp - the_comment - 1, the_comment );
 		    else
 			printf( ", %s=%s", *comment_names, the_comment );
 		    break;
