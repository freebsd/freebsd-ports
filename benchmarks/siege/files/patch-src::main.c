--- src/main.c.orig	Thu Jul 17 21:50:43 2003
+++ src/main.c	Thu Nov 27 01:27:55 2003
@@ -301,6 +301,12 @@
    */
   fprintf( stderr, "** " ); 
   display_version( FALSE );
+  /* prevents from segfaulting */
+  if ( my.cusers == 0) {
+		fprintf(stderr, "\nERROR: concurrent users is not set or set to 0.\n");
+		display_help();
+		exit (EXIT_FAILURE);
+	};
   fprintf( stderr, "** Preparing %d concurrent users for battle.\n", my.cusers );
   fprintf( stderr, "The server is now under siege..." );
   if( my.verbose ){ fprintf( stderr, "\n" ); }
