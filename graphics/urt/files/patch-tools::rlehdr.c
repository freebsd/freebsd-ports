--- tools/rlehdr.c.orig	Thu Mar 10 21:04:49 2005
+++ tools/rlehdr.c	Thu Mar 10 21:13:14 2005
@@ -289,7 +289,7 @@
 		{
 		    if ( (cp = index( the_comment, '\n' )) )
 			printf( ", %s=%.*s", *comment_names,
-				cp - the_comment - 1, the_comment );
+				*comment_names,cp - the_comment - 1, the_comment );
 		    else
 			printf( ", %s=%s", *comment_names, the_comment );
 		    break;
