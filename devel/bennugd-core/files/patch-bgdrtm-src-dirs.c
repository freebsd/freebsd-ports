--- bgdrtm/src/dirs.c.orig	2013-09-12 05:40:07.257227650 +0400
+++ bgdrtm/src/dirs.c	2013-09-12 05:40:48.926466619 +0400
@@ -261,7 +261,7 @@
     /* Convert '*.*' to '*' */
     if ( fptr > hDir->pattern + 2 && fptr[ -1 ] == '*' && fptr[ -2 ] == '.' && fptr[ -3 ] == '*' ) fptr[ -2 ] = 0;
 
-#if defined(TARGET_MAC) || defined(TARGET_BEOS)
+#if defined(TARGET_MAC) || defined(TARGET_BEOS) || defined (TARGET_BSD)
     r = glob( hDir->pattern, GLOB_ERR | GLOB_NOSORT, NULL, &hDir->globd );
 #else
     r = glob( hDir->pattern, GLOB_ERR | GLOB_PERIOD | GLOB_NOSORT, NULL, &hDir->globd );
