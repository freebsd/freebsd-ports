--- src/mantiuk06/pfstmo_mantiuk06.cpp.orig	2009-09-02 01:11:39.000000000 +0000
+++ src/mantiuk06/pfstmo_mantiuk06.cpp	2014-06-18 15:29:52.298957047 +0000
@@ -219,6 +219,14 @@
   try {
     tmo_mantiuk06( argc, argv );
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
