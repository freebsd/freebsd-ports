
$FreeBSD$

--- jday.c.orig	Mon Dec 30 16:49:30 2002
+++ jday.c	Mon Dec 30 16:49:44 2002
@@ -122,7 +122,7 @@
 				if ( day < 1 ) day = 1;
 			case 3:
 		if ( ! strcmp((const char *)argv[1], (const char *) "-d") ) {
-	if ( 3 != sscanf( argv[2], "%d/%d/%d", & year, & mo, & day ) ) {
+	if ( 3 != sscanf( argv[2], "%ld/%d/%d", & year, & mo, & day ) ) {
 fprintf( stderr, "failed sscanf for ymd\n" );
 		exit (-1);
 	} else {
