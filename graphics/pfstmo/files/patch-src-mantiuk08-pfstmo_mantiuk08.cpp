--- src/mantiuk08/pfstmo_mantiuk08.cpp.orig	2012-06-25 13:03:28.000000000 +0000
+++ src/mantiuk08/pfstmo_mantiuk08.cpp	2014-06-18 15:29:52.308951834 +0000
@@ -31,7 +31,6 @@
 
 #include <config.h>
 
-#include <iostream>
 #include <stdio.h>
 #include <stdlib.h>
 #include <math.h>
@@ -356,6 +355,14 @@
   try {
     tmo_mantiuk08( argc, argv );
   }
+  catch (std::bad_alloc ex) {
+    fprintf(stderr, PROG_NAME " error: out of memory\n");
+    return EXIT_FAILURE;
+  }
+  catch (std::exception ex) {
+    fprintf(stderr, PROG_NAME " error: %s\n", ex.what());
+    return EXIT_FAILURE;
+  }
   catch( pfs::Exception ex ) {
     fprintf( stderr, PROG_NAME " error: %s\n", ex.getMessage() );
     return EXIT_FAILURE;
