--- lib/rle_open_f.c.orig	Thu May 13 21:28:51 1993
+++ lib/rle_open_f.c	Wed Jan 12 16:06:07 2005
@@ -56,6 +56,7 @@
     CONST_DECL char *err_str;
     register char *cp;
     char *combuf;
+    size_t combuf_size;
 
 #ifdef STDIO_NEEDS_BINARY
     char mode_string[32];	/* Should be enough. */
@@ -63,7 +64,7 @@
     /* Concatenate a 'b' onto the mode. */
     mode_string[0] = mode[0];
     mode_string[1] = 'b';
-    strcpy( mode_string + 2, mode + 1 );
+    strncpy( mode_string + 2, mode + 1, sizeof(mode_string + 2) );
     mode = mode_string;
 #endif
 
@@ -150,7 +151,8 @@
 	else if ( cp > file_name && *cp == '.' && *(cp + 1) == 'Z' )
 	{
 	    int thepid;		/* PID from my_popen. */
-	    combuf = (char *)malloc( 20 + strlen( file_name ) );
+	    combuf_size = 20 + strlen( file_name );
+	    combuf = (char *)malloc( combuf_size );
 	    if ( combuf == NULL )
 	    {
 		err_str = "%s: out of memory opening (compressed) %s for %s";
@@ -158,11 +160,11 @@
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
