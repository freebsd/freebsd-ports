--- tools/into.c.orig	1992-04-30 23:10:15.000000000 +0900
+++ tools/into.c	2012-10-16 01:10:25.000000000 +0900
@@ -27,6 +27,8 @@
 
 #include "rle_config.h"
 #include <stdio.h>
+#include <string.h>
+#include <unistd.h>
 #include <errno.h>
 #include <sys/types.h>
 #include <sys/param.h>			/* for MAXPATHLEN */
@@ -41,9 +43,12 @@
 short forceflg;				/* overwrite an unwritable file? */
 
 extern int errno;
+
+#ifndef BSD
 extern char *sys_errlist[];
+#endif
 
-void
+int
 main(argc, argv)
 int argc;
 char **argv;
@@ -82,7 +87,7 @@
     }
     else
 	strcpy( buf, temp );
-    mktemp( buf );
+    mkstemp( buf );
 
     if ( (outf = fopen( buf, "w" )) == NULL )
     {
