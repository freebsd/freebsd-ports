--- lib/rle_open_f.c.orig	1993-05-14 06:28:51.000000000 +0900
+++ lib/rle_open_f.c	2012-10-15 22:07:34.000000000 +0900
@@ -10,6 +10,9 @@
 
 #include "rle_config.h"
 #include <stdio.h>
+#include <string.h>
+#include <sys/types.h>
+#include <unistd.h>
 
 #ifndef NO_OPEN_PIPES
 /* Need to have a SIGCLD signal catcher. */
@@ -56,6 +59,7 @@
     CONST_DECL char *err_str;
     register char *cp;
     char *combuf;
+    size_t combuf_size;
 
 #ifdef STDIO_NEEDS_BINARY
     char mode_string[32];	/* Should be enough. */
@@ -150,7 +154,8 @@
 	else if ( cp > file_name && *cp == '.' && *(cp + 1) == 'Z' )
 	{
 	    int thepid;		/* PID from my_popen. */
-	    combuf = (char *)malloc( 20 + strlen( file_name ) );
+	    combuf_size = 20 + strlen( file_name );
+	    combuf = (char *)malloc( combuf_size );
 	    if ( combuf == NULL )
 	    {
 		err_str = "%s: out of memory opening (compressed) %s for %s";
@@ -158,11 +163,11 @@
 	    }
 
 	    if ( *mode == 'w' )
-		sprintf( combuf, "compress > %s", file_name );
+		snprintf( combuf, combuf_size, "compress > %s", file_name );
 	    else if ( *mode == 'a' )
-		sprintf( combuf, "compress >> %s", file_name );
+		snprintf( combuf, combuf_size, "compress >> %s", file_name );
 	    else
-		sprintf( combuf, "compress -d < %s", file_name );
+		snprintf( combuf, combuf_size, "compress -d < %s", file_name );
 
 	    fp = my_popen( combuf, mode, &thepid );
 	    free( combuf );
@@ -256,7 +261,6 @@
     int pipefd[2];
     int i;
     char *argv[4];
-    extern int errno;
 
     /* Check args. */
     if ( *mode != 'r' && *mode != 'w' )
