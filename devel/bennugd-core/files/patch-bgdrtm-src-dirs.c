--- bgdrtm/src/dirs.c.orig	2009-07-09 05:10:52.000000000 +0400
+++ bgdrtm/src/dirs.c	2009-11-06 05:50:02.000000000 +0300
@@ -230,9 +230,7 @@
     /* Convert *.* to * */
     if ( fptr > path_final + 2 && fptr[ -1 ] == '*' && fptr[ -2 ] == '.' && fptr[ -3 ] == '*' ) fptr[ -2 ] = 0;
 
-#if defined(TARGET_MAC)
-    glob( path_final, GLOB_ERR | GLOB_NOSORT, NULL, &hDir->globd );
-#elif defined(TARGET_BEOS)
+#if defined(TARGET_MAC) || defined(TARGET_BEOS) || defined(TARGET_BSD)
     glob( path_final, GLOB_ERR | GLOB_NOSORT, NULL, &hDir->globd );
 #else
     glob( path_final, GLOB_ERR | GLOB_PERIOD | GLOB_NOSORT, NULL, &hDir->globd );
