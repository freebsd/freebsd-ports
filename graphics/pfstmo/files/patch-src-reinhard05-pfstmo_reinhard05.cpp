--- src/reinhard05/pfstmo_reinhard05.cpp.orig	2008-09-04 12:46:49.000000000 +0000
+++ src/reinhard05/pfstmo_reinhard05.cpp	2014-06-18 15:29:52.328951402 +0000
@@ -157,6 +157,14 @@
   try {
     pfstmo_reinhard05( argc, argv );
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
